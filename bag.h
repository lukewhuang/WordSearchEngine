#ifndef BAG_H
#define BAG_H
#include <string>
#include "word.h"
#include "dnode.h"

using namespace std;


class Bag{
  
    private:
        // Below is an array of Word objects.
        // You must store new objects or modify existing objects in this array.
        dnode<Word>* head = new dnode<Word>;

        // ADD NEW MEMBER VARIABLES HERE IF NEEDED
  
    public:
        // the below function is used to print the contents of
        // container array (declared at line 40)  in the format <WORD::COUNT>

        // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED

        void insertWord(Word x, string file);
        void printCount(string a, int threshold);
        void printUnion(string a, string b);
       bool dup(string a, dnode<string>* list);
};

#endif