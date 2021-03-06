#ifndef RAT_H
#define RAT_H
#include<string>

class Rat {
	friend std::ostream &operator<<(std::ostream &, const Rat &);
	friend std::istream &operator>>(std::istream &, Rat &);
	friend Rat operator-(const Rat &);

	friend bool operator==(const Rat &, const Rat &);
	friend bool operator!=(const Rat &, const Rat &);
	friend bool operator>(const Rat &, const Rat &);
	friend bool operator<(const Rat &, const Rat &);
	friend bool operator>=(const Rat &, const Rat &);
	friend bool operator<=(const Rat &, const Rat &);
    
	// arithmetic
	friend Rat operator+(const Rat &, const Rat &);
	friend Rat operator-(const Rat &, const Rat &);
	friend Rat operator*(const Rat &, const Rat &);
	friend Rat operator/(const Rat &, const Rat &);
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

		// assignment operators
		Rat &operator+=(const Rat &);
		Rat &operator-=(const Rat &);
		Rat &operator*=(const Rat &);
		Rat &operator/=(const Rat &);


};

#endif
