//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game_selection.h"
#include "game0_friend.h"
#include "game1_selection.h"
#include "game2_selection.h"
#include "game3_selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

  TForm4 *NewForm = new TForm4(this);

  NewForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  TForm5*NewForm = new TForm5(this);
  NewForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  TForm6 *NewForm = new TForm6(this);
  NewForm->Show();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  TForm7 *NewForm = new TForm7(this);
  NewForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

