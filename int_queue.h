//
// Created by vally on 26.09.24.
//

#ifndef INC_3_SEM_INT_QUEUE_H
#define INC_3_SEM_INT_QUEUE_H

//Enqueue() — вставляет элемент в конец очереди
//Dequeue() — удаляет элемент из начала очереди
//isEmpty() — возвращает значение true, если очередь пуста
//Top() — возвращает первый элемент очереди
//swap() - меняет две позиции в очереди местами


class queue {
private:
    int len_queue;
    int len_arr;
    int *arr_queue;
    int first;
    int last;
public:
    queue();

    queue(int num);

    queue(const queue &que);

    ~queue();

    void swap(queue &que);

    void swap(int &a, int &b);

    const queue &operator=(const queue &que);

    friend const queue &operator+(queue &que1, const queue &que2);

    const queue &operator+=(const queue &que);

    int Top() const;

    inline bool isEmpty() const;

    int Enqueue(int num);

    int Dequeue();

    int get_len_queue() const;

    friend std::string put_to_str(queue &que);

    friend void print(queue &que);

    friend std::ostream &operator<<(std::ostream &stream, const queue &que);
    friend std::istream &operator>>(std::istream &stream, queue &que);
    friend bool operator==(queue &que1, const queue &que2);
    friend bool operator<=(queue &que1, const queue &que2);
    friend bool operator>=(queue &que1, const queue &que2);
    friend bool operator!=(queue &que1, const queue &que2);
    friend bool operator<(queue &que1, const queue &que2);
    friend bool operator>(queue &que1, const queue &que2);


    };
queue &operator<<(queue &que, const int &num);
queue &operator>>(const int &num, queue &que);
int &operator>>(queue &que, int& num);
int &operator<<(int& num, queue &que);


#endif //INC_3_SEM_INT_QUEUE_H
