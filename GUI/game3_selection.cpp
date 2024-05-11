//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "game3_selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm7 *Form7;

char curr_symbol='x';
int n_moves=0;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
  Label2->Text=curr_symbol;
}
//---------------------------------------------------------------------------

std::string TForm7::is_winner(){
	TButton* board[25];
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
    int X_wins=0;
    int O_wins=0;

		for (int j = 0; j <= 20; j+=5) {
		for (int i = 0; i < 3; i++) {
		   if (board[i+j]->Text == 'x' && board[i+j+1]->Text == 'x' && board[i+j+2]->Text == 'x'){
					X_wins++;
				}
				else if(board[i+j]->Text == 'o' && board[i+j+1]->Text == 'o' && board[i+j+2]->Text == 'o' ){
					O_wins++;
				}
		}
				
		}


		for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= 14; j+=5) {
				if (board[i+j]->Text == 'x' && board[i+j+5]->Text == 'x' && board[i+j+10]->Text == 'x'){
					X_wins++;
				}
				else if(board[i+j]->Text == 'o' && board[i+j+5]->Text == 'o' && board[i+j+10]->Text == 'o' ){
					O_wins++;
				}
		}
		}


		for (int j = 0; j <= 10; j+=5) {
		for (int i = 0; i < 3; i++) {
				if (board[i+j]->Text == 'x' && board[i + j + 6]->Text == 'x' && board[i +j + 12]->Text == 'x' ){
					X_wins++;
				}
				else if(board[i+j]->Text == 'o' && board[i + j + 6]->Text == 'o' && board[i + j + 12]->Text == 'o'){
					O_wins++;
				}
		}
		}

		for (int j = 4; j <= 14; j+=5) {
		for (int i = 0; i < 3 ; i++) {
				if (board[j-i]->Text == 'x' && board[(j-i) + 4]->Text == 'x' && board[(j-i)+8]->Text == 'x' ){
					X_wins++;
				}
				else if(board[j-i]->Text == 'o' && board[(j-i) + 4]->Text == 'o' && board[(j-i)+8]->Text == 'o'){
					O_wins++;
				}
		}
		}


        if (X_wins>O_wins){
			return ("x");
        }
        else if (O_wins>X_wins){
			return ("o");
        }
		else if (X_wins==O_wins){
            return ("Draw");
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ButtonClick(TObject *Sender)
{
   TButton* clickedButton = dynamic_cast<TButton*>(Sender);
   clickedButton -> Text=curr_symbol;

   n_moves++;

   if (n_moves==24) {
      if (is_winner()=="x") {
	 Label4->Text="Player x won";
	}
	else if (is_winner()=="o") {
	 Label4->Text="Player o won";
	} else if (is_winner()=="Draw"){
	  Label4->Text="Draw!";
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
void __fastcall TForm7::Button3Click(TObject *Sender){
}

void __fastcall TForm7::Button26Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

