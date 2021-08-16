#ifndef DNODE_H
#define DNODE_H

template <class T>

class dnode{ // doubly linked list class
    private:
       T data_field;
       dnode<T>* next;
       dnode<T>* prev;
    public:
        dnode(){
            next = NULL;
            prev = NULL;
        }

        dnode(T& field, dnode<T>* n = 0, dnode<T>* p = 0){
            data_field = field;
            next = n;
            prev = p;
        }

        ~dnode(){
            delete data_field;
            delete this;
        }

        void setData(T data){
            data_field = data;
        }

        void setNext(dnode<T>* dnode){
            next = dnode;
        }
        void setPrev(dnode<T>* dnode){
            prev = dnode;
        }

        T* getData() {
            T* temp = &data_field;
            return temp;
        }

        T getDataField(){
            return data_field;
        }
        
        dnode<T>* getNext(){
            return next;
        }
        dnode<T>* getPrev(){
            return prev;
        }

        void addNode(dnode<T>* x){
            dnode<T>* temp = this;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = x;
            x->prev = temp;
            x->next = NULL;
        }

        void removeNode(){
            (this->prev)->next = next;
            (this->next)->prev = prev;
            delete this;
        }
};

#endif