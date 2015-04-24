//---------------------------------------------------------------------------

#ifndef FilterCellsH
#define FilterCellsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmCells : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *lblSlider2;
    TEdit *edtSlider1;
    TTrackBar *trbSlider1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
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
    TButton *btnRandomize;
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall trbSlider2Change(TObject *Sender);
    void __fastcall btnRandomizeClick(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmCells(TComponent* Owner);
    unsigned int randParam;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCells *frmCells;
//---------------------------------------------------------------------------
#endif
