//
// Created by vally on 28.09.24.
//


#include <iostream>
#include "queue.h"
#include <stdexcept>


template<typename T>
queue<T>::queue() {
    len_queue = 0;
    len_arr = 1;
    arr_queue = new T[len_arr];
    first = 0;
    last = 0;
}

template<typename T>
queue<T>::queue(const queue<T>& que) {
    len_queue = que.len_queue;
    len_arr = que.len_arr;
    arr_queue = new T[len_arr];
    for (int i = 0; i < len_arr; i++) {
        arr_queue[i] = que.arr_queue[i];
    }
    first = que.first;
    last = que.last;
}

template<typename T>
queue<T>::~queue() {
    delete[] arr_queue;
}

template<typename T>
void queue<T>::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void queue<T>::swap(queue<T> &que) {
    swap(len_queue, que.len_queue);
    swap(len_arr, que.len_arr);
    T *tmp = arr_queue;
    arr_queue = que.arr_queue;
    que.arr_queue = tmp;
    swap(first, que.first);
    swap(last, que.last);

}

template<typename T>
const queue<T> &queue<T>::operator=(const queue<T> &que) {
    queue<T> tmp(que);
    tmp.swap(*this);
    return *this;
}

template<typename T>
const queue<T> &operator+(queue<T> &que1, const queue<T> &que2) {
    for (int i = 0; i < que2.len_queue; i++) {
        que1.Enqueue(que2.arr_queue[(que2.first + i) % que2.len_arr]);
    }
    return que1;
}

template<typename T>
const queue<T> &queue<T>::operator+=(const queue<T> &que) {
    *this = *this + que;
    return *this;
}

template<typename T>
queue<T>::queue(T num) {
    len_queue = 1;
    len_arr = 1;
    arr_queue = new T[len_arr];
    arr_queue[0] = num;
    first = 0;
    last = 0;
}

template<typename T>
T queue<T>::Top() const {
//    if (isEmpty()) throw std::runtime_error("ERR_IS_EMPTY");
    if (isEmpty()) throw std::string("ERR_IS_EMPTY");
    return arr_queue[first];
}

template<typename T>
inline bool queue<T>::isEmpty() const {
    return len_queue == 0;
}

template<typename T>
bool queue<T>::Enqueue(T num) {
    if (len_queue == len_arr) {
        T *ptr = new T[len_arr * 2];
        for (int i = 0; i < len_queue; i++) {
            ptr[i] = arr_queue[(first + i) % len_arr];
        }
        len_arr *= 2;
//        for (int i = len_queue; i < len_arr; i++) {
//            ptr[i] = 0;
//        }
        delete[] arr_queue;
        arr_queue = ptr;
        first = 0;
        last = len_queue - 1;
    }
    (last += 1) %= len_arr;
    arr_queue[last] = num;
    len_queue += 1;
    return true;
}

template<typename T>
queue<T> &operator<<(queue<T> &que, const T &num) {
    que.Enqueue(num);
    return que;
}

template<typename T>
queue<T> &operator>>(const T &num, queue<T> &que) {
    que.Enqueue(num);
    return que;
}

template<typename T>
T &operator>>(queue<T> &que, T &num) {
    num = que.Dequeue();
    return num;
}

template<typename T>
T &operator<<(T &num, queue<T> &que) {
    num = que.Dequeue();
    return num;
}


template<typename T>
T queue<T>::Dequeue() {
//    if (isEmpty()) throw std::runtime_error("ERR_IS_EMPTY");
    if (isEmpty()) throw std::string("ERR_IS_EMPTY");
//    if (isEmpty()) throw "ERR_IS_EMPTY";
    T tmp = arr_queue[first];
    arr_queue[first] = 0;
    (first += 1) %= len_arr;
    len_queue -= 1;
    return tmp;
}

template<typename T>
int queue<T>::get_len_queue() const {
    return len_queue;
}

template<typename T>
void print(queue<T> &que) {
    for (int i = 0; i < que.len_queue; i++) {
        std::cout << que.arr_queue[(que.first + i) % que.len_arr] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const queue<T> &que) {
    if (que.len_queue == 0) {
        stream << "";
        return stream;
    }
    for (int i = 0; i < que.len_queue; i++) {
        stream << que.arr_queue[(que.first + i) % que.len_arr] << " ";
    }
    stream << std::endl;
    return stream;
}

template<typename T>
std::string put_to_str(queue<T> &que) {
    std::string res;
    if (que.len_queue == 0) return "";
    for (int i = 0; i < que.len_queue - 1; i++) {
        res += std::to_string(que.arr_queue[(que.first + i) % que.len_arr]) + " ";
    }
//    res += std::to_string(que.arr_queue[(que.first+que.len_queue-1) % que.len_arr]);
    res += std::to_string(que.arr_queue[que.last]);
    return res;
}


template<typename T>
std::istream &operator>>(std::istream &stream, queue<T> &que) {
    T num;
    while (stream >> num) {
        num >> que;
    }
    return stream;
}

template<typename T>
bool operator==(queue<T> &que1, const queue<T> &que2) {
    int len = que1.len_queue;
    if (que1.len_queue != que2.len_queue) return false;
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] != que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}

template<typename T>
bool operator<=(queue<T> &que1, const queue<T> &que2) {
    int len = que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] > que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return que1.len_queue <= que2.len_queue;
}

template<typename T>
bool operator>=(queue<T> &que1, const queue<T> &que2) {
    int len = que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] < que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return que1.len_queue >= que2.len_queue;
}

template<typename T>
bool operator!=(queue<T> &que1, const queue<T> &que2) {
    return !(que1 == que2);
}

template<typename T>
bool operator<(queue<T> &que1, const queue<T> &que2) {
    int len = que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] >= que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}

template<typename T>
bool operator>(queue<T> &que1, const queue<T> &que2) {
    int len = que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] <= que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}



