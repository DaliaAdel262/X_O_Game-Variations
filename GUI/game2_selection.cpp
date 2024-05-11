//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game2_selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm6 *Form6;

char curr_symbol='x';
int n_moves=0;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
  Label2->Text=curr_symbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::ButtonClick(TObject *Sender)
{
   TButton* clickedButton = dynamic_cast<TButton*>(Sender);
   clickedButton -> Text=curr_symbol;

   n_moves++;

   if (is_draw()) {
	  Label4->Text="Draw!";
   }

   if (is_winner()) {
	 if (curr_symbol=='o') {
	   Label4->Text="O won";
	 }
	 else if (curr_symbol=='x') {
		Label4->Text="X won";
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
 bool TForm6::is_winner(){
	TButton* board[42];
	board[0] = Button1;
	board[1] = Button2;
	board[2] = Button3;
	board[3] = Button4;
	board[4] = Button5;
	board[5] = Button6;
	board[6] = Button7;
	board[7] = Button8;
	board[8] = Button9;
	board[9] = Button10;
	board[10] = Button11;
	board[11] = Button12;
	board[12] = Button13;
	board[13] = Button14;
	board[14]  = Button15;
	board[15] = Button16;
	board[16] = Button17;
	board[17] = Button18;
	board[18]  = Button19;
	board[19] = Button20;
	board[20] = Button21;
	board[21] = Button22;
	board[22] = Button23;
	board[23] = Button24;
	board[24] = Button25;
	board[25] = Button26;
	board[26] = Button27;
	board[27] = Button28;
	board[28] = Button29;
	board[29] = Button30;
	board[30] = Button31;
	board[31] = Button32;
	board[32] = Button33;
	board[33] = Button34;
	board[34] = Button35;
	board[35] = Button36;
	board[36] = Button37;
	board[37] = Button38;
	board[38] = Button39;
	board[39] = Button40;
	board[40] = Button41;
	board[41] = Button42;


		for (int j = 0; j <= 35; j+=7) {
		for (int i = 0; i < 5; i++) {
		   if (!board[i+j]->Text.IsEmpty() && board[i+j]->Text == board[i+j+1]->Text && board[i+j+2]->Text == board[i+j+1]->Text
		   && board[i+j+3]->Text==board[i+j+1]->Text){
					return true;
				}
		}

		}


		for (int i = 0; i < 7; i++) {
		for (int j = 0; j <= 27; j+=7) {
				if (!board[i+j]->Text.IsEmpty() && board[i+j]->Text == board[i+j+5]->Text  && board[i+j+10]->Text == board[i+j+5]->Text
				&& board[i+j+15]->Text==board[i+j+5]->Text ){
					return true;
				}
		}
		}


		for (int j = 0; j <= 14; j+=7) {
		for (int i = 0; i < 6; i++) {
				if (!board[i+j]->Text.IsEmpty() && board[i+j]->Text ==  board[i + j + 8]->Text   && board[i +j + 16]->Text == board[i + j + 8]->Text
				&& board[i+j+24]->Text==board[i+j+8]->Text  ){
					return true;
				}
		}
		}

		for (int j = 6; j <= 20; j+=7) {
		for (int i = 0; i < 6 ; i++) {
				if (!board[j-i]->Text.IsEmpty() && board[j-i]->Text == board[(j-i) + 6]->Text  && board[(j-i)+12]->Text == board[(j-i) + 6]->Text
				&& board[(j-i)+18]->Text==board[(j-i) + 6]->Text ){
					return true;
				}
		}
		}

        return false;

}
//---------------------------------------------------------------------------
bool TForm6::is_draw(){
  return (n_moves==42 && !is_winner());
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button43Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

