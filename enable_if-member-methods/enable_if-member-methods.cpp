#include <type_traits>
#include <iostream>
#include <string>

// C++11 Proof of concept of different implementations of
// member methods for different types of class instances.

// Compile: g++ -std=c++11 ...

template<class T>
struct Foo {
    void bar() {
        if (std::is_same<T,std::string>::value) {
            bar(std::string{});
        } else {
            int i = 0;
            bar(i);
        }
    }
    void bar(std::string) { std::cout << "string impl" << std::endl; }
    void bar(int) { std::cout << "int impl" << std::endl; }

};

auto main() -> int {
    Foo<std::string>    foo_s;
    foo_s.bar();
 
    Foo<int>            foo_i;
    foo_i.bar();
    return 0;
}