//---------------------------------------------------------------------------

#ifndef UpdatesH
#define UpdatesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmUpdates : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TMemo *mmoUpdates;
    TButton *btnOk;
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmUpdates(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmUpdates *frmUpdates;
//---------------------------------------------------------------------------
#endif
