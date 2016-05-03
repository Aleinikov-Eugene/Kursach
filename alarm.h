//---------------------------------------------------------------------------

#ifndef alarmH
#define alarmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	TTimer *Timer1;
	TMediaPlayer *MediaPlayer1;
	void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations
	TDateTime time;
	int hour,minute, alarm_h,alarm_min;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
