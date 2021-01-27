/*  Program: A3P4 - Tic Tac Toe
    Author: Tom Stutler
    Last Date Modified: 3/19/15

    The intent of this program is to use a class tictactoe that will emulate a game of Tic Tac Toe between two human users,
    or one human versus the computer.
*/

#include <iostream>
//#include <cstdlib>
//#include <ctime>

using namespace std;

class tictactoe
{
public:
    tictactoe() : board() {}
    ///Constructor.
    void clearboard();
    ///Resets a used board to all 0's.
    void showboard();
    ///Displays the current game board to the user.
    void getXmove();
    ///Prompts the user for a row and column they want to put their X on.
    ///This function validates the move is to a position that is not already used.
    void getOmove();
    ///Prompts the user for a row and column they want to put their X on.
    ///This function validates the move is to a position that is not already used.
    //void tictactoe::compOmove();
    ///The computer generates a move for O.
    ///This function validates the move is to a position that is not already used.
    int checkwin();
    ///Checks whether X wins, O wins, if the game is a tie, or still in progress.

private:
    int xRow;
    int xCol;
    int oRow;
    int oCol;
    int board[3][3];
};

int main()
{
    int status;
    char repeat;
    bool gameOn;
    tictactoe game;

    cout << "Time to play Tic Tac Toe!\n\n";

    do {
        game.clearboard();
        game.showboard();

        do {
            game.getXmove();
            game.showboard();
            game.getOmove();
            game.showboard();
            status = game.checkwin();

            switch (status)
            {
            default:
                cout << "ERROR IN MAIN() WITH RETURN FROM tictactoe::checkwin()!!!\n";
                gameOn = false;
                break;
            case 0:
                cout << "The game is a draw...\n";
                gameOn = false;
                break;
            case -1:
                cout << "O has won the game!!!\n";
                gameOn = false;
                break;
            case 1:
                cout << "X has won the game!!!\n";
                gameOn = false;
                break;
            case 2:
                gameOn = true;
                break;
            }
        } while (gameOn == true);

        //Prompt the user if they want to play another game.
        cout << "Would you like to play again? (y or n) ";
        cin >> repeat;
    } while ((repeat == 'y') || (repeat == 'Y'));
}

void tictactoe::showboard()
{
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            if (board[r][c] == -1) {
                cout << "\tO";
            } else if (board[r][c] == 1) {
                cout << "\tX";
            } else {
                cout << "\t-";
            }
        }
        cout << endl;
    }
}
void tictactoe::clearboard()
{
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            board[r][c] = 0;
        }
    }
}
void tictactoe::getXmove()
{
    bool repeat;
    do {
        cout << "Enter X play position (row# column#): ";
        cin >> xRow >> xCol;


        if ((xRow>0) && (xRow<4) && (xCol>0) && (xCol<4)){
            if (board[xRow-1][xCol-1] == 0) {
                board[xRow-1][xCol-1] = 1;
                repeat = false;
            }else{
                cout << "The space is not available. Please pick another move.\n";
                repeat = true;
            }
        } else {
            cout << "Please enter a valid input.\n";
            repeat = true;
        }
    } while (repeat == true);
}

void tictactoe::getOmove()
{
    bool repeat;
    do {
        cout << "Enter O play position (row# column#): ";
        cin >> oRow >> oCol;

        if ((oRow>0) && (oRow<4) && (oCol>0) && (oCol<4)){
            if (board[oRow-1][oCol-1] == 0) {
                board[oRow-1][oCol-1] = 1;
                repeat = false;
            }else{
                cout << "The space is not available. Please pick another move.\n";
                repeat = true;
            }
        } else {
            cout << "Please enter a valid input.\n";
            repeat = true;
        }
    } while (repeat == true);
}

int tictactoe::checkwin()
{
    int line;

    //Check if the game is still in progress.
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            if (board[r][c] == 0){
                return 2;
            }
        }
    }
    //Check each row for a win.
    for(int r=0; r<3; r++){
        line = 0;
        for (int c=0; c<3; c++){
            line += board[r][c];
            if (line == 3) {
                return 1;
            } else if (line == -3) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}
