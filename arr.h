//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: 
//Description: 

#ifndef ARR_H
#define ARR_H
#include <iostream>
using namespace std;
template <class T>
class Arr {
    T* arr;
    int num;
    int max;

   public:
    Arr();
    Arr(T*, int, int);
    Arr(const Arr&);

    T* getArr();
    T& getAtIndex(int);
    int getNum();
    int getMax();

    void addToEnd(T);
    void replaceAtIndex(int, T);
    void removeAtIndex(int);
    void clearArr();
    ~Arr();
    Arr& operator=(const Arr&);
    friend ostream& operator<<(ostream&, const Arr&);
    void operator+(const T&);
};
#include "arr.cpp"
#endif