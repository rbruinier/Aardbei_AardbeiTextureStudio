//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterHsv.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHsv *frmHsv;
//---------------------------------------------------------------------------
__fastcall TfrmHsv::TfrmHsv(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHsv::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmHsv::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmHsv::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
    edtSlider2->Text = IntToStr(trbSlider2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmHsv::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterHsv *filter = new FilterHsv();

    filter->command  = TEXGEN_HSV;

    filter->rotation    = trbSlider1->Position;
    filter->saternation = 255 - trbSlider2->Position;

    generator->FilterHsv(filter->rotation,
                         filter->saternation);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmHsv::btnOkClick(TObject *Sender)
{
    FilterHsv *filter = new FilterHsv();

    filter->command  = TEXGEN_HSV;

    filter->rotation    = trbSlider1->Position;
    filter->saternation = 255 - trbSlider2->Position;

    generator->FilterHsv(filter->rotation,
                         filter->saternation);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
