//---------------------------------------------------------------------------

#ifndef FilterHsvH
#define FilterHsvH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmHsv : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *Label1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TTrackBar *trbSlider1;
    TEdit *edtSlider1;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmHsv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmHsv *frmHsv;
//---------------------------------------------------------------------------
#endif
