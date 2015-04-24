//---------------------------------------------------------------------------

#ifndef FilterBoxBlurH
#define FilterBoxBlurH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmBoxBlur : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmBoxBlur(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBoxBlur *frmBoxBlur;
//---------------------------------------------------------------------------
#endif
