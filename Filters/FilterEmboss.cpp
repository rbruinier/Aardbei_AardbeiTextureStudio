//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterEmboss.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEmboss *frmEmboss;
//---------------------------------------------------------------------------
__fastcall TfrmEmboss::TfrmEmboss(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmEmboss::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    Filter *filter = new Filter();

    filter->command  = TEXGEN_EMBOSS;

    generator->FilterEmboss();

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEmboss::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmEmboss::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEmboss::btnOkClick(TObject *Sender)
{
    Filter *filter = new Filter();

    filter->command  = TEXGEN_EMBOSS;

    generator->FilterEmboss();

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
