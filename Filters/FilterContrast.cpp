//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterContrast.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmContrast *frmContrast;
//---------------------------------------------------------------------------
__fastcall TfrmContrast::TfrmContrast(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmContrast::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmContrast::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmContrast::btnOkClick(TObject *Sender)
{
    FilterContrast *filter = new FilterContrast();

    filter->command  = TEXGEN_CONTRAST;

    filter->strength = trbSlider1->Position;

    generator->FilterContrast(filter->strength);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmContrast::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmContrast::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterContrast *filter = new FilterContrast();

    filter->command  = TEXGEN_CONTRAST;

    filter->strength = trbSlider1->Position;

    generator->FilterContrast(filter->strength);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
