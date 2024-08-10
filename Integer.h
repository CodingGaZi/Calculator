#include "UnsignedInteger.h"
#include<iostream>
using namespace std;

struct Integer{
    UnsignedInteger Int;
    bool Flag;
    Integer(int x);
    Integer(long long int x);
    Integer();
    Integer(const UnsignedInteger &UnInt);
    Integer(const Integer &b);
    void operator=(const Integer &b);
    friend istream& operator>> (istream& in, Integer &b);
    friend ostream& operator<< (ostream& out, Integer b);
    void Read();
    void Print() const;
    bool operator< (const Integer& b) const;
    bool operator== (const Integer& b) const;
    bool operator> (const Integer& b) const;
    bool operator<= (const Integer& b) const;
    bool operator>= (const Integer& b) const;
    bool operator!= (const Integer& b) const;
    Integer operator+ (const Integer & b) const;
    Integer operator- (const Integer & b) const;
    Integer operator* (const Integer & b) const;
    Integer operator/ (const Integer & b) const;
    Integer operator% (const Integer & b) const;
    Integer operator^ (const Integer & b) const;
    Integer operator+ () const;
    Integer operator- () const;
    Integer operator++ ();
    Integer operator++ (int);
    Integer operator-- ();
    Integer operator-- (int);
    void operator+= (const Integer& b);
    void operator-= (const Integer& b);
    void operator*= (const Integer& b);
    void operator/= (const Integer& b);
    void operator%= (const Integer& b);
    void operator^= (const Integer& b);
    friend Integer Pow(Integer a, Integer b);
    friend Integer Gcd(Integer a, Integer b);
    friend Integer Lcm(Integer a, Integer b);
};

