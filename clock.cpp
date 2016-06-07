// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clock.h"
#include "alarm.h"
#include "option.h"
#include "weather.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DateUtils.hpp"
#include "math.h"
TForm3 *Form3;

#define R 75
#define INDENT 30
int R1 = R;
int x0, y0;
int hour, minute, second;
int r, str;
int mode = 0;
bool check_mode = false;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
	TDateTime t;

	ClientHeight = (R1 + INDENT) * 2;
	ClientWidth = (R1 + INDENT) * 2;
	x0 = R1 + INDENT;
	y0 = R1 + INDENT;

	t = Now();

	hour = 90 - HourOf(t) * INDENT - (MinuteOf(Today()) / 12) * 6;
	minute = 90 - MinuteOf(t) * 6;
	second = 90 - SecondOf(Today()) * 6;
	Timer1->Interval = 1000;
	Timer1->Enabled = true;

}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Vector(int x0, int y0, int angle, int length) {
#define TORAD 0.0174532
	int x, y;
	Canvas->MoveTo(x0, y0);
	x = x0 + length * cos(angle * TORAD);
	y = y0 - length * sin(angle * TORAD);
	Canvas->LineTo(x, y);
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::FormPaint() {
	int x, y;
	int angle;
	int h;
	// TDateTime check;

	TBrushStyle bs;
	TColor pc;
	int pw;

	bs = Canvas->Brush->Style;
	pc = Canvas->Pen->Color;
	pw = Canvas->Pen->Width;

	Canvas->Brush->Style = bsClear;
	Canvas->Pen->Width = 1;

	if (((HourOf(Now()) >= 22) || (HourOf(Now()) < 5)) && (!check_mode)) {
		mode = 1;
	}
	if (((HourOf(Now()) < 22) && (HourOf(Now()) >= 5)) && (!check_mode)) {
		mode = 0;
	}

	switch (mode) {
	case 0:
		StandartMode();
		break;
	case 1:
		NightMode();
		break;
	default: ;
	}

	angle = 0;
	h = 3;

	// циферблат
	while (angle < 360) {
		x = x0 + R1 * cos(angle * TORAD);
		y = x0 - R1 * sin(angle * TORAD); //
		Form3->Canvas->MoveTo(x, y);
		if ((angle % INDENT) == 0) {
			if (str != 0) // Canvas->Ellipse(x-1,y-1,x+1,y+1);
					Canvas->Rectangle(x - 3, y - 3, x + 3, y + 3);
			else
				Canvas->Ellipse(x - 3, y - 3, x + 3, y + 3);
			// Canvas->Ellipse(x-2,y-2,x+3,y+3);

			Canvas->MoveTo(x - 2, y - 2);
			Canvas->LineTo(x + 3, y + 3);
			// цифры по большому радиусу
			x = x0 + (R1 + 15) * cos(angle * TORAD);
			y = x0 - (R1 + 15) * sin(angle * TORAD);
			Canvas->TextOut(x - 5, y - 7, IntToStr(h));
			h--;
			if (h == 0) {
				h = 12;
			}
		}
		else {
			if (str != 0) // Canvas->Ellipse(x-1,y-1,x+1,y+1);
					Canvas->Rectangle(x - 1, y - 1, x + 1, y + 1);
			else
				Canvas->Ellipse(x - 1, y - 1, x + 1, y + 1);
		}

		angle += 6;
	}
	Canvas->Brush->Style = bs;
	Canvas->Pen->Width = pw;
	Canvas->Pen->Color = pc;

	DrawClock();
}

void __fastcall TForm3::DrawClock(void) {
	TDateTime t;

	// стуреть изображение срелок
	Canvas->Pen->Color = Form3->Color; // ->clBtnFace;
	Canvas->Pen->Width = 3;

	Vector(x0, y0, hour, R1 - 20);

	Vector(x0, y0, minute, R1 - 15);

	Vector(x0, y0, second, R1 - 7);
	//
	t = Now();
	// новое положение стрелок
	hour = 90 - HourOf(t) * 30 - (MinuteOf(t) / 12) * 6;
	minute = 90 - MinuteOf(t) * 6;
	second = 90 - SecondOf(t) * 6;
	// рисование
	if (((HourOf(Now()) >= 22) || (HourOf(Now()) < 5)) && (!check_mode)) {
		mode = 1;
	}

	if (((HourOf(Now()) < 22) && (HourOf(Now()) >= 5)) && (!check_mode)) {
		mode = 0;
	}

	switch (mode) {
	case 0:
		StandartMode();
		break;
	case 1:
		NightMode();
		break;
	default: ;
	}

	Canvas->Pen->Width = 3;
	Vector(x0, y0, hour, R1 - 20);

	Canvas->Pen->Width = 2;
	Vector(x0, y0, minute, R1 - 15);

	Canvas->Pen->Width = 1;
	Canvas->Pen->Color = clRed;
	Vector(x0, y0, second, R1 - 7);
}

void __fastcall TForm3::NightMode(void) {
	Canvas->Pen->Color = clWhite;
	Color = clBackground;
	Font->Color = clWhite;
	Canvas->Pen->Color = clWhite;
}

void __fastcall TForm3::StandartMode(void) {
	Canvas->Pen->Color = clBlack;
	Color = clWhite;
	Font->Color = clBlack;
	Canvas->Pen->Color = clBlack;
}

void __fastcall TForm3::Timer1Timer(TObject *Sender) {
	DrawClock();
	FormPaint();
	R1 = Form2->TrackBar1->Position;
	ClientHeight = (R1 + INDENT) * 2;
	ClientWidth = (R1 + INDENT) * 2;
	x0 = R1 + INDENT;
	y0 = R1 + INDENT;

}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N11Click(TObject *Sender) {
	if (CloseQuery()) {
		Close();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	TPoint P;
	P = GetClientOrigin();
	if (Button = mbRight) {
		PopupMenu1->Popup(P.X + X, P.Y + Y);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender) {
	mode = 1;
	check_mode = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N5Click(TObject *Sender) {
	mode = 0;
	str = 0;
	check_mode = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N9Click(TObject *Sender) {
	Form1->Show();

}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N3Click(TObject *Sender) {

	Form4->weather();
	Form4->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Stn11Click(TObject *Sender) {
	str = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Stn21Click(TObject *Sender) {
	str = 1;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N10Click(TObject *Sender) {
	if (Form1->checkbul != 0) {
		Form1->checkbul = 0;
		ShowMessage("Будильник удален");
	}
	else
		ShowMessage("Будильник не установлен");

}
// ---------------------------------------------------------------------------

void __fastcall TForm3::N7Click(TObject *Sender) {
	Form2->Show();
}
// ---------------------------------------------------------------------------



