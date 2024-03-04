#ifndef _FIB_H
#define _FIB_H

#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Fib {
    private:
        vector<bool> val;
        void extend();
        void fix();
        void set(int i);

    public:
        Fib();
        Fib(const string &s);
        Fib(const Fib &f);

        int size();

        friend bool operator==(const Fib &lhs, const Fib &rhs);
        friend bool operator<(const Fib &lhs, const Fib &rhs);
        friend bool operator<=(const Fib &lhs, const Fib &rhs);
        friend bool operator>(const Fib &lhs, const Fib &rhs);
        friend bool operator>=(const Fib &lhs, const Fib &rhs);

        Fib& operator+=(const Fib &rhs);
        Fib& operator&=(const Fib &rhs);
        Fib& operator|=(const Fib &rhs);
        Fib& operator^=(const Fib &rhs);
        Fib& operator<<=(size_t n);

        Fib operator+(const Fib &rhs) const;
        Fib operator&(const Fib &rhs) const;
        Fib operator|(const Fib &rhs) const;
        Fib operator^(const Fib &rhs) const;
        Fib operator<<(size_t n) const;

        Fib& operator=(const Fib& rhs);
        ostream& operator<<(ostream &stream);
};

#endif