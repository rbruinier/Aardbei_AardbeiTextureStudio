//---------------------------------------------------------------------------

#ifndef FilterTileH
#define FilterTileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmTile : public TForm
{
__published:	// IDE-managed Components
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    TLabel *lblSlider2;
    TEdit *edtSlider1;
    TTrackBar *trbSlider1;
    TTrackBar *trbSlider2;
    TEdit *edtSlider2;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall trbSlider1Change(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmTile(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTile *frmTile;
//---------------------------------------------------------------------------
#endif
