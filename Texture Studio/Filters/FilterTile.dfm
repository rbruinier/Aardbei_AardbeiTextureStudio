object frmTile: TfrmTile
  Left = 219
  Top = 148
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Tile'
  ClientHeight = 112
  ClientWidth = 362
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
    Top = 80
    Width = 75
    Height = 26
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
      Width = 73
      Height = 13
      Caption = 'Repetition In X:'
    end
    object lblSlider2: TLabel
      Left = 184
      Top = 18
      Width = 73
      Height = 13
      Caption = 'Repetition In Y:'
    end
    object edtSlider1: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 1
      Text = '2'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 63
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 2
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object trbSlider2: TTrackBar
      Left = 184
      Top = 32
      Width = 105
      Height = 25
      Max = 63
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 2
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider2: TEdit
      Left = 291
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 3
      Text = '2'
    end
  end
end
