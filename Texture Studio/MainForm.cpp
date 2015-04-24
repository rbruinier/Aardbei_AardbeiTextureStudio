//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fcntl.h>
#include <sys\stat.h>
#include <io.h>

#include "MainForm.h"

#include "Other\Layer.h"
#include "Other\NewForm.h"
#include "Other\AboutForm.h"
#include "Other\Updates.h"

#include "Filters.h"

#include "Filters\FilterPlasma.h"
#include "Filters\FilterFractalPlasma.h"
#include "Filters\FilterCells.h"
#include "Filters\FilterText.h"
#include "Filters\FilterBrush.h"
#include "Filters\FilterNoise.h"
#include "Filters\FilterRectangle.h"

#include "Filters\FilterGaussianBlur.h"
#include "Filters\FilterMotionBlur.h"
#include "Filters\FilterEdge.h"
#include "Filters\FilterEmboss.h"
#include "Filters\FilterSobel.h"
#include "Filters\FilterBoxBlur.h"
#include "Filters\FilterTopLeft.h"
#include "Filters\FilterDirBlur.h"

#include "Filters\FilterCopy.h"
#include "Filters\FilterAdd.h"
#include "Filters\FilterSub.h"
#include "Filters\FilterMul.h"
#include "Filters\FilterNotNull.h"
#include "Filters\FilterMix.h"
#include "Filters\FilterShade.h"

#include "Filters\FilterHsv.h"
#include "Filters\FilterBrightness.h"
#include "Filters\FilterContrast.h"
#include "Filters\FilterInvert.h"

#include "Filters\FilterSineDistort.h"
#include "Filters\FilterTile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

TextureGenerator *generator = NULL;

short textureWidth;
short textureHeight;

short mousePositionX = 0;
short mousePositionY = 0;
bool  mouseClicked   = false;
extern bool mouseOpenBrushOnClick = true;

const int menuIndexFile     = 0;
const int menuIndexGenerate = 1;
const int menuIndexColor    = 2;
const int menuIndexBlur     = 3;
const int menuIndexDistort  = 4;
const int menuIndexLayer    = 5;
const int menuIndexWindows  = 6;
//const int menuIndexUndo     = 7;

const int menuIndexClose    = 2;
const int menuIndexSave     = 4;
const int menuIndexSaveAs   = 5;

int nrLayers = 0;
TfrmLayer *frmLayers[255];

TfrmLayer *frmLayerActive = NULL;

unsigned int *layerPreview = NULL;          // wordt als backup layer gebruikt

short nrFilters = 0;                         // used for saving and undoing
Filter *filters[2048];                       // used for saving and undoing

char *textureFilename = "";

bool workingOnTexture = false;              // staat er een texture open op moment
bool havesFilename    = false;              // is deze texture al eens gesaved?
bool loadingTexture   = false;              // als je aan het laden bent, niet filter ding updaten
bool openedByClicking = false;              // als ATS via file is geopend
bool firstTime        = true;               // voor code die alleen bij start up doorlopen mag worden

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
    ForceCurrentDirectory = true;
}
//---------------------------------------------------------------------------

// voor het bijwerken van registry
void RegIns(char *name, char *val)
{
    HKEY tmp;
    RegCreateKey(HKEY_CLASSES_ROOT, name, &tmp);
    RegSetValue(tmp, NULL, REG_SZ, val, lstrlen(val));
    RegCloseKey(tmp);
}

#include <dos.h>
void __fastcall TfrmMain::FormActivate(TObject *Sender)
{
    if (firstTime)
    {
        this->WindowState = wsMaximized;

        RegIns(".ats", "atsfile");

        RegIns("atsfile", "Aardbei Texture Studio 1");
        RegIns("atsfile\\shell", "");
        RegIns("atsfile\\shell\\open", "");
        char tmp[128];
        wsprintf(tmp, "%s \"%%1\"", Application->ExeName);
        RegIns("atsfile\\shell\\open\\command", tmp);
        wsprintf(tmp, "%s,0", Application->ExeName);
        RegIns("atsfile\\DefaultIcon",  tmp);

        mnuMain->Items->Items[menuIndexGenerate]->Visible = false;
        mnuMain->Items->Items[menuIndexDistort]->Visible  = false;
        mnuMain->Items->Items[menuIndexLayer]->Visible    = false;
        mnuMain->Items->Items[menuIndexColor]->Visible    = false;
        mnuMain->Items->Items[menuIndexBlur]->Visible     = false;
        Undo1->Enabled = false;
        Export1->Enabled = false;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexClose]->Visible  = false;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSave]->Visible   = false;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSaveAs]->Visible = false;

        Repaint();

        // if paramcount is 1, load the file
        if (ParamCount() == 1)
        {
            _sleep(1);
            openedByClicking = true;
            textureFilename = new char[ParamStr(1).Length() + 1];
            strcpy(textureFilename, ParamStr(1).c_str());
//            textureFilename = ParamStr(1).c_str();
            Open1Click(Sender);
        }

        firstTime = false;
   }
}
//---------------------------------------------------------------------------

