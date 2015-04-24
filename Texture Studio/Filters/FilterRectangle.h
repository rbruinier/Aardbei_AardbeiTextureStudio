//---------------------------------------------------------------------------

#ifndef FilterRectangleH
#define FilterRectangleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmRectangle : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider4;
    TLabel *lblSlider5;
    TLabel *lblSlider6;
    TLabel *lblSlider7;
    TTrackBar *trbSlider4;
    TEdit *edtSlider4;
    TTrackBar *trbSlider5;
    TEdit *edtSlider5;
    TTrackBar *trbSlider6;
    TEdit *edtSlider6;
    TTrackBar *trbSlider7;
    TEdit *edtSlider7;
    TGroupBox *grbColor;
    TLabel *lblSlider1;
    TLabel *lblResult;
    TBevel *bvlResult;
    TLabel *lblSlider2;
    TLabel *lblSlider3;
    TImage *imgResult;
    TTrackBar *trbSlider1;
    TEdit *edtSlider1;
    TCheckBox *chbInHex;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    TEdit *edtSlider3;
    TTrackBar *trbSlider3;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbLayer;
    TRadioButton *rdbFill;
    TRadioButton *rdbAdd;
    TRadioButton *rdbSub;
    TRadioButton *rdbMul;
    TRadioButton *rdbNotNullCopy;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall trbSlider4Change(TObject *Sender);
    void __fastcall chbInHexClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmRectangle(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRectangle *frmRectangle;
//---------------------------------------------------------------------------
#endif
