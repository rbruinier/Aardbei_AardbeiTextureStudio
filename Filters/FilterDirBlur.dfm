object frmDirBlur: TfrmDirBlur
  Left = 175
  Top = 149
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Direction Blur'
  ClientHeight = 161
  ClientWidth = 361
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object btnOk: TButton
    Left = 16
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
  object grbColor: TGroupBox
    Left = 8
    Top = 80
    Width = 345
    Height = 41
    Caption = 'Source Channel'
    TabOrder = 4
    object rdbRed: TRadioButton
      Left = 16
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Red'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object rdbGreen: TRadioButton
      Left = 107
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Green'
      TabOrder = 1
    end
    object rdbBlue: TRadioButton
      Left = 197
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Blue'
      TabOrder = 2
    end
    object rdbAll: TRadioButton
      Left = 288
      Top = 16
      Width = 49
      Height = 17
      Caption = 'All'
      Enabled = False
      TabOrder = 3
    end
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
      Width = 66
      Height = 13
      Caption = 'Source Layer:'
    end
    object Label1: TLabel
      Left = 176
      Top = 18
      Width = 36
      Height = 13
      Caption = 'Radius:'
    end
    object cmbLayer: TComboBox
      Left = 24
      Top = 35
      Width = 137
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
    end
    object trbSlider1: TTrackBar
      Left = 176
      Top = 33
      Width = 105
      Height = 25
      Max = 127
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 5
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider1: TEdit
      Left = 283
      Top = 35
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 2
      Text = '5'
    end
  end
end
