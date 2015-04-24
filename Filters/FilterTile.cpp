//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterTile.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTile *frmTile;
//---------------------------------------------------------------------------
__fastcall TfrmTile::TfrmTile(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTile::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmTile::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmTile::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
    edtSlider2->Text = IntToStr(trbSlider2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTile::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterTile *filter = new FilterTile();

    filter->command  = TEXGEN_TILE;

    filter->repX = trbSlider1->Position;
    filter->repY = trbSlider2->Position;

    generator->FilterTile(filter->repX,
                          filter->repY);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTile::btnOkClick(TObject *Sender)
{
    FilterTile *filter = new FilterTile();

    filter->command  = TEXGEN_TILE;

    filter->repX = trbSlider1->Position;
    filter->repY = trbSlider2->Position;

    generator->FilterTile(filter->repX,
                          filter->repY);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------
