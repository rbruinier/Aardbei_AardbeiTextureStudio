//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterInvert.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmInvert *frmInvert;
//---------------------------------------------------------------------------
__fastcall TfrmInvert::TfrmInvert(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmInvert::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmInvert::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmInvert::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    Filter *filter = new Filter();

    filter->command  = TEXGEN_INVERT;

    generator->FilterInvert();

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TfrmInvert::btnOkClick(TObject *Sender)
{
    Filter *filter = new Filter();

    filter->command  = TEXGEN_INVERT;

    generator->FilterInvert();

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
