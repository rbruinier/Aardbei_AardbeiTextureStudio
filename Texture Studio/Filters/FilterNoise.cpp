//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterNoise.h"

#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmNoise *frmNoise;
//---------------------------------------------------------------------------
__fastcall TfrmNoise::TfrmNoise(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::btnRandomizeClick(TObject *Sender)
{
    randParam = rand() + rand() + rand() * 235;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::chbCheckBox1Click(TObject *Sender)
{
    // uniform (dan geen layer/channel options
    if (chbCheckBox1->Checked)
    {
        rdbRed->Enabled         = false;
        rdbGreen->Enabled       = false;
        rdbBlue->Enabled        = false;
        rdbAll->Enabled         = false;
        rdbFill->Enabled        = false;
        rdbAdd->Enabled         = false;
        rdbSub->Enabled         = false;
        rdbMul->Enabled         = false;
        rdbNotNullCopy->Enabled = false;
    }
    else
    {
        rdbRed->Enabled         = true;
        rdbGreen->Enabled       = true;
        rdbBlue->Enabled        = true;
        rdbAll->Enabled         = true;
        rdbFill->Enabled        = true;
        rdbAdd->Enabled         = true;
        rdbSub->Enabled         = true;
        rdbMul->Enabled         = true;
        rdbNotNullCopy->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterNoise *filter = new FilterNoise();

    filter->command  = TEXGEN_NOISE;

    filter->strength = trbSlider1->Position;
    filter->uniform  = chbCheckBox1->Checked;
    filter->multi    = !chbCheckBox2->Checked;
    filter->seed     = randParam;

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

    if (filter->uniform)
    {
        filter->channel = CHANNEL_ALL;
        filter->method  = TEXGEN_COPY;
    }

    generator->FilterNoise(filter->strength,
                           filter->uniform,
                           filter->multi,
                           filter->seed,
                           filter->channel,
                           filter->method);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::btnOkClick(TObject *Sender)
{
    FilterNoise *filter = new FilterNoise();

    filter->command  = TEXGEN_NOISE;

    filter->strength = trbSlider1->Position;
    filter->uniform  = chbCheckBox1->Checked;
    filter->multi    = !chbCheckBox2->Checked;
    filter->seed     = randParam;

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

    if (filter->uniform)
    {
        filter->channel = CHANNEL_ALL;
        filter->method  = TEXGEN_COPY;
    }

    generator->FilterNoise(filter->strength,
                           filter->uniform,
                           filter->multi,
                           filter->seed,
                           filter->channel,
                           filter->method);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNoise::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

