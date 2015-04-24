//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterSub.h"
#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSub *frmSub;
//---------------------------------------------------------------------------
__fastcall TfrmSub::TfrmSub(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSub::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSub::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmSub::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }    
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSub::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterSub *filter = new FilterSub();

    filter->command  = TEXGEN_SUB;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterSub(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSub::btnOkClick(TObject *Sender)
{
    FilterSub *filter = new FilterSub();

    filter->command  = TEXGEN_SUB;

    filter->sourceNr = cmbLayer->ItemIndex;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterSub(generator->layerActive,
                         generator->layers[filter->sourceNr],
                         filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

