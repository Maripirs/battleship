#ifndef ARR_H
#define ARR_H

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
};
#include "arr.cpp"
#endif