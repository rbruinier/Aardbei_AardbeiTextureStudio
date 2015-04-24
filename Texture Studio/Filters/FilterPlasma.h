//---------------------------------------------------------------------------

#ifndef FilterPlasmaH
#define FilterPlasmaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Mask.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPlasma : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TButton *btnOk;
    TButton *btnCancel;
    TGroupBox *grbColor;
    TGroupBox *grbLayer;
    TRadioButton *rdbRed;
    TRadioButton *rdbGreen;
    TRadioButton *rdbBlue;
    TRadioButton *rdbAll;
    TRadioButton *rdbFill;
    TButton *btnPreview;
    TRadioButton *rdbAdd;
    TRadioButton *rdbSub;
    TRadioButton *rdbMul;
    TRadioButton *rdbNotNullCopy;
    TEdit *edtSlider1;
    TLabel *lblSlider1;
    TTrackBar *trbSlider1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    TLabel *lblSlider2;
    TLabel *lblSlider3;
    TTrackBar *trbSlider3;
    TEdit *edtSlider3;
    TLabel *lblSlider4;
    TTrackBar *trbSlider4;
    TEdit *edtSlider4;
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall trbSlider2Change(TObject *Sender);
    void __fastcall trbSlider3Change(TObject *Sender);
    void __fastcall trbSlider4Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmPlasma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPlasma *frmPlasma;
//---------------------------------------------------------------------------
#endif
