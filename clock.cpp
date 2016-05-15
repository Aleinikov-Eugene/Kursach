//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clock.h"
#include "alarm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DateUtils.hpp"
#include "math.h"
TForm3 *Form3;

#define R 75

int x0,y0;
int hour,minute,second;
int r,str;
AnsiString weather_s[28];
int mode = 0;
bool check_mode = false;
int f;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	TDateTime t;

	ClientHeight = (R+30)*2;
	ClientWidth = (R+30)*2;
	x0 = R + 30;
	y0 = R + 30;

	t= Now();

	hour = 90 - HourOf(t)*30-(MinuteOf(Today())/12)*6;
	minute = 90 - MinuteOf(t)*6;
	second = 90 - SecondOf(Today())*6;
	Timer1->Interval = 1000;
	Timer1->Enabled = true;




}
//---------------------------------------------------------------------------
void __fastcall TForm3::Vector(int x0, int y0, int angle, int length)
{
	#define TORAD 0.0174532
	int x,y;
	Canvas->MoveTo(x0,y0);
	x = x0 + length*cos(angle*TORAD);
	y = y0 - length*sin(angle*TORAD);
	Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormPaint()
{
	int x,y;
	int angle;
	int h;
	//TDateTime check;

	TBrushStyle bs;
	TColor pc;
	int pw;

	bs = Canvas->Brush->Style;
	pc = Canvas->Pen->Color;
	pw = Canvas->Pen->Width;

	Canvas->Brush->Style = bsClear;
	Canvas->Pen->Width = 1;

	if (((HourOf(Now())>=22) || (HourOf(Now())<5)) && (!check_mode)) {
		mode = 1;
	}
	if (((HourOf(Now())<22) && (HourOf(Now())>=5)) && (!check_mode)) {
		mode = 0;
	}

   	switch (mode) {
	case 0:
		StandartMode();
		break;
	case 1:
		NightMode();
        break;
    default:
        ;
	}

	angle = 0;
	h = 3;

	//���������
	while (angle < 360)
	{
		x = x0+ R*cos(angle*TORAD);
		y = x0 - R*sin(angle*TORAD);                  //
		Form3->Canvas->MoveTo(x,y);
		if ((angle%30)==0) {
			if (str != 0)//Canvas->Ellipse(x-1,y-1,x+1,y+1);
				Canvas->Rectangle(x-3,y-3,x+3,y+3);
			else
				Canvas->Ellipse(x-3,y-3,x+3,y+3);
			//Canvas->Ellipse(x-2,y-2,x+3,y+3);

            Canvas->MoveTo(x-2,y-2);
            Canvas->LineTo(x+3,y+3);
			//����� �� �������� �������
			x = x0+(R+15)*cos(angle*TORAD);
			y = x0-(R+15)*sin(angle*TORAD);
			Canvas->TextOut(x-5,y-7,IntToStr(h));
			h--;
			if ( h == 0)  {
				h = 12;
			}
		}
		else
		{
			if (str != 0)//Canvas->Ellipse(x-1,y-1,x+1,y+1);
				Canvas->Rectangle(x-1,y-1,x+1,y+1);
			else
				Canvas->Ellipse(x-1,y-1,x+1,y+1);
        }

		angle += 6;
	}
	Canvas->Brush->Style = bs;
	Canvas->Pen->Width = pw;
	Canvas->Pen->Color = pc;

	DrawClock();
}

void __fastcall TForm3::DrawClock(void)
{
	TDateTime t;

	//������� ����������� ������
	Canvas->Pen->Color = Form3->Color;//->clBtnFace;
	Canvas->Pen->Width = 3;

	Vector(x0,y0,hour,R-20);

	Vector (x0,y0,minute,R-15);

	Vector (x0,y0,second,R-7);
	//
	t = Now();
	//����� ��������� �������
	hour = 90 - HourOf(t)*30-(MinuteOf(t)/12)*6;
	minute = 90 - MinuteOf(t)*6;
	second = 90 - SecondOf(t)*6;
	//���������
	if (((HourOf(Now())>=22) || (HourOf(Now())<5)) && (!check_mode)) {
		mode = 1;
	}

	if (((HourOf(Now())<22) && (HourOf(Now())>=5)) && (!check_mode)) {
		mode = 0;
    }

	switch (mode) {
		case 0:
			StandartMode();
			break;
		case 1:
			NightMode();
			break;
    	default:
        ;
	}


	Canvas->Pen->Width = 3;
	Vector(x0,y0,hour,R-20);

	Canvas->Pen->Width = 2;
	Vector(x0,y0,minute,R-15);

	Canvas->Pen->Width = 1;
	Canvas->Pen->Color = clRed;
	Vector(x0,y0,second,R-7);
}
void __fastcall TForm3::NightMode(void)
{
	Canvas->Pen->Color = clWhite;
	Color = clBackground;
	Font->Color = clWhite;
	Canvas->Pen->Color = clWhite;
}

void __fastcall TForm3::StandartMode(void)
{
	Canvas->Pen->Color = clBlack;
	Color = clWhite;
	Font->Color = clBlack;
	Canvas->Pen->Color = clBlack;
}

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	DrawClock();
	FormPaint();

}
//---------------------------------------------------------------------------





