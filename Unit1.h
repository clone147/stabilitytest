//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Media.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <memory>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMediaPlayer *MediaPlayer1;
	TMediaPlayerControl *MediaPlayerControl1;
	TTimer *Timer1;
	TLabel *Label2;
	TWebBrowser *WebBrowser1;
	TLabel *Label3;
	TMemo *Memo1;
	TLabel *Label4;
	TTimer *Timer2;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
int VCounter;
String KeyString;
String TempString;
String LastDSMarks;

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
