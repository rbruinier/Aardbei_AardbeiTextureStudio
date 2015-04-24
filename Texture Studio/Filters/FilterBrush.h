//---------------------------------------------------------------------------

#ifndef FilterBrushH
#define FilterBrushH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmBrush : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TLabel *lblSlider4;
    TTrackBar *trbSlider4;
    TEdit *edtSlider4;
    TLabel *lblSlider5;
    TTrackBar *trbSlider5;
    TEdit *edtSlider5;
    TLabel *lblSlider6;
    TTrackBar *trbSlider6;
    TEdit *edtSlider6;
    TLabel *lblSlider7;
    TTrackBar *trbSlider7;
    TEdit *edtSlider7;
    TLabel *lblSlider8;
    TTrackBar *trbSlider8;
    TEdit *edtSlider8;
    TLabel *lblSlider9;
    TTrackBar *trbSlider9;
    TEdit *edtSlider9;
    TGroupBox *grbColor;
    TLabel *lblSlider1;
    TTrackBar *trbSlider1;
    TEdit *edtSlider1;
    TCheckBox *chbInHex;
    TLabel *lblResult;
    TBevel *bvlResult;
    TTrackBar *trbSlider2;
    TLabel *lblSlider2;
    TEdit *edtSlider2;
    TEdit *edtSlider3;
    TTrackBar *trbSlider3;
    TLabel *lblSlider3;
    TImage *imgResult;
    TLabel *lblCheckBox1;
    TCheckBox *chbCheckBox1;
    TCheckBox *chbCheckBox2;
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall trbSlider2Change(TObject *Sender);
    void __fastcall trbSlider3Change(TObject *Sender);
    void __fastcall chbInHexClick(TObject *Sender);
    void __fastcall trbSlider6Change(TObject *Sender);
    void __fastcall trbSlider4Change(TObject *Sender);
    void __fastcall trbSlider5Change(TObject *Sender);
    void __fastcall trbSlider7Change(TObject *Sender);
    void __fastcall trbSlider8Change(TObject *Sender);
    void __fastcall trbSlider9Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmBrush(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBrush *frmBrush;
//---------------------------------------------------------------------------
#endif
