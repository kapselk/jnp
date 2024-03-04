#include "fib.h"
#include <vector>
#include <string>
#include <ostream>


Fib::Fib() {
    val.assign(1, 0);
}

Fib::Fib(const string &s) {
    int n = (int) s.size();
    val.resize(n);
    for (int i = 0; i < n; i++) {
        val[i] = s[n - i - 1] == '1';
    }
    fix();
}

Fib::Fib(const Fib& f) {
    val = f.val;
}

void Fib::extend() {
    val.push_back(false);
}

int Fib::size() {
    return (int) val.size();
}

void Fib::fix() {
    for (int i = 0; i < ((int) val.size() - 1); i+=2) {
        if (val[i] && val[i + 1]) {
            val[i] = false;
            val[i + 1] = false;
            if (i == ((int) val.size() - 2)) extend();
            set(i + 2);
        }
    }
}

void Fib::set(int i) {
    int n = (int) val.size();
    for (int j = i; j < n; j += 2) {
        if (j == (n - 1)) { extend(); n++; }
        if (!val[i]) {
            val[i] = true;
            break;
        } else if (val[i + 1]) {
            val[i] = false;
            val[i + 1] = false;
            extend(); n++;
            val[i + 2] = true;
        } else {
            val[i] = false;
            val[i + 1] = true;
            if (i == 1) {
                if (val[0]) {
                    val[0] = false;
                    val[1] = true;
                } else val[0] = true;
                break;
            } else {
                i -= 2;
            }
        }
    }
}

bool operator==(const Fib &lhs, const Fib &rhs) { return lhs.val == rhs.val; }

bool operator<(const Fib &lhs, const Fib &rhs) {
    if (lhs.val.size() != rhs.val.size()) return lhs.val.size() < rhs.val.size();
    for (int i = (int) lhs.val.size(); i >= 0; i--) {
        if (lhs.val[i] && !rhs.val[i]) return true;
        else if (!lhs.val[i] && rhs.val[i]) return false;
    }
    return false;
}

bool operator<=(const Fib &lhs, const Fib &rhs) { return lhs == rhs || lhs < rhs; }

bool operator>(const Fib &lhs, const Fib &rhs) { return !(lhs <= rhs); }

bool operator>=(const Fib &lhs, const Fib &rhs) { return lhs == rhs || lhs > rhs; }

Fib& Fib::operator+=(const Fib &rhs) {
    int n = (int) val.size();
    for (int i = 0; i < n; i++) {
        if (i >= (int) rhs.val.size()) break;
        if (val[i] != rhs.val[i]) val[i] = val[i] | rhs.val[i];
        else {
            set(i);   
        }
    }
    return *this;
}

Fib& Fib::operator&=(const Fib &rhs) {
    int n = (int) val.size();
    for (int i = 0; i < n; i++) {
        if (i >= (int) rhs.val.size()) val[i] = false;
        else val[i] = val[i] & rhs.val[i];
    }
    return *this;
}

Fib& Fib::operator|=(const Fib &rhs) {
    if ((int) val.size() < (int) rhs.val.size()) val.resize((int) rhs.val.size(), false);
    int n = (int) val.size();
    for (int i = 0; i < n; i++) {
        val[i] = val[i] | rhs.val[i];
    }
    return *this;
}

Fib& Fib::operator^=(const Fib &rhs) {
    if ((int) val.size() < (int) rhs.val.size()) val.resize((int) rhs.val.size(), false);
    int n = (int) val.size();
    for (int i = 0; i < n; i++) {
        val[i] = val[i] ^ rhs.val[i];
    }
    return *this;
}

Fib& Fib::operator<<=(size_t n) {
    val.resize((int) val.size() + n, false);
    int m = (int) val.size();
    for (int i = m - 1; i >= (int) n; i--) {
        val[i] = val[i - n];
    }
    for (int i = 0; i < (int) n; i++) val[i] = false;
    return *this;
}

Fib Fib::operator+(const Fib &rhs) const {
    return Fib(*this) += rhs;
}

Fib Fib::operator&(const Fib &rhs) const {
    return Fib(*this) &= rhs;
}

Fib Fib::operator|(const Fib &rhs) const {
    return Fib(*this) |= rhs;
}

Fib Fib::operator^(const Fib &rhs) const {
    return Fib(*this) ^= rhs;
}

Fib Fib::operator<<(size_t n) const {
    return Fib(*this) <<= n;
}

Fib& Fib::operator=(const Fib& rhs) {
    return *this = Fib(rhs);
}

ostream& Fib::operator<<(ostream &stream) {
    for (int i = 0; i < (int) val.size(); i++) {
        stream << val[i];
    }
    return stream;
}