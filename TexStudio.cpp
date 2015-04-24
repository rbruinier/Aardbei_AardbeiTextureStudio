//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("TexStudio.res");
USEFORM("MainForm.cpp", frmMain);
USEUNIT("Filters.cpp");
USEFORM("Filters\FilterTopLeft.cpp", frmTopLeft);
USEFORM("Filters\FilterBoxBlur.cpp", frmBoxBlur);
USEFORM("Filters\FilterBrightness.cpp", frmBrightness);
USEFORM("Filters\FilterBrush.cpp", frmBrush);
USEFORM("Filters\FilterCells.cpp", frmCells);
USEFORM("Filters\FilterContrast.cpp", frmContrast);
USEFORM("Filters\FilterCopy.cpp", frmCopy);
USEFORM("Filters\FilterDirBlur.cpp", frmDirBlur);
USEFORM("Filters\FilterEdge.cpp", frmEdge);
USEFORM("Filters\FilterEmboss.cpp", frmEmboss);
USEFORM("Filters\FilterFractalPlasma.cpp", frmFractalPlasma);
USEFORM("Filters\FilterGaussianBlur.cpp", frmGaussianBlur);
USEFORM("Filters\FilterHsv.cpp", frmHsv);
USEFORM("Filters\FilterInvert.cpp", frmInvert);
USEFORM("Filters\FilterMix.cpp", frmMix);
USEFORM("Filters\FilterMotionBlur.cpp", frmMotionBlur);
USEFORM("Filters\FilterMul.cpp", frmMul);
USEFORM("Filters\FilterNoise.cpp", frmNoise);
USEFORM("Filters\FilterNotNull.cpp", frmNotNull);
USEFORM("Filters\FilterPlasma.cpp", frmPlasma);
USEFORM("Filters\FilterRectangle.cpp", frmRectangle);
USEFORM("Filters\FilterShade.cpp", frmShade);
USEFORM("Filters\FilterSineDistort.cpp", frmSineDistort);
USEFORM("Filters\FilterSobel.cpp", frmSobel);
USEFORM("Filters\FilterSub.cpp", frmSub);
USEFORM("Filters\FilterText.cpp", frmText);
USEFORM("Filters\FilterTile.cpp", frmTile);
USEFORM("Filters\FilterAdd.cpp", frmAdd);
USEFORM("Other\NewForm.cpp", frmNew);
USEFORM("Other\Layer.cpp", frmLayer);
USEFORM("Other\AboutForm.cpp", frmAbout);
USEFORM("Other\Updates.cpp", frmUpdates);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "Aardbei Texture Studio";
         Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->CreateForm(__classid(TfrmTopLeft), &frmTopLeft);
         Application->CreateForm(__classid(TfrmBoxBlur), &frmBoxBlur);
         Application->CreateForm(__classid(TfrmBrightness), &frmBrightness);
         Application->CreateForm(__classid(TfrmBrush), &frmBrush);
         Application->CreateForm(__classid(TfrmCells), &frmCells);
         Application->CreateForm(__classid(TfrmContrast), &frmContrast);
         Application->CreateForm(__classid(TfrmCopy), &frmCopy);
         Application->CreateForm(__classid(TfrmDirBlur), &frmDirBlur);
         Application->CreateForm(__classid(TfrmEdge), &frmEdge);
         Application->CreateForm(__classid(TfrmEmboss), &frmEmboss);
         Application->CreateForm(__classid(TfrmFractalPlasma), &frmFractalPlasma);
         Application->CreateForm(__classid(TfrmGaussianBlur), &frmGaussianBlur);
         Application->CreateForm(__classid(TfrmHsv), &frmHsv);
         Application->CreateForm(__classid(TfrmInvert), &frmInvert);
         Application->CreateForm(__classid(TfrmMix), &frmMix);
         Application->CreateForm(__classid(TfrmMotionBlur), &frmMotionBlur);
         Application->CreateForm(__classid(TfrmMul), &frmMul);
         Application->CreateForm(__classid(TfrmNoise), &frmNoise);
         Application->CreateForm(__classid(TfrmNotNull), &frmNotNull);
         Application->CreateForm(__classid(TfrmPlasma), &frmPlasma);
         Application->CreateForm(__classid(TfrmRectangle), &frmRectangle);
         Application->CreateForm(__classid(TfrmShade), &frmShade);
         Application->CreateForm(__classid(TfrmSineDistort), &frmSineDistort);
         Application->CreateForm(__classid(TfrmSobel), &frmSobel);
         Application->CreateForm(__classid(TfrmSub), &frmSub);
         Application->CreateForm(__classid(TfrmText), &frmText);
         Application->CreateForm(__classid(TfrmTile), &frmTile);
         Application->CreateForm(__classid(TfrmAdd), &frmAdd);
         Application->CreateForm(__classid(TfrmAbout), &frmAbout);
         Application->CreateForm(__classid(TfrmUpdates), &frmUpdates);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
