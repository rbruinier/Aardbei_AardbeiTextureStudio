object frmHsv: TfrmHsv
  Left = 213
  Top = 150
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Hsv'
  ClientHeight = 112
  ClientWidth = 361
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
    TabOrder = 3
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 43
      Height = 13
      Caption = 'Rotation:'
    end
    object Label1: TLabel
      Left = 176
      Top = 18
      Width = 51
      Height = 13
      Caption = 'Saturation:'
    end
    object trbSlider2: TTrackBar
      Left = 176
      Top = 33
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider2: TEdit
      Left = 283
      Top = 35
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 2
      Text = '255'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 255
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
    object edtSlider1: TEdit
      Left = 123
      Top = 35
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 3
      Text = '0'
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 81
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 81
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 81
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
end
