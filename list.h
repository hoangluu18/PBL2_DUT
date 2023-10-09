#include <iostream>
#include <stdlib.h>

using namespace std; 
template <class T>
struct node{
      T data;
      node<T>*next;
      node(){
        this->data = 0;
        this->next = NULL;
      }
      node(T data){
        this->data=data;
        this->next = NULL;
      }
   };

template <class T>
class list
{


    private:

   node<T>*head;
    int size ;

   public:
    list();
   virtual ~list();
   virtual void insert(T data);
   virtual  void remove(T data);
   virtual void print();
   virtual  void edit(T data);
   virtual T* search(int data);
    virtual int getSize();
};

template <class T>
list<T>::list(){
  this->head = NULL;
  this->size = 0;
}

template <class T>

list<T>::~list(){
    cout<<"huy list\n";
    node<T> *current = this->head;
    node<T> *next;
    while(current!=NULL){
        next = current->next;
        delete current;
        current = next;
    }
    this->head = NULL;
    this->size = 0;
}

template <class T>

void list<T>::insert(T data){
    node<T> *newNode = new node<T>(data);
    if(this->head == NULL){
        this->head = newNode;
    }
    else{
        node<T> *current = this->head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    this->size++;
}

template <class T>
void list<T>::remove(T data){
    node<T> *current = this->head;
    node<T> *prev = NULL;
    while(current!=NULL){
        if(current->data == data){ 
            if(prev == NULL){
                this->head = current->next;
            }
            else{
                prev->next = current->next;
            }
            delete current;
            this->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <class T>
void list<T>::print(){
    node<T> *current = this->head;
    while(current!=NULL){
        cout<<current->data;
        current = current->next;
    }
    cout<<endl;
}

template <class T>
void list<T>::edit(T data){ 
  node<T> *current = this->head;
  while(current != NULL){
     if(current->data == data){
          T temp;
          cin>>temp;
          current->data = temp;
          return;
     }
     current = current->next;
  }
  cout<<"not found\n";
}


template <class T>
int list<T>::getSize(){
    return this->size;
}


template <class T>
T* list<T>::search(int data) {
    node<T>* current = this->head;

    while (current != nullptr) {
        if (current->data.getId() == data) {
            return &(current->data);  // Trả về con trỏ đến đối tượng T nếu tìm thấy
        }
        current = current->next;
    }

    // Trả về nullptr nếu không tìm thấy
    return NULL;
}