//---------------------------------------------------------------------------

#ifndef FilterSineDistortH
#define FilterSineDistortH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmSineDistort : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *Label1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    TTrackBar *trbSlider1;
    TEdit *edtSlider1;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TLabel *Label4;
    TTrackBar *trbSlider5;
    TEdit *edtSlider5;
    TLabel *Label5;
    TTrackBar *trbSlider6;
    TEdit *edtSlider6;
    TLabel *Label2;
    TTrackBar *trbSlider3;
    TEdit *edtSlider3;
    TLabel *Label3;
    TTrackBar *trbSlider4;
    TEdit *edtSlider4;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSineDistort(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSineDistort *frmSineDistort;
//---------------------------------------------------------------------------
#endif
