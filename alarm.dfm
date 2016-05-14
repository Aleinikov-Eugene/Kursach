object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1041#1091#1076#1080#1083#1100#1085#1080#1082
  ClientHeight = 211
  ClientWidth = 473
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 32
    Top = 8
    Width = 385
    Height = 129
    Caption = 'Panel1'
    TabOrder = 0
    VerticalAlignment = taAlignTop
    object Panel2: TPanel
      Left = 8
      Top = 24
      Width = 89
      Height = 57
      Color = clMenu
      ParentBackground = False
      TabOrder = 0
      object Label1: TLabel
        Left = 17
        Top = 20
        Width = 14
        Height = 16
        Caption = '00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 37
        Top = 18
        Width = 5
        Height = 16
        Caption = ':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 45
        Top = 20
        Width = 14
        Height = 16
        Caption = '00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
    end
    object Panel3: TPanel
      Left = 103
      Top = 24
      Width = 162
      Height = 57
      Color = clMenu
      ParentBackground = False
      TabOrder = 1
      object Label4: TLabel
        Left = 16
        Top = 20
        Width = 7
        Height = 16
        Caption = '0'
      end
      object Label5: TLabel
        Left = 46
        Top = 20
        Width = 14
        Height = 16
        Caption = '00'
      end
      object Label6: TLabel
        Left = 35
        Top = 20
        Width = 5
        Height = 16
        Caption = ':'
      end
      object UpDown1: TUpDown
        Left = 103
        Top = 4
        Width = 17
        Height = 43
        Hint = #1052#1080#1085#1091#1090#1099
        Max = 59
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Wrap = True
        OnClick = UpDown1Click
      end
      object UpDown2: TUpDown
        Left = 66
        Top = 4
        Width = 17
        Height = 43
        Hint = #1063#1072#1089#1099
        Max = 23
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        Wrap = True
        OnClick = UpDown2Click
      end
    end
  end
  object Button1: TButton
    Left = 100
    Top = 160
    Width = 75
    Height = 25
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 32
    Top = 152
  end
end
