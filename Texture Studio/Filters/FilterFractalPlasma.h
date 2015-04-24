//---------------------------------------------------------------------------

#ifndef FilterFractalPlasmaH
#define FilterFractalPlasmaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmFractalPlasma : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TEdit *edtSlider1;
    TTrackBar *trbSlider1;
    TButton *btnRandomize;
    TGroupBox *grbColor;
    TRadioButton *rdbRed;
    TRadioButton *rdbGreen;
    TRadioButton *rdbBlue;
    TRadioButton *rdbAll;
    TGroupBox *grbLayer;
    TRadioButton *rdbFill;
    TRadioButton *rdbAdd;
    TRadioButton *rdbSub;
    TRadioButton *rdbMul;
    TRadioButton *rdbNotNullCopy;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall btnRandomizeClick(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmFractalPlasma(TComponent* Owner);
    unsigned int randParam;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFractalPlasma *frmFractalPlasma;
//---------------------------------------------------------------------------
#endif
