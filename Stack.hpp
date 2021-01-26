// Definitions for Stack class as well as stack actions
// Demo code supplied by Prof. Lymar
#pragma once
#define MAX_LENGTH 100
#include <cstdlib>
#include <iostream>

using namespace std;

class StackEmptyException{
private:
    string message;
public:
    StackEmptyException(): message{"Stack is empty"}{cout << message << endl;}
};
class StackFullException{};

template <typename T>
class Stack{
private:
    T* data;
    int top;
    int maxLength;
public:
    Stack():maxLength{MAX_LENGTH}{
        data = new T[maxLength];
        top = -1;
    }
    Stack(int len):maxLength{len}{
        data = new T[maxLength];
        top = -1;
    }
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(T item);
    T Top();
    void Pop();
    ~Stack(){
        try {
            if (!IsEmpty()) delete[]data; throw StackEmptyException();
            Stack();
        }
        catch (StackEmptyException ex1){
            //Stack();
        }
    }
};

template <typename T>
void Stack<T>::MakeEmpty(){
    top = -1;
}

template <typename T>
bool Stack<T>::IsEmpty(){
    return top == -1;
}

template <typename T>
bool Stack<T>::IsFull(){
    return top == maxLength - 1;
}

template <typename T>
void Stack<T>::Push(T item){
    if(IsFull()) throw StackFullException();
    
    data[++top] = item;
}
template <typename T>
T Stack<T>::Top(){
    if (IsEmpty()) throw StackEmptyException();
    return data[top];
    
}

template <typename T>
void Stack<T>::Pop(){
    if (IsEmpty())
        throw StackEmptyException();
    else
        top--;
}
