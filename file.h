#ifndef FILE_H
#define FILE_H
#include<string>
using namespace std;

class File{
    private:
        string name;
        int count = 0;   
    public:
        File();
        File(string x);
        void setName(string x);
        string getName();
        void setOccurrence(int c);
        void addOccurrence();
        int getOccurrence();

        void printFile();        
};

#endif