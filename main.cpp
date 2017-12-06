//Author Willy Iparraguirre
#include <iostream>
#include "hangman.h"
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <istream>
using namespace std;

char again;
char display();
void prompt();
char getResponse(char& a);
void correctOrWrong(const string& a, char& b,int& c);

int main()
{
 do
 {
    const int WRONG_MAX = 5; //attempt limit
    vector<string> words; //created a vector called words to hold the words to guess.
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
    random_shuffle(words.begin(), words.end());//<algorithm> Rearranges the elements in the range (first, last) randomly.
    const string WORDS_TO_GUESS = words[0];//word to guess
    int misses = 0; //counts the wrong guesses
    string exposed = " ";//letters already guessed

    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"$                                                           $"<<endl; 
    cout<<"$  Welcome to Hangman! May the odds be ever in your favor.  $"<<endl;
    cout<<"$                                                           $"<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
   
  while(misses < WRONG_MAX)
   {
    cout<<"You have "<<(WRONG_MAX -misses)<<" guesses left."<<endl;
    cout<<"Here is the word you have to guess: ";
    cout<<display()<<endl;
    char response;
    prompt();
    getResponse(response);
    response = toupper(response);//makes the character which was guessed uppercase.
   
    while(exposed.find(response) != string::npos)//searches the string for the first occurence of the sequence specified, string::npos goes until it reaches the end of the string.
    {
     cout<<"You have already guessed this letter."<<endl;
    }
    correctOrWrong(WORDS_TO_GUESS, response, misses);//function that checks to see if the letter guessed is in the word or not.
   }

   if(misses == WRONG_MAX)
   {
    cout<<"GAME OVER!! YOU'VE BEEN HANGED!!"<<endl;
   }
   else
   {
    cout<<"CONGRATULATIONS!! YOU GUESSED CORRECTLY"<<endl;
   }
 
   cout<<"The word was "<<WORDS_TO_GUESS<<endl;//displays the word the user had to guess.

   cout<<"Would you like to play again?(Enter Y or N)"<<endl;
   cin>>again;
 }
 while(again == 'Y' || again == 'y');
 {
  cout<<"Thanks for playing, goodbye."<<endl;
 }
return 0; 
}


char display()
{
 const string WORDS_TO_GUESS;
  for(int i=0; i < WORDS_TO_GUESS.length(); i++)
   {
    WORDS_TO_GUESS[i] = '*';
   }
   return WORDS_TO_GUESS[i];
}


void prompt()
{
 cout<<"Enter your guess"<<endl;
}

char getResponse(char& a)
{
 cin>>a;
 return a;
}


void correctOrWrong(const string& a, char& b, int& d)
{
 if(a.find(b) != string::npos)
 {
  cout<<"Congrats! "<<b<<" is a letter in the word you're trying to guess."<<endl;
 }
 else
 {
  cout<<"Sorry, but "<<b<<" is not a letter in the word you're trying to guess."<<endl;
  d++;
 }
}

