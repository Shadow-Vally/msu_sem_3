//
// Created by vally on 27.09.24.
//
#include <iostream>
#include "int_queue.h"
#include <string>


//typedef enum {
//    OK,                 // код выполнен без ошибок
//    ERR_IS_EMPTY,   // попытка достать что-то из пустой очереди
//} error;

//#define 1 "en"
//#define -1 "de"
typedef struct {
    const int num;
    std::string comands[15];   // команды для объекта класса
    std::string err;   // код ошибки
    std::string right_out;
} test_case;

std::string comp_test(test_case& test, std::string& res){
    queue que;
    int k=0;
    try {
        for (int i = 0; i < test.num; i++) {
            if (test.comands[i] == "en") {
                k++;
                que.Enqueue(k);
                res += put_to_str(que) + ", ";
            } else if (test.comands[i] == "de") {
                que.Dequeue();
                res += put_to_str(que) + ", ";
            }
        }
    } catch(std::string err){
//        std::cout<<"catch err: "<<err<<std::endl;
        res+= err;
        return err;
    }
    res+= "OK";
    return "OK";
}

int main() {
    // Массив тестовых данных
    test_case tests[] = {
            {5, {"en", "de", "de", "de", "de"}, "ERR_IS_EMPTY",
                    "1, , ERR_IS_EMPTY"},
            {4, {"en", "de", "en", "de"},   "OK",
                    "1, , 2, , OK"},
            {1, {"de"},             "ERR_IS_EMPTY", "ERR_IS_EMPTY"},
            {5, {"en", "en", "en", "de", "de"},  "OK",
                    "1, 1 2, 1 2 3, 2 3, 3, OK"},
            {6, {"en", "en", "de", "en", "en", "en"},             "OK",
                    "1, 1 2, 2, 2 3, 2 3 4, 2 3 4 5, OK"},
            {8, {"en", "en", "de", "en", "de", "en", "de", "en"}, "OK",
                    "1, 1 2, 2, 2 3, 3, 3 4, 4, 4 5, OK"}
    };

    int n = std::size(tests);
    for (int i=0; i<n; i++){
        std::string res;
        std::string err = comp_test(tests[i], res);
        if (res!=tests[i].right_out) {
            std::cout << "test[" << i << "] crashed. res err: " << err << " right err: " << tests[i].err << std::endl;
            std::cout << "received res: " << res << std::endl;
            std::cout << "expected res: " << tests[i].right_out << std::endl<<std::endl;
        }
        else{
            std::cout<<"test["<<i<<"] OK"<<std::endl;
        }
    }

    std::cout << "End of test :)" << std::endl;
    return 0;
}