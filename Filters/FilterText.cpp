//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterText.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmText *frmText;
//---------------------------------------------------------------------------
__fastcall TfrmText::TfrmText(TComponent* Owner)
    : TForm(Owner)
{
    drdFont->ItemIndex = 0;
    int imgX = imgResult->Width;
    int imgY = imgResult->Height;
    imgResult->Picture->Bitmap = new Graphics::TBitmap();
    imgResult->Picture->Bitmap->Width       = imgX;
    imgResult->Picture->Bitmap->Height      = imgY;
    imgResult->Picture->Bitmap->PixelFormat = pf32bit;
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::FormActivate(TObject *Sender)
{
    trbSlider1->Max = textureWidth  - 1;
    trbSlider2->Max = textureHeight - 1;
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::trbSlider1Change(TObject *Sender)
{
    edtSlider1->Text = IntToStr(trbSlider1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::trbSlider2Change(TObject *Sender)
{
    edtSlider2->Text = IntToStr(trbSlider2->Position);    
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::trbSlider3Change(TObject *Sender)
{
    edtSlider3->Text = IntToStr(trbSlider3->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::trbSlider4Change(TObject *Sender)
{
    edtSlider4->Text = IntToStr(trbSlider4->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterText *filter = new FilterText();

    filter->command = TEXGEN_TEXT;

    memset(filter->text, 0, 128);
    strcpy(filter->text, edtText->Text.c_str());

    filter->color = (trbSlider5->Position << 16) |
                    (trbSlider6->Position <<  8) |
                    (trbSlider7->Position <<  0);

    filter->x      = trbSlider1->Position;
    filter->y      = trbSlider2->Position;
    filter->size   = trbSlider3->Position;
    filter->style  = trbSlider4->Position;
    filter->font   = drdFont->ItemIndex;
    filter->aa     = chbCheckBox1->Checked;
    filter->clip   = !chbCheckBox2->Checked;
    filter->style |= chbCheckBox3->Checked << 5;

    if (strlen(filter->text) == 0)
    {
        btnPreview->Enabled = true;
        return;
    }

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

    generator->FilterText(filter->text,
                          filter->font,
                          filter->color,
                          filter->size,
                          filter->x,
                          filter->y,
                          filter->aa,
                          filter->style,
                          filter->clip,
                          filter->method);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::btnOkClick(TObject *Sender)
{
    FilterText *filter = new FilterText();

    filter->command = TEXGEN_TEXT;

    memset(filter->text, 0, 128);
    strcpy(filter->text, edtText->Text.c_str());

    filter->color = (trbSlider5->Position << 16) |
                    (trbSlider6->Position <<  8) |
                    (trbSlider7->Position <<  0);

    filter->x      = trbSlider1->Position;
    filter->y      = trbSlider2->Position;
    filter->size   = trbSlider3->Position;
    filter->style  = trbSlider4->Position;
    filter->font   = drdFont->ItemIndex;
    filter->aa     = chbCheckBox1->Checked;
    filter->clip   = !chbCheckBox2->Checked;
    filter->style |= chbCheckBox3->Checked << 5;

    if (strlen(filter->text) == 0)
    {
        btnPreview->Enabled = true;
        return;
    }

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

    generator->FilterText(filter->text,
                          filter->font,
                          filter->color,
                          filter->size,
                          filter->x,
                          filter->y,
                          filter->aa,
                          filter->style,
                          filter->clip,
                          filter->method);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::chbInHexClick(TObject *Sender)
{
    if (chbInHex->Checked)
    {
        edtSlider5->Text = "#" + IntToHex(trbSlider5->Position, 2);
        edtSlider6->Text = "#" + IntToHex(trbSlider6->Position, 2);
        edtSlider7->Text = "#" + IntToHex(trbSlider7->Position, 2);
    }
    else
    {
        edtSlider5->Text = IntToStr(trbSlider5->Position);
        edtSlider6->Text = IntToStr(trbSlider6->Position);
        edtSlider7->Text = IntToStr(trbSlider7->Position);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmText::trbSlider5Change(TObject *Sender)
{
    chbInHexClick(this);

    int imgX = imgResult->Width;
    int imgY = imgResult->Height;

    unsigned int color = (trbSlider5->Position << 16) |
                         (trbSlider6->Position <<  8) |
                         (trbSlider7->Position <<  0);

    for (int y = 0; y < imgY; y++)
    {
        unsigned int *start = (unsigned int*) imgResult->Picture->Bitmap->ScanLine[y];
        for (int x = 0; x < imgX; x++)
        {
            *start++ = color;
        }
    }

    imgResult->Repaint();
}
//---------------------------------------------------------------------------

