//---------------------------------------------------------------------------

#ifndef FilterContrastH
#define FilterContrastH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmContrast : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TEdit *edtSlider1;
    TTrackBar *trbSlider1;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmContrast(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmContrast *frmContrast;
//---------------------------------------------------------------------------
#endif
