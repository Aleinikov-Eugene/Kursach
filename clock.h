//---------------------------------------------------------------------------

#ifndef clockH
#define clockH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *Stn11;
	TMenuItem *Stn21;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall Stn11Click(TObject *Sender);
	void __fastcall Stn21Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void __fastcall Vector(int x0, int y0, int a, int l);
	void __fastcall FormPaint();
	void __fastcall DrawClock(void);
	void __fastcall NightMode(void);
	void __fastcall StandartMode(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
