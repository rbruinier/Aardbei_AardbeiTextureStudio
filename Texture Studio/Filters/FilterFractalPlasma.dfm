object frmFractalPlasma: TfrmFractalPlasma
  Left = 154
  Top = 95
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Fractal Plasma'
  ClientHeight = 264
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
    Height = 97
    Caption = 'Filter Parameters'
    TabOrder = 3
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 33
      Height = 13
      Caption = 'Factor:'
    end
    object edtSlider1: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 2
      Text = '7'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 7
      Min = 2
      Orientation = trHorizontal
      Frequency = 1
      Position = 7
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object btnRandomize: TButton
      Left = 16
      Top = 64
      Width = 313
      Height = 25
      Caption = 'Randomize'
      TabOrder = 1
      OnClick = btnRandomizeClick
    end
  end
  object grbColor: TGroupBox
    Left = 8
    Top = 112
    Width = 345
    Height = 41
    Caption = 'Channel Parameters'
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
      TabOrder = 3
    end
    object rdbAll: TRadioButton
      Left = 288
      Top = 16
      Width = 49
      Height = 17
      Caption = 'All'
      TabOrder = 2
    end
  end
  object grbLayer: TGroupBox
    Left = 8
    Top = 160
    Width = 345
    Height = 65
    Caption = 'Layer Parameters'
    TabOrder = 5
    object rdbFill: TRadioButton
      Left = 16
      Top = 16
      Width = 41
      Height = 17
      Caption = 'Fill'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object rdbAdd: TRadioButton
      Left = 107
      Top = 16
      Width = 41
      Height = 17
      Caption = 'Add'
      TabOrder = 1
    end
    object rdbSub: TRadioButton
      Left = 288
      Top = 16
      Width = 41
      Height = 17
      Caption = 'Sub'
      TabOrder = 3
    end
    object rdbMul: TRadioButton
      Left = 197
      Top = 16
      Width = 41
      Height = 17
      Caption = 'Mul'
      TabOrder = 2
    end
    object rdbNotNullCopy: TRadioButton
      Left = 16
      Top = 40
      Width = 89
      Height = 17
      Caption = 'Not Null Copy'
      TabOrder = 4
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 233
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 233
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 233
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
end
