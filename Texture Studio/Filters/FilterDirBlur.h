//---------------------------------------------------------------------------

#ifndef FilterDirBlurH
#define FilterDirBlurH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmDirBlur : public TForm
{
__published:	// IDE-managed Components
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbColor;
    TRadioButton *rdbRed;
    TRadioButton *rdbGreen;
    TRadioButton *rdbBlue;
    TRadioButton *rdbAll;
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *Label1;
    TComboBox *cmbLayer;
    TTrackBar *trbSlider1;
    TEdit *edtSlider1;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmDirBlur(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDirBlur *frmDirBlur;
//---------------------------------------------------------------------------
#endif