bool CloseTexture(char *question = "Are you sure?", char *title = "Close")
{
    if (!workingOnTexture)
    {
        return true;
    }

    if (Application->MessageBoxA(question, title, MB_YESNO | MB_ICONWARNING) == mrNo)
    {
        return false;
    }

    if (generator != NULL)
    {
        delete generator;
    }

    if (layerPreview != NULL)
    {
        delete [] layerPreview;
    }

    for(int i = frmMain->MDIChildCount - 1; i >= 0; i--)
    {
        frmMain->MDIChildren[i]->Release();
    }

    for (int i = 0; i < nrFilters; i++)
    {
        delete filters[i];
    }

    nrFilters = 0;

    nrLayers  = 0;

    frmMain->mnuMain->Items->Items[menuIndexGenerate]->Visible = false;
    frmMain->mnuMain->Items->Items[menuIndexDistort]->Visible  = false;
    frmMain->mnuMain->Items->Items[menuIndexLayer]->Visible    = false;
    frmMain->mnuMain->Items->Items[menuIndexBlur]->Visible     = false;
    frmMain->Undo1->Enabled = false;
    frmMain->Export1->Enabled = false;
    frmMain->mnuMain->Items->Items[menuIndexColor]->Visible    = false;
    frmMain->mnuMain->Items->Items[menuIndexFile]->Items[menuIndexClose]->Visible  = false;
    frmMain->mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSave]->Visible   = false;
    frmMain->mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSaveAs]->Visible = false;

    workingOnTexture = false;

    frmMain->Caption = "Aardbei Texture Studio";

    frmMain->dlgSaveAs->FileName = "";
    frmMain->dlgOpen->FileName = "";
    frmMain->dlgExportTGA->FileName = "";

    return true;
}
//---------------------------------------------------------------------------

void OptimizeFilterList()
{
    int nrFiltersNew = 0;
    Filter **filtersNew = new Filter*[nrFilters]; // hij kan toch nooit groter worden

    // check voor dubbele layer wisselingen
    for (int i = 0; i < nrFilters; i++)
    {
        filtersNew[nrFiltersNew] = filters[i];
        if (i < (nrFilters - 1))
        {
            if ((filtersNew[nrFiltersNew]->command == TEXGEN_CHANGELAYER) &&
                (filters[i + 1]->command == TEXGEN_CHANGELAYER))
            {
                nrFiltersNew = nrFiltersNew;
            }
            else
            {
                nrFiltersNew = nrFiltersNew + 1;
            }
        }
        else
        {
            nrFiltersNew = nrFiltersNew + 1;
        }
    }

    for (int i = 0; i < nrFiltersNew; i++)
    {
        filters[i] = filtersNew[i];
    }

    nrFilters = nrFiltersNew;

    // check voor nieuw en dan layer swap filter waste
    int tempLayerNr = 0;
    nrFiltersNew = 0;
    for (int i = 0; i < nrFilters; i++)
    {
        if (filters[i]->command == TEXGEN_NEWLAYER)
        {
            tempLayerNr++;
        }
        filtersNew[nrFiltersNew] = filters[i];
        if (i >= 1)
        {
            if ((filtersNew[nrFiltersNew]->command == TEXGEN_CHANGELAYER) &&
                (filters[i - 1]->command == TEXGEN_NEWLAYER))
            {
                // kijken of het wel dezelfde layer is
                FilterChangeLayer *tempFilterPtr = (FilterChangeLayer*) filtersNew[nrFiltersNew];
                if (tempFilterPtr->layerNr == tempLayerNr)
                {
                    nrFiltersNew = nrFiltersNew;
                }
                else
                {
                    nrFiltersNew = nrFiltersNew + 1;
                }
            }
            else
            {
                nrFiltersNew = nrFiltersNew + 1;
            }
        }
        else
        {
            nrFiltersNew = nrFiltersNew + 1;
        }
    }

    for (int i = 0; i < nrFiltersNew; i++)
    {
        filters[i] = filtersNew[i];
    }

    nrFilters = nrFiltersNew;

    delete [] filtersNew;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::New1Click(TObject *Sender)
{
    if (workingOnTexture)
    {
        if (CloseTexture("This will close current texture, are you sure?", "Warning") == false)
        {
            return;
        }
    }

    frmNew = new TfrmNew(this);

    if (frmNew->ShowModal() == mrOk)
    {
        nrLayers = 0;

        textureWidth  = newInputTextureWidth;
        textureHeight = newInputTextureHeight;

        generator = new TextureGenerator(textureWidth, textureHeight);

        NewLayer1Click(this);

        layerPreview = new unsigned int[textureWidth * textureHeight];

        mnuMain->Items->Items[menuIndexGenerate]->Visible = true;
        mnuMain->Items->Items[menuIndexDistort]->Visible  = true;
        mnuMain->Items->Items[menuIndexLayer]->Visible    = true;
        mnuMain->Items->Items[menuIndexBlur]->Visible     = true;
        Undo1->Enabled = true;
        Export1->Enabled = true;
        mnuMain->Items->Items[menuIndexColor]->Visible    = true;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexClose]->Visible  = true;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSave]->Visible   = true;
        mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSaveAs]->Visible = true;

        Cascade();

        workingOnTexture = true;
        havesFilename    = false;

        Caption = "Aardbei Texture Studio";
    }

    frmNew->Release();
}
//---------------------------------------------------------------------------


