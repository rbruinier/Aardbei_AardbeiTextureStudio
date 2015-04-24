//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAbout *frmAbout;

//---------------------------------------------------------------------------
__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::btnOkClick(TObject *Sender)
{
    ModalResult = mrOk;
}

//---------------------------------------------------------------------------


