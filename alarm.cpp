//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "alarm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DateUtils.hpp"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	hour = HourOf(Now());
	minute = MinuteOf(Now());
	if (minute<=9) {
		Label3->Caption ="0"+IntToStr(minute);
	}
	else
		Label3->Caption =IntToStr(minute);

	if (hour<=9) {
		Label1->Caption ="0"+IntToStr(hour);
	}
	else
		Label1->Caption =IntToStr(hour);
	Timer1->Interval = 1000;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
    Label4->Caption = IntToStr(UpDown2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
	if (UpDown1->Position<=9) {
		Label5->Caption = "0"+IntToStr(UpDown1->Position);
	}
	else
        Label5->Caption =IntToStr(UpDown1->Position);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (!Timer1->Enabled) {
        Timer1->Enabled = true;
	}
	alarm_h=UpDown2->Position-1;
	alarm_min = UpDown1->Position-1;
    Form1->Visible=false;
	ShowMessage("Будильник установлен на "+IntToStr(alarm_h)+":"+IntToStr(alarm_min));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Label2->Visible = !Label2->Visible;

    hour = HourOf(Now());
	minute = MinuteOf(Now());
	if (minute<=9) {
		Label3->Caption ="0"+IntToStr(minute);
	}
	else
		Label3->Caption =IntToStr(minute);

	if (hour<=9) {
		Label1->Caption ="0"+IntToStr(hour);
	}
	else
		Label1->Caption =IntToStr(hour);

	if ((minute ==alarm_min) && (hour == alarm_h))  {
		//MediaPlayer1->FileName = "D:\Учеба\2 семестр\Программирование\Курсач\25\WavLibraryNet_Sound15279.mp3";
		//MediaPlayer1->Open();
		Timer1->Enabled = false;
        ShowMessage ("Будильник!!!");
	}
}
//---------------------------------------------------------------------------
