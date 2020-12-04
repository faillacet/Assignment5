#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
using namespace std;

template <class T>              //NOTE TO SELF: template classes are implemented in header file, no cpp file
class GenStack {
private:
    int top;
    int arrSize;
    T* arr;
public:
    GenStack();             //default constructor
    GenStack(int size);     //initilizes with size of stack
    ~GenStack();

    T* doubleSize();         //used to create a larger array in case of stack overflow
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
};

template <class T>
GenStack<T>::GenStack() {
    top = -1;
    arrSize = 5;
    arr = new T[5];            //default size of stack
}

template <class T>
GenStack<T>::GenStack(int size) {
    top =-1;
    arr = new T[size];
    arrSize = size;
}

template <class T>
GenStack<T>::~GenStack() {
    
}

template <class T>
T* GenStack<T>::doubleSize() {
    T* newArr = new T[arrSize*2];
        for (int i =0; i < arrSize; ++i) {
            newArr[i]=arr[i];
        }
    delete arr;
    arrSize=arrSize*2;
    return newArr;
}

template <class T>
void GenStack<T>::push(T data) {
    if (top >= arrSize-1) {
        //cout << "Array is full, stack overflow." << endl;                 //functiom to let stack double in size in this case TODO
        arr = doubleSize();
    }
    arr[++top] = data;
    //cout << data << " pushed to stack." <<endl;
}

template <class T>
T GenStack<T>::pop() {
    if (top < 0) {
        cout << "Stack is empty!"<<endl;
    }
    else {
        T temp = arr[top--];
        //cout << temp << " removed from stack." <<endl;
        return temp;
    }
}

template <class T>
T GenStack<T>::peek() {
    if (top <0) {
       // cout << "Stack is empty!"<<endl;
        return '\0';                            //only applies to this project remove later
    }
    else {
        T temp = arr[top];
        return temp;
    }
}

template <class T>
bool GenStack<T>::isEmpty() {
    return (top<0);                 //returns true if empty
}

#endif