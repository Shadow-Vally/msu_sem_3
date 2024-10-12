//
// Created by vally on 26.09.24.
//
#include <iostream>
#include "int_queue.h"
#include <stdexcept>

queue::queue() {
    len_queue = 0;
    len_arr = 1;
    arr_queue = new int[len_arr];
    arr_queue[0] = 0;
    first = 0;
    last = 0;
}

queue::queue(const queue &que) {
    len_queue = que.len_queue;
    len_arr = que.len_arr;
    arr_queue = new int[len_arr];
    for (int i = 0; i < len_arr; i++) {
        arr_queue[i] = que.arr_queue[i];
    }
    first = que.first;
    last = que.last;
}

queue::~queue() {
    delete[] arr_queue;
}

void queue::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void queue::swap(queue &que) {
    swap(len_queue, que.len_queue);
    swap(len_arr, que.len_arr);
    int *tmp = arr_queue;
    arr_queue = que.arr_queue;
    que.arr_queue = tmp;
    swap(first, que.first);
    swap(last, que.last);

}

const queue &queue::operator=(const queue &que) {
    queue tmp(que);
    tmp.swap(*this);
    return *this;
}

const queue &operator+(queue &que1, const queue &que2) {
    for (int i = 0; i < que2.len_queue; i++) {
        que1.Enqueue(que2.arr_queue[(que2.first + i) % que2.len_arr]);
    }
    return que1;
}

const queue &queue::operator+=(const queue &que) {
    *this = *this + que;
    return *this;
}


queue::queue(int num) {
    len_queue = 1;
    len_arr = 1;
    arr_queue = new int[len_arr];
    arr_queue[0] = num;
    first = 0;
    last = 0;
}

int queue::Top() const {
//    if (isEmpty()) throw std::runtime_error("ERR_IS_EMPTY");
    if (isEmpty()) throw std::string("ERR_IS_EMPTY");
    return arr_queue[first];
}

inline bool queue::isEmpty() const {
    return len_queue == 0;
}

int queue::Enqueue(int num) {
    if (len_queue == len_arr) {
        int *ptr = new int[len_arr * 2];
        for (int i = 0; i < len_queue; i++) {
            ptr[i] = arr_queue[(first + i) % len_arr];
        }
        len_arr *= 2;
        for (int i = len_queue; i < len_arr; i++) {
            ptr[i] = 0;
        }
        delete[] arr_queue;
        arr_queue = ptr;
        first = 0;
        last = len_queue - 1;
    }
    (last += 1) %= len_arr;
    arr_queue[last] = num;
    len_queue += 1;
    return 1;
}

queue &operator<<(queue &que, const int &num) {
    que.Enqueue(num);
    return que;
}

queue &operator>>(const int &num, queue &que) {
    que.Enqueue(num);
    return que;
}

int &operator>>(queue &que, int &num) {
    num = que.Dequeue();
    return num;
}

int &operator<<(int &num, queue &que) {
    num = que.Dequeue();
    return num;
}


int queue::Dequeue() {
//    if (isEmpty()) throw std::runtime_error("ERR_IS_EMPTY");
    if (isEmpty()) throw std::string("ERR_IS_EMPTY");
//    if (isEmpty()) throw "ERR_IS_EMPTY";
    int bar = arr_queue[first];
    arr_queue[first] = 0;
    (first += 1) %= len_arr;
    len_queue -= 1;
    return bar;
}


int queue::get_len_queue() const {
    return len_queue;
}

void print(queue &que) {
    for (int i = 0; i < que.len_queue; i++) {
        std::cout << que.arr_queue[(que.first + i) % que.len_arr] << " ";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const queue &que) {
    if (que.len_queue == 0) {stream <<""; return stream;}
    for (int i = 0; i < que.len_queue; i++) {
        stream << que.arr_queue[(que.first + i) % que.len_arr] << " ";
    }
    stream << std::endl;
    return stream;
}

std::string put_to_str(queue &que) {
    std::string res;
    if (que.len_queue == 0) return "";
    for (int i = 0; i < que.len_queue - 1; i++) {
        res += std::to_string(que.arr_queue[(que.first + i) % que.len_arr]) + " ";
    }
//    res += std::to_string(que.arr_queue[(que.first+que.len_queue-1) % que.len_arr]);
    res += std::to_string(que.arr_queue[que.last]);
    return res;
}


std::istream &operator>>(std::istream &stream, queue &que) {
    int num;
    while (stream >> num) {
        num >> que;
    }
    return stream;
}

bool operator==(queue &que1, const queue &que2) {
    int len=que1.len_queue;
    if (que1.len_queue != que2.len_queue) return false;
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] != que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}

bool operator<=(queue &que1, const queue &que2){
    int len=que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] > que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return que1.len_queue<=que2.len_queue;
}

bool operator>=(queue &que1, const queue &que2){
    int len=que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] < que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return que1.len_queue>=que2.len_queue;
}

bool operator!=(queue &que1, const queue &que2){
    return !(que1==que2);
}

bool operator<(queue &que1, const queue &que2){
    int len=que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] >= que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}

bool operator>(queue &que1, const queue &que2){
    int len=que1.len_queue;
    if (que1.len_queue != que2.len_queue) len = std::min(que1.len_queue, que2.len_queue);
    for (int i = 0; i < len; i++) {
        if (que1.arr_queue[(que1.first + i) % que1.len_arr] <= que2.arr_queue[(que2.first + i) % que2.len_arr])
            return false;
    }
    return true;
}



