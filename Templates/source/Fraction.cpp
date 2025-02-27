#include "Fraction.h"

Fraction::Fraction(int a, int b) : numerator(a), denominator(b) 
{
    Simplify();
}

Fraction Fraction::Multiply(Fraction other)
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator+(const Fraction& other) const
{
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

int gcd(int a, int b)
{
    int x;
    while (b != 0)
    {
        x = b;
        b = a % b;
        a = x;
    }
    return a;
}

void Fraction::Simplify()
{
    int n;
    while((n = gcd(numerator, denominator)) != 1)
    {
        numerator /= n;
        denominator /= n;
    }
}

Fraction Fraction::Add(Fraction other)
{
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

std::string Fraction::toString() const
{
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
    out << f.toString();
    return out;
}