int GetSizeOfFilter(int command)
{
    int size = -1;
    switch (command)
    {
        case TEXGEN_NEWLAYER:
            size = sizeof(Filter);
            break;
        case TEXGEN_COPY:
            size = sizeof(FilterCopy);
            break;
        case TEXGEN_ADD:
            size = sizeof(FilterAdd);
            break;
        case TEXGEN_SUB:
            size = sizeof(FilterSub);
            break;
        case TEXGEN_MUL:
            size = sizeof(FilterMul);
            break;
        case TEXGEN_NOTNULLCOPY:
            size = sizeof(FilterNotNull);
            break;
        case TEXGEN_MIX:
            size = sizeof(FilterMix);
            break;
        case TEXGEN_SHADE:
            size = sizeof(FilterShade);
            break;
        case TEXGEN_CHANGELAYER:
            size = sizeof(FilterChangeLayer);
            break;
        case TEXGEN_PLASMA:
            size = sizeof(FilterPlasma);
            break;
        case TEXGEN_FRACTALPLASMA:
            size = sizeof(FilterFractalPlasma);
            break;
        case TEXGEN_CELLS:
            size = sizeof(FilterCells);
            break;
        case TEXGEN_TEXT:
            size = sizeof(FilterText);
            break;
        case TEXGEN_BRUSH:
            size = sizeof(FilterBrush);
            break;
        case TEXGEN_NOISE:
            size = sizeof(FilterNoise);
            break;
        case TEXGEN_RECTANGLE:
            size = sizeof(FilterRectangle);
            break;
        case TEXGEN_GAUSSIANBLUR:
            size = sizeof(FilterGaussianBlur);
            break;
        case TEXGEN_MOTIONBLUR:
            size = sizeof(FilterMotionBlur);
            break;
        case TEXGEN_DIRBLUR:
            size = sizeof(FilterDirBlur);
            break;
        case TEXGEN_BOXBLUR:
            size = sizeof(Filter);
            break;
        case TEXGEN_EMBOSS:
            size = sizeof(Filter);
            break;
        case TEXGEN_EDGE:
            size = sizeof(Filter);
            break;
        case TEXGEN_SOBEL:
            size = sizeof(Filter);
            break;
        case TEXGEN_TOPLEFT:
            size = sizeof(Filter);
            break;
        case TEXGEN_HSV:
            size = sizeof(FilterHsv);
            break;
        case TEXGEN_CONTRAST:
            size = sizeof(FilterContrast);
            break;
        case TEXGEN_BRIGHTNESS:
            size = sizeof(FilterBrightness);
            break;
        case TEXGEN_INVERT:
            size = sizeof(Filter);
            break;
        case TEXGEN_SINEDISTORT:
            size = sizeof(FilterSineDistort);
            break;
        case TEXGEN_TILE:
            size = sizeof(FilterTile);
            break;
    }
    return size;
}

