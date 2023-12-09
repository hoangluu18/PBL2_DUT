#pragma once
// doubly linklist
#include <iostream>
#include <stdlib.h>

using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;

    node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    node(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class list
{
protected:
    node<T> *head;
    int size;

public:
    list();
    virtual ~list();
    virtual void insert(T data);
    virtual void remove(T data);
    virtual void print();
    virtual void edit(T data, T newData);
    virtual T *search(string data);
    virtual int getSize();
};

template <class T>
list<T>::list()
{
    this->head = NULL;
    this->size = 0;
}

template <class T>

list<T>::~list()
{
    node<T> *current = this->head;
    node<T> *next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    this->head = NULL;
    this->size = 0;
}

template <class T>

void list<T>::insert(T data)
{
    node<T> *newNode = new node<T>(data);
    if (this->head == NULL)
    {
        this->head = newNode;
    }
    else
    {
        node<T> *current = this->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        current->next->prev = current;
    }
    this->size++;
}

template <class T>
void list<T>::remove(T data)
{
    node<T> *current = this->head;
    node<T> *prev = NULL;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (prev == NULL)
            {
                this->head = current->next;
            }
            else if (current->next != NULL)
            {
                prev->next = current->next;
                current->next->prev = prev;
            }
            else
            {
                prev->next = NULL;
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
void list<T>::print()
{
    node<T> *current = this->head;
    while (current != NULL)
    {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}

template <class T>
void list<T>::edit(T data, T newData)
{
    node<T> *current = this->head;
    while (current != NULL)
    {
        if (current->data == data)
        {

            current->data = newData;
            return;
        }
        current = current->next;
    }
    cout << "not found\n";
}

template <class T>
int list<T>::getSize()
{
    return this->size;
}

template <class T>
T *list<T>::search(string data)
{
    node<T> *current = this->head;

    while (current != NULL)
    {
        if (current->data.getId() == data)
        {
            return &(current->data); // Trả về con trỏ đến đối tượng T nếu tìm thấy
        }
        current = current->next;
    }

    // Trả về nullptr nếu không tìm thấy
    return NULL;
}
