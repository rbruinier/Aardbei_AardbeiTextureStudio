//---------------------------------------------------------------------------

#ifndef NewFormH
#define NewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmNew : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbDimensions;
    TLabel *lblWidth;
    TLabel *lblHeight;
    TEdit *edtWidth;
    TEdit *edtHeight;
    TButton *btnOk;
    TButton *btnCancel;
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmNew(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNew *frmNew;
extern int newInputTextureWidth;
extern int newInputTextureHeight;
//---------------------------------------------------------------------------
#endif
