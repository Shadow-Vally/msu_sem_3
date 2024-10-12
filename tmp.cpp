//
// Created by vally on 28.09.24.
//
#include <iostream>

template <typename T>
class Person {
public:
    Person(std::string name) : name{name} { }
    void setId(T value) { id = value;}
    void print() const
    {
        std::cout << "Id: " << id << "\tName: " << name << std::endl;
    }
private:
    T id;
    std::string name;
};
int main()
{
    Person<std::string> bob{"Bob"};    // T - std::string
    bob.setId("id1345");
    bob.print();    // Id: id1345  Name: Bob

    Person<int> tom{"Tom"};      // T - int
    tom.setId(23456);
    tom.print();    // Id: 23456    Name: Tom
}