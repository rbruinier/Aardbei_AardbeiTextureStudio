object frmUpdates: TfrmUpdates
  Left = 577
  Top = 215
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Updates'
  ClientHeight = 413
  ClientWidth = 402
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 385
    Height = 361
    Caption = 'Updates'
    TabOrder = 1
    object mmoUpdates: TMemo
      Left = 16
      Top = 24
      Width = 353
      Height = 321
      Color = clScrollBar
      Lines.Strings = (
        'ATS v1.2 (06-01-2002):'
        
          ' * Fixed a very small bug with size of main form when loading a ' +
          'texture'
        ' * Fixed tiny bug with brush positioner'
        ''
        'ATS v1.1 (13-11-2001):'
        
          ' * Added "brush-on-click" option. When this option is checked, y' +
          'ou can'
        
          '   click on the texture to open the brush window. The mouse posi' +
          'tion will'
        '   be used to position the brush'
        ' * The sub/add/mix/shade filters are mmx optimized'
        ' * ATS file type is now in registry'
        ' * Replaced Gaussian blur with more precise one (slower also)'
        ' * Added export C++ code to clipboard option'
        ' * Added export bitmap to clipboard option'
        ''
        'ATS v1.0 (18-10-2001):'
        'First version finished!')
      ReadOnly = True
      TabOrder = 0
    end
  end
  object btnOk: TButton
    Left = 164
    Top = 380
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
end
