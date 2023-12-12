
template <class T>
Arr<T>::Arr() {
    arr = new T[1];
    num = 0;
    max = 1;
}
template <class T>
Arr<T>::Arr(T* a, int c, int m) {
    num = c;
    max = m;
    arr = new T[max];
    for (int i = 0; i < num; i++) {
        arr[i] = a[i];
    }
}
template <class T>
Arr<T>::Arr(const Arr& rhs) {
    num = rhs.num;
    max = rhs.max;
    arr = new T[max];
    for (int i = 0; i < num; i++) {
        arr[i] = rhs.arr[i];
    }
}

template <class T>
T* Arr<T>::getArr() {
    return arr;
}
template <class T>
T& Arr<T>::getAtIndex(int idx) {
    return arr[idx];
}
template <class T>
int Arr<T>::getNum() {
    return num;
}
template <class T>
int Arr<T>::getMax() {
    return max;
}

template <class T>
void Arr<T>::addToEnd(T item) {
    if (num == max) {
        max = max + 1;
        T* temp = new T[max];
        for (int i = 0; i < num; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    arr[num] = item;
    num++;
}
template <class T>
void Arr<T>::replaceAtIndex(int idx, T item) {
    arr[idx] = item;
}
template <class T>
void Arr<T>::removeAtIndex(int idx) {
    T* temp = new T[max];
    for (int i = 0; i < idx; i++) {

        temp[i] = arr[i];
    }
    for (int i = idx; i < num ; i++) {

        temp[i] = arr[i+1];
    }
    delete[] arr;
    arr = temp;
    num--;
}
template <class T>
void Arr<T>::clearArr() {
    delete[] arr;
    arr = new T[1];
    num = 0;
    max = 1;
}
template <class T>
Arr<T>::~Arr() {
    delete[] arr;
}

template <class T>
Arr<T>& Arr<T>::operator=(const Arr& rhs) {
    num = rhs.num;
    max = rhs.max;
    arr = new T[max];
    for (int i = 0; i < num; i++) {
        arr[i] = rhs.arr[i];
    }
    return *this;
}
template <class T>
void Arr<T>::operator+(const T& newElement){
    addToEnd(newElement);
}