#include <iostream>
#include <string>
#include "SharedPointer.hpp"
#include "WeakPointer.hpp"

class Person {
private:
    std::string name;

public:
    explicit Person(const std::string& n) : name(n) {
        std::cout << "Person constructor: " << name << '\n';
    }

    ~Person() {
        std::cout << "Person destructor: " << name << '\n';
    }

    void sayHello() const {
        std::cout << "Hello, I am " << name << '\n';
    }
};

int main() {
    std::cout << "===== SharedPointer Test =====\n";
    SharedPointer<Person> sp1(new Person("Alice"));
    std::cout << "sp1 use_count = " << sp1.use_count() << '\n';

    {
        SharedPointer<Person> sp2 = sp1;
        std::cout << "After copy:\n";
        std::cout << "sp1 use_count = " << sp1.use_count() << '\n';
        std::cout << "sp2 use_count = " << sp2.use_count() << '\n';

        sp2->sayHello();

        WeakPointer<Person> wp1 = sp1;
        std::cout << "WeakPointer created. sp1 use_count = " << wp1.use_count() << '\n';

        if (!wp1.expired()) {
            SharedPointer<Person> sp3 = wp1.lock();
            std::cout << "Lock success. sp3 use_count = " << sp3.use_count() << '\n';
            sp3->sayHello();
        }
    }

    std::cout << "After inner scope:\n";
    std::cout << "sp1 use_count = " << sp1.use_count() << '\n';

    WeakPointer<Person> wp2 = sp1;
    std::cout << "Before reset, expired = " << (wp2.expired() ? "true" : "false") << '\n';

    sp1.reset();

    std::cout << "After reset sp1:\n";
    std::cout << "wp2 expired = " << (wp2.expired() ? "true" : "false") << '\n';

    SharedPointer<Person> sp4 = wp2.lock();
    if (!sp4) {
        std::cout << "Lock failed because object is already deleted.\n";
    }

    return 0;
}