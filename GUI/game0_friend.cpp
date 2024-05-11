//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game0_friend.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm4 *Form4;

char curr_symbol = 'x';
int n_moves=0;
//---------------------------------------------------------------------------
bool TForm4::is_winner(){
  if (!Button1->Text.IsEmpty() && Button1->Text==Button2->Text && Button2->Text==Button3->Text) {
	 return true;
  }
  if (!Button6->Text.IsEmpty() && Button6->Text==Button5->Text && Button5->Text==Button4->Text) {
	 return true;
  }
  if (!Button7->Text.IsEmpty() && Button7->Text==Button8->Text && Button8->Text==Button9->Text) {
	 return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text==Button6->Text && Button6->Text==Button7->Text) {
	 return true;
  }
  if (!Button2->Text.IsEmpty() && Button2->Text==Button5->Text && Button5->Text==Button8->Text) {
	 return true;
  }
  if (!Button3->Text.IsEmpty() && Button3->Text==Button4->Text && Button4->Text==Button9->Text) {
	 return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text==Button5->Text && Button5->Text==Button9->Text) {
	 return true;
  }
  if (!Button3->Text.IsEmpty() && Button3->Text==Button5->Text && Button5->Text==Button7->Text) {
	 return true;
  }

  return false;
}

//---------------------------------------------------------------------------
bool TForm4::is_draw(){
  return (n_moves==9 && !is_winner());
}
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
  Label3->Text= curr_symbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ButtonClick(TObject *Sender)
{

   TButton* clickedButton = dynamic_cast<TButton*>(Sender);
   clickedButton -> Text=curr_symbol;

   n_moves++;

   if (is_draw()) {
	 Label6->Text="Draw!";
   }

   if (is_winner()) {
	 if (curr_symbol=='o') {
	   Label6->Text="O won";
	 }
	 else if (curr_symbol=='x') {
		Label6->Text="X won";
	 }
   }

   if (curr_symbol=='x') {
	  curr_symbol='o';
   }
   else{
	   curr_symbol = 'x';
   }



   Label3->Text=curr_symbol;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button10Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

