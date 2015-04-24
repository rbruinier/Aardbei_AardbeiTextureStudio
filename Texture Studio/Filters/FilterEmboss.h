//---------------------------------------------------------------------------

#ifndef FilterEmbossH
#define FilterEmbossH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmEmboss : public TForm
{
__published:	// IDE-managed Components
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmEmboss(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEmboss *frmEmboss;
//---------------------------------------------------------------------------
#endif
