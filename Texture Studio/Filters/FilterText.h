//---------------------------------------------------------------------------

#ifndef FilterTextH
#define FilterTextH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmText : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *lblSlider2;
    TLabel *lblSlider3;
    TEdit *edtSlider1;
    TTrackBar *trbSlider1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    TTrackBar *trbSlider3;
    TEdit *edtSlider3;
    TGroupBox *grbLayer;
    TRadioButton *rdbFill;
    TRadioButton *rdbAdd;
    TRadioButton *rdbSub;
    TRadioButton *rdbMul;
    TRadioButton *rdbNotNullCopy;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TLabel *lblCheckBox1;
    TCheckBox *chbCheckBox1;
    TComboBox *drdFont;
    TLabel *lblFont;
    TCheckBox *chbCheckBox2;
    TLabel *lblText;
    TEdit *edtText;
    TLabel *lblSlider4;
    TTrackBar *trbSlider4;
    TEdit *edtSlider4;
    TCheckBox *chbCheckBox3;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *lblResult;
    TBevel *bvlResult;
    TLabel *Label2;
    TLabel *Label3;
    TImage *imgResult;
    TTrackBar *trbSlider5;
    TEdit *edtSlider5;
    TCheckBox *chbInHex;
    TTrackBar *trbSlider6;
    TEdit *edtSlider6;
    TEdit *edtSlider7;
    TTrackBar *trbSlider7;
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall trbSlider2Change(TObject *Sender);
    void __fastcall trbSlider3Change(TObject *Sender);
    void __fastcall trbSlider4Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall chbInHexClick(TObject *Sender);
    void __fastcall trbSlider5Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmText(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmText *frmText;
//---------------------------------------------------------------------------
#endif
