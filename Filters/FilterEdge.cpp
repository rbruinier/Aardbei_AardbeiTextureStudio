//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterEdge.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEdge *frmEdge;
//---------------------------------------------------------------------------
__fastcall TfrmEdge::TfrmEdge(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdge::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdge::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdge::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    Filter *filter = new Filter();

    filter->command  = TEXGEN_EDGE;

    generator->FilterEdge();

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdge::btnOkClick(TObject *Sender)
{
    Filter *filter = new Filter();

    filter->command  = TEXGEN_EDGE;

    generator->FilterEdge();

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
