object frmText: TfrmText
  Left = 393
  Top = 176
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Text'
  ClientHeight = 496
  ClientWidth = 362
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
    Height = 225
    Caption = 'Filter Parameters'
    TabOrder = 4
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 62
      Height = 13
      Caption = 'Position In X:'
    end
    object lblSlider2: TLabel
      Left = 184
      Top = 18
      Width = 62
      Height = 13
      Caption = 'Position In Y:'
    end
    object lblSlider3: TLabel
      Left = 16
      Top = 66
      Width = 23
      Height = 13
      Caption = 'Size:'
    end
    object lblCheckBox1: TLabel
      Left = 16
      Top = 114
      Width = 39
      Height = 13
      Caption = 'Options:'
    end
    object lblFont: TLabel
      Left = 184
      Top = 114
      Width = 24
      Height = 13
      Caption = 'Font:'
    end
    object lblText: TLabel
      Left = 16
      Top = 178
      Width = 24
      Height = 13
      Caption = 'Text:'
    end
    object lblSlider4: TLabel
      Left = 184
      Top = 66
      Width = 43
      Height = 13
      Caption = 'Boldness'
    end
    object edtSlider1: TEdit
      Left = 123
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 3
      Text = '0'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 127
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
    object trbSlider2: TTrackBar
      Left = 184
      Top = 32
      Width = 105
      Height = 25
      Max = 127
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider2Change
    end
    object edtSlider2: TEdit
      Left = 291
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 9
      Text = '0'
    end
    object trbSlider3: TTrackBar
      Left = 16
      Top = 80
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 24
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider3Change
    end
    object edtSlider3: TEdit
      Left = 123
      Top = 81
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 10
      Text = '24'
    end
    object chbCheckBox1: TCheckBox
      Left = 24
      Top = 128
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Anti Alias'
      TabOrder = 4
    end
    object drdFont: TComboBox
      Left = 192
      Top = 128
      Width = 132
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 7
      Items.Strings = (
        'Arial'
        'Courier New'
        'Times New Roman'
        'Symbol')
    end
    object chbCheckBox2: TCheckBox
      Left = 24
      Top = 144
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Clip'
      Checked = True
      State = cbChecked
      TabOrder = 5
    end
    object edtText: TEdit
      Left = 24
      Top = 192
      Width = 300
      Height = 21
      TabOrder = 8
    end
    object chbCheckBox3: TCheckBox
      Left = 24
      Top = 160
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Italic'
      TabOrder = 6
    end
  end
  object grbLayer: TGroupBox
    Left = 8
    Top = 392
    Width = 345
    Height = 65
    Caption = 'Layer Parameters'
    TabOrder = 6
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
    Top = 465
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 465
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 465
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
  object trbSlider4: TTrackBar
    Left = 192
    Top = 88
    Width = 105
    Height = 25
    Max = 15
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    TickMarks = tmBoth
    TickStyle = tsNone
    OnChange = trbSlider4Change
  end
  object edtSlider4: TEdit
    Left = 299
    Top = 89
    Width = 33
    Height = 21
    TabStop = False
    ReadOnly = True
    TabOrder = 7
    Text = '0'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 240
    Width = 345
    Height = 145
    Caption = 'Color Parameters'
    TabOrder = 5
    object Label1: TLabel
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
    object Label2: TLabel
      Left = 16
      Top = 58
      Width = 89
      Height = 13
      Caption = 'Green Component:'
    end
    object Label3: TLabel
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
    object trbSlider5: TTrackBar
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
      OnChange = trbSlider5Change
    end
    object edtSlider5: TEdit
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
      TabOrder = 1
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider5Change
    end
    object edtSlider6: TEdit
      Left = 123
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 5
      Text = '#FF'
    end
    object edtSlider7: TEdit
      Left = 123
      Top = 113
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 6
      Text = '#FF'
    end
    object trbSlider7: TTrackBar
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
      OnChange = trbSlider5Change
    end
  end
end
