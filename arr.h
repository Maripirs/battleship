// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose:
// Description:

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

    // puprose: Access element at a given index.
    // input:
    //     int: Index to use.
    // output: Templated element from the array at the given index.

    T& getAtIndex(int);
    int getNum();
    int getMax();

    // puprose: Add element at the end of the array.
    // input:
    //     T: Templated element to add.
    // output: None. All updates done directly on the array.

    void addToEnd(T);

    // purpose: Replaces element at given index.
    // input:
    //     int: Index to replace
    //     T: Templated element to add.
    // output: None. All updates done directly on the array.

    void replaceAtIndex(int, T);

    // purpose: Removes element at given index.
    // input:
    //     int: Index of element to replace
    // output: None. All updates done directly on the array.

    void removeAtIndex(int);

    // purpose: Returns the array to an empty state.
    // input: None.
    // output: None. All updates done directly on the array.

    void clearArr();
    ~Arr();

    // purpose: Asignment operator overload.
    // input:
    //     Arr: Object to copy.
    // output: The updated version of the array.

    Arr& operator=(const Arr&);
    friend ostream& operator<<(ostream&, const Arr&);

    // purpose: Add element at the end of the array.
    // input:
    //     T: Templated element to add.
    // output: None. All updates done directly on the array.

    void operator+(const T&);
};
#include "arr.cpp"
#endif