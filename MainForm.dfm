object frmMain: TfrmMain
  Left = 279
  Top = 114
  Width = 756
  Height = 551
  Caption = 'Aardbei Texture Studio'
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = mnuMain
  OldCreateOrder = False
  Position = poDefault
  WindowMenu = Window1
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object stbMain: TStatusBar
    Left = 0
    Top = 478
    Width = 748
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object mnuMain: TMainMenu
    Left = 8
    Top = 8
    object File1: TMenuItem
      Caption = '&File'
      object New1: TMenuItem
        Caption = '&New'
        OnClick = New1Click
      end
      object Open1: TMenuItem
        Caption = '&Open...'
        OnClick = Open1Click
      end
      object Close1: TMenuItem
        Caption = '&Close'
        OnClick = Close1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Save1: TMenuItem
        Caption = '&Save'
        OnClick = Save1Click
      end
      object SaveAs1: TMenuItem
        Caption = 'Save &As'
        OnClick = SaveAs1Click
      end
      object Export1: TMenuItem
        Caption = '&Export'
        object TGA1: TMenuItem
          Caption = '&TGA'
          OnClick = TGA1Click
        end
        object N5: TMenuItem
          Caption = '-'
        end
        object Clipboard1: TMenuItem
          Caption = '&C++ To Clipboard'
          OnClick = Clipboard1Click
        end
        object BitmapToClipboard1: TMenuItem
          Caption = 'Bitmap To Clipboard'
          OnClick = BitmapToClipboard1Click
        end
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
        GroupIndex = 9
        OnClick = Exit1Click
      end
    end
    object Generate1: TMenuItem
      Caption = '&Generate'
      object Plasma1: TMenuItem
        Caption = '&Plasma'
        OnClick = Plasma1Click
      end
      object FractalPlasma1: TMenuItem
        Caption = '&Fractal Plasma'
        OnClick = FractalPlasma1Click
      end
      object Cells1: TMenuItem
        Caption = '&Cells'
        OnClick = Cells1Click
      end
      object Text1: TMenuItem
        Caption = '&Text'
        OnClick = Text1Click
      end
      object Brush1: TMenuItem
        Caption = '&Brush'
        OnClick = Brush1Click
      end
      object Rectangle1: TMenuItem
        Caption = '&Rectangle'
        OnClick = Rectangle1Click
      end
      object Noise1: TMenuItem
        Caption = '&Noise'
        OnClick = Noise1Click
      end
    end
    object Color1: TMenuItem
      Caption = '&Color'
      object Hsv1: TMenuItem
        Caption = '&Hsv'
        OnClick = Hsv1Click
      end
      object Invert1: TMenuItem
        Caption = '&Invert'
        OnClick = Invert1Click
      end
      object Contrast1: TMenuItem
        Caption = '&Contrast'
        OnClick = Contrast1Click
      end
      object Brightness1: TMenuItem
        Caption = '&Brightness'
        OnClick = Brightness1Click
      end
    end
    object Blur1: TMenuItem
      Caption = '&Blur'
      object Gaussian1: TMenuItem
        Caption = '&Gaussian'
        OnClick = Gaussian1Click
      end
      object Motion1: TMenuItem
        Caption = '&Motion'
        OnClick = Motion1Click
      end
      object Direction1: TMenuItem
        Caption = '&Direction'
        OnClick = Direction1Click
      end
      object Emboss1: TMenuItem
        Caption = '&Emboss'
        OnClick = Emboss1Click
      end
      object TopLeft1: TMenuItem
        Caption = '&Top Left'
        OnClick = TopLeft1Click
      end
      object EdgeDetect1: TMenuItem
        Caption = '&Edge Detect'
        OnClick = EdgeDetect1Click
      end
      object Sobel1: TMenuItem
        Caption = '&Sobel'
        OnClick = Sobel1Click
      end
      object Box1: TMenuItem
        Caption = '&Box'
        OnClick = Box1Click
      end
    end
    object Distort1: TMenuItem
      Caption = '&Distort'
      object Sin1: TMenuItem
        Caption = 'Sine'
        OnClick = Sin1Click
      end
      object Tile2: TMenuItem
        Caption = '&Tile'
        OnClick = Tile2Click
      end
    end
    object Layer1: TMenuItem
      Caption = '&Layer'
      object NewLayer1: TMenuItem
        Caption = '&New Layer'
        OnClick = NewLayer1Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Copy1: TMenuItem
        Caption = '&Copy'
        OnClick = Copy1Click
      end
      object Add1: TMenuItem
        Caption = '&Add'
        OnClick = Add1Click
      end
      object Sub1: TMenuItem
        Caption = '&Sub'
        OnClick = Sub1Click
      end
      object Mul1: TMenuItem
        Caption = '&Mul'
        OnClick = Mul1Click
      end
      object NotNullCopy1: TMenuItem
        Caption = 'Not &Null Copy'
        OnClick = NotNullCopy1Click
      end
      object Mix1: TMenuItem
        Caption = 'Mi&x'
        OnClick = Mix1Click
      end
      object Shade1: TMenuItem
        Caption = 'S&hade'
        OnClick = Shade1Click
      end
    end
    object Options1: TMenuItem
      Caption = '&Options'
      object BrushOnClick1: TMenuItem
        Caption = 'Brush On Click'
        Checked = True
        OnClick = BrushOnClick1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Undo1: TMenuItem
        Caption = '&Undo'
        ShortCut = 16474
        OnClick = Undo1Click
      end
    end
    object Window1: TMenuItem
      Caption = '&Window'
      GroupIndex = 9
      object Tile1: TMenuItem
        Caption = '&Tile'
        OnClick = Tile1Click
      end
      object Cascade1: TMenuItem
        Caption = '&Cascade'
        OnClick = Cascade1Click
      end
      object Arrangeicons1: TMenuItem
        Caption = '&Arrange icons'
        OnClick = Arrangeicons1Click
      end
    end
    object Help1: TMenuItem
      Caption = '&Help'
      GroupIndex = 9
      object Updates1: TMenuItem
        Caption = '&Updates'
        OnClick = Updates1Click
      end
      object About1: TMenuItem
        Caption = '&About ATS'
        OnClick = About1Click
      end
    end
  end
  object dlgSaveAs: TSaveDialog
    DefaultExt = '*.ats'
    Filter = 'ATS Files (*.ats)|*.ats|All files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly]
    Title = 'Save File'
    Left = 48
    Top = 8
  end
  object dlgOpen: TOpenDialog
    DefaultExt = '*.ats'
    Filter = 'ATS Files (*.ats)|*.ats|All files|*.*'
    Options = [ofHideReadOnly]
    Title = 'Open File'
    Left = 88
    Top = 8
  end
  object dlgExportTGA: TSaveDialog
    DefaultExt = '*.tga'
    Filter = 'TGA Files (*.tga)|*.tga|All files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly]
    Title = 'Save File'
    Left = 48
    Top = 40
  end
end
