//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterPlasma.h"

#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TfrmPlasma *frmPlasma;
//---------------------------------------------------------------------------
__fastcall TfrmPlasma::TfrmPlasma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::trbSlider2Change(TObject *Sender)
{
    edtSlider2->Text = IntToStr(trbSlider2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::trbSlider3Change(TObject *Sender)
{
    edtSlider3->Text = IntToStr(trbSlider3->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::trbSlider4Change(TObject *Sender)
{
    edtSlider4->Text = IntToStr(trbSlider4->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    int channel, method;

    int aantalX = trbSlider1->Position;
    int aantalY = trbSlider2->Position;

    int offsetX = trbSlider3->Position;
    int offsetY = trbSlider4->Position;

    if (rdbRed->Checked)
        channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        channel = CHANNEL_ALL;

    if (rdbFill->Checked)
        method = TEXGEN_COPY;
    else if (rdbAdd->Checked)
        method = TEXGEN_ADD;
    else if (rdbSub->Checked)
        method = TEXGEN_SUB;
    else if (rdbMul->Checked)
        method = TEXGEN_MUL;
    else if (rdbNotNullCopy->Checked)
        method = TEXGEN_NOTNULLCOPY;

    generator->FilterPlasma(aantalX, aantalY, offsetX, offsetY, channel, method);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::btnOkClick(TObject *Sender)
{
    FilterPlasma *filter = new FilterPlasma();

    filter->command = TEXGEN_PLASMA;

    filter->aantalX = trbSlider1->Position;
    filter->aantalY = trbSlider2->Position;
    filter->shiftX  = trbSlider3->Position;
    filter->shiftY  = trbSlider4->Position;

    if (rdbRed->Checked)
        filter->channel = CHANNEL_RED;
    else if (rdbGreen->Checked)
        filter->channel = CHANNEL_GREEN;
    else if (rdbBlue->Checked)
        filter->channel = CHANNEL_BLUE;
    else if (rdbAll->Checked)
        filter->channel = CHANNEL_ALL;

    if (rdbFill->Checked)
        filter->method = TEXGEN_COPY;
    else if (rdbAdd->Checked)
        filter->method = TEXGEN_ADD;
    else if (rdbSub->Checked)
        filter->method = TEXGEN_SUB;
    else if (rdbMul->Checked)
        filter->method = TEXGEN_MUL;
    else if (rdbNotNullCopy->Checked)
        filter->method = TEXGEN_NOTNULLCOPY;

    generator->FilterPlasma(filter->aantalX,
                            filter->aantalY,
                            filter->shiftX,
                            filter->shiftY,
                            filter->channel,
                            filter->method);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPlasma::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

