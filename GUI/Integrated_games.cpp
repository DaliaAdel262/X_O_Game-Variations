//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("..\..\..\final_gui\game_selection.cpp", Form1);
USEFORM("..\..\..\final_gui\player_selection.cpp", Form2);
USEFORM("..\..\..\final_gui\game3_selection.cpp", Form7);
USEFORM("..\..\..\final_gui\game0_computer.cpp", Form3);
USEFORM("..\..\..\final_gui\game0_friend.cpp", Form4);
USEFORM("..\..\..\final_gui\game1_selection.cpp", Form5);
USEFORM("..\..\..\final_gui\game2_selection.cpp", Form6);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
