#include "bag.h"
#include "word.h"
#include "file.h"
#include "dnode.h"
#include<iostream>
#include<string>

using namespace std;

void Bag::insertWord(Word x, string file){
    dnode<Word>* dahyun = head;
    while(dahyun != nullptr){
        Word temp = (dahyun->getData())->getWord();

        if (temp.getWord().compare(x.getWord()) == 0){
            dahyun->getData()->insertFile(file);
            return;
        }
        dahyun = dahyun->getNext(); 
    }

    Word newWord = Word(x.getWord());
    dnode<Word>* tzuyu = new dnode<Word>;
    tzuyu->setData(newWord);
    tzuyu->getData()->insertFile(file);
    head->addNode(tzuyu);
    return;
}

void Bag::printCount(string a, int threshold){
    dnode<Word>* temp = head;
    while(temp != nullptr){
        Word current = temp->getData()->getWord();
        if (current.getWord().compare(a) == 0){
            dnode<File>* tempFile;
            tempFile = temp->getData()->getHead();
            while(tempFile != nullptr){
                if (tempFile->getData()->getOccurrence() >= threshold){
                    cout << tempFile->getData()->getName() << endl;
                }
                tempFile = tempFile->getNext();
            }
            return;
        } 
        temp = temp->getNext();
    }
    cout << "Word not found in database" << endl;
    return;
}

void Bag::printUnion(string a, string b){
    dnode<Word>* temp1 = head; // will hold result for word a found
    dnode<Word>* temp2 = head; // will hold result for word b found

    while (temp1 != nullptr){  
        string temp = temp1->getData()->getWord();
        if (temp.compare(a) == 0){ 
            break;  
        } 
        temp1 = temp1->getNext();
        if (temp1 == nullptr){
            break;
        }
    }

    while (temp2 != nullptr){
        string temp = temp2->getData()->getWord();
        
        if (temp.compare(b) == 0){ 
            break;  
        } 
        temp2 = temp2->getNext();
        if (temp2 == nullptr){
            break;
        }
    }

    // ------

    dnode<string>* output = new dnode<string>;

    if (temp1 != nullptr && temp2 != nullptr){
        dnode<File>* match1 = temp1->getData()->getHead();
        dnode<File>* match2 = temp2->getData()->getHead();

        string filename1 = match1->getData()->getName();
        output->setData(filename1);
        match1 = match1->getNext();

        while (match1 != nullptr){
            dnode<string>* insert = new dnode<string>;
            insert->setData(match1->getData()->getName());
            output->addNode(insert);
            match1 = match1->getNext();
        }

        while (match2 != nullptr){
            dnode<string>* insert = new dnode<string>;
            string newfilename = match2->getData()->getName();
            if(!dup(newfilename, output)){
                insert->setData(newfilename);
                output->addNode(insert);
            }
            match2 = match2->getNext();
        }
    }

    if (temp1 != nullptr){
        if (temp2 == nullptr){
            dnode<File>* match1 = temp1->getData()->getHead();
            string filename1 = match1->getData()->getName();
            output->setData(filename1);
            match1 = match1->getNext();
            while (match1 != nullptr){
                dnode<string>* insert = new dnode<string>;
                insert->setData(match1->getData()->getName());
                output->addNode(insert);
                match1 = match1->getNext();
            }
        }
    } else{
        if (temp2 != nullptr){
            dnode<File>* match2 = temp2->getData()->getHead();
            output->setData(match2->getData()->getName());
            match2 = match2->getNext();
            while (match2 != nullptr){
                dnode<string>* insert = new dnode<string>;
                string newfilename = match2->getData()->getName();
                if(!dup(newfilename, output)){
                    insert->setData(newfilename);
                    output->addNode(insert);
                }
                match2 = match2->getNext();
            }
        }
    }

    if (temp1 == nullptr && temp2 == nullptr){
        cout << "Word not found in database" << endl;
    }else{
        while (output != nullptr){
            cout << output->getDataField() << endl;
            output = output->getNext();
        }
    }
    
    return; 
}


bool Bag::dup(string a, dnode<string>* list) {
    dnode<string>* search = list; 

    while(search != nullptr) {  
        if (search->getDataField().compare(a) == 0){
            return true;
        }
        search = search->getNext();
    }
    return false;
}

