#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <map>


using namespace std;

class Rational{
public:
	Rational(){
		num = 0;
		den = 1;
	}

	Rational(const long& numerator, const long& denominator){
		if(denominator == 0){
			throw invalid_argument("Invalid argument");
			return;
		}
		const long div = MaxDiv(abs(numerator), abs(denominator));
		if(numerator * denominator >= 0){
			if(numerator == 0){
				num = numerator;
				den = 1;
			}
			else{
				num = abs(numerator) / div;
				den = abs(denominator) / div;
			}
		}
		else{
			if(numerator > 0)
				num = -1 * (numerator / div);
			else
				num = numerator / div;
			den = abs(denominator) / div;
		}
	}

	long Numerator() const{
		return num;
	}

	long Denominator() const{
		return den;
	}

	bool operator==(const Rational& other_rational) const{
		return (num == other_rational.Numerator()) && (den == other_rational.Denominator());
	}

	bool operator!=(const Rational& other_rational) const{
		return (num != other_rational.Numerator()) || (den != other_rational.Denominator());
	}

	Rational operator+(const Rational& other_rational) const{
		return Rational( num * other_rational.Denominator() + other_rational.Numerator() * den,
			den * other_rational.Denominator() );
	}

	Rational operator-(const Rational& other_rational) const{
		return Rational(num * other_rational.Denominator() - other_rational.Numerator() * den,
			den * other_rational.Denominator());
	}

	Rational operator*(const Rational& other_rational) const{
		return Rational(num * other_rational.Numerator(), den * other_rational.Denominator());
	}

	Rational operator/(const Rational& other_rational) const{
		if(other_rational.Numerator() == 0)
			throw domain_error("Division by zero");
		else
			return Rational(num * other_rational.Denominator(), den * other_rational.Numerator());
	}

	istream& operator>>(istream& stream){
		long numerator = num;
		long denominator = den;

		stream >> numerator;
		stream.ignore(1);
		stream >> denominator;

		Rational tmp_obj(numerator, denominator);

		this->num = tmp_obj.Numerator();
		this->den = tmp_obj.Denominator();

		return stream;
	}

	ostream& operator<<(ostream& stream) const{
		stream << this->Numerator() << "/" << this->Denominator();
		return stream;
	}

	bool operator>(const Rational& other_rational) const{
		Rational tmp_obj(Numerator() * other_rational.Denominator() - other_rational.Numerator() * Denominator(),
			Denominator() * other_rational.Denominator());
		return tmp_obj.Numerator() > 0;
	}

	bool operator<(const Rational& other_rational) const{
		Rational tmp_obj(Numerator() * other_rational.Denominator() - other_rational.Numerator() * Denominator(),
			Denominator() * other_rational.Denominator());
		return tmp_obj.Numerator() < 0;
	}

private:

	long num;
	long den;

	static long MaxDiv(long a, long b){
		return (b == 0) ? abs(a) : MaxDiv(b, a % b);
	}
};


istream& operator>>(istream& stream, Rational& rational){
	long numerator = rational.Numerator();
	long denominator = rational.Denominator();

	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;

	rational = Rational(numerator, denominator);

	return stream;
}


ostream& operator<<(ostream& stream, const Rational& rational){
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}


