//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterDirBlur.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDirBlur *frmDirBlur;
//---------------------------------------------------------------------------
__fastcall TfrmDirBlur::TfrmDirBlur(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDirBlur::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

void __fastcall TfrmDirBlur::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDirBlur::FormActivate(TObject *Sender)
{
    cmbLayer->Clear();
    for (int i = 0; i < nrLayers; i++)
    {
        cmbLayer->Items->Add(AnsiString("Layer ") + IntToStr(i + 1));
    }
    cmbLayer->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDirBlur::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterDirBlur *filter = new FilterDirBlur();

    filter->command  = TEXGEN_DIRBLUR;

    filter->sourceNr  = cmbLayer->ItemIndex;
    filter->aantal    = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterDirBlur(generator->layers[filter->sourceNr],
                             filter->aantal,
                             filter->channel);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDirBlur::btnOkClick(TObject *Sender)
{
    FilterDirBlur *filter = new FilterDirBlur();

    filter->command  = TEXGEN_DIRBLUR;

    filter->sourceNr  = cmbLayer->ItemIndex;
    filter->aantal    = trbSlider1->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    generator->FilterDirBlur(generator->layers[filter->sourceNr],
                             filter->aantal,
                             filter->channel);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDirBlur::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);    
}
//---------------------------------------------------------------------------
