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

    public:
      void setName(string);
      char response;
      char getResponse(char& a);

};

#endif



