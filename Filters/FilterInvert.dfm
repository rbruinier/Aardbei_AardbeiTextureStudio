object frmInvert: TfrmInvert
  Left = 209
  Top = 202
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Invert'
  ClientHeight = 97
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
    Height = 49
    Caption = 'Filter Parameters'
    TabOrder = 0
    object lblSlider1: TLabel
      Left = 119
      Top = 21
      Width = 107
      Height = 13
      Caption = 'No options for this filter'
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 65
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 1
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 64
    Width = 75
    Height = 26
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 65
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 3
    OnClick = btnPreviewClick
  end
end
