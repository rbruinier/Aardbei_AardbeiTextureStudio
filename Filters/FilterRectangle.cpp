//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterRectangle.h"

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRectangle *frmRectangle;
//---------------------------------------------------------------------------
__fastcall TfrmRectangle::TfrmRectangle(TComponent* Owner)
    : TForm(Owner)
{
    int imgX = imgResult->Width;
    int imgY = imgResult->Height;
    imgResult->Picture->Bitmap = new Graphics::TBitmap();
    imgResult->Picture->Bitmap->Width       = imgX;
    imgResult->Picture->Bitmap->Height      = imgY;
    imgResult->Picture->Bitmap->PixelFormat = pf32bit;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::FormActivate(TObject *Sender)
{
    trbSlider4->Max = textureWidth  - 1;
    trbSlider5->Max = textureHeight - 1;
    trbSlider6->Max = textureWidth  - 1;
    trbSlider7->Max = textureHeight - 1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    FilterRectangle *filter = new FilterRectangle();

    filter->command  = TEXGEN_RECTANGLE;

    filter->color = (trbSlider1->Position << 16) |
                    (trbSlider2->Position <<  8) |
                    (trbSlider3->Position <<  0);

    filter->x1 = trbSlider4->Position;
    filter->y1 = trbSlider5->Position;
    filter->x2 = trbSlider6->Position;
    filter->y2 = trbSlider7->Position;

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


    generator->FilterRectangle(filter->x1,
                               filter->y1,
                               filter->x2,
                               filter->y2,
                               filter->color,
                               filter->method);

    delete filter;

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::trbSlider1Change(TObject *Sender)
{
    chbInHexClick(this);

    int imgX = imgResult->Width;
    int imgY = imgResult->Height;

    unsigned int color = (trbSlider1->Position << 16) |
                         (trbSlider2->Position <<  8) |
                         (trbSlider3->Position <<  0);

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
void __fastcall TfrmRectangle::trbSlider4Change(TObject *Sender)
{
        edtSlider4->Text = IntToStr(trbSlider4->Position);
        edtSlider5->Text = IntToStr(trbSlider5->Position);
        edtSlider6->Text = IntToStr(trbSlider6->Position);
        edtSlider7->Text = IntToStr(trbSlider7->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::chbInHexClick(TObject *Sender)
{
    if (chbInHex->Checked)
    {
        edtSlider1->Text = "#" + IntToHex(trbSlider1->Position, 2);
        edtSlider2->Text = "#" + IntToHex(trbSlider2->Position, 2);
        edtSlider3->Text = "#" + IntToHex(trbSlider3->Position, 2);
    }
    else
    {
        edtSlider1->Text = IntToStr(trbSlider1->Position);
        edtSlider2->Text = IntToStr(trbSlider2->Position);
        edtSlider3->Text = IntToStr(trbSlider3->Position);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::btnOkClick(TObject *Sender)
{
    FilterRectangle *filter = new FilterRectangle();

    filter->command  = TEXGEN_RECTANGLE;

    filter->color = (trbSlider1->Position << 16) |
                    (trbSlider2->Position <<  8) |
                    (trbSlider3->Position <<  0);

    filter->x1 = trbSlider4->Position;
    filter->y1 = trbSlider5->Position;
    filter->x2 = trbSlider6->Position;
    filter->y2 = trbSlider7->Position;

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


    generator->FilterRectangle(filter->x1,
                               filter->y1,
                               filter->x2,
                               filter->y2,
                               filter->color,
                               filter->method);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRectangle::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
