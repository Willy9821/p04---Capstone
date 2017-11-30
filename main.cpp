//Author Willy Iparraguirre
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

char getGuess(string prompt);
void yesOrNo();

int main()
{
 do
 {
    char again;
    const int WRONG_MAX = 5; //attempt limit
    vector<string> words; //add vectors in here
    //adding words here
    words.push_back("ALABAMA");
    words.push_back("ALASKA");
    words.push_back("ARIZONA");
    words.push_back("ARKANSAS");
    words.push_back("CALIFORNIA");
    words.push_back("COLORADO");
    words.push_back("CONNECTICUT");
    words.push_back("DELAWARE");
    words.push_back("FLORIDA");
    words.push_back("GEORGIA");
    words.push_back("HAWAII");
    words.push_back("IDAHO");
    words.push_back("ILLINOIS");
    words.push_back("INDIANA");
    words.push_back("IOWA");
    words.push_back("KANSAS");
    words.push_back("KENTUCKY");
    words.push_back("LOUISIANA");
    words.push_back("MAINE");
    words.push_back("MARYLAND");
    words.push_back("MASSACHUSETTS");
    words.push_back("MICHIGAN");
    words.push_back("MINNESOTA");
    words.push_back("MISSISSIPPI");
    words.push_back("MISSOURI");
    words.push_back("MONTANA");
    words.push_back("NEBRASKA");
    words.push_back("NEVADA");
    words.push_back("NEW HAMPSHIRE");
    words.push_back("NEW JERSEY");
    words.push_back("NEW MEXICO");
    words.push_back("NEW YORK");
    words.push_back("NORTH CAROLINA");
    words.push_back("NORTH DAKOTA");
    words.push_back("OHIO");
    words.push_back("OKLAHOMA");
    words.push_back("OREGON");
    words.push_back("PENNSYLVANIA");
    words.push_back("RHODE ISLAND");
    words.push_back("SOUTH CAROLINA");
    words.push_back("SOUTH DAKOTA");
    words.push_back("TENNESSEE");
    words.push_back("TEXAS");
    words.push_back("UTAH");
    words.push_back("VERMONT");
    words.push_back("VIRGINIA");
    words.push_back("WASHINGTON");
    words.push_back("WEST VIRGINIA");
    words.push_back("WISCONSIN");
    words.push_back("WYOMING");
    
    srand(time(0));
    random_shuffle(words.begin(), words.end());//shuffles out words in random way
    const string WORDS_TO_GUESS = words[0];//word to guess
    string soFar(WORDS_TO_GUESS.size(), '_');//created string filled with '_'
    string usedLetters = ""; //shows which were already guessed
    int wrong = 0; //counts the wrong guesses

    cout<<"Welcome to Hangman! May the odds be ever in your favor"<<endl;
    //add main game loop
    while((wrong < WRONG_MAX) && (soFar != WORD_TO_GUESS))
    {
     cout<<"You have "<<(WRONG_MAX - wrong)<<" guesses left."<<endl;
     cout<<"These are the letters you have already used: "<<usedLetters<<endl.
     cout<<"So far, this is what you're working with: "<<soFar<<endl;
     
     guess = getGuess("Enter your guess: ");
     guess = toupper(guess);//converts lowercase letter to uppercase

     while(usedLetters.find(guess) != string::npos)//while entered something already used, keeps looping
     {
      cout<<"You've already guessed: "<<guess<<endl;
      guess = getGuess("Enter your guess: "
      guess = toupper(guess);
     }

     usedLetters += guess;

     if (WORD_TO_GUESS.find(guess) != string::npos)
     {
      cout<<"That's it! "<<guess<<" is in the word"<<endl;
      //update soFar to include new letters guessed
      for(int i = 0;i < WORD_TO_GUESS.length(); i++)
      {
       if(WORD_TO_GUESS[i] == guess)
       { 
        soFar[i] = guess;
       } 
       else
       {
        cout<<"Sorry, but "<<guess<<" is not in the word."<<endl;
        wrong++;
       }
     if(wrong == WRONG_MAX)
     {
      cout<<"Game over. You've been hanged!"<<endl;
     }
     else
     {
      cout<<"Congratulations, you got the word"<<endl;
     } 
     
     cout<<"The word was: "<<WORD_TO_GUESS<<endl;
    } 
   }
  } 
   cout<<"Would you like to play again? Enter y or n"<<endl;
   cin>>again; 
 }
while(again == 'y' || again == 'Y');

 cout<<"Thanks for playing, goodbye"<<endl;

return 0;
}

char getGuess(string prompt)
{
 char character;
 cout<<prompt;
 cin>>character;
