//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FilterBrush.h"

#include "MainForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBrush *frmBrush;
//---------------------------------------------------------------------------
__fastcall TfrmBrush::TfrmBrush(TComponent* Owner)
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

void __fastcall TfrmBrush::FormActivate(TObject *Sender)
{
    trbSlider4->Min = -textureWidth  / 4;
    trbSlider5->Min = -textureHeight / 4;

    trbSlider4->Max = (textureWidth  - 1) + (textureWidth  / 4);
    trbSlider5->Max = (textureHeight - 1) + (textureHeight / 4);

    if (mouseClicked)
    {
        trbSlider4->Position = mousePositionX;
        trbSlider5->Position = mousePositionY;

        mouseClicked = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider1Change(TObject *Sender)
{
    if (chbInHex->Checked)
    {
        edtSlider1->Text = "#" + IntToHex(trbSlider1->Position, 2);
    }
    else
    {
        edtSlider1->Text = IntToStr(trbSlider1->Position);
    }

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
void __fastcall TfrmBrush::trbSlider2Change(TObject *Sender)
{
    if (chbInHex->Checked)
    {
        edtSlider2->Text = "#" + IntToHex(trbSlider2->Position, 2);
    }
    else
    {
        edtSlider2->Text = IntToStr(trbSlider2->Position);
    }

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
void __fastcall TfrmBrush::trbSlider3Change(TObject *Sender)
{
    if (chbInHex->Checked)
    {
        edtSlider3->Text = "#" + IntToHex(trbSlider3->Position, 2);
    }
    else
    {
        edtSlider3->Text = IntToStr(trbSlider3->Position);
    }

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

void __fastcall TfrmBrush::trbSlider4Change(TObject *Sender)
{
    edtSlider4->Text = IntToStr(trbSlider4->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider5Change(TObject *Sender)
{
    edtSlider5->Text = IntToStr(trbSlider5->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider6Change(TObject *Sender)
{
    edtSlider6->Text = IntToStr(trbSlider6->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider7Change(TObject *Sender)
{
    edtSlider7->Text = IntToStr(trbSlider7->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider8Change(TObject *Sender)
{
    edtSlider8->Text = IntToStr(trbSlider8->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::trbSlider9Change(TObject *Sender)
{
    edtSlider9->Text = IntToStr(trbSlider9->Position);
}

//---------------------------------------------------------------------------
void __fastcall TfrmBrush::chbInHexClick(TObject *Sender)
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



void __fastcall TfrmBrush::btnPreviewClick(TObject *Sender)
{
    btnPreview->Enabled = false;

    memcpy(layerPreview, generator->layerActive, textureWidth * textureHeight * 4);

    unsigned char options = 0;

    bool wrap = !chbCheckBox1->Checked;
    bool cont = chbCheckBox2->Checked;

    if (wrap)
        options |= (1 << 0);

    if (cont)
        options |= (1 << 1);

    unsigned int color = (trbSlider1->Position << 16) |
                         (trbSlider2->Position <<  8) |
                         (trbSlider3->Position <<  0) |
                         (options << 24);

    int positionX = trbSlider4->Position;
    int positionY = trbSlider5->Position;
    int size      = trbSlider6->Position;
    int density   = trbSlider7->Position;
    int hardness  = trbSlider8->Position;
    int opacity   = trbSlider9->Position;

    generator->FilterBrush(positionX, positionY, size, density, hardness, opacity, color);

    frmLayerActive->UpdateOutput();

    memcpy(generator->layerActive, layerPreview,  textureWidth * textureHeight * 4);

    btnPreview->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TfrmBrush::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::FormHide(TObject *Sender)
{
    frmLayerActive->UpdateOutput();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrush::btnOkClick(TObject *Sender)
{
    FilterBrush *filter = new FilterBrush();

    filter->command  = TEXGEN_BRUSH;

    unsigned char options = 0;

    bool wrap = !chbCheckBox1->Checked;
    bool cont = chbCheckBox2->Checked;

    if (wrap)
        options |= (1 << 0);

    if (cont)
        options |= (1 << 1);

    filter->color = (trbSlider1->Position << 16) |
                    (trbSlider2->Position <<  8) |
                    (trbSlider3->Position <<  0) |
                    (options << 24);

    filter->x        = trbSlider4->Position;
    filter->y        = trbSlider5->Position;
    filter->size     = trbSlider6->Position;
    filter->density  = trbSlider7->Position;
    filter->hardness = trbSlider8->Position;
    filter->opacity  = trbSlider9->Position;

    generator->FilterBrush(filter->x,
                           filter->y,
                           filter->size,
                           filter->density,
                           filter->hardness,
                           filter->opacity,
                           filter->color);

    filters[nrFilters++] = filter;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

