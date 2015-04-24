//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NewForm.h"
#include <Math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmNew *frmNew;

int newInputTextureWidth  = 0;
int newInputTextureHeight = 0;

//---------------------------------------------------------------------------
__fastcall TfrmNew::TfrmNew(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmNew::btnOkClick(TObject *Sender)
{
    try
    {
        newInputTextureWidth = StrToInt(edtWidth->Text);
    }
    catch (...)
    {
        MessageBox(NULL, "Width is not a valid number", "Error", MB_OK);
        return;
    }

    try
    {
        newInputTextureHeight = StrToInt(edtHeight->Text);
    }
    catch (...)
    {
        MessageBox(NULL, "Height is not a valid number", "Error", MB_OK);
        return;
    }

    if ((newInputTextureWidth < 1) || (newInputTextureWidth > 2048))
    {
        MessageBox(NULL, "Width must be between 1 and 2048", "Error", MB_OK);
        return;
    }

    if ((newInputTextureHeight < 1) || (newInputTextureHeight > 2048))
    {
        MessageBox(NULL, "Height must be between 1 and 2048", "Error", MB_OK);
        return;
    }

    bool powerOf2X = false;
    bool powerOf2Y = false;
    for (int i = 0; i < 15; i++)
    {
        if ((int)(pow(2, i)) == newInputTextureWidth)
        {
            powerOf2X = true;
        }
        if ((int)(pow(2, i)) == newInputTextureHeight)
        {
            powerOf2Y = true;
        }
    }


    if (powerOf2X && powerOf2Y)
    {
        ModalResult = mrOk;
    }
    else
    {
        MessageBox(NULL, "At the moment the dimensions must both be a power of 2", "Error", MB_OK);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNew::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

