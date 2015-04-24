//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterCells.h"

#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCells *frmCells;
//---------------------------------------------------------------------------
__fastcall TfrmCells::TfrmCells(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::trbSlider2Change(TObject *Sender)
{
    edtSlider2->Text = IntToStr(trbSlider2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::btnRandomizeClick(TObject *Sender)
{
    randParam = rand() + rand() + rand() * 235;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    int channel, method;

    int density  = trbSlider1->Position;
    int strength = trbSlider2->Position;

    if (rdbRed->Checked)
        channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        channel = CHANNEL_ALL;

    if (rdbFill->Checked)
        method = TEXGEN_COPY;
    else if (rdbAdd->Checked)
        method = TEXGEN_ADD;
    else if (rdbSub->Checked)
        method = TEXGEN_SUB;
    else if (rdbMul->Checked)
        method = TEXGEN_MUL;
    else if (rdbNotNullCopy->Checked)
        method = TEXGEN_NOTNULLCOPY;


    generator->FilterCells(density, strength, randParam, channel, method);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::btnOkClick(TObject *Sender)
{
    FilterCells *filter = new FilterCells();

    filter->command  = TEXGEN_CELLS;

    filter->density  = trbSlider1->Position;
    filter->strength = trbSlider2->Position;
    filter->seed     = randParam;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    if (rdbFill->Checked)
        filter->method = TEXGEN_COPY;
    else if (rdbAdd->Checked)
        filter->method = TEXGEN_ADD;
    else if (rdbSub->Checked)
        filter->method = TEXGEN_SUB;
    else if (rdbMul->Checked)
        filter->method = TEXGEN_MUL;
    else if (rdbNotNullCopy->Checked)
        filter->method = TEXGEN_NOTNULLCOPY;

    generator->FilterCells(filter->density,
                           filter->strength,
                           filter->seed,
                           filter->channel,
                           filter->method);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCells::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

