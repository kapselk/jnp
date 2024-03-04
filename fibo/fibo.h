#ifndef _FIBO_H
#define _FIBO_H

#include <vector>

using namespace std;

class Fibo {
    private:
        vector<bool> val;

    public:
        Fibo();
        Fibo(const string &s);

        friend bool operator==(const Fibo&lhs, const Fibo &rhs);
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
        Fibo operator<<=(const size_t n) const;

        Fibo& operator=(const Fibo& rhs);
        ostream& operator<<(osteram &stream, const Fibo& rhs);
};

#endif