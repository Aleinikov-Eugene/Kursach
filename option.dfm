object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 322
  ClientWidth = 603
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 24
    Top = 24
    Width = 209
    Height = 225
  end
  object TrackBar1: TTrackBar
    Left = 24
    Top = 255
    Width = 209
    Height = 45
    Max = 150
    Min = 75
    Position = 75
    TabOrder = 0
    OnChange = TrackBar1Change
  end
end
