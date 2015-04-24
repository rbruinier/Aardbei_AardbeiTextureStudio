//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterSobel.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSobel *frmSobel;
//---------------------------------------------------------------------------
__fastcall TfrmSobel::TfrmSobel(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSobel::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmSobel::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmSobel::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    Filter *filter = new Filter();

    filter->command  = TEXGEN_SOBEL;

    generator->FilterSobel();

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSobel::btnOkClick(TObject *Sender)
{
    Filter *filter = new Filter();

    filter->command  = TEXGEN_SOBEL;

    generator->FilterSobel();

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
