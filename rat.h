#ifndef RAT_H
#define RAT_H
#include<string>

class Rat {
	private:
		int numerator;
		int denominator;
	public:
		// constructors
		Rat Rat(int);
		Rat Rat(int,int);
		Rat Rat(double);
		Rat Rat(string);
};
