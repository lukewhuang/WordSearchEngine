#include<iostream>
#include<cstring>
#include "file.h"
#include "word.h"
using namespace std;

File::File(){
    this->name = "";
    this->count = 0;
}

File::File(string x){
    this->count = 0;
    this->name = x;
}

void File::setName(string x){
    this->name = x;
}

string File::getName(){
    return this->name;
}

void File::setOccurrence(int c){
    this->count = c;
}

void File::addOccurrence(){
    (this->count)++;
}

int File::getOccurrence(){
    return this->count;
}

void File::printFile(){
    cout << this->name << "::" << this->count << endl;
}