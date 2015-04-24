//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterTopLeft.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTopLeft *frmTopLeft;
//---------------------------------------------------------------------------
__fastcall TfrmTopLeft::TfrmTopLeft(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTopLeft::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTopLeft::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTopLeft::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    Filter *filter = new Filter();

    filter->command  = TEXGEN_TOPLEFT;

    generator->FilterTopLeft();

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TfrmTopLeft::btnOkClick(TObject *Sender)
{
    Filter *filter = new Filter();

    filter->command  = TEXGEN_TOPLEFT;

    generator->FilterTopLeft();

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
