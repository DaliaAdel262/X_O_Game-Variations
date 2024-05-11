//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game1_selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm5 *Form5;

char curr_symbol = 'x';
int n_moves=0;

//---------------------------------------------------------------------------

bool TForm5::is_winner(){
  if (!Button2->Text.IsEmpty() && Button2->Text==Button3->Text && Button3->Text==Button4->Text) {
	 return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text==Button3->Text && Button3->Text==Button6->Text) {
	 return true;
  }
  if (!Button6->Text.IsEmpty() && Button6->Text==Button7->Text && Button7->Text==Button8->Text) {
	 return true;
  }
  if (!Button5->Text.IsEmpty() && Button5->Text==Button6->Text && Button6->Text==Button7->Text) {
	 return true;
  }
  if (!Button9->Text.IsEmpty() && Button9->Text==Button5->Text && Button5->Text==Button6->Text) {
	 return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text==Button4->Text && Button4->Text==Button8->Text) {
	 return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text==Button2->Text && Button2->Text==Button9->Text) {
	 return true;
  }

  return false;
}

//---------------------------------------------------------------------------
bool TForm5::is_draw(){
  return (n_moves==9 && !is_winner());
}
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
  Label2->Text= curr_symbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::ButtonClick(TObject *Sender)
{
   TButton* clickedButton = dynamic_cast<TButton*>(Sender);
   clickedButton -> Text=curr_symbol;

   n_moves++;

   if (is_draw()) {
	  Label3->Text="Draw!";
   }

   if (is_winner()) {
	 if (curr_symbol=='o') {
	   Label3->Text="O won";
	 }
	 else if (curr_symbol=='x') {
		Label3->Text="X won";
	 }
   }
   if (curr_symbol=='x') {
	  curr_symbol='o';
   }
   else{
	   curr_symbol = 'x';
   }

   Label2->Text=curr_symbol;

}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button10Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

