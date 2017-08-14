#include <scope_exit>

#include <iostream>
#include <fstream>

struct A {
    A() : x{counter++} {
        std::cout << "A() " << x << " \n";
    }
    ~A() {
        std::cout << "~A() " << x << " \n";
    }

    int x = 0;

    static int counter;
};

int A::counter;

int f()
{
    using namespace std;
    SCOPE_EXIT { cout << "Bye f()\n"; };
    return 0;
}

extern int main(int argc, char *argv[]) {
    (void)argc, (void)argv;

    using namespace std;

    SCOPE_EXIT{ cout << "Bye\n"; };
    f();

    auto ip = new A;
    auto g1 = scope_exit([=] () { cout << static_cast<void*>(ip) << '\n'; delete ip; });

    ip = new A;
    auto g2 = scope_exit([=] () { cout << static_cast<void*>(ip) << '\n'; delete ip; });

    ip = new A;
    auto g3 = scope_exit([=] () { cout << static_cast<void*>(ip) << '\n'; delete ip; });
    g3.commit();

    ifstream fstdin("/dev/stdin");
    SCOPE_EXIT{fstdin.close();};

    ip = new A;
    SCOPE_ON_EXIT([=]() {cout << static_cast<void*>(ip) << '\n'; delete ip;});

    return 0;
}
