#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "p04.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::logic_error;


void f(Deque d, const Deque& master) {
    if (&d == &master) {
        throw logic_error("f1: copy-constructor does not make a true copy");
    }
    if (d.size() != 9) {
        throw logic_error("f2: size method does not produce correct size");
    }
    stringstream s;
    while (!d.is_empty()) {
        s << d.pop_back();
    }
    if (s.str() != "864201357") {
        string msg = "f3: pop_back (or pushing) does not produce correct order";
        throw logic_error(msg);
    }
}

void g(const Deque& d) {
    Deque c;
    c = d;
    if (&c == &d) {
        throw logic_error("g1: assignment operator does not make a true copy");
    }
    if (c.size() != d.size()) {
        throw logic_error("g2: assignment operator does not make a true copy");
    }
    stringstream s;
    while (!c.is_empty()) {
        s << c.pop_back();
    }
    if (s.str() != "864201357") {
        throw logic_error("g3: assignment operator does not make a true copy");
    }
}


int main() {
    Deque d;
    if (d.size() != 0) {
        string msg = "m1: constructor does not set 0 size or size method fails";
        throw logic_error(msg);
    }
    d.push_back(0);
    if (d.size() != 1) {
        string msg = "m2: error with push_back or size";
        throw logic_error(msg);
    }
    d.push_front(1);
    if (d.size() != 2) {
        string msg = "m3: error with push_front or size";
        throw logic_error(msg);
    }
    for (int i = 2; i < 9; i++) {
        if (i % 2 == 0) {
            d.push_back(i);
        } else {
            d.push_front(i);
        }
    }

    f(d, d);
    g(d);

    stringstream s;
    while (!d.is_empty()) {
        int n = d.pop_front();
        s << n;
    }
    if (s.str() != "753102468") {
        throw logic_error("m4: error in pop_front");
    }

    try {
        d.pop_front();
        throw logic_error("m5: pop_front should throw DequeEmptyException");
    } catch (DequeEmptyException e) { }

    cout << "All tests pass  --  SUCCESS" << endl;

    return 0;
}