Integer::Integer(int x) {
    if(x > 0) { Int = x, Flag = true;}
    else if(x == 0) { Int = 0, Flag = true;}
    else { Int = -x, Flag = false;}
}
Integer::Integer(long long int x) {
    if(x > 0) { Int = x, Flag = true;}
    else if(x == 0) { Int = 0, Flag = true;}
    else { Int = -x, Flag = false;}
}
Integer::Integer() {
    Int = 0, Flag = true;
}
Integer::Integer(const UnsignedInteger &UnInt) {
    Int = UnInt, Flag = true;
}
Integer::Integer(const Integer &b) {
    Int = b.Int, Flag = b.Flag;
}
void Integer::operator=(const Integer &b) {
    Int = b.Int, Flag = b.Flag;
}
istream &operator>>(istream &in, Integer &b) {
    Integer num = 0, f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + Integer(ch - '0');
    b = Integer(num * f);
    return in;
}
ostream& operator<< (ostream& out, Integer b) {
    if(b.Flag) {b.Int.Print();}
    else {printf("-"); b.Int.Print();}
    return out;
}
void Integer::Read() {
    Integer num = 0, f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + (ch - '0');
    *this = Integer(num * f);
}
void Integer::Print() const {
    if(Flag == true) { Int.Print(); }
    else { printf("-"); Int.Print(); }
}
bool Integer::operator<(const Integer &b) const {
    if(Flag == true && b.Flag == false) return false;
    if(Flag == false && b.Flag == true) return true;
    if(Flag == true && b.Flag == true) return Int < b.Int;
    if(Flag == false && b.Flag == false) return Int > b.Int;
}
bool Integer::operator==(const Integer &b) const {
    if(Flag == true && b.Flag == false) return false;
    if(Flag == false && b.Flag == true) return false;
    if(Flag == true && b.Flag == true) return Int == b.Int;
    if(Flag == false && b.Flag == false) return Int == b.Int;
}
bool Integer::operator>(const Integer &b) const {
    if(Flag == true && b.Flag == false) return true;
    if(Flag == false && b.Flag == true) return false;
    if(Flag == true && b.Flag == true) return Int > b.Int;
    if(Flag == false && b.Flag == false) return Int < b.Int;
}
bool Integer::operator<=(const Integer &b) const {
    return !(*this > b);
}
bool Integer::operator>=(const Integer &b) const {
    return !(*this < b);
}
bool Integer::operator!=(const Integer &b) const {
    return !(*this == b);
}
Integer Integer::operator+(const Integer &b) const {
    Integer c;
    if(Flag == true && b.Flag == true) {
        c.Flag = true; c.Int = Int + b.Int;
    }
    if (Flag == true && b.Flag == false) {
        if(Int < b.Int) { c.Flag = false; c.Int = b.Int - Int; }
        if(Int == b.Int) { c.Flag = true; c.Int = 0; }
        if(Int > b.Int) { c.Flag = true; c.Int = Int - b.Int; }
    }
    if (Flag == false && b.Flag == true) {
        if(Int < b.Int) { c.Flag = true; c.Int = b.Int - Int; }
        if(Int == b.Int) { c.Flag = true; c.Int = 0; }
        if(Int > b.Int) { c.Flag = false; c.Int = Int - b.Int; }
    }
    if (Flag == false && b.Flag == false) {
        c.Flag = false; c.Int = Int + b.Int;
    }
    return c;
}
Integer Integer::operator-(const Integer &b) const {
    Integer c;
    if(Flag == true && b.Flag == true) {
        if(Int < b.Int) { c.Flag = false; c.Int = b.Int - Int; }
        if(Int == b.Int) { c.Flag = true; c.Int = 0; }
        if(Int > b.Int) { c.Flag = true; c.Int = Int - b.Int; }
    }
    if (Flag == true && b.Flag == false) {
        c.Flag = true; c.Int = Int + b.Int;
    }
    if (Flag == false && b.Flag == true) {
        c.Flag = false; c.Int = Int + b.Int;
    }
    if (Flag == false && b.Flag == false) {
        if(Int < b.Int) { c.Flag = true; c.Int = b.Int - Int; }
        if(Int == b.Int) { c.Flag = true; c.Int = 0; }
        if(Int > b.Int) { c.Flag = false; c.Int = Int - b.Int; }
    }
    return c;
}
Integer Integer::operator*(const Integer &b) const {
    Integer c;
    if(Flag == true && b.Flag == true) c.Flag = true;
    if(Flag == true && b.Flag == false) c.Flag = false;
    if(Flag == false && b.Flag == true) c.Flag = false;
    if(Flag == false && b.Flag == false) c.Flag = true;
    c.Int = Int * b.Int;
    return c;
}
Integer Integer::operator/(const Integer &b) const {
    Integer c;
    if(b == 0) { throw "Divide 0"; }
    if(Flag == true && b.Flag == true) c.Flag = true;
    if(Flag == true && b.Flag == false) c.Flag = false;
    if(Flag == false && b.Flag == true) c.Flag = false;
    if(Flag == false && b.Flag == false) c.Flag = true;
    c.Int = Int / b.Int;
    if(Int % b.Int != 0) c.Int += 1;
    if(c.Int == 0) return Integer(0);
    return c;
}
Integer Integer::operator%(const Integer &b) const {
    Integer c;
    if(b == 0) { throw "Divide 0"; }
    if(Flag == true && b.Flag == true) c.Flag = true;
    if(Flag == true && b.Flag == false) c.Flag = false;
    if(Flag == false && b.Flag == true) c.Flag = false;
    if(Flag == false && b.Flag == false) c.Flag = true;
    c.Int = Int - (Int / b.Int) * b.Int;
    c.Int = (c.Int + b.Int) % b.Int;
    if(c.Int == 0) return Integer(0);
    return c;
}
Integer Integer::operator^(const Integer &b) const {
    Integer c;
    if(b == 0) return Integer(1);
    if(*this == 0) return Integer(0);
    if(*this > 0) {
        if(b > 0) {
            c.Flag = true;
            c.Int = Int ^ b.Int;
        }
        else {
            c.Flag = true;
            c.Int = UnsignedInteger(1) / (Int ^ b.Int);
        }
    }
    else {
        if(b > 0) {
            if(b % 2 == 0) {
                c.Flag = true;
                c.Int = Int ^ b.Int;
            }
            else {
                c.Flag = false;
                c.Int = Int ^ b.Int;
            }
        }
        else {
            c.Flag = false;
            c.Int = UnsignedInteger(1) / (Int ^ b.Int);
        }
    }
    if(c.Int == 0) return Integer(0);
    return c;
}
Integer Integer::operator+() const {
    return *this;
}
Integer Integer::operator-() const {
    if(*this == 0) return *this;
    else { Integer c; c.Flag = !Flag; return c; }
}
Integer Integer::operator++() {
    *this = *this + 1;
    return *this;
}
Integer Integer::operator++(int) {
    Integer c = *this;
    *this = *this + 1;
    return c;
}
Integer Integer::operator--() {
    *this = *this - 1;
    return *this;
}
Integer Integer::operator--(int) {
    Integer c = *this;
    *this = *this - 1;
    return c;
}
void Integer::operator+=(const Integer &b) {
    *this = *this + b;
}
void Integer::operator-=(const Integer &b) {
    *this = *this - b;
}
void Integer::operator*=(const Integer &b) {
    *this = *this * b;
}
void Integer::operator/=(const Integer &b) {
    *this = *this / b;
}
void Integer::operator%=(const Integer &b) {
    *this = *this % b;
}
void Integer::operator^=(const Integer &b) {
    *this = *this ^ b;
}
Integer Pow(Integer a, Integer b) {
    return a ^ b;
}
Integer Gcd(Integer a, Integer b) {
    return a % b == 0 ? b : Gcd(b, a % b);
}
Integer Lcm(Integer a, Integer b) {
    return a / Gcd(a, b) * b;
}