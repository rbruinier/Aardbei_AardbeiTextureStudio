//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Layer.h"

#include "MainForm.h"
#include "FilterBrush.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmLayer *frmLayer;
//---------------------------------------------------------------------------
__fastcall TfrmLayer::TfrmLayer(TComponent* Owner)
    : TForm(Owner)
{
    stillInCreation = true;
}

//---------------------------------------------------------------------------
void TfrmLayer::Setup(char * name, int width, int height, unsigned int *iBuffer)
{
    // set attributes
    this->width  = width;
    this->height = height;

    // setup form
    Caption      = name;
    ClientWidth  = width  + 2;
    ClientHeight = height + 2;

    // create the output bitmap
    imgOutput->Width  = width;
    imgOutput->Height = height;
    imgOutput->Picture->Bitmap = new Graphics::TBitmap();
    imgOutput->Picture->Bitmap->Width       = width;
    imgOutput->Picture->Bitmap->Height      = height;
    imgOutput->Picture->Bitmap->PixelFormat = pf32bit;

    if (ClientWidth < 128)
    {
        ClientWidth = 128;
        imgOutput->Left = (128 - width) / 2;
    }

    // create buffer
    buffer = iBuffer;

    // update
    UpdateOutput();
}

void TfrmLayer::UpdateOutput()
{
    for (int y = 0; y < height; y++)
    {
        memcpy((unsigned int*) imgOutput->Picture->Bitmap->ScanLine[y],
               buffer + (y * width), width * 4);
    }
    imgOutput->Repaint();
}

void __fastcall TfrmLayer::FormDestroy(TObject *Sender)
{
    imgOutput->Picture->Bitmap->FreeImage();
}
//---------------------------------------------------------------------------


void __fastcall TfrmLayer::FormActivate(TObject *Sender)
{
    int activeLayerNr = -1;
    if (stillInCreation == true)
    {
        stillInCreation = false;
        return;
    }

    frmLayerActive = this;

    for (int i = 0; i < nrLayers; i++)
    {
        if (frmLayerActive == frmLayers[i])
        {
            activeLayerNr = i;
            generator->layerActive = generator->layers[i];
            break;
        }
    }

    if (!loadingTexture)
    {
        FilterChangeLayer *filter = new FilterChangeLayer();
        filter->command = TEXGEN_CHANGELAYER;
        filter->layerNr = activeLayerNr;
        filters[nrFilters++] = filter;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmLayer::imgOutputClick(TObject *Sender)
{
    TPoint mousePosition = Mouse->CursorPos;

    mousePositionX = mousePosition.x - imgOutput->ClientOrigin.x;
    mousePositionY = mousePosition.y - imgOutput->ClientOrigin.y;

    mouseClicked = true;

    if (mouseOpenBrushOnClick)
    {
        frmBrush->ShowModal();
    }
}
//---------------------------------------------------------------------------

