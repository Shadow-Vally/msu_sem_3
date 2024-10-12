//
// Created by vally on 28.09.24.
//
#include <iostream>
#include "queue.h"
#include "queue.hpp"

struct Person {
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &stream, const Person &pers);

std::ostream &operator<<(std::ostream &stream, const Person &pers) {
    stream << pers.name << " " << pers.age << " ";
    return stream;
}


int main() {
    queue A(10);
    std::cout << A.get_len_queue() << std::endl;
    print(A);

    A.Enqueue(11);
    std::cout << A.get_len_queue() << std::endl;
    print(A);

    int a = A.Dequeue();
    std::cout << a << std::endl;
    std::cout << A.get_len_queue() << std::endl;
    print(A);

    A.Dequeue();
    std::cout << A.get_len_queue() << std::endl;
    print(A);
    std::cout<<"A is empty? - "<<A.isEmpty()<<std::endl;

    A.Enqueue(12);
    std::cout << A.get_len_queue() << std::endl;
    print(A);

    A.Enqueue(13);
    std::cout << A.get_len_queue() << std::endl;
    print(A);
    std::string res = put_to_str(A);
    std::cout << res << std::endl;

    std::cin >> A;
    print(A);

    14 >> A;
    print(A);
    A << 15;
    print(A);
    int num = num << A;
    std::cout << num << std::endl;
    print(A);
    A >> num;
    std::cout << num << std::endl;
    std::cout << A << std::endl;

    std::cout << "new que" << std::endl;
    queue<int> que;
    queue<int> que2;
    (3 >> (2 >> (1 >> que)));
    std::cout << "que: " << que;
//    1>>que2;
//    3>>2>>1>>que2; //не работает, выводит хрень
    que2 << 1 << 2 << 3;
    std::cout << "que2: " << que2;
    std::cout << "que2: " << put_to_str(que2) << std::endl;
    print(que2);

    std::cout << "que==que2? " << (que == que2) << std::endl;
    std::cout << "A==que2? " << (A == que2) << std::endl;
    std::cout << "A>que2? " << (A >= que2) << std::endl;
    que2 << 4;
    std::cout << "que2: " << que2;
    std::cout << "que<=que2? " << (que <= que2) << std::endl;
    std::cout << "que2<=que? " << (que2 <= que) << std::endl;
    que2 = que;
    std::cout << "que: " << que;
    std::cout << "que2: " << que2;
    que2 << 4;
    std::cout << "que: " << que;
    std::cout << "que2: " << que2;
    queue que3(que);
    std::cout << "que: " << que;
    std::cout << "que3: " << que3;

    que3 = que + que2;
    std::cout << "que3: " << que3;


    queue<Person> People;
    Person Sasha = {"Sasha", 19};
    Person Lesha = {"Lesha", 19};
    Person Anna = {"Anna", 50};
    People << Sasha;

    std::cout << "People: " << People;
    People << Sasha;
    People << Lesha;
    People << Sasha;
    People << Anna;
    People << Lesha;
    People << Sasha;
    std::cout << "People: " << People;


    std::cout << "End of test 0." << std::endl;
    return 0;
}
