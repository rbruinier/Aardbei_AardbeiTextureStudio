object frmSineDistort: TfrmSineDistort
  Left = 215
  Top = 207
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Sine Distort'
  ClientHeight = 193
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
    Height = 145
    Caption = 'Filter Parameters'
    TabOrder = 3
    object lblSlider1: TLabel
      Left = 16
      Top = 18
      Width = 73
      Height = 13
      Caption = 'Repetition In X:'
    end
    object Label1: TLabel
      Left = 176
      Top = 18
      Width = 73
      Height = 13
      Caption = 'Repetition In Y:'
    end
    object Label4: TLabel
      Left = 16
      Top = 98
      Width = 41
      Height = 13
      Caption = 'Offset X:'
    end
    object Label5: TLabel
      Left = 176
      Top = 98
      Width = 38
      Height = 13
      Caption = 'Offset Y'
    end
    object Label2: TLabel
      Left = 16
      Top = 58
      Width = 70
      Height = 13
      Caption = 'Amplitude in X:'
    end
    object Label3: TLabel
      Left = 176
      Top = 58
      Width = 70
      Height = 13
      Caption = 'Amplitude in Y:'
    end
    object trbSlider2: TTrackBar
      Left = 176
      Top = 33
      Width = 105
      Height = 25
      Max = 64
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
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
      TabOrder = 6
      Text = '1'
    end
    object trbSlider1: TTrackBar
      Left = 16
      Top = 32
      Width = 105
      Height = 25
      Max = 64
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
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
      TabOrder = 7
      Text = '1'
    end
    object trbSlider5: TTrackBar
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
      OnChange = trbSlider1Change
    end
    object edtSlider5: TEdit
      Left = 123
      Top = 115
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object trbSlider6: TTrackBar
      Left = 176
      Top = 113
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 5
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider6: TEdit
      Left = 283
      Top = 115
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 9
      Text = '0'
    end
    object trbSlider3: TTrackBar
      Left = 16
      Top = 72
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 30
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider3: TEdit
      Left = 123
      Top = 75
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 10
      Text = '30'
    end
    object trbSlider4: TTrackBar
      Left = 176
      Top = 73
      Width = 105
      Height = 25
      Max = 255
      Orientation = trHorizontal
      Frequency = 1
      Position = 30
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = trbSlider1Change
    end
    object edtSlider4: TEdit
      Left = 283
      Top = 75
      Width = 33
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 11
      Text = '30'
    end
  end
  object btnOk: TButton
    Left = 16
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 144
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnPreview: TButton
    Left = 271
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Preview'
    TabOrder = 2
    OnClick = btnPreviewClick
  end
end
