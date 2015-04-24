//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterSineDistort.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSineDistort *frmSineDistort;
//---------------------------------------------------------------------------
__fastcall TfrmSineDistort::TfrmSineDistort(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSineDistort::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmSineDistort::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmSineDistort::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterSineDistort *filter = new FilterSineDistort();

    filter->command  = TEXGEN_SINEDISTORT;

    filter->nrX    = trbSlider1->Position;
    filter->nrY    = trbSlider2->Position;
    filter->ampX   = trbSlider3->Position;
    filter->ampY   = trbSlider4->Position;
    filter->shiftX = trbSlider5->Position;
    filter->shiftY = trbSlider6->Position;

    generator->FilterSineDistort(filter->nrX,
                                 filter->nrY,
                                 filter->ampX,
                                 filter->ampY,
                                 filter->shiftX,
                                 filter->shiftY);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSineDistort::btnOkClick(TObject *Sender)
{
    FilterSineDistort *filter = new FilterSineDistort();

    filter->command  = TEXGEN_SINEDISTORT;

    filter->nrX    = trbSlider1->Position;
    filter->nrY    = trbSlider2->Position;
    filter->ampX   = trbSlider3->Position;
    filter->ampY   = trbSlider4->Position;
    filter->shiftX = trbSlider5->Position;
    filter->shiftY = trbSlider6->Position;

    generator->FilterSineDistort(filter->nrX,
                                 filter->nrY,
                                 filter->ampX,
                                 filter->ampY,
                                 filter->shiftX,
                                 filter->shiftY);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSineDistort::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
    edtSlider2->Text = IntToStr(trbSlider2->Position);
    edtSlider3->Text = IntToStr(trbSlider3->Position);
    edtSlider4->Text = IntToStr(trbSlider4->Position);
    edtSlider5->Text = IntToStr(trbSlider5->Position);
    edtSlider6->Text = IntToStr(trbSlider6->Position);
}
//---------------------------------------------------------------------------
