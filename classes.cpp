#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

template <class C>
class Lifecycle {
    bool empty = false;
public:
    Lifecycle() {
        std::cout << C::classname << "()" << std::endl;
    }

    Lifecycle(const Lifecycle &other) = delete;
    // {
    //     std::cout << C::classname << "(const " << C::classname << "&)" << std::endl;
    //     empty = other.empty;
    // }

    Lifecycle(Lifecycle &&other) {
        std::cout << C::classname << "(" << C::classname << "&&)" << std::endl;
        empty = other.empty;
        other.empty = true;
    }

    ~Lifecycle() {
        std::cout << "~" << C::classname << "(" << (empty ? "EMPTY" : "") << ")" << std::endl;
    }

    Lifecycle &operator=(Lifecycle &&other) {
        std::cout << "operator=(" << C::classname << " &&)" << std::endl;
        empty = other.empty;
        other.empty = true;
        return *this;
    }

    Lifecycle &operator=(Lifecycle const &other) = delete;
    // {
    //     std::cout << "operator=(" << C::classname << "&)" << std::endl;
    //     empty = other.empty;
    //     return *this;
    // }
};

class Foo: Lifecycle<Foo> {
public:
    static constexpr const char * classname = "Foo";

    Foo(int _a) : a(_a) {}

    Foo(const Foo &other) = delete;

    Foo(Foo &&other) : Lifecycle<Foo>(std::move(other)) {
        a = other.a;
        other.a = 9999;
    }

    Foo &operator=(Foo const &other) = delete;
    Foo &operator=(Foo &&other) {
        a = other.a;
        other.a = 9999;
        return *this;
    }
    
    int val() const { return a; }
private:
    int a;
};

static std::ostream& operator<< (std::ostream& o, Foo const &f) {
    return o << f.val();
}

int main(int argc, char **argv) {
    std::vector<Foo> v;

    v.push_back(Foo(1));

    std::cout << "capaciy " << v.capacity() << std::endl;
    
    v.push_back(Foo(2));
    std::cout << "capaciy " << v.capacity() << std::endl;
    v.push_back(Foo(3));
    std::cout << "capaciy " << v.capacity() << std::endl;

    std::random_device rd;
    std::mt19937 g(rd());

    std::cout << " === begin shuffle ===" << std::endl;
    std::shuffle(v.begin(), v.end(), g);
    std::cout << " === end shuffle ===" << std::endl;
 
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    for (auto const &f: v)
        std::cout << f << " ";
    
    std::cout << "\n";
    
    return 0;
}
