//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterMul.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMul *frmMul;
//---------------------------------------------------------------------------
__fastcall TfrmMul::TfrmMul(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMul::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmMul::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMul::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterMul *filter = new FilterMul();

    filter->command  = TEXGEN_MUL;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterMul(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TfrmMul::btnOkClick(TObject *Sender)
{
    FilterMul *filter = new FilterMul();

    filter->command  = TEXGEN_MUL;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterMul(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMul::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------
