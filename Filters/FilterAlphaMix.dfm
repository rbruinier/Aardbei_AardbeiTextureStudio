object frmAlphaMix: TfrmAlphaMix
  Left = 271
  Top = 107
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Alpha Mix'
  ClientHeight = 161
  ClientWidth = 361
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
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
      Width = 66
      Height = 13
      Caption = 'Source Layer:'
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
  end
  object grbColor: TGroupBox
    Left = 8
    Top = 80
    Width = 345
    Height = 41
    Caption = 'Channel Parameters'
    TabOrder = 1
    object rdbRed: TRadioButton
      Left = 16
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Red'
      Enabled = False
      TabOrder = 0
    end
    object rdbGreen: TRadioButton
      Left = 107
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Green'
      Enabled = False
      TabOrder = 1
    end
    object rdbBlue: TRadioButton
      Left = 197
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Blue'
      Enabled = False
      TabOrder = 2
    end
    object rdbAll: TRadioButton
      Left = 288
      Top = 16
      Width = 49
      Height = 17
      Caption = 'All'
      Checked = True
      TabOrder = 3
      TabStop = True
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 2
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 129
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 4
    OnClick = btnPreviewClick
  end
end
