//Author Willy Iparraguirre
#ifndef _HANGMAN_H_
#define _HANGMAN_H_
#include <string>
#include <vector>

using namespace std;

class hangman
{
    private:
      string firstName;  
      char response;

    public:
      void setName(string);
      char getResponse(char& a);

};

#endif



