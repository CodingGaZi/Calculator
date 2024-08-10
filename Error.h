#include<iostream>
#include<cstring>
using namespace std;
class Error {
    public: 
        Error(int n) {
            switch(n) {
                case 1:
                    ErrorMessage = "Divide 0";
                    break;
                case 2:
                    ErrorMessage = "Not support negative";
                    break;
                case 3:
                    ErrorMessage = "Cannot Calculate";
                    break;
                default:
                    ErrorMessage = "Unknown Error";
                    break;
            }
        }
        Error(string message) : ErrorMessage(message) {}
        string What() { return ErrorMessage; }
    private:
        string ErrorMessage;
};