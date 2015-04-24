//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterShade.h"
#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmShade *frmShade;
//---------------------------------------------------------------------------
__fastcall TfrmShade::TfrmShade(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmShade::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmShade::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmShade::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }    
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmShade::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterShade *filter = new FilterShade();

    filter->command  = TEXGEN_SHADE;

    filter->sourceNr  = cmbLayer->ItemIndex;
    filter->lightning = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterShade(generator->layerActive,
                           generator->layers[filter->sourceNr],
                           filter->lightning,
                           filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmShade::btnOkClick(TObject *Sender)
{
    FilterShade *filter = new FilterShade();

    filter->command  = TEXGEN_SHADE;

    filter->sourceNr = cmbLayer->ItemIndex;
    filter->lightning = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterShade(generator->layerActive,
                           generator->layers[filter->sourceNr],
                           filter->lightning,
                           filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmShade::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);    
}
//---------------------------------------------------------------------------

