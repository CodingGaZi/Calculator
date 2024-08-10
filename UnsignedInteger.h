#include<iostream>
#include"Error.h"
using namespace std;

struct UnsignedInteger {
    int p[10100];
    int cnt;
    const int Max = 10000;
    // Init Function
    UnsignedInteger();
    UnsignedInteger(int x);
    UnsignedInteger(long long int x);
    UnsignedInteger(const UnsignedInteger &b);
    void operator= (const UnsignedInteger &b);
    friend istream& operator>> (istream& in, UnsignedInteger& b);
    friend ostream& operator<< (ostream& out, UnsignedInteger b);
    void Read();
    void Print() const;
    bool operator< (const UnsignedInteger& b) const;
    bool operator== (const UnsignedInteger& b) const; 
    bool operator> (const UnsignedInteger& b) const;
    bool operator<= (const UnsignedInteger& b) const;
    bool operator>= (const UnsignedInteger& b) const;
    bool operator!= (const UnsignedInteger& b) const;
    UnsignedInteger operator+ (const UnsignedInteger& b) const;
    UnsignedInteger operator- (const UnsignedInteger& b) const;
    UnsignedInteger operator* (const UnsignedInteger& b) const;
    UnsignedInteger operator/ (const UnsignedInteger& b) const;
    UnsignedInteger operator% (const UnsignedInteger& b) const;
    UnsignedInteger operator^ (const UnsignedInteger& b) const;
    UnsignedInteger operator++ ();
    UnsignedInteger operator++ (int);
    UnsignedInteger operator-- ();
    UnsignedInteger operator-- (int);
    void operator+= (const UnsignedInteger& b);
    void operator-= (const UnsignedInteger& b);
    void operator*= (const UnsignedInteger& b);
    void operator/= (const UnsignedInteger& b);
    void operator%= (const UnsignedInteger& b);
    void operator^= (const UnsignedInteger& b);
    friend UnsignedInteger Pow(UnsignedInteger a, UnsignedInteger b);
    friend UnsignedInteger Gcd(UnsignedInteger a, UnsignedInteger b);
    friend UnsignedInteger Lcm(UnsignedInteger a, UnsignedInteger b);
};


