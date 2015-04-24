object frmBrush: TfrmBrush
  Left = 402
  Top = 69
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Brush'
  ClientHeight = 392
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
    Height = 193
    Caption = 'Filter Parameters'
    TabOrder = 3
    object lblSlider4: TLabel
      Left = 16
      Top = 18
      Width = 62
      Height = 13
      Caption = 'Position In X:'
    end
    object lblSlider5: TLabel
      Left = 176
      Top = 18
      Width = 62
      Height = 13
      Caption = 'Position In Y:'
    end
    object lblSlider6: TLabel
      Left = 16
      Top = 58
      Width = 23
      Height = 13
      Caption = 'Size:'
    end
    object lblSlider7: TLabel
      Left = 176
      Top = 58
      Width = 38
      Height = 13
      Caption = 'Density:'
    end
    object lblSlider8: TLabel
      Left = 16
      Top = 98
      Width = 48
      Height = 13
      Caption = 'Hardness:'
    end
    object lblSlider9: TLabel
      Left = 176
      Top = 98
      Width = 39
      Height = 13
      Caption = 'Opacity:'
    end
    object lblCheckBox1: TLabel
      Left = 16
      Top = 138
      Width = 39
      Height = 13
      Caption = 'Options:'
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
      TabOrder = 8
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
      OnChange = trbSlider5Change
    end
    object edtSlider5: TEdit
      Left = 283
      Top = 33
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 9
      Text = '0'
    end
    object trbSlider6: TTrackBar
      Left = 16
      Top = 72
      Width = 105
      Height = 25
      Max = 511
      Orientation = trHorizontal
      Frequency = 1
      Position = 200
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider6Change
    end
    object edtSlider6: TEdit
      Left = 123
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 10
      Text = '200'
    end
    object trbSlider7: TTrackBar
      Left = 176
      Top = 72
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 200
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider7Change
    end
    object edtSlider7: TEdit
      Left = 283
      Top = 73
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 11
      Text = '200'
    end
    object trbSlider8: TTrackBar
      Left = 16
      Top = 112
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 4
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider8Change
    end
    object edtSlider8: TEdit
      Left = 123
      Top = 113
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 12
      Text = '0'
    end
    object trbSlider9: TTrackBar
      Left = 176
      Top = 112
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 255
      SelEnd = 0
      SelStart = 0
      TabOrder = 5
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider9Change
    end
    object edtSlider9: TEdit
      Left = 283
      Top = 113
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 13
      Text = '255'
    end
    object chbCheckBox1: TCheckBox
      Left = 24
      Top = 152
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Clip'
      TabOrder = 6
    end
    object chbCheckBox2: TCheckBox
      Left = 24
      Top = 168
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      Caption = 'Overlay'
      TabOrder = 7
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 361
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 361
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 361
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
  object grbColor: TGroupBox
    Left = 8
    Top = 208
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
      OnChange = trbSlider2Change
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
      OnChange = trbSlider3Change
    end
  end
end
