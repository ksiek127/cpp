#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

class Fraction{
    private:
        static int removedFractions_ = 0;
        static int invalidDenominatorValue = 0;
        String name;
        constexpr int defaultDenominatorValue = 1;
    protected:
        int numerator;
        int denominator;
    public:
        Fraction(){
            numerator = 1;
            denominator = 1;
            name = "";
        }
        Fraction(String name, int numerator, int denominator = defaultDenominatorValue);

       int getNumerator(){
           return numerator;
       } 

       int getDenominator(){
           return denominator;
       }

       void setNumerator(int val){
           numerator = val;
       }

       void setDenominator(int val){
           denominator = val;
       }

       void print(){
           cout << numerator << "/" << denominator << endl;
       }
       
       static int removedFractions(){
           return removedFractions_;
       }

       static int getInvalidDenominatorValue(){
           return invalidDenominatorValue;
       }

       string read(istream& is){
            string str;
            getline(is, str);
            size_t pos = 0;
            while((pos = str.find("/") != string::npos)){
                numerator = stoi(str.substr(0, pos));
                denominator = stoi(str.substr(pos+1, str.length() - 1));
            }
       }

       void write(ostream& os){
           os << to_string(numerator) + "/" + to_string(denominator);
       }

       string getFractionName(){
           return name;
       }

       ~Fraction(){
           removedFractions_++;
       }
};

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
