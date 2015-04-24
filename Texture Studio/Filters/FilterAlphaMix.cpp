//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterAlphaMix.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAlphaMix *frmAlphaMix;
//---------------------------------------------------------------------------
__fastcall TfrmAlphaMix::TfrmAlphaMix(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlphaMix::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlphaMix::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlphaMix::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlphaMix::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterAlphaMix *filter = new FilterAlphaMix();

    filter->command  = TEXGEN_ALPHAMIX;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterAlphaMix(generator->layerActive,
                              generator->layers[filter->sourceNr],
                              filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlphaMix::btnOkClick(TObject *Sender)
{
    FilterAlphaMix *filter = new FilterAlphaMix();

    filter->command  = TEXGEN_ALPHAMIX;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterAlphaMix(generator->layerActive,
                              generator->layers[filter->sourceNr],
                              filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------
