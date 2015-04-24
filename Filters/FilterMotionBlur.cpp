//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterMotionBlur.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMotionBlur *frmMotionBlur;
//---------------------------------------------------------------------------
__fastcall TfrmMotionBlur::TfrmMotionBlur(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMotionBlur::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
    edtSlider2->Text = IntToStr(trbSlider2->Position);    
}
//---------------------------------------------------------------------------
void __fastcall TfrmMotionBlur::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterMotionBlur *filter = new FilterMotionBlur();

    filter->command  = TEXGEN_MOTIONBLUR;

    filter->angle  = trbSlider1->Position;
    filter->radius = trbSlider2->Position;

    generator->FilterMotionBlur(filter->angle,
                                filter->radius);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMotionBlur::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMotionBlur::btnOkClick(TObject *Sender)
{
    FilterMotionBlur *filter = new FilterMotionBlur();

    filter->command  = TEXGEN_MOTIONBLUR;

    filter->angle  = trbSlider1->Position;
    filter->radius = trbSlider2->Position;

    generator->FilterMotionBlur(filter->angle,
                                filter->radius);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMotionBlur::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