void __fastcall TfrmMain::Save1Click(TObject *Sender)
{
    if (!havesFilename)
    {
        SaveAs1Click(this);
        return;
    }

    OptimizeFilterList();

    int handle;

    if ((handle = open(textureFilename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, S_IWRITE)) == -1)
    {
        Application->MessageBoxA("Error creating file", "Error", MB_OK);
        return;
    }

    write(handle, TEXGEN_HEADER2, 4);

    write(handle, &nrFilters, 2);

    write(handle, &textureWidth, 2);
    write(handle, &textureHeight, 2);

    for (int i = 0; i < nrFilters; i++)
    {
        int size = GetSizeOfFilter(filters[i]->command);
        if (size != -1)
        {
            write(handle, filters[i], size);
        }
        else
        {
            Application->MessageBoxA("Wrong filter found :(", "Error", MB_OK);
            break;
        }
    }

    close(handle);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::SaveAs1Click(TObject *Sender)
{
    if (!workingOnTexture)
    {
        return;
    }

    if (dlgSaveAs->Execute() == false)
    {
        return;
    }

    textureFilename = dlgSaveAs->Files->Strings[0].c_str();

    havesFilename    = true;

    Caption = "Aardbei Texture Studio (" + AnsiString(textureFilename) + ")";

    Save1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Open1Click(TObject *Sender)
{
    if (CloseTexture("This will close current texture, are you sure?", "Warning") == false)
    {
        return;
    }

    if (openedByClicking)
    {
        openedByClicking = false;
    }
    else
    {
        if (dlgOpen->Execute() == false)
        {
            return;
        }

        textureFilename = dlgOpen->Files->Strings[0].c_str();
    }

    loadingTexture = true;

    nrLayers = 0;

    int handle;

    if ((handle = open(textureFilename, O_RDONLY | O_BINARY, S_IREAD)) == -1)
    {
        Application->MessageBoxA("Error opening file", "Error", MB_OK);
        return;
    }

    char header[5] = {'0','0','0','0','\0'};
    read(handle, header, 4);

    int version = - 1;
    if (strcmp(header, TEXGEN_HEADER1) == 0)
    {
        version = 1;
    }
    else
    if (strcmp(header, TEXGEN_HEADER2) == 0)
    {
        version = 2;
    }
    if (version == -1)
    {
        Application->MessageBoxA("Not a valid Aardbei Texture Studio file", "Error", MB_OK);
        return;
    }

    read(handle, &nrFilters, 2);

    read(handle, &textureWidth, 2);
    read(handle, &textureHeight, 2);

    generator = new TextureGenerator(textureWidth, textureHeight);

    NewLayer1Click(this);

    layerPreview = new unsigned int[textureWidth * textureHeight];

    for (int i = 0; i < nrFilters; i++)
    {
        stbMain->SimpleText = "Loading texture (filter " + IntToStr(i + 1) + " / " + IntToStr(nrFilters) + ")";
        unsigned char command;
        long offset = lseek(handle, 0, SEEK_CUR);
        read(handle, &command, 1);
        lseek(handle, offset, SEEK_SET);
        if (command == TEXGEN_NEWLAYER)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            NewLayer1Click(this);
        }
        if (command == TEXGEN_CHANGELAYER)
        {
            FilterChangeLayer *filter = new FilterChangeLayer();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterChangeLayer));
            frmLayers[filter->layerNr]->SetFocus();
        }
        if (command == TEXGEN_COPY)
        {
            FilterCopy *filter = new FilterCopy();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterCopy));
            generator->FilterCopy(generator->layerActive,
                                  generator->layers[filter->sourceNr],
                                  filter->channel);
        }
        if (command == TEXGEN_ADD)
        {
            FilterAdd *filter = new FilterAdd();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterAdd));
            generator->FilterAdd(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_SUB)
        {
            FilterSub *filter = new FilterSub();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterSub));
            generator->FilterSub(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_MUL)
        {
            FilterMul *filter = new FilterMul();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterMul));
            generator->FilterMul(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_NOTNULLCOPY)
        {
            FilterNotNull *filter = new FilterNotNull();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterNotNull));
            generator->FilterNotNullCopy(generator->layerActive,
                                         generator->layers[filter->sourceNr],
                                         filter->channel);
        }
        if (command == TEXGEN_MIX)
        {
            FilterMix *filter = new FilterMix();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterMix));
            generator->FilterMix(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->alpha,
                                 filter->channel);
        }
        if (command == TEXGEN_SHADE)
        {
            FilterShade *filter = new FilterShade();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterShade));
            generator->FilterShade(generator->layerActive,
                                   generator->layers[filter->sourceNr],
                                   filter->lightning,
                                   filter->channel);
        }
        if (command == TEXGEN_PLASMA)
        {
            FilterPlasma *filter = new FilterPlasma();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterPlasma));
            generator->FilterPlasma(filter->aantalX,
                                    filter->aantalY,
                                    filter->shiftX,
                                    filter->shiftY,
                                    filter->channel,
                                    filter->method);
        }
        if (command == TEXGEN_FRACTALPLASMA)
        {
            FilterFractalPlasma *filter = new FilterFractalPlasma();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterFractalPlasma));
            generator->FilterFractalPlasma(filter->factor,
                                           filter->seed,
                                           filter->channel,
                                           filter->method);
        }
        if (command == TEXGEN_CELLS)
        {
            FilterCells *filter = new FilterCells();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterCells));
            generator->FilterCells(filter->density,
                                   filter->strength,
                                   filter->seed,
                                   filter->channel,
                                   filter->method);
        }
        if (command == TEXGEN_TEXT)
        {
            FilterText *filter = new FilterText();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterText));
            generator->FilterText(filter->text,
                                  filter->font,
                                  filter->color,
                                  filter->size,
                                  filter->x,
                                  filter->y,
                                  filter->aa,
                                  filter->style,
                                  filter->clip,
                                  filter->method);
        }
        if (command == TEXGEN_BRUSH)
        {
            FilterBrush *filter = new FilterBrush();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterBrush));
            generator->FilterBrush(filter->x,
                                    filter->y,
                                    filter->size,
                                    filter->density,
                                    filter->hardness,
                                    filter->opacity,
                                    filter->color);
        }
        if (command == TEXGEN_NOISE)
        {
            FilterNoise *filter = new FilterNoise();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterNoise));
            generator->FilterNoise(filter->strength,
                                   filter->uniform,
                                   filter->multi,
                                   filter->seed,
                                   filter->channel,
                                   filter->method);
        }
        if (command == TEXGEN_RECTANGLE)
        {
            FilterRectangle *filter = new FilterRectangle();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterRectangle));
            generator->FilterRectangle(filter->x1,
                                       filter->y1,
                                       filter->x2,
                                       filter->y2,
                                       filter->color,
                                       filter->method);
        }
        if (command == TEXGEN_GAUSSIANBLUR)
        {
            FilterGaussianBlur *filter = new FilterGaussianBlur();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterGaussianBlur));
            if (version == 1)
            {
                filter->radius *= 27;
            }
            generator->FilterGaussianBlur(filter->radius);
        }
        if (command == TEXGEN_MOTIONBLUR)
        {
            FilterMotionBlur *filter = new FilterMotionBlur();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterMotionBlur));
            generator->FilterMotionBlur(filter->angle,
                                        filter->radius);
        }
        if (command == TEXGEN_DIRBLUR)
        {
            FilterDirBlur *filter = new FilterDirBlur();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterDirBlur));
            generator->FilterDirBlur(generator->layers[filter->sourceNr],
                                     filter->aantal,
                                     filter->channel);
        }
        if (command == TEXGEN_BOXBLUR)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterBoxBlur();
        }
        if (command == TEXGEN_EMBOSS)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterEmboss();
        }
        if (command == TEXGEN_SOBEL)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterSobel();
        }
        if (command == TEXGEN_EDGE)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterEdge();
        }
        if (command == TEXGEN_TOPLEFT)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterTopLeft();
        }
        if (command == TEXGEN_HSV)
        {
            FilterHsv *filter = new FilterHsv();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterHsv));
            generator->FilterHsv(filter->rotation,
                                 filter->saternation);
        }
        if (command == TEXGEN_INVERT)
        {
            Filter *filter = new Filter();
            filters[i] = filter;
            read(handle, filter, sizeof(Filter));
            generator->FilterInvert();
        }
        if (command == TEXGEN_CONTRAST)
        {
            FilterContrast *filter = new FilterContrast();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterContrast));
            generator->FilterContrast(filter->strength);
        }
        if (command == TEXGEN_BRIGHTNESS)
        {
            FilterBrightness *filter = new FilterBrightness();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterBrightness));
            generator->FilterBrightness(filter->strength);
        }
        if (command == TEXGEN_SINEDISTORT)
        {
            FilterSineDistort *filter = new FilterSineDistort();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterSineDistort));
            generator->FilterSineDistort(filter->nrX,
                                         filter->nrY,
                                         filter->ampX,
                                         filter->ampY,
                                         filter->shiftX,
                                         filter->shiftY);
        }
        if (command == TEXGEN_TILE)
        {
            FilterTile *filter = new FilterTile();
            filters[i] = filter;
            read(handle, filter, sizeof(FilterTile));
            generator->FilterTile(filter->repX,
                                  filter->repY);
        }
    }

    close(handle);

    mnuMain->Items->Items[menuIndexGenerate]->Visible = true;
    mnuMain->Items->Items[menuIndexDistort]->Visible  = true;
    mnuMain->Items->Items[menuIndexLayer]->Visible    = true;
    mnuMain->Items->Items[menuIndexBlur]->Visible     = true;
    Undo1->Enabled = true;
    Export1->Enabled = true;
    mnuMain->Items->Items[menuIndexColor]->Visible    = true;
    mnuMain->Items->Items[menuIndexFile]->Items[menuIndexClose]->Visible  = true;
    mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSave]->Visible   = true;
    mnuMain->Items->Items[menuIndexFile]->Items[menuIndexSaveAs]->Visible = true;

    Caption = "Aardbei Texture Studio (" + AnsiString(textureFilename) + ")";

    havesFilename    = true;
    workingOnTexture = true;
    loadingTexture   = false;

    for (int i = 0; i < nrLayers; i++)
    {
        frmLayers[i]->UpdateOutput();
    }

    stbMain->SimpleText = "";

    Cascade();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Close1Click(TObject *Sender)
{
    CloseTexture("This will close current texture, are you sure?", "Close");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Exit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Tile1Click(TObject *Sender)
{
    Tile();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Cascade1Click(TObject *Sender)
{
    Cascade();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Arrangeicons1Click(TObject *Sender)
{
    ArrangeIcons();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (CloseTexture("This will close current texture, are you sure?", "Close") == false)
    {
        Action = caNone;
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::NewLayer1Click(TObject *Sender)
{
    generator->AddLayer();

    frmLayers[nrLayers] = new TfrmLayer(this);
    frmLayers[nrLayers]->Setup((String("Layer ") + IntToStr(nrLayers + 1)).c_str(),
                               textureWidth,
                               textureHeight,
                               generator->layers[nrLayers]);

    frmLayerActive = frmLayers[nrLayers];

    if ((nrLayers != 0) && (!loadingTexture))
    {
        Filter *filter = new Filter();

        filter->command = TEXGEN_NEWLAYER;

        filters[nrFilters++] = filter;
    }

    nrLayers++;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Plasma1Click(TObject *Sender)
{
    frmPlasma->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FractalPlasma1Click(TObject *Sender)
{
    frmFractalPlasma->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::Cells1Click(TObject *Sender)
{
    frmCells->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Text1Click(TObject *Sender)
{
    frmText->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Brush1Click(TObject *Sender)
{
    frmBrush->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::Noise1Click(TObject *Sender)
{
    frmNoise->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Undo1Click(TObject *Sender)
{
    loadingTexture = true;

    OptimizeFilterList();

    // completely regenerate texture from list;
    for (int i = 0; i < nrLayers; i++)
    {
        memset(generator->layers[i], 0, textureWidth * textureHeight * 4);
    }

    if (nrFilters == 0)
    {
        return;
    }

    frmLayers[0]->SetFocus();
    frmLayerActive = frmLayers[0];

    nrFilters--;

    if (filters[nrFilters]->command == TEXGEN_NEWLAYER)
    {
        frmLayers[nrLayers - 1]->Release();
        delete [] generator->layers[nrLayers - 1];
        generator->nrLayers--;
        nrLayers--;
    }


    int tempLayerCounter = 0;
    for (int i = 0; i < nrFilters; i++)
    {
        stbMain->SimpleText = "Please wait while recalculating texture (filter " + IntToStr(i + 1) + " / " + IntToStr(nrFilters) + ")";
        int command = filters[i]->command;
        if (command == TEXGEN_NEWLAYER)
        {
            frmLayers[++tempLayerCounter]->SetFocus();
        }
        if (command == TEXGEN_CHANGELAYER)
        {
            frmLayers[((FilterChangeLayer*) filters[i])->layerNr]->SetFocus();
        }
        if (command == TEXGEN_COPY)
        {
            FilterCopy *filter = (FilterCopy*) filters[i];
            generator->FilterCopy(generator->layerActive,
                                  generator->layers[filter->sourceNr],
                                  filter->channel);
        }
        if (command == TEXGEN_ADD)
        {
            FilterAdd *filter = (FilterAdd*) filters[i];
            generator->FilterAdd(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_SUB)
        {
            FilterSub *filter = (FilterSub*) filters[i];
            generator->FilterSub(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_MUL)
        {
            FilterMul *filter = (FilterMul*) filters[i];
            generator->FilterMul(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->channel);
        }
        if (command == TEXGEN_NOTNULLCOPY)
        {
            FilterNotNull *filter = (FilterNotNull*) filters[i];
            generator->FilterNotNullCopy(generator->layerActive,
                                         generator->layers[filter->sourceNr],
                                         filter->channel);
        }
        if (command == TEXGEN_MIX)
        {
            FilterMix *filter = (FilterMix*) filters[i];
            generator->FilterMix(generator->layerActive,
                                 generator->layers[filter->sourceNr],
                                 filter->alpha,
                                 filter->channel);
        }
        if (command == TEXGEN_SHADE)
        {
            FilterShade *filter = (FilterShade*) filters[i];
            generator->FilterShade(generator->layerActive,
                                   generator->layers[filter->sourceNr],
                                   filter->lightning,
                                   filter->channel);
        }
        if (command == TEXGEN_PLASMA)
        {
            FilterPlasma *filter = (FilterPlasma*) filters[i];
            generator->FilterPlasma(filter->aantalX,
                                    filter->aantalY,
                                    filter->shiftX,
                                    filter->shiftY,
                                    filter->channel,
                                    filter->method);
        }
        if (command == TEXGEN_FRACTALPLASMA)
        {
            FilterFractalPlasma *filter = (FilterFractalPlasma*) filters[i];
            generator->FilterFractalPlasma(filter->factor,
                                           filter->seed,
                                           filter->channel,
                                           filter->method);
        }
        if (command == TEXGEN_CELLS)
        {
            FilterCells *filter = (FilterCells*) filters[i];
            generator->FilterCells(filter->density,
                                   filter->strength,
                                   filter->seed,
                                   filter->channel,
                                   filter->method);
        }
        if (command == TEXGEN_TEXT)
        {
            FilterText *filter = (FilterText*) filters[i];
            generator->FilterText(filter->text,
                                  filter->font,
                                  filter->color,
                                  filter->size,
                                  filter->x,
                                  filter->y,
                                  filter->aa,
                                  filter->style,
                                  filter->clip,
                                  filter->method);
        }
        if (command == TEXGEN_BRUSH)
        {
            FilterBrush *filter = (FilterBrush*) filters[i];
            generator->FilterBrush(filter->x,
                                    filter->y,
                                    filter->size,
                                    filter->density,
                                    filter->hardness,
                                    filter->opacity,
                                    filter->color);
        }
        if (command == TEXGEN_NOISE)
        {
            FilterNoise *filter = (FilterNoise*) filters[i];
            generator->FilterNoise(filter->strength,
                                   filter->uniform,
                                   filter->multi,
                                   filter->seed,
                                   filter->channel,
                                   filter->method);
        }
        if (command == TEXGEN_RECTANGLE)
        {
            FilterRectangle *filter = (FilterRectangle*) filters[i];
            generator->FilterRectangle(filter->x1,
                                       filter->y1,
                                       filter->x2,
                                       filter->y2,
                                       filter->color,
                                       filter->method);
        }
        if (command == TEXGEN_GAUSSIANBLUR)
        {
            FilterGaussianBlur *filter = (FilterGaussianBlur*) filters[i];
            generator->FilterGaussianBlur(filter->radius);
        }
        if (command == TEXGEN_MOTIONBLUR)
        {
            FilterMotionBlur *filter = (FilterMotionBlur*) filters[i];
            generator->FilterMotionBlur(filter->angle,
                                        filter->radius);
        }
        if (command == TEXGEN_DIRBLUR)
        {
            FilterDirBlur *filter = (FilterDirBlur*) filters[i];
            generator->FilterDirBlur(generator->layers[filter->sourceNr],
                                     filter->aantal,
                                     filter->channel);
        }
        if (command == TEXGEN_BOXBLUR)
        {
            generator->FilterBoxBlur();
        }
        if (command == TEXGEN_EMBOSS)
        {
            generator->FilterEmboss();
        }
        if (command == TEXGEN_SOBEL)
        {
            generator->FilterSobel();
        }
        if (command == TEXGEN_EDGE)
        {
            generator->FilterEdge();
        }
        if (command == TEXGEN_TOPLEFT)
        {
            generator->FilterTopLeft();
        }
        if (command == TEXGEN_HSV)
        {
            FilterHsv *filter = (FilterHsv*) filters[i];
            generator->FilterHsv(filter->rotation,
                                 filter->saternation);
        }
        if (command == TEXGEN_INVERT)
        {
            generator->FilterInvert();
        }
        if (command == TEXGEN_CONTRAST)
        {
            FilterContrast *filter = (FilterContrast*) filters[i];
            generator->FilterContrast(filter->strength);
        }
        if (command == TEXGEN_BRIGHTNESS)
        {
            FilterBrightness *filter = (FilterBrightness*) filters[i];
            generator->FilterBrightness(filter->strength);
        }
        if (command == TEXGEN_SINEDISTORT)
        {
            FilterSineDistort *filter = (FilterSineDistort*) filters[i];
            generator->FilterSineDistort(filter->nrX,
                                         filter->nrY,
                                         filter->ampX,
                                         filter->ampY,
                                         filter->shiftX,
                                         filter->shiftY);
        }
        if (command == TEXGEN_TILE)
        {
            FilterTile *filter = (FilterTile*) filters[i];
            generator->FilterTile(filter->repX,
                                  filter->repY);
        }
    }

    for (int i = 0; i < nrLayers; i++)
    {
        frmLayers[i]->UpdateOutput();
    }

    stbMain->SimpleText = "";

    loadingTexture = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Gaussian1Click(TObject *Sender)
{
    frmGaussianBlur->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Motion1Click(TObject *Sender)
{
    frmMotionBlur->ShowModal();
}
//---------------------------------------------------------------------------




void __fastcall TfrmMain::Rectangle1Click(TObject *Sender)
{
    frmRectangle->ShowModal();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Emboss1Click(TObject *Sender)
{
    frmEmboss->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EdgeDetect1Click(TObject *Sender)
{
    frmEdge->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Sobel1Click(TObject *Sender)
{
    frmSobel->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Box1Click(TObject *Sender)
{
    frmBoxBlur->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Copy1Click(TObject *Sender)
{
    frmCopy->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Add1Click(TObject *Sender)
{
    frmAdd->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Sub1Click(TObject *Sender)
{
    frmSub->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Mul1Click(TObject *Sender)
{
    frmMul->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::NotNullCopy1Click(TObject *Sender)
{
    frmNotNull->ShowModal();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Mix1Click(TObject *Sender)
{
    frmMix->ShowModal();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Shade1Click(TObject *Sender)
{
    frmShade->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::TopLeft1Click(TObject *Sender)
{
    frmTopLeft->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Hsv1Click(TObject *Sender)
{
    frmHsv->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Sin1Click(TObject *Sender)
{
    frmSineDistort->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Direction1Click(TObject *Sender)
{
    frmDirBlur->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Tile2Click(TObject *Sender)
{
    frmTile->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::About1Click(TObject *Sender)
{
    frmAbout->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Invert1Click(TObject *Sender)
{
    frmInvert->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Contrast1Click(TObject *Sender)
{
    frmContrast->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Brightness1Click(TObject *Sender)
{
    frmBrightness->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::TGA1Click(TObject *Sender)
{
    if (!dlgExportTGA->Execute())
    {
        return;
    }

    char *filename = dlgExportTGA->FileName.c_str();

    int handle;

    if ((handle = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, S_IWRITE)) == -1)
    {
        Application->MessageBoxA("Error creating file", "Error", MB_OK);
        return;
    }

    unsigned short bpp = 24;

    char h[] = "\0\0\2\0\0\0\0\0\0\0\0\0";

    write(handle, h, 12);

    write(handle, &textureWidth, 2);
    write(handle, &textureHeight, 2);
    write(handle, &bpp, 2);

    char *tempmap = new char[textureWidth * textureHeight * 3];
    int index = 0;
    for (int y = textureHeight - 1; y >= 0; y--)
    {
        for (int x = 0; x < textureWidth; x++)
        {
            int col = generator->layerActive[x + (y * textureWidth)];
            char r = (col >> 16) & 255;
            char g = (col >> 8) & 255;
            char b = (col) & 255;
            tempmap[index++] = b;
            tempmap[index++] = g;
            tempmap[index++] = r;
        }
    }
    write(handle, tempmap, textureWidth * textureHeight * 3);

    close(handle);

    delete [] tempmap;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BrushOnClick1Click(TObject *Sender)
{
    if (BrushOnClick1->Checked)
    {
        BrushOnClick1->Checked = false;
        mouseOpenBrushOnClick = false;
    }
    else
    {
        BrushOnClick1->Checked = true;
        mouseOpenBrushOnClick = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Updates1Click(TObject *Sender)
{
    frmUpdates->ShowModal();
}
//---------------------------------------------------------------------------
#include <Clipbrd.hpp>
void __fastcall TfrmMain::Clipboard1Click(TObject *Sender)
{
    OptimizeFilterList();

    String finalBuffer;

    finalBuffer += "unsigned char [";

    unsigned char temp[65536];

    memset(temp, '\0', 65536);

    memcpy(temp, TEXGEN_HEADER2, 4);

    memcpy(temp + 4, &nrFilters, 2);

    memcpy(temp + 6, &textureWidth, 2);
    memcpy(temp + 8, &textureHeight, 2);

    String buffer;

    int totalSize = 10;

    for (int i = 0; i < nrFilters; i++)
    {
        int size = GetSizeOfFilter(filters[i]->command);
        memcpy(temp + totalSize, filters[i], size);
        totalSize += size;
    }

    int blockOf16 = totalSize / 16;
    int rest      = totalSize % 16;

    for (int i = 0; i < blockOf16; i++)
    {
        buffer += "\t";
        for (int j = 0; j < 16; j++)
        {
            if (j != 0)
            {
                buffer += ", 0x" + IntToHex(temp[(i * 16) + j], 2);
            }
            else
            {
                buffer += "0x" + IntToHex(temp[(i * 16) + j], 2);
            }
        }
        if (i == blockOf16 - 1)
        {
            if (rest != 0)
            {
                buffer += ", \n";
            }
            else
            {
                buffer += "\n";
            }
        }
        else
        {
            buffer += ", \n";
        }
    }

    for (int j = 0; j < rest; j++)
    {
        if (j != 0)
        {
            buffer += ", 0x" + IntToHex(temp[(blockOf16 * 16) + j], 2);
        }
        else
        {
            buffer += "\t0x" + IntToHex(temp[(blockOf16 * 16) + j], 2);
        }
    }
    if (rest != 0)
    {
        buffer += "\n";
    }

    finalBuffer += IntToStr(totalSize) + "] = \n";
    finalBuffer += "{ \n" + buffer;
    finalBuffer += "};";
    Clipboard()->SetTextBuf(finalBuffer.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BitmapToClipboard1Click(TObject *Sender)
{
    Clipboard()->Assign(frmLayerActive->imgOutput->Picture);
}
//---------------------------------------------------------------------------

// 400 x 350

