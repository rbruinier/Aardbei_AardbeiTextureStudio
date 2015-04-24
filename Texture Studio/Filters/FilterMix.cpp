//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterMix.h"
#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMix *frmMix;
//---------------------------------------------------------------------------
__fastcall TfrmMix::TfrmMix(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMix::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMix::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMix::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMix::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterMix *filter = new FilterMix();

    filter->command  = TEXGEN_MIX;

    filter->sourceNr = cmbLayer->ItemIndex;
    filter->alpha    = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterMix(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->alpha,
                         filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMix::btnOkClick(TObject *Sender)
{
    FilterMix *filter = new FilterMix();

    filter->command  = TEXGEN_MIX;

    filter->sourceNr = cmbLayer->ItemIndex;
    filter->alpha    = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterMix(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->alpha,
                         filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMix::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);    
}
//---------------------------------------------------------------------------

