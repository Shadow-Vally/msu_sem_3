//
// Created by vally on 28.09.24.
//

#ifndef INC_3_SEM_QUEUE_H
#define INC_3_SEM_QUEUE_H

//Enqueue() — вставляет элемент в конец очереди
//Dequeue() — удаляет элемент из начала очереди
//isEmpty() — возвращает значение true, если очередь пуста
//Top() — возвращает первый элемент очереди
//swap() - меняет две позиции в очереди местами

template<typename T>
class queue {
private:
    int len_queue;
    int len_arr;
    T *arr_queue;
    int first;
    int last;
public:
    queue();

    queue(T num);

    queue(const queue &que);

    ~queue();

    void swap(queue &que);

    void swap(int &a, int &b);

    const queue &operator=(const queue &que);

    template<typename X>
    friend const queue<X> &operator+(queue<X> &que1, const queue<X> &que2);

    const queue &operator+=(const queue &que);

    T Top() const;

    inline bool isEmpty() const;

    bool Enqueue(T num);

    T Dequeue();

    int get_len_queue() const;

    template<typename X>
    friend std::string put_to_str(queue<X> &que);

    template<typename X>
    friend void print(queue<X> &que);

    template<typename X>
    friend std::ostream &operator<<(std::ostream &stream, const queue<X> &que);

    template<typename X>
    friend std::istream &operator>>(std::istream &stream, queue<X> &que);

    template<typename X>
    friend bool operator==(queue<X> &que1, const queue<X> &que2);

    template<typename X>
    friend bool operator<=(queue<X> &que1, const queue<X> &que2);

    template<typename X>
    friend bool operator>=(queue<X> &que1, const queue<X> &que2);

    template<typename X>
    friend bool operator!=(queue<X> &que1, const queue<X> &que2);

    template<typename X>
    friend bool operator<(queue<X> &que1, const queue<X> &que2);

    template<typename X>
    friend bool operator>(queue<X> &que1, const queue<X> &que2);


};


template<typename T>
queue<T> &operator<<(queue<T> &que, const T &num);

template<typename T>
queue<T> &operator>>(const T &num, queue<T> &que);

template<typename T>
T &operator>>(queue<T> &que, T &num);

template<typename T>
T &operator<<(T &num, queue<T> &que);


#endif //INC_3_SEM_QUEUE_H
