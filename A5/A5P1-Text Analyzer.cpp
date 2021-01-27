/*	Program: A5P1-Text Analyzer
	Author: Tom Stutler
	Last Date Modified: 5/7/2015

	The intent of this program is to take a passage from a text file,
	analyze it, then output the analysis to a new file.
*/

#include <iostream>
#include <fstream>

using namespace std;

string get_inFile(ifstream& fin);
int count_Words(ifstream& fin);
void count_searchWord(ofstream& fout, string* arrayParam, string wordParam, int sizeParam);
string* analyze_Text(ifstream& fin, ofstream& fout, int wordCount, float& small, float& large);
void list_shortWords(ofstream& fout, string *arrayParam, int sizeParam, float wordParam);
void list_longWords(ofstream& fout, string *arrayParam, int sizeParam, float wordParam);

int main()
{
    string userInFile, userOutFile, searchWord, *wordsArray;
    int sel, totalCount, searchCount;
    float smallest, largest;
    ofstream outFile;
    ifstream inFile;

    cout << "Enter output file name: ";
    getline(cin, userOutFile);
    outFile.open(userOutFile.c_str());
    if (outFile.fail()) {
        cout << "Opening " << userOutFile << " failed.\n"
             << "Please restart the program and try again.\n";
    }

    do
    {
        cout << "\nSelect an option:\n"
             << "\t1 - Enter input file name\n"
             << "\t2 - Determine word statistics\n"
             << "\t3 - List shortest words\n"
             << "\t4 - List longest words\n"
             << "\t5 - Search for a word\n"
             << "\t6 - Exit\n";

        cin >> sel;
        cin.ignore();

        switch (sel)
        {
        case 1:
            userInFile = get_inFile(inFile);
            totalCount = count_Words(inFile);
            break;

        case 2:
            cout << "\nFilename: " << userInFile << endl;
            outFile << "\nFilename: " << userInFile << endl;
            wordsArray = analyze_Text(inFile, outFile, totalCount, smallest, largest);
            break;

        case 3:
            cout << "\nFilename: " << userInFile << endl;
            outFile << "\nFilename: " << userInFile << endl;
            list_shortWords(outFile, wordsArray, totalCount, smallest);
            break;

        case 4:
            cout << "\nFilename: " << userInFile << endl;
            outFile << "\nFilename: " << userInFile << endl;
            list_longWords(outFile, wordsArray, totalCount, largest);
            break;

        case 5:
            cout << "\nFilename: " << userInFile << endl;
            cout << "\nEnter word to find in file: ";
            cin >> searchWord;
            count_searchWord(outFile, wordsArray, searchWord, totalCount);
            break;

        case 6:
            cout << "Thank you, come again!\n";
            break;

        default:
            cout << "Invalid entry, try again.\n";
            break;
        }
    } while (sel!=6);
}

string get_inFile(ifstream& fin)
{
    string fileName;

    if (fin.is_open()) {
        fin.close();
    }

    cout << "Enter input file name: ";
    getline(cin, fileName);
    cout << "Filename entered: " << fileName << endl;
    fin.open(fileName.c_str());

    if (fin.fail()) {
        cout << "Input file openeing failed in get_inFile\n"
             << "File name: " << fileName << endl
             << "Please exit the program and try again.\n";
    } else {
        return fileName;
    }
}

int count_Words(ifstream& fin)
{
    int count=0;
    string word;

    fin >> word;

    do
    {
        if (word!="\n" && word!=" ") {
            count++;
        }
        fin >> word;

    } while (!fin.eof());

    return count;
}

void count_searchWord(ofstream& fout, string* arrayParam, string wordParam, int sizeParam)
{
    int count=0;

    for (int i=0; i<sizeParam; i++) {
        if (*(arrayParam+i) == wordParam) {
            count++;
        }
    }

    cout << "Search word: " << wordParam << endl
         << "This word appears " << count << " time(s) in the file.\n";

    fout << "Search word: " << wordParam << endl
         << "This word appears " << count << " time(s) in the file.\n";
}

string* analyze_Text(ifstream& fin, ofstream& fout, int wordCount, float& small, float& large)
{
    int index=0, punctCount=0, charCount=0;
    float avg=0;
    string word, *temp = new string[wordCount];

    if (fin.is_open()) {

        fin.clear();
        fin.seekg(0);

        fin >> word;
        small = word.length();
        large = word.length();

        do
        {
            if (word!="\n") {

                //Checks each word for leading/trailing punctuation,
                //then counts and removes it.
                while (ispunct(word[0]) || ispunct(word[word.length()-1]))
                {
                    if (ispunct(word[0])) {
                        word.erase(word.begin());
                        punctCount++;
                    }
                    if (ispunct(word[word.length()-1])) {
                        word.erase(word.end()-1);
                        punctCount++;
                    }
                }

                charCount += word.length();

                //Checks each word if it's the smallest.
                if (small>word.length()) {
                    small = word.length();
                }
                //Checks each word if it's the largest.
                if (large<word.length()) {
                    large = word.length();
                }

                //Adds the word to the array.
                *(temp+index) = word;
                index++;
            }
            fin >> word;

        } while(!fin.eof());

        avg = static_cast<float>(charCount)/static_cast<float>(wordCount);

        cout << "\nTotal number of words = " << wordCount
             << "\nAverage word length = " << avg << " characters."
             << "\nTotal number of word characters = " << charCount
             << "\nTotal number of punctuation characters = " << punctCount
             << "\nShortest word length = " << small
             << "\nLongest word length = " << large << endl;

        fout << "\nTotal number of words = " << wordCount
             << "\nAverage word length = " << avg << " characters."
             << "\nTotal number of word characters = " << charCount
             << "\nTotal number of punctuation characters = " << punctCount
             << "\nShortest word length = " << small
             << "\nLongest word length = " << large << endl;

        return temp;

    } else {
        cout << "No input file currently open.\n";
        delete [] temp;
    }
}

void list_shortWords(ofstream& fout, string *arrayParam, int sizeParam, float wordParam)
{
    string currWord;

    cout << "Shortest words in file:\n";
    fout << "Shortest words in file:\n";

    for (int i=0; i<sizeParam; i++) {
        currWord = *(arrayParam+i);
        if (currWord.length()==wordParam) {
            cout << currWord << endl;
            fout << currWord << endl;
        }
    }
}

void list_longWords(ofstream& fout, string *arrayParam, int sizeParam, float wordParam)
{
    string currWord;

    cout << "Longest words in file:\n";
    fout << "Longest words in file:\n";

    for (int i=0; i<sizeParam; i++) {
        currWord = *(arrayParam+i);
        if (currWord.length()==wordParam) {
            cout << currWord << endl;
            fout << currWord << endl;
        }
    }
}
