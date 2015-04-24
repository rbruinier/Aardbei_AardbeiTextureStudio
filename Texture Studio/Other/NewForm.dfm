object frmNew: TfrmNew
  Left = 379
  Top = 253
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'New Image'
  ClientHeight = 143
  ClientWidth = 218
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
  object grbDimensions: TGroupBox
    Left = 8
    Top = 8
    Width = 201
    Height = 97
    Caption = 'Dimensions'
    TabOrder = 2
    object lblWidth: TLabel
      Left = 29
      Top = 30
      Width = 28
      Height = 13
      Caption = 'Width'
    end
    object lblHeight: TLabel
      Left = 29
      Top = 62
      Width = 31
      Height = 13
      Caption = 'Height'
    end
    object edtWidth: TEdit
      Left = 103
      Top = 26
      Width = 73
      Height = 21
      TabOrder = 0
      Text = '256'
    end
    object edtHeight: TEdit
      Left = 103
      Top = 58
      Width = 73
      Height = 21
      TabOrder = 1
      Text = '256'
    end
  end
  object btnOk: TButton
    Left = 17
    Top = 113
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 125
    Top = 113
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
end