void __fastcall TForm3::N11Click(TObject *Sender)
{
 if (CloseQuery()) {
      Close();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	TPoint P;
	P = GetClientOrigin();
	if (Button = mbRight) {
        PopupMenu1->Popup(P.X+X,P.Y+Y);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
	mode = 1;
	check_mode = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm3::N5Click(TObject *Sender)
{
	mode = 0;
    str = 0;
    check_mode = true;
}
//---------------------------------------------------------------------------




void __fastcall TForm3::N9Click(TObject *Sender)
{
	Form1->Show();

}
//---------------------------------------------------------------------------



void __fastcall TForm3::N3Click(TObject *Sender)
{
	AnsiString s;
    weather();
	s = "����������� : ��� "+weather_s[0]+" ��� "+weather_s[7]+"\n�����������:"+weather_s[14]+"\n��������� ���������: "+weather_s[21];
	ShowMessage(s);
	//ShowMessage("������� � ����������! ���� � ��� ���� �����-�� ����, ��� ����� zheniasenno@gmail.com! ������� ������ ����� ������!");
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Stn11Click(TObject *Sender)
{
    str = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Stn21Click(TObject *Sender)
{
	str = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::weather(void)
{
    int outf,j=0;
	AnsiString st,strcopy;
	if (FileExists("meteo.txt")) {
		f = FileOpen("meteo.txt",fmOpenWrite);
	}
	else
	  f = FileCreate("meteo.txt");
	if (f != -1) {
		st = IdHTTP1->Get("http://api.pogoda.com/index.php?api_lang=ru&localidad=13096&affiliate_id=as7tojk239lm");
		FileSeek(f,0,0);
		FileWrite(f,st.c_str(),st.Length());
		FileClose(f);
		if (FileExists("out.txt")) {
			outf = FileOpen("out.txt",fmOpenWrite);
		}
		else
			outf = FileCreate("out.txt");
		for (int i = 0; i < 14; i++,j++) {
			st = st.SubString(st.Pos("forecast")+34,st.Length());
			weather_s[j] = st.SubString(0,st.Pos('"')-1);
			strcopy += st.SubString(0,st.Pos('"')-1);
			strcopy +="\n";
		}
		for	(int i = 0; i<7 ;i++){
			st = st.SubString(st.Pos("forecast")+8,st.Length());
		}
		for(int i =0;i<7;i++,j++){
			st = st.SubString(st.Pos("forecast")+49,st.Length());
			weather_s[j] = st.SubString(0,st.Pos('"')-1);
			strcopy += st.SubString(0,st.Pos('"')-1);
			strcopy +="\n";
		}

		for	(int i = 0; i<7 ;i++){
			st = st.SubString(st.Pos("forecast")+8,st.Length());
		}

		for (int i = 0;i< 7; i++,j++) {
			st = st.SubString(st.Pos("forecast")+34,st.Length());
			weather_s[j] = st.SubString(0,st.Pos('"')-1);
			strcopy += st.SubString(0,st.Pos('"')-1);
			strcopy +="\n";
		}

		FileSeek(outf,0,0);
	   // FileClear(outf);
		FileWrite(outf,strcopy.c_str(),strcopy.Length());
		FileClose(outf);
	}

}
//---------------------------------------------------------------------------







