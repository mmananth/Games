#include <iostream>
#include <vector>
#include <cctype>       //convert between lower and upper cases
#include <ctime>        //for time functions
#include <cstring>      //for strcmp
#include <algorithm>    //srand and random_shuffle

using namespace std;



/**
 * 1. Choose a word at random from a list.
 * 2. Create a string of "-" for that word.
 * 3. Initialize a count for guesses from user.
 * 4. Ask user to guess a char.
 * 5. Check if that char is in the string or not.
 *  a. If present, assign char at its proper location in the string. Display updated string to user.
 *  b. If char not present, inform user about wrong guess and increment bad guess count.
 * 6. Keep asking user for a guess until either the word is filled or bad guess count is reached.
 */
 

const int GUESSES = 8;
const int TOTAL_WORDS = 3;


int main()
{
    vector<string> wordList;
    wordList.push_back("PROPER");
    wordList.push_back("MINIMUM");
    wordList.push_back("ATTIRE");

    int userGuessWrongCount = 0;
    int userGuessRemaining = GUESSES;
    char userGuessCurrent;

    srand(static_cast<unsigned int>(time(0)));
    //random_shuffle(wordList.begin(), wordList.end());
    //const string THE_WORD = wordList[0];
    int wordIndex = rand() % 3;
    const string THE_WORD = wordList[wordIndex];
    string targetWord(THE_WORD.size(), '-');

    string userGuessCumulative;

    //Keep getting guesses from user until word is found or guesses allowed are over
    while(userGuessWrongCount < GUESSES)
    {
        //cout << "The word is " << THE_WORD << endl;
        cout << "Enter a char " << endl;
        cin >> userGuessCurrent;
        //cout << "You guessed: " << userGuessCurrent << endl;
        userGuessCurrent = toupper(userGuessCurrent);

        /**
         * static const size_t npos = -1;
         * - npos is a static member constant value with the greatest possible value for an element of type size_t.
         * - This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
         * - As a return value, it is usually used to indicate no matches.
         * - This constant is defined with a value of -1, which because size_t is an unsigned integral type, 
         *                      it is the largest possible representable value for this type.
         */
        if(THE_WORD.find(userGuessCurrent) != string::npos)
        {
            //found a char in the word
            int i = 0;
            while(THE_WORD[i] != '\0')
            {
                if(THE_WORD[i] == userGuessCurrent)
                {
                    targetWord[i] = userGuessCurrent;
                }
                i++;
            }
        }
        else if(userGuessCumulative.find(userGuessCurrent) != string::npos) {
            //found a char that has already been guessed
            cout << "You already guessed " <<  userGuessCurrent << endl;
            userGuessWrongCount++;
        }
        else {
            //New char that has not been guessed yet. Add char to cumulative guess
            userGuessCumulative += userGuessCurrent;
            userGuessWrongCount++;
        }
        
        userGuessRemaining = GUESSES - userGuessWrongCount;

        if(THE_WORD.compare(targetWord) == 0)
        {
            cout << "congrats!! You found the word" << endl;
            cout << "The target word is " << targetWord << endl;
            break;
        }

        cout << "The target word is " << targetWord << endl;
        cout << "Guesses remaining " << userGuessRemaining << endl;

        if(userGuessRemaining == 0) {
            cout << "Game over!! Word is " << THE_WORD << endl;
            break;
        }
    }   
}




