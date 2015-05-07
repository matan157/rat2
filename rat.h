#ifndef RAT_H
#define RAT_H
#include<string>

class Rat {
	private:
		int numerator;
		int denominator;
		bool NaN;
	public:
		// constructors
		Rat();
		Rat(int);
		Rat(int,int);
		Rat(double);
		Rat(std::string);

		friend std::ostream &operator<<(std::ostream &, const Rat &);
		friend std::istream &operator>>(std::istream &, Rat &);
};

#endif
