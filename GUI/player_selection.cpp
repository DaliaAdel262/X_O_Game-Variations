//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "player_selection.h"
#include "game0_computer.h"
#include "game0_friend.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  TForm3 *NewForm3 = new TForm3(this);


  NewForm3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{

  TForm4 *NewForm4 = new TForm4(this);


  NewForm4->Show();
}
//---------------------------------------------------------------------------

