//---------------------------------------------------------------------------

#ifndef FilterMixH
#define FilterMixH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMix : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbColor;
    TRadioButton *rdbRed;
    TRadioButton *rdbGreen;
    TRadioButton *rdbBlue;
    TRadioButton *rdbAll;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TComboBox *cmbLayer;
    TLabel *Label1;
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
    __fastcall TfrmMix(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMix *frmMix;
//---------------------------------------------------------------------------
#endif
