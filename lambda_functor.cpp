#include <iostream>
#include <boost/bind.hpp>

using namespace std;

class A {
public:
    string g(string x) {
        return "g(): " + x;
    }

    string h(string x, string y) {
        return "h(): " + x + ", " + y;
    }


    template< class F >
    string hello(F fun) {
        string test = "hello";
        return fun(test);
    }
};

int main() {
    A a;
    cout << a.hello( boost::bind( &A::g, a, _1) ) << endl;
    cout << a.hello( boost::bind( &A::h, a, _1, "blah") ) << endl;
    return 0;
}
