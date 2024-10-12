#include <iostream>
#include "int_queue.h"

int main() {
    queue A(10);
    std::cout<< A.get_len_queue()<<std::endl;
    print(A);

    A.Enqueue(11);
    std::cout<< A.get_len_queue()<<std::endl;
    print(A);

    int a = A.Dequeue();
    std::cout<<a<<std::endl;
    std::cout<< A.get_len_queue()<<std::endl;
    print(A);

    A.Enqueue(12);
    std::cout<< A.get_len_queue()<<std::endl;
    print(A);

    A.Enqueue(13);
    std::cout<< A.get_len_queue()<<std::endl;
    print(A);
    std::string res = put_to_str(A);
    std::cout << res << std::endl;

    std::cin>>A;
    print(A);

    14>>A;
    print(A);
    A<<15;
    print(A);
    int num = num<<A;
    std::cout << num << std::endl;
    print(A);
    A>>num;
    std::cout << num << std::endl;
    std::cout << A << std::endl;

    std::cout << "new que" << std::endl;
    queue que;
    queue que2;
    (3>>(2>>(1>>que)));
    std::cout <<"que: " << que;
//    1>>que2;
//    3>>2>>1>>que2; //не работает, выводит хрень
    que2<<1<<2<<3;
    std::cout << "que2: " << que2;
    std::cout << "que2: " << put_to_str(que2)<<std::endl;
    print(que2);

    std::cout<< "que==que2? "<< (que==que2) <<std::endl;
    std::cout<< "A==que2? "<< (A==que2) <<std::endl;
    std::cout<< "A>que2? "<< (A>=que2) <<std::endl;
    que2<<4;
    std::cout << "que2: " << que2;
    std::cout<< "que<=que2? "<< (que<=que2) <<std::endl;
    std::cout<< "que2<=que? "<< (que2<=que) <<std::endl;



    std::cout << "End of test 0." << std::endl;
    return 0;
}
