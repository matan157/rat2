#include<iostream>
#include<string>
#include<cmath>
#include<cstddef>
#include"normalize.h"
#include"rat.h"
using namespace std;

// constructors
Rat::Rat() : numerator(0), denominator(1), NaN(false) {}
Rat::Rat(int x) : numerator(x), denominator(1), NaN(false) {}
Rat::Rat(int n, int d) {
    normalize(n,d);
    if(d < 0) {
	n = -n;
	d = -d;
    }
    numerator = n;
    denominator = d;
    d == 0? NaN = true : NaN = false;
}

Rat::Rat(double x) {
    int n, d, tmp = 10;

    n = (int)(pow(10,tmp)) * x;
    d = (int)(pow(10,tmp));
    normalize(n,d);
    numerator = n;
    denominator = d;
    d == 0? NaN = true : NaN = false;
}

Rat::Rat(string str) {
    bool sep = false;
    Rat r;
    for(int i = 0; i < str.length(); i++) {
	if(str[i] == '.')
	    sep = true;
	if((str[i] < '0' || str[i] > '9') && str[i] != '.') {
	    numerator = 0;
	    denominator = 1;
	    NaN = true;
	    return;
	}
    }
    if(sep)
	r = * ( new Rat(stod(str)));
    else
	r = *(new Rat(stoi(str)));
    if(r.denominator != 0) {
	numerator = r.numerator;
	denominator = r.denominator;
	NaN = r.NaN;
    } else {
	numerator = 0;
	denominator = 1;
	NaN = true;
    }
}
// end constructors
//
// insertion operators
ostream &operator<<(ostream &out, const Rat &r) {
    if(r.NaN)
	out << "NaN";
    else if(r.numerator == 0)
	out << "0";
    else if(r.denominator == 1)
	out << r.numerator;
    else
	out << '(' << r.numerator << '/' << r.denominator << ')';
    return out;
}

istream &operator>>(istream &is, Rat &r) {
    string s;
    Rat tmp;
   
    is >> s;
    tmp = *(new Rat(s));
    r.numerator = tmp.numerator;
    r.denominator = tmp.denominator;
    r.NaN = tmp.NaN;
    return is; 
}
// end insertion operators
//
// assignment operators

// end assignment operators
//
// arithmetic operators

// end arithmetic operators
//
// conditional operators

// end conditional operators

#ifdef TEST

int main() {

    //Rat r1 = *( new Rat());
    Rat r2(2);
    Rat r3("0.5");
    Rat r4("5");
    Rat r5(2,4);
    Rat r6(3,0);
    Rat r7(0.75);
    Rat r8("hello");

    //cout << "This should be (0/1): " << r1 << endl;
    cout << "This should be 2: " << r2 << endl;
    cout << "This should be (1/2): " << r3 << endl;
    cout << "This should be 5: " << r4 << endl;
    cout << "this should be (1/2): " << r5 << endl;
    cout << "This should be NaN: " << r6 << endl;
    cout << "This should be (3/4): " << r7 << endl;
    cout << "This should be NaN: " << r8 << endl;

    return 0;
}
#endif
