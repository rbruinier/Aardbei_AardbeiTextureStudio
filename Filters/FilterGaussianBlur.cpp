//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterGaussianBlur.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGaussianBlur *frmGaussianBlur;
//---------------------------------------------------------------------------
__fastcall TfrmGaussianBlur::TfrmGaussianBlur(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGaussianBlur::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGaussianBlur::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterGaussianBlur *filter = new FilterGaussianBlur();

    filter->command  = TEXGEN_GAUSSIANBLUR;

    filter->radius   = trbSlider1->Position;

    generator->FilterGaussianBlur(filter->radius);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGaussianBlur::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGaussianBlur::btnOkClick(TObject *Sender)
{
    FilterGaussianBlur *filter = new FilterGaussianBlur();

    filter->command  = TEXGEN_GAUSSIANBLUR;

    filter->radius   = trbSlider1->Position;

    generator->FilterGaussianBlur(filter->radius);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGaussianBlur::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

