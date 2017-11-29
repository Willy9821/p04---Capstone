//Author Willy Iparraguirre
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
 do
 {
    char again;
    const int WRONG_MAX = 5; //attempt limit
    vector<string> words; //add vectors in here
    //adding words here
    words.push_back("Alabama");
    words.push_back("Alaska");
    words.push_back("Arizona");
    words.push_back("Arkansas");
    words.push_back("California");
    words.push_back("Colorado");
    words.push_back("Connecticut");
    words.push_back("Delaware");
    words.push_back("Florida");
    words.push_back("Georgia");
    words.push_back("Hawaii");
    words.push_back("Idaho");
    words.push_back("Illinois");
    words.push_back("Indiana");
    words.push_back("Iowa");
    words.push_back("Kansas");
    words.push_back("Kentucky");
    words.push_back("Louisiana");
    words.push_back("Maine");
    words.push_back("Maryland");
    words.push_back("Massachusetts");
    words.push_back("Michigan");
    words.push_back("Minnesota");
    words.push_back("Mississippi");
    words.push_back("Missouri");
    words.push_back("Montana");
    words.push_back("Nebraska");
    words.push_back("Nevada");
    words.push_back("New Hampshire");
    words.push_back("New Jersey");
    words.push_back("New Mexico");
    words.push_back("New York");
    words.push_back("North Carolina");
    words.push_back("North Dakota");
    words.push_back("Ohio");
    words.push_back("Oklahoma");
    words.push_back("Oregon");
    words.push_back("Pennsylvania");
    words.push_back("Rhose Island");
    words.push_back("South Carolina");
    words.push_back("South Dakota");
    words.push_back("Tennessee");
    words.push_back("Texas");
    words.push_back("Utah");
    words.push_back("Vermont");
    words.push_back("Virginia");
    words.push_back("Washington");
    words.push_back("West Virginia");
    words.push_back("Wisconsin");
    words.push_back("Wyoming");
    
    srand(time(NULL));//seed for random numbers
    random_shuffle(words.begin(), words.end());//shuffles out words in random way
    const string WORDS_TO_GUESS = words[0];
    string soFar(WORDS_TO_GUESS.size(), '_');//created string filled with '_'
    string usedLetters = "";
    int wrong = 0; //counts the wrong letters

    cout<<"Welcome to Hangman!"<<endl;
    //add main game loop
    while((wrong < WRONG_MAX) && (soFar != WORD_TO_GUESS))
    {
     cout<<"You have "<<(WRONG_MAX - wrong)<<" guesses left."<<endl;
     cout<<"You've used this letter: "<<usedLetters<<endl.
     cout<<"So far, the word looks like this: "<<soFar<<endl;
     
     char guess;
     cout<<"Enter your guess: "<<endl;
     cin>>guess;
     guess = toupper(guess);

     while(usedLetters.find(guess) != string::npos)//while entered something already used, keeps looping
     {
      cout<<"You've already guessed: "<<guess<<endl;
      cout<<"Enter your guess: "<<endl;
      cin>> guess;
      guess = toupper(guess);
     }

     usedLetters += guess;
     if (WORD_TO_GUESS.find(guess) != string::npos)
     {
      cout<<"That's it! "<<guess<<" is in the word"<<endl;
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
