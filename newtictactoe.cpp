#include <iostream>
using namespace std;
bool checkwinner(char*, char, char);
bool checktie(char*);
void playermove(char*, char);
void board(char*);
void aimove(char*, char);
void cleanboard(char*);
int main () {
     char spaces[9]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
     char player='X';
     char ai='O';
     char again;
     bool running=true;
     while(running) {
          playermove(spaces, player);
          board(spaces);
          if(checkwinner(spaces, player, ai)) {
               cout << "\n\nDo you want to play again?(Y-Yes N-No)\n";
               cin >> again;
               if(again=='n' || again=='N') {
                    running=false;
                    break;
               }
               else{
                    cleanboard(spaces);
                    running=true;
               }
          }
          else if(checktie(spaces)) {
               cout << "\n\nDo you want to play again?(Y-Yes N-No)\n";
               cin >> again;
               if(again=='n' || again=='N') {
                    running=false;
                    break;
               }
               else{
                    cleanboard(spaces);
                    running=true;
               }
          }
          aimove(spaces, ai);
          board(spaces);
          if(checkwinner(spaces, player, ai)) {
               cout << "\n\nDo you want to play again?(Y-Yes N-No)\n";
               cin >> again;
               if(again=='n' || again=='N') {
                    running=false;
                    break;
               }
               else{
                    cleanboard(spaces);
                    running=true;
               }
          }
          else if(checktie(spaces)) {
               cout << "\n\nDo you want to play again?(Y-Yes N-No)\n";
               cin >> again;
               if(again=='n' || again=='N') {
                    running=false;
                    break;
               }
               else{
                    cleanboard(spaces);
                    running=true;
               }
          }
          
     }
     return 0;
}
bool checkwinner(char* spaces, char player, char ai){
     if((spaces[0]!=' ') && (spaces[0]==spaces[1] && spaces[0]==spaces[2])) {
          spaces[0]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[0]!=' ') && (spaces[0]==spaces[3] && spaces[0]==spaces[6])) {
          spaces[0]== player ? cout << "You win!\n" : cout << "You lose!\n";
}
     else if((spaces[0]!=' ') && (spaces[0]==spaces[4] && spaces[0]==spaces[8])) {
          spaces[0]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[1]!=' ') && (spaces[1]==spaces[4] && spaces[1]==spaces[7])) {
          spaces[1]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[2]!=' ') && (spaces[2]==spaces[4] && spaces[2]==spaces[6])) {
          spaces[2]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[2]!=' ') && (spaces[2]==spaces[5] && spaces[2]==spaces[8])) {
          spaces[2]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[3]!=' ') && (spaces[3]==spaces[4] && spaces[3]==spaces[5])) {
          spaces[3]== player ? cout << "You win!\n" : cout << "You lose!\n";
     }
     else if((spaces[6]!=' ') && (spaces[6]==spaces[7] && spaces[6]==spaces[8])) {
          spaces[6]== player ? cout << "You win!\n" : cout << "You lose!\n";
     } 
     }

bool checktie(char* spaces) {
     for(int i=0; i<9; i++) {
          if(spaces[i]==' ') {
               return false;
          }
     }
     cout << "The game is tie.\n";
     return true;
}
void playermove(char* spaces, char player) {
     int number;
     do{ 
          cout << "Which spaces do you wanna choice(1-9)?:\n";
          cin >> number;
          number--;
     if(spaces[number]==' ') {
          spaces[number]=player;
          break;
     }
     else {
          cout << "Which spaces do you wanna choice(1-9)?:\n";
          cin >> number;
     }
     }while((number>=0 && number<=8) || (spaces[number]==' '));
}
void board(char* spaces) {
cout << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[0] << "  |   " << spaces[1] << "  |   " << spaces[2] << "   " << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[3] << "  |   " << spaces[4] << "  |   " << spaces[5] << "   " << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[6] << "  |   " << spaces[7] << "  |   " << spaces[8] << "   " << endl;
    cout << "      |      |      " << endl;
    cout << endl;
}
void aimove(char* spaces, char ai) {
     ai='O';
     char player='X';
     for(int i=0; i<=8; i++) {
          if(spaces[i]==' ') {
               spaces[i]=ai;
               if(checkwinner(spaces, player, ai)) {
                    return;
          }
          spaces[i]=' ';
          }
     }
     for(int i=0; i<=8; i++) {
          if(spaces[i]==' ') {
               spaces[i]=player;
               if(checkwinner(spaces, player, ai)) {
                    spaces[i]=player;
                    return;
          }
          spaces[i]=' ';
          }
     }
     if(spaces[4]==' ') {
          spaces[4]=ai;
          return;
     }
     if(spaces[0]==player && spaces[8]==' ') {
          spaces[8]=ai;
          return;
     }
     if(spaces[2]==player && spaces[6]==' ') {
          spaces[6]=ai;
          return;
     }
     if(spaces[6]==player && spaces[2]==' ') {
          spaces[2]=ai;
          return;
     }
     if(spaces[8]==player && spaces[0]==' ') {
          spaces[0]=ai;
          return;
     }
     for(int i=0; i<=8; i++) {
          if(spaces[i]==' ') {
               spaces[i]=ai;
               return;
          }
     }
     


}
void cleanboard(char* spaces) {
     for(int i=0; i<9; i++) {
          spaces[i]=' ';
     }
}
