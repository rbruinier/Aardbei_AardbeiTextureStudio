//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

#include "Filters.h"
#include "Other\Layer.h"
#include <Dialogs.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *mnuMain;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Window1;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeicons1;
    TMenuItem *Save1;
    TMenuItem *SaveAs1;
    TMenuItem *N2;
    TStatusBar *stbMain;
    TMenuItem *Generate1;
    TMenuItem *FractalPlasma1;
    TMenuItem *Plasma1;
    TMenuItem *Distort1;
    TMenuItem *Layer1;
    TMenuItem *NewLayer1;
    TMenuItem *N3;
    TMenuItem *Copy1;
    TMenuItem *Add1;
    TMenuItem *Sub1;
    TMenuItem *Mul1;
    TMenuItem *Cells1;
    TMenuItem *Text1;
    TMenuItem *Sin1;
    TMenuItem *Brush1;
    TMenuItem *Close1;
    TSaveDialog *dlgSaveAs;
    TOpenDialog *dlgOpen;
    TMenuItem *Noise1;
    TMenuItem *Blur1;
    TMenuItem *Gaussian1;
    TMenuItem *Motion1;
    TMenuItem *Rectangle1;
    TMenuItem *Emboss1;
    TMenuItem *EdgeDetect1;
    TMenuItem *Sobel1;
    TMenuItem *Box1;
    TMenuItem *NotNullCopy1;
    TMenuItem *Mix1;
    TMenuItem *Shade1;
    TMenuItem *TopLeft1;
    TMenuItem *Color1;
    TMenuItem *Hsv1;
    TMenuItem *Direction1;
    TMenuItem *Tile2;
    TMenuItem *Help1;
    TMenuItem *About1;
    TMenuItem *Invert1;
    TMenuItem *Contrast1;
    TMenuItem *Brightness1;
    TMenuItem *Export1;
    TMenuItem *TGA1;
    TMenuItem *BrushOnClick1;
    TMenuItem *Options1;
    TMenuItem *N4;
    TMenuItem *Undo1;
    TSaveDialog *dlgExportTGA;
    TMenuItem *Updates1;
    TMenuItem *Clipboard1;
    TMenuItem *BitmapToClipboard1;
    TMenuItem *N5;
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall SaveAs1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeicons1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Plasma1Click(TObject *Sender);
    void __fastcall NewLayer1Click(TObject *Sender);
    void __fastcall Cells1Click(TObject *Sender);
    void __fastcall FractalPlasma1Click(TObject *Sender);
    void __fastcall Text1Click(TObject *Sender);
    void __fastcall Brush1Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Noise1Click(TObject *Sender);
    void __fastcall Undo1Click(TObject *Sender);
    void __fastcall Gaussian1Click(TObject *Sender);
    void __fastcall Motion1Click(TObject *Sender);
    void __fastcall Rectangle1Click(TObject *Sender);
    void __fastcall Emboss1Click(TObject *Sender);
    void __fastcall EdgeDetect1Click(TObject *Sender);
    void __fastcall Sobel1Click(TObject *Sender);
    void __fastcall Box1Click(TObject *Sender);
    void __fastcall Copy1Click(TObject *Sender);
    void __fastcall Add1Click(TObject *Sender);
    void __fastcall Sub1Click(TObject *Sender);
    void __fastcall Mul1Click(TObject *Sender);
    void __fastcall NotNullCopy1Click(TObject *Sender);
    void __fastcall Mix1Click(TObject *Sender);
    void __fastcall Shade1Click(TObject *Sender);
    void __fastcall TopLeft1Click(TObject *Sender);
    void __fastcall Hsv1Click(TObject *Sender);
    void __fastcall Sin1Click(TObject *Sender);
    void __fastcall Direction1Click(TObject *Sender);
    void __fastcall Tile2Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall Invert1Click(TObject *Sender);
    void __fastcall Contrast1Click(TObject *Sender);
    void __fastcall Brightness1Click(TObject *Sender);
    void __fastcall TGA1Click(TObject *Sender);
    void __fastcall BrushOnClick1Click(TObject *Sender);
    void __fastcall Updates1Click(TObject *Sender);
    void __fastcall Clipboard1Click(TObject *Sender);
    void __fastcall BitmapToClipboard1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern bool CloseTexture(char *question, char *title);
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
extern short textureWidth;
extern short textureHeight;
extern unsigned int *layerPreview;
extern TextureGenerator *generator;
extern TfrmLayer *frmLayerActive;
extern int nrLayers;
extern TfrmLayer *frmLayers[];
extern short nrFilters;
extern Filter *filters[];
extern bool workingOnTexture;
extern bool havesFilename;
extern bool loadingTexture;
extern short mousePositionX;
extern short mousePositionY;
extern bool  mouseClicked;
extern bool mouseOpenBrushOnClick;
//---------------------------------------------------------------------------
#endif
