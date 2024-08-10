#include "Integer.h"
#include<algorithm>
#include<conio.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<Windows.h>
using namespace std;
void SetColor(int FroeColor, int BlackColor) {
    /*  0 = 黑色   1 = 蓝色
        2 = 绿色   3 = 湖蓝色
        4 = 红色   5 = 紫色
        6 = 黄色   7 = 白色
        8 = 灰色   9 = 淡蓝色
        10 = 淡绿色  11 = 淡浅绿
        12 = 淡红色  13 = 淡紫色
        14 = 淡黄色  15 = 亮白色
        */
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        FroeColor + BlackColor * 0x10);
}
template<typename T>
void ColorOut(T t, int FroeColor, int BackColor = 0) {
    SetColor(FroeColor, BackColor);
    cout << t;
    SetColor(15, 0);
}
void FirstGraph(void) {
    char ch[][1000] = {
        "                          ",
        "   ***  ***     *** ***   ",
        "   *    * *       *  *    ",
        "   * ** ***      *   *    ",
        "   * *  * *     *    *    ",
        "   ***  * *     *** ***   ",
        "                          "
        //  "       Ga Zi Studio       "
    };
    for (int i = 0; i < 7; i++) {
        int len = strlen(ch[i]);
        for (int j = 0; j < len; j++) {
            if (ch[i][j] != '*') ColorOut(" ", 0, 1);
            else ColorOut(" ", 0, 4);
        }
        cout << endl;
    }
    ColorOut("       ", 0, 1);
    ColorOut("Ga", 3, 4);
    ColorOut(" ", 0, 4);
    ColorOut("Zi", 3, 4);
    ColorOut(" ", 0, 4);
    ColorOut("Studio", 3, 4);
    ColorOut("       ", 0, 1);
    cout << endl;
    cout << "Calculator 2.0\n";
    Sleep(2000);
    system("CLS");
}

stack<Integer> num;
stack<char> oper;
bool IsNum(char ch) {
    return (ch >= '0' && ch <= '9');
}
bool IsOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*'
        || ch == '/' || ch == '^' || ch == '%');
}
void Calculate() {
    if (num.size() < 2) throw Error(3);
    if (oper.empty()) throw Error(3);
    Integer b = num.top(); num.pop();
    Integer a = num.top(); num.pop();
    char op = oper.top(); oper.pop();
    if (op == '+') { num.push((a + b)); return; }
    if (op == '-') { num.push((a - b)); return; }
    if (op == '*') { num.push((a * b)); return; }
    if (op == '^') { num.push((a ^ b)); return; }
    if (op == '/') { if (b == 0) { throw Error(1); } num.push(a / b); return; }
    if (op == '%') { if (b == 0) { throw Error(1); } num.push(a % b); return; }
    else throw Error(3);
}
string str;
int main() {
#if 1
    FirstGraph();
    unordered_map<char, int> pr = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3} };
    while (true) {
        ColorOut(">>>>", 1, 11);
        getline(cin, str);
        if (str == "clean") {
            system("CLS");
            continue;
        }
        if (str == "EXIT" || str == "exit" || str == "EXIT()" || str == "exit()") {
            ColorOut("Thank you for using! Goodbye!\n", 2, 0);
            Sleep(1000);
            exit(0);
        }
        ColorOut("<<<<", 4, 12);
        try {
            for (int i = 0; i < str.size(); i++) {
                auto c = str[i];
                if (IsNum(c)) {
                    Integer now = 0;
                    int j = i;
                    while (j < str.size() && IsNum(str[j]))
                        now = (now * 10) + Integer(str[j++] - '0');
                    num.push(now);
                    i = j - 1;
                }
                else if (c == '(') {
                    oper.push(c);
                }
                else if (c == ')') {
                    while (oper.top() != '(') Calculate();
                    oper.pop();
                }
                else if (c == ' ') continue;
                else if (IsOperator(c)) {
                    while (oper.size() && pr[oper.top()] >= pr[c]) {
                        Calculate();
                    }
                    oper.push(c);
                }
                else throw Error(3);
            }
            while (oper.size()) Calculate();
            throw num.top();
            
        }
        catch (Error& b) { ColorOut(b.What(), 4, 0); }
        catch (Integer& a) { SetColor(2, 0); a.Print(); SetColor(15, 0); }
        printf("\n");
        num = stack<Integer>();
        oper = stack<char>();
    }
#endif
#if 0
    UnsignedInteger a, b;
    cin >> a >> b;
    cout << (a ^ b) << endl;
#endif
}