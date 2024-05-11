//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game0_computer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;

char curr_symbol = 'x';
std::string name;

//---------------------------------------------------------------------------

bool TForm3::is_winner(){
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
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
//  AnsiString player_name = Edit1->Text;
//  std::string name = player_name.c_str();
//  Label5->Text=name.c_str();
  Label3->Text= curr_symbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonClick(TObject *Sender)
{
   TButton* clickedButton = dynamic_cast<TButton*>(Sender);
   clickedButton -> Text=curr_symbol;

   
   if (is_winner()) {
	 Label6->Text="You won";
   }

   if (curr_symbol=='x') {
	  curr_symbol='o';
	  Label3->Text=curr_symbol;
	  Get_computer_move();
   }
   else{
	   curr_symbol = 'x';
   }

   Label3->Text=curr_symbol;
}
//---------------------------------------------------------------------------

void TForm3::Get_computer_move(){
   int randomMove = 1 + std::rand() % 9;
   TButton* selectedButton = nullptr;
   switch (randomMove)
  {
    case 1: selectedButton = Button1; break;
	case 2: selectedButton = Button2; break;
    case 3: selectedButton = Button3; break;
    case 4: selectedButton = Button4; break;
    case 5: selectedButton = Button5; break;
    case 6: selectedButton = Button6; break;
    case 7: selectedButton = Button7; break;
    case 8: selectedButton = Button8; break;
	case 9: selectedButton = Button9; break;

	if (selectedButton && selectedButton->Text.IsEmpty())
  {
	selectedButton->Text = "o";
  }

  if (is_winner()) {
	 Label6->Text="Computer won";
   }

  curr_symbol = 'x';
  
  }
}
