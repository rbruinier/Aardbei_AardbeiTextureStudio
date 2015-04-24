object frmBrightness: TfrmBrightness
  Left = 272
  Top = 135
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Brightness'
  ClientHeight = 113
  ClientWidth = 360
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object grbParameters: TGroupBox
    Left = 8
    Top = 8
    Width = 345
    Height = 65
    Caption = 'Filter Parameters'
    TabOrder = 0
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 43
      Height = 13
      Caption = 'Strength:'
    end
    object edtSlider1: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 1
      Text = '0'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 128
      Min = -127
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 81
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 1
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 80
    Width = 75
    Height = 26
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 81
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 3
    OnClick = btnPreviewClick
  end
end
