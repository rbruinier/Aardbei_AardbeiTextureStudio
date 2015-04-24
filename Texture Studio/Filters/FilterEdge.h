//---------------------------------------------------------------------------

#ifndef FilterEdgeH
#define FilterEdgeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmEdge : public TForm
{
__published:	// IDE-managed Components
    TButton *btnOk;
    TButton *btnCancel;
    TButton *btnPreview;
    TGroupBox *grbParameters;
    TLabel *lblSlider1;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnPreviewClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmEdge(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEdge *frmEdge;
//---------------------------------------------------------------------------
#endif
