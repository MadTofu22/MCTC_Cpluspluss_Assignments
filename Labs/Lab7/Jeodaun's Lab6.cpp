/*	Program: Lab7
	Author: Tom Stutler, Jeodaun Lee
	Last Date Modified: 4/7/15

	The intent of this program
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int getlength(string word);
int main()
{
    int i = 0;
    string words[100];
    string chars[20];
    int wordLength, sum=0; //Sum is assigned here so you can use += in loop later.
    double average = 0;
    cout << "Enter a sentence: ";

    do
    {
        cin >> words[i];
        if (words[i] != "," || words[i] != ";")
        {
            wordLength = words[i].length(); //I assume you are trying to get the length of the word at index i in the array of words.
            sum += wordLength;//Assigned above so you can use += otherwise it tries to add to something that doesn't exist.
        }
        i++;
    }while (words[i-1] != "." && words[i-1] != "!" && words[i-1] != "?"); //use and (&&) instead of or (||) to stop if any of them occur.

    cout << "Number of words = ";

    return 0;
}
