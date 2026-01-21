#include <iostream>
using namespace std;


bool checkWinner(char* board, char player, char ai);
bool checkTie(char* board);
void playerMove(char* board);
void aiMove(char* board, char ai, char player);
void displayBoard(char* board);
void cleanBoard(char* board);

int main() {
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    char ai = 'O';
    char again;
    bool running = true;

    while (running) {
        displayBoard(board);
        playerMove(board);
        displayBoard(board);

        if (checkWinner(board, player, ai)) {
            cout << "\nDo you want to play again? (Y-Yes N-No): ";
            cin >> again;
            if (again == 'n' || again == 'N') running = false;
            else cleanBoard(board);
            continue;
        }
        if (checkTie(board)) {
            cout << "\nDo you want to play again? (Y-Yes N-No): ";
            cin >> again;
            if (again == 'n' || again == 'N') running = false;
            else cleanBoard(board);
            continue;
        }

        aiMove(board, ai, player);
        displayBoard(board);

        if (checkWinner(board, player, ai)) {
            cout << "\nDo you want to play again? (Y-Yes N-No): ";
            cin >> again;
            if (again == 'n' || again == 'N') running = false;
            else cleanBoard(board);
            continue;
        }
        if (checkTie(board)) {
            cout << "\nDo you want to play again? (Y-Yes N-No): ";
            cin >> again;
            if (again == 'n' || again == 'N') running = false;
            else cleanBoard(board);
            continue;
        }
    }

    return 0;
}


bool checkWinner(char* board, char player, char ai) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8}, 
        {0,4,8},{2,4,6}           
    };

    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] != ' ' &&
            board[wins[i][0]] == board[wins[i][1]] &&
            board[wins[i][0]] == board[wins[i][2]]) {
            board[wins[i][0]] == player ? cout << "You win!\n" : cout << "You lose!\n";
            return true;
        }
    }
    return false;
}


bool checkTie(char* board) {
    for (int i = 0; i < 9; i++)
        if (board[i] == ' ') return false;

    cout << "The game is tie.\n";
    return true;
}


void playerMove(char* board) {
    int move;
    while (true) {
        cout << "Choose a position (1-9): ";
        cin >> move;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number 1-9.\n";
            continue;
        }

        move--; 
        if (move >= 0 && move < 9 && board[move] == ' ') {
            board[move] = 'X';
            break;
        }
        cout << "Invalid move. Try again.\n";
    }
}


void displayBoard(char* board) {
    cout << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    cout << endl;
}


void aiMove(char* board, char ai, char player) {
 
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = ai;
            if (checkWinner(board, player, ai)) return;
            board[i] = ' ';
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = player;
            if (checkWinner(board, player, ai)) {
                board[i] = ai;
                return;
            }
            board[i] = ' ';
        }
    }
    
    if (board[4] == ' ') { board[4] = ai; return; }

    
    int positions[9] = {0,2,6,8,1,3,5,7};
    for (int i = 0; i < 9; i++) {
        if (board[positions[i]] == ' ') {
            board[positions[i]] = ai;
            return;
        }
    }
}


void cleanBoard(char* board) {
    for (int i = 0; i < 9; i++) board[i] = ' ';
}
