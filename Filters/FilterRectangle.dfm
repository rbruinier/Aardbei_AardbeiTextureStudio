object frmRectangle: TfrmRectangle
  Left = 271
  Top = 48
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Rectangle'
  ClientHeight = 377
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
  object grbParameters: TGroupBox
    Left = 8
    Top = 8
    Width = 345
    Height = 105
    Caption = 'Filter Parameters'
    TabOrder = 3
    object lblSlider4: TLabel
      Left = 16
      Top = 18
      Width = 32
      Height = 13
      Caption = 'Top X:'
    end
    object lblSlider5: TLabel
      Left = 176
      Top = 18
      Width = 32
      Height = 13
      Caption = 'Top Y:'
    end
    object lblSlider6: TLabel
      Left = 16
      Top = 58
      Width = 46
      Height = 13
      Caption = 'Bottom X:'
    end
    object lblSlider7: TLabel
      Left = 176
      Top = 58
      Width = 46
      Height = 13
      Caption = 'Bottom Y:'
    end
    object trbSlider4: TTrackBar
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
      OnChange = trbSlider4Change
    end
    object edtSlider4: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object trbSlider5: TTrackBar
      Left = 176
      Top = 32
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider4Change
    end
    object edtSlider5: TEdit
      Left = 283
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 5
      Text = '0'
    end
    object trbSlider6: TTrackBar
      Left = 16
      Top = 72
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider4Change
    end
    object edtSlider6: TEdit
      Left = 123
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 6
      Text = '255'
    end
    object trbSlider7: TTrackBar
      Left = 176
      Top = 72
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider4Change
    end
    object edtSlider7: TEdit
      Left = 283
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 7
      Text = '255'
    end
  end
  object grbColor: TGroupBox
    Left = 8
    Top = 120
    Width = 345
    Height = 145
    Caption = 'Color Parameters'
    TabOrder = 4
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 80
      Height = 13
      Caption = 'Red Component:'
    end
    object lblResult: TLabel
      Left = 176
      Top = 58
      Width = 33
      Height = 13
      Caption = 'Result:'
    end
    object bvlResult: TBevel
      Left = 187
      Top = 80
      Width = 131
      Height = 59
      Style = bsRaised
    end
    object lblSlider2: TLabel
      Left = 16
      Top = 58
      Width = 89
      Height = 13
      Caption = 'Green Component:'
    end
    object lblSlider3: TLabel
      Left = 16
      Top = 98
      Width = 81
      Height = 13
      Caption = 'Blue Component:'
    end
    object imgResult: TImage
      Left = 188
      Top = 81
      Width = 129
      Height = 57
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider1: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 4
      Text = '#FF'
    end
    object chbInHex: TCheckBox
      Left = 174
      Top = 35
      Width = 140
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Show RGB In Hex'
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnClick = chbInHexClick
    end
    object trbSlider2: TTrackBar
      Left = 16
      Top = 72
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
      Left = 123
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 5
      Text = '#FF'
    end
    object edtSlider3: TEdit
      Left = 123
      Top = 113
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 6
      Text = '#FF'
    end
    object trbSlider3: TTrackBar
      Left = 16
      Top = 112
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 345
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 345
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 345
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
  object grbLayer: TGroupBox
    Left = 8
    Top = 272
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
end
