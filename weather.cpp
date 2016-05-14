//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "weather.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int f;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{

	AnsiString st;
	if (FileExists("meteo.txt")) {
	f = FileOpen("meteo.txt",fmOpenWrite);
	}
	else
	  f = FileCreate("meteo.txt");
	if (f != -1) {
	st = IdHTTP1->Get("http://api.pogoda.com/index.php?api_lang=ru&localidad=13096&affiliate_id=as7tojk239lm");
	FileSeek(f,0,2);
	FileWrite(f,st.c_str(),st.Length());
	FileClose(f);
	}

}
//---------------------------------------------------------------------------

