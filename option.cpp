//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "option.h"
#include "clock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
int __fastcall TForm2::R()
{
    return 0;
}
void __fastcall TForm2::TrackBar1Change(TObject *Sender)
{
 	Form3->StandartMode();
}
//---------------------------------------------------------------------------
