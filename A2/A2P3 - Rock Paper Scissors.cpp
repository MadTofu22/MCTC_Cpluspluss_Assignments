/*  Program: Rock, Paper, Scissors
    Author: Tom Stutler
    Last Date Modified: 2/12/15

    The intent of this program is to have the user play Rock, Paper, Scissors! against the computer. The program will then prompt
    the user if they want to play again. Once the user is done playing the game will display the total win-loss-tie record to the user.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getcompselection();
//The purpose of this function is to use rand() to pick the computers selection and return it to main().

int getuserselection();
//The purpose of this function is to prompt the user for their selection and return it to main().

void playresults(int userParam, int compParam, int& wins, int& loss, int& ties);
//The purpose of this function is to take the user's and comp's selection, determine the winner, then display the results to the user.
//This function will also increment the user's win-loss-tie record accordingly.

void finalresults(int winsParam, int lossParam, int tiesParam);
//The purpose of this function is to display the overall win-loss-tie record to the user when they are done playing.

int main()
{
    //Declare variables.
    int compSelection, userSelection, wins=0, loss=0, ties=0;
    char repeat;

    //Seed rand().
    srand(time(NULL));

    //Display game start statement.
    cout << "It's time to play ROCK, PAPER, SCISSORS!\n";

    //Loop to repeat game until the user says to stop.
    do
    {
        //Get the comp's and user's selections and store to their variables.
        compSelection = getcompselection();
        userSelection = getuserselection();

        //Find and display the results of the game.
        playresults(userSelection, compSelection, wins, loss, ties);

        //Prompt the user to see if they want to play again.
        cout << "\nPlay again? (y or n): ";
        cin >> repeat;

    } while ((repeat == 'y') || (repeat == 'Y'));

    //Display the final results to the user.
    finalresults(wins, loss, ties);

}

int getcompselection()
{
    return rand() % 3 + 1;
}

int getuserselection()
{
    int selection;

    cout << "What is your play?\n"
         << "Paper (1), Rock (2), Scissors (3): ";
    cin >> selection;

    return selection;
}

void playresults(int userParam, int compParam, int& wins, int& loss, int& ties)
{
    //Declare variables.
    int winner;
    string userChoice, compChoice;

    //Determine winner. 1 = comp wins; 2 = user wins; 0 = tie.
    winner = (3 + (compParam - userParam)) % 3;

    //Switch branch to assign word value to userChoice based on userParam.
    switch (userParam)
    {
    case 1:
        userChoice = "paper";
        break;
    case 2:
        userChoice = "rock";
        break;
    case 3:
        userChoice = "scissors";
        break;
    }

    //Switch branch to assign word value to compChoice based on compParam.
    switch (compParam)
    {
    case 1:
        compChoice = "paper";
        break;
    case 2:
        compChoice = "rock";
        break;
    case 3:
        compChoice = "scissors";
        break;
    }

    //Display the user's and comp's choices.
    cout << "You played "
         << userChoice
         << " and I played "
         << compChoice
         << endl;

    //Switch statement to display the appropriate results to the user and adjust the win-loss-tie record accordingly.
    switch (winner)
    {
    case 0:
        ties++;
        cout << "The play was a tie.\n";
        break;
    case 1:
        loss++;
        cout << "I WIN YOU FLESHY SCUM!\n";
        break;
    case 2:
        wins++;
        cout << "You win this round human.\n";
        break;
    }
}

void finalresults(int winsParam, int lossParam, int tiesParam)
{
    cout << "Final results of our match:\n"
         << "You won " << winsParam << " time(s).\n"
         << "I won " << lossParam << "time(s).\n"
         << "There were " << tiesParam << " ties.\n"
         << "Until we play again my mortal friend.\n";
}
