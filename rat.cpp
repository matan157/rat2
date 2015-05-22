#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
#include"normalize.h"
#include"rat.h"
using namespace std;

// constructors
Rat::Rat() : numerator(0), denominator(1), NaN(false) {}
Rat::Rat(int x) : numerator(x), denominator(1), NaN(false) {}
Rat::Rat(int n, int d) {
    if(d == 0) {
	NaN = true;
	numerator = 1;
	denominator = 1;
	return;
    }
    if(d < 0) {
	n = -n;
	d = -d;
    }
    normalize(n,d);
    numerator = n;
    denominator = d;
    NaN = false;
}

Rat::Rat(double x) {
    int n, d, tmp = 8;
    double m;
    
    m = (pow(10,tmp)) * x;
    n = (int)m;
    d = (int)(pow(10,tmp));
    normalize(n,d);
    numerator = n;
    denominator = d;
    d == 0? NaN = true : NaN = false;
}

Rat::Rat(string str) {
    bool sep = false;
    bool paren = false;
    istringstream iss;

    int n, d;
    Rat r;
    for(int i = 0; i < str.length(); i++) {
	if(str[i] == '.')
	    sep = true;
	if((str[i] < '0' || str[i] > '9') && (str[i] != '.'
	&& str[i] != '(' && str[i] != ')' && str[i] != '/')) {
	    numerator = 0;
	    denominator = 1;
	    NaN = true;
	    return;
	}
	if(str[i] == '(')
	    paren = true;
    }
    if(paren) {
	for(int j = 0; j < str.length(); j++) {
	    if(str[j] == '(' || str[j] == '/' || str[j] == ')')
		str[j] = ' ';
	}
	iss.str(str);
	iss >> n;
	iss >> d;
	numerator = n;
	denominator = d;
	NaN = false;
	return;
    }
    if(sep)
	r = *(new Rat(stod(str)));
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
Rat &Rat::operator+=(const Rat &r) {
    int t1 = denominator, t2 = r.denominator;
    int n2 = r.numerator, d2 = r.denominator;
    if(denominator == r.denominator) {
	numerator = numerator + r.numerator;
    } else { 
	numerator *= t2;
	denominator *= t2;
	n2 *= t1;
	d2 *= t1;
    	numerator += n2;
    }
    t1 = numerator;
    t2 = denominator;
    normalize(t1,t2);
    numerator = t1;
    denominator = t2;
    return *this;
}
Rat &Rat::operator-=(const Rat &r) {
    int t1 = denominator, t2 = r.denominator;
    int n2 = r.numerator, d2 = r.denominator;
    if(denominator == r.denominator) {
	numerator = numerator - r.numerator;
    } else { 
	numerator *= t2;
	denominator *= t2;
	n2 *= t1;
	d2 *= t1;
    	numerator -= n2;
    }
    t1 = numerator;
    t2 = denominator;
    normalize(t1,t2);
    numerator = t1;
    denominator = t2;
    return *this;
}
Rat &Rat::operator*=(const Rat &r) {
    int n, d;
    n = numerator * r.numerator;
    d = denominator * r.denominator;
    normalize(n,d);
    numerator = n;
    denominator = d;
    return *this;
}

Rat &Rat::operator/=(const Rat &r) {
    int n = r.denominator * numerator, d = r.numerator * denominator;
    normalize(n,d);
    numerator = n;
    denominator = d;
    return *this;
}
// end assignment operators
//
// arithmetic operators

// end arithmetic operators
//
// conditional operators

// end conditional operators

#ifdef TEST

int main() {

    Rat r1 = *( new Rat());
    cout << "0" << endl;
    Rat r2(2);
    cout << "2" << endl;
    Rat r3("0.5");
    cout << "0.5" << endl;
    Rat r4("5");
    cout << "5" << endl;
    Rat r5(2,4);
    cout << "(1/2)" << endl;
    Rat r6(3,0);
    cout << "NaN" << endl;
    Rat r7(0.75);
    cout << "(3/4)" << endl;
    Rat r8("hello");
    cout << "NaN" << endl;

    Rat r9;
    cout << "enter rat number: ";
    cin >> r9;
    cout << "here is your rat number you filthy animal: " << r9 << endl;
    cout << "end here" << endl;
    
    // IT FUCKING WORKS HOLY SHIT
    cout << "This should be (0/1): " << r1 << endl;
    cout << "This should be 2: " << r2 << endl;
    cout << "This should be (1/2): " << r3 << endl;
    cout << "This should be 5: " << r4 << endl;
    cout << "this should be (1/2): " << r5 << endl;
    cout << "This should be NaN: " << r6 << endl;
    cout << "This should be (3/4): " << r7 << endl;
    cout << "This should be NaN: " << r8 << endl;

    r5+=r7;
    cout << "This should be (5/4): " << r5 << endl;
    
    r5-=r7;
    cout << "This should be (1/2): " << r5 << endl;

    r5*=r7;
    cout << "This should be (3/8): " << r5 << endl;

    r5/=r7;
    cout << "This should be (1/2): " << r5 << endl;
    return 0;
}
#endif
