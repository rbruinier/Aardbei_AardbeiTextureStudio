//---------------------------------------------------------------------------

#ifndef LayerH
#define LayerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmLayer : public TForm
{
__published:	// IDE-managed Components
    TImage *imgOutput;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall imgOutputClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmLayer(TComponent* Owner);

    void Setup(char * name, int width, int height, unsigned int *iBuffer);
    void UpdateOutput();

    int width;
    int height;
    unsigned int *buffer;

    bool stillInCreation;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLayer *frmLayer;
//---------------------------------------------------------------------------
#endif
