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
	if(str[i] == ' ') {
	    numerator = 0;
	    denominator = 1;
	    NaN = true;
	    return;
	}
    }
    if(sep)
	r = new Rat(stod(str));
    else
	r = new Rat(stoi(str));
    if(r.numerator != NULL && r.denominator != NULL && r.denominator != 0) {
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
ostream &operator<<(ostream &cout, const Rat &r) {
    if(r.NaN)
	cout << "NaN";
    else if(r.numerator == 0)
	cout << "0";
    else if(r.denominator == 1)
	cout << r.numerator;
    else
	cout << '(' << r.numerator << '/' << r.denominator << ')';
    return cout;
}

istream &operator>>(istream &cin, Rat &r) {
    string s;
    Rat tmp;
   
    cin >> s;
    tmp = new Rat(s);
    r.numerator = tmp.numerator;
    r.denominator = tmp.denominator;
    r.NaN = tmp.NaN;
    return cin; 
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

    Rat r1, r2, r3, r4, r5, r6, r7, r8, r9;

    r1 = new Rat();
    r2 = new Rat(2);
    r3 = new Rat("0.5");
    r4 = new Rat("5");
    r5 = new Rat(2,4);
    r6 = new Rat(3,0);
    r7 = new Rat(0.75);
    r8 = new Rat("hello");

    cout << "This should be (0/1): " << r1 << endl;
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
