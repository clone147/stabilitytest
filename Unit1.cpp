// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#include "System.IOUtils.hpp"
#include <System.Threading.hpp>

TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}



// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	Timer1->Interval = 8000;            // 60000
	std::unique_ptr<TStringList>A(new TStringList);
	try
	{
	if (WebBrowser1->URL == "")
		WebBrowser1->URL = "file://" + IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "animation.html";
	if (MediaPlayer1->FileName == IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "benchmark.mp4")
		MediaPlayer1->FileName = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "benchmark2.mp4";
	else
		MediaPlayer1->FileName = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "benchmark.mp4";
    } catch (...) {}
	Timer2->Enabled = true;
	VCounter++;

	if (LastDSMarks == "") {
		if (FileExists("/sdcard/dsmark")) {

			A->LoadFromFile("/sdcard/dsmark");
			if (A->Count > 0)
				LastDSMarks = A->Strings[0];
		}
	}


	A->Text = IntToStr(VCounter);
	try {
		A->SaveToFile("/sdcard/dsmark");
	}
	catch (...) {
	}
	A->Free();

	if (FileExists("/sys/class/thermal/thermal_zone0/temp")) {

		try {
			A->LoadFromFile("/sys/class/thermal/thermal_zone0/temp");
		}
		catch (...) {
		}
		TempString = A->Text;
		Label3->Text = "CPU Temperature: " + TempString.Delete(2, 3);

	}
	if (LastDSMarks != "")
		Label2->Text = "Loops: " + IntToStr(VCounter) + " (last : " + LastDSMarks + ")";
	else
		Label2->Text = "Loops: " + IntToStr(VCounter);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender) {
	Timer2->Enabled = false;
	if (MediaPlayer1->Media != NULL) {

		MediaPlayer1->Play();
	}

}
// ---------------------------------------------------------------------------

String CleanNonStandard(String What) {
	String Result;
	for (int i = 0; i <= What.Length() - 1; i++) {
		if ((What[i] == 0x30) || (What[i] == 0x31) || (What[i] == 0x32))
			Result = Result + What[i];
	}

	return Result;
}

String StringReplaceAll(String source, String wwhat, String wwith) {
	String result = source;
	if (wwhat == "")
		return source;
	if (wwhat == wwith)
		return source;

	return StringReplace(source, wwhat, wwith, TReplaceFlags() << rfReplaceAll);
}

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar, TShiftState Shift) {
	if (Key == 0x0D) {
		KeyString = "";
		Key = 0x20;

	}
	else {
		KeyString = KeyString + KeyChar;
		Label1->Text = StringReplaceAll(KeyString, sLineBreak, "");
	}
}
// ---------------------------------------------------------------------------