UnsignedInteger::UnsignedInteger() {
    memset(p, 0, sizeof p);
    cnt = 1;
}
UnsignedInteger::UnsignedInteger(int x) {
    if (x == 0) {
        memset(p, 0, sizeof p);
        cnt = 1;
    }
    else {
        memset(p, 0, sizeof p);
        cnt = 0;
        while (x > 0) {
            p[cnt++] = x % Max;
            x /= Max;
        }
    }
}
UnsignedInteger::UnsignedInteger(long long int x) {
    if (x == 0) {
        memset(p, 0, sizeof p);
        cnt = 1;
    }
    else {
        memset(p, 0, sizeof p);
        cnt = 0;
        while (x > 0) {
            p[cnt++] = x % Max;
            x /= Max;
        }
    }
}
UnsignedInteger::UnsignedInteger(const UnsignedInteger& b) {
    cnt = b.cnt;
    for (int i = 0; i < cnt; i++) p[i] = b.p[i];
}
void UnsignedInteger::operator= (const UnsignedInteger& b) {
    cnt = b.cnt;
    for (int i = 0; i < cnt; i++) p[i] = b.p[i];
}
//Input & Output Function
istream& operator>> (istream& in, UnsignedInteger& b) {
    UnsignedInteger num = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if(ch == '-') throw Error(2);
    for (; isdigit(ch); ch = getchar()) num = num * 10 + UnsignedInteger(ch - '0');
    b.cnt = num.cnt;
    for (int i = 0; i < b.cnt; i++) b.p[i] = num.p[i];
    return in;
}
ostream& operator<< (ostream& out, UnsignedInteger b) {
    out << b.p[b.cnt - 1];
    for (int i = b.cnt - 2; i >= 0; i--) {
        printf("%04d", b.p[i]);
    }
    return out;
}
void UnsignedInteger::Read() {
    UnsignedInteger num = 0, f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') throw Error(2);
    for (; isdigit(ch); ch = getchar()) num = num * 10 + (ch - '0');
    cnt = num.cnt;
    for (int i = 0; i < cnt; i++) p[i] = num.p[i];
}
void UnsignedInteger::Print() const {
    printf("%d", p[cnt - 1]);
    for (int i = cnt - 2; i >= 0; i--) {
        printf("%04d", p[i]);
    }
}
//Compare Function
bool UnsignedInteger::operator< (const UnsignedInteger& b) const {
    if (cnt != b.cnt)
        if (cnt < b.cnt)
            return true;
        else
            return false;
    else {
        for (int i = cnt - 1; i >= 0; i--)
            if (p[i] != b.p[i])
                if (p[i] < b.p[i])
                    return true;
                else
                    return false;
        return false;
    }
}
bool UnsignedInteger::operator== (const UnsignedInteger& b) const {
    if (cnt != b.cnt) return false;
    for (int i = cnt - 1; i >= 0; i--)
        if (p[i] != b.p[i]) return false;
    return true;
}
bool UnsignedInteger::operator> (const UnsignedInteger& b) const {
    if (cnt != b.cnt)
        if (cnt < b.cnt)
            return false;
        else
            return true;
    for (int i = cnt - 1; i >= 0; i--)
        if (p[i] != b.p[i])
            if (p[i] < b.p[i])
                return false;
            else
                return true;
    return false;

}
bool UnsignedInteger::operator<= (const UnsignedInteger& b) const {
    return !(*this > b);
}
bool UnsignedInteger::operator>= (const UnsignedInteger& b) const {
    return !(*this < b);
}
bool UnsignedInteger::operator!= (const UnsignedInteger& b) const {
    return !(*this == b);
}
//Calculate Function
UnsignedInteger UnsignedInteger::operator+ (const UnsignedInteger& b) const {
    UnsignedInteger c;
    c.cnt = max(cnt, b.cnt);
    int flag = 0;
    for (int i = 0; i < c.cnt; i++) {
        c.p[i] = p[i] + b.p[i] + flag;
        flag = c.p[i] / Max;
        c.p[i] %= Max;
    }
    if (flag != 0) c.p[c.cnt++] = flag;
    return c;
}
UnsignedInteger UnsignedInteger::operator- (const UnsignedInteger& b) const {
    if (*this < b) throw Error(2);
    UnsignedInteger c;
    c.cnt = max(cnt, b.cnt);
    int flag = 0;
    for (int i = 0; i < c.cnt; i++) {
        c.p[i] = p[i] - b.p[i] - flag;
        flag = 0;
        if (c.p[i] < 0) c.p[i] += Max, flag = 1;
    }
    while (c.cnt > 1 && c.p[c.cnt - 1] == 0) c.cnt--;
    return c;
}
UnsignedInteger UnsignedInteger::operator* (const UnsignedInteger& b) const {
    UnsignedInteger c = 0;
    c.cnt = cnt + b.cnt;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < b.cnt; j++) {
            c.p[i + j] += p[i] * b.p[j];
            c.p[i + j + 1] += c.p[i + j] / Max;
            c.p[i + j] %= Max;
        }
    }
    while (c.cnt > 1 && c.p[c.cnt - 1] == 0) c.cnt--;
    return c;
}
UnsignedInteger UnsignedInteger::operator/ (const UnsignedInteger& b) const {
    if (b == 0) throw Error(1);
    UnsignedInteger flag = 0;
    UnsignedInteger ans;
    ans.cnt = cnt;
    for (int i = cnt - 1; i >= 0; i--) {
        int Answer = 0;
        flag = flag * Max + UnsignedInteger(p[i]);
        int l = 0, r = Max;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (UnsignedInteger(mid) * b <= flag) {
                Answer = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans.p[i] = Answer;
        flag = flag - UnsignedInteger(Answer) * b;
    }
    while (ans.cnt > 1 && ans.p[ans.cnt - 1] == 0) ans.cnt--;
    return ans;
}
UnsignedInteger UnsignedInteger::operator% (const UnsignedInteger& b) const {
    if (b == 0) throw Error(1);
    UnsignedInteger flag = 0;
    UnsignedInteger ans;
    ans.cnt = cnt;
    for (int i = cnt - 1; i >= 0; i--) {
        int Answer = 0;
        flag = flag * Max + UnsignedInteger(p[i]);
        int l = 0, r = Max;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (UnsignedInteger(mid) * b <= flag) {
                Answer = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans.p[i] = Answer;
        flag = flag - UnsignedInteger(Answer) * b;
    }
    return flag;
}
UnsignedInteger UnsignedInteger::operator^ (const UnsignedInteger& b) const {
    return Pow(*this, b);
}
// Self Modifying Function
UnsignedInteger UnsignedInteger::operator++ () {
    *this = *this + 1;
    return *this;
}
UnsignedInteger UnsignedInteger::operator++ (int) {
    UnsignedInteger c = *this;
    *this = *this + 1;
    return c;
}
UnsignedInteger UnsignedInteger::operator-- () {
    *this = *this - 1;
    return *this;
}
UnsignedInteger UnsignedInteger::operator-- (int) {
    UnsignedInteger c = *this;
    *this = *this - 1;
    return c;
}
void UnsignedInteger::operator+= (const UnsignedInteger& b) {
    *this = *this + b;
}
void UnsignedInteger::operator-= (const UnsignedInteger& b) {
    *this = *this - b;
}
void UnsignedInteger::operator*= (const UnsignedInteger& b) {
    *this = *this * b;
}
void UnsignedInteger::operator/= (const UnsignedInteger& b) {
    *this = *this / b;
}
void UnsignedInteger::operator%= (const UnsignedInteger& b) {
    *this = *this % b;
}
void UnsignedInteger::operator^= (const UnsignedInteger& b) {
    *this = *this ^ b;
}
//Spceial Function
UnsignedInteger Pow(UnsignedInteger a, UnsignedInteger b) {
    UnsignedInteger ret = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ret *= a;
        }
        a *= a;
        b /= 2;
    }
    return ret;
}
UnsignedInteger Gcd(UnsignedInteger a, UnsignedInteger b) {
    return b == 0 ? a : Gcd(b, a % b);
}
UnsignedInteger Lcm(UnsignedInteger a, UnsignedInteger b) {
    return a / Gcd(a, b) * b;
}