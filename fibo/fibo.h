#ifndef _FIBO_H
#define _FIBO_H

#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Fibo {
    private:
        vector<bool> val;
        void extend();
        void fix();
        void set(int i);

    public:
        Fibo();
        Fibo(const string &s);
        Fibo(const Fibo &f);

        int size();

        friend bool operator==(const Fibo &lhs, const Fibo &rhs);
        friend bool operator<(const Fibo &lhs, const Fibo &rhs);
        friend bool operator<=(const Fibo &lhs, const Fibo &rhs);
        friend bool operator>(const Fibo &lhs, const Fibo &rhs);
        friend bool operator>=(const Fibo &lhs, const Fibo &rhs);

        Fibo& operator+=(const Fibo &rhs);
        Fibo& operator&=(const Fibo &rhs);
        Fibo& operator|=(const Fibo &rhs);
        Fibo& operator^=(const Fibo &rhs);
        Fibo& operator<<=(size_t n);

        Fibo operator+(const Fibo &rhs) const;
        Fibo operator&(const Fibo &rhs) const;
        Fibo operator|(const Fibo &rhs) const;
        Fibo operator^(const Fibo &rhs) const;
        Fibo operator<<(size_t n) const;

        Fibo& operator=(const Fibo& rhs);
        ostream& operator<<(ostream &stream);
};

#endif