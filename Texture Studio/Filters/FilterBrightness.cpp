//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterBrightness.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBrightness *frmBrightness;
//---------------------------------------------------------------------------
__fastcall TfrmBrightness::TfrmBrightness(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmBrightness::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBrightness::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBrightness::btnOkClick(TObject *Sender)
{
    FilterBrightness *filter = new FilterBrightness();

    filter->command  = TEXGEN_BRIGHTNESS;

    filter->strength = trbSlider1->Position + 127;

    generator->FilterBrightness(filter->strength);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBrightness::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBrightness::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterBrightness *filter = new FilterBrightness();

    filter->command  = TEXGEN_BRIGHTNESS;

    filter->strength = trbSlider1->Position + 127;

    generator->FilterBrightness(filter->strength);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
