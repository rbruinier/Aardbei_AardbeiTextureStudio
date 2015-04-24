//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Updates.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmUpdates *frmUpdates;
//---------------------------------------------------------------------------
__fastcall TfrmUpdates::TfrmUpdates(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmUpdates::btnOkClick(TObject *Sender)
{
    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------

