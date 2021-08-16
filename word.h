#ifndef WORD_H
#define WORD_H
#include <string>
#include "file.h"
#include "dnode.h"
using namespace std;

class Word{
    dnode<File>* head = new dnode<File>; // head pointer to DLL
    string word;
    int total = 0;

public:
    Word();  
    Word(string x); 

    void insertFile(string x);
    void setWord(string x);
    string getWord();
    
    void printWord();
    dnode<File>* getHead();
};

#endif