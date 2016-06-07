// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "alarm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DateUtils.hpp"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	hour = HourOf(Now());
	minute = MinuteOf(Now());
	if (minute <= 9) {
		Label3->Caption = "0" + IntToStr(minute);
	}
	else
		Label3->Caption = IntToStr(minute);

	if (hour <= 9) {
		Label1->Caption = "0" + IntToStr(hour);
	}
	else
		Label1->Caption = IntToStr(hour);
	Timer1->Interval = 1000;
	Timer1->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button) {
	if (UpDown2->Position <= 9) {
		Label5->Caption = "0" + IntToStr(UpDown2->Position);
	}
	else
		Label5->Caption = IntToStr(UpDown2->Position);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button) {
	if (UpDown1->Position <= 9) {
		Label4->Caption = "0" + IntToStr(UpDown1->Position);
	}
	else
		Label4->Caption = IntToStr(UpDown1->Position);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (!Timer1->Enabled) {
		Timer1->Enabled = true;
	}
	checkbul = 1;
	alarm_h = StrToInt(Label4->Caption);
	alarm_min = StrToInt(Label5->Caption);
	Form1->Visible = false;
	ShowMessage("Будильник установлен на " + IntToStr(alarm_h) + ":" +
		IntToStr(alarm_min));
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	Label2->Visible = !Label2->Visible;

	hour = HourOf(Now());
	minute = MinuteOf(Now());
	if (minute <= 9) {
		Label3->Caption = "0" + IntToStr(minute);
	}
	else
		Label3->Caption = IntToStr(minute);

	if (hour <= 9) {
		Label1->Caption = "0" + IntToStr(hour);
	}
	else
		Label1->Caption = IntToStr(hour);

	if (((minute == alarm_min) && (hour == alarm_h)) && (checkbul != 0)) {

		if (MediaPlayer1->Mode == mpStopped) {
			MediaPlayer1->Play();
		}
		else {
			MediaPlayer1->Open();
			MediaPlayer1->Play();
			Button2->Visible = true;
			Button3->Visible = true;
			Form1->Show();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	MediaPlayer1->FileName = "11.mp3";
	for (int i = 0; i < 7; i++) {
		week[i] = 0;
	}
	checkbul = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender) {
	weekclick(SpeedButton1, 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender) {
	weekclick(SpeedButton2, 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender) {
	weekclick(SpeedButton3, 2);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender) {
	weekclick(SpeedButton4, 3);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender) {
	weekclick(SpeedButton5, 4);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender) {
	weekclick(SpeedButton6, 5);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender) {
	weekclick(SpeedButton7, 6);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::weekclick(TSpeedButton *s, int x) {
	if (week[x] == 0) {
		week[x] = 1;
		s->Font->Color = clRed;
	}
	else {
		week[x] = 0;
		s->Font->Color = clWindowText;
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
    MediaPlayer1->Stop();
	if (alarm_min >= 50) {
		alarm_h++;
		alarm_min %= 10;
	}
	else
		alarm_min += 10;
    Form1->Close();
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	checkbul = 0;
	Form1->Close();
	Button2->Visible = false;
	Button3->Visible = false;
	MediaPlayer1->Stop();
}
//---------------------------------------------------------------------------

