#include <type_traits>
#include <iostream>
#include <string>

// C++11 Proof of concept of different implementations of
// member methods for different types of class instances.

// Compile: g++ -std=c++11 ...

struct string_tag {};
struct int_tag {};

template<class T>
struct Foo {
    void bar() {
        if (std::is_same<T,std::string>::value) {
            bar(string_tag{});
        } else {
            bar(int_tag{});
        }
    }
    void bar(string_tag) { std::cout << "string impl" << std::endl; }
    void bar(int_tag)    { std::cout << "int impl" << std::endl; }

};

auto main() -> int {
    Foo<std::string>    foo_s;
    foo_s.bar();
 
    Foo<int>            foo_i;
    foo_i.bar();
    return 0;
}