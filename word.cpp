#include <iostream>
#include "file.h"
#include "word.h"
#include "dnode.h"
using namespace std;

Word::Word(){
    head = new dnode<File>;
    word = "";
    total = 0;
}

Word::Word(string x){
    word = x;
    head = new dnode<File>;
    total = 0;
}

void Word::insertFile(string x){
    dnode<File>* temp = head;

    while(temp != nullptr){
        if (temp->getData()->getName() == x){
            temp->getData()->addOccurrence();
            total++;
            return;
        }
        temp = temp->getNext();
    }
    if (total == 0){
        File newfile (x);
        head->setData(newfile);
        head->getData()->addOccurrence();
        
        total++;
    }   
    else{
        File newfile (x);
        dnode<File>* pointer = new dnode<File>;
        pointer->setData(newfile);
        pointer->getData()->addOccurrence();
        head->addNode(pointer);
        total++;
    }
}

void Word::setWord(string x){
    this->word = x;
}

string Word::getWord(){
    return word;
}

void Word::printWord(){
    cout << "Total Count: " << total << endl;
    dnode<File>* temp = head;
    while(temp != nullptr){
        temp->getData()->printFile();
        temp = temp->getNext();
    }
}

dnode<File>* Word::getHead() { 
  return this->head;
}