#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    Fraction operator+(const Fraction& op_l) {
        int numerator = numerator_ * op_l.denominator_ + op_l.numerator_ * denominator_;
        int denominator = denominator_ * op_l.denominator_;

        check(numerator_, denominator_, op_l.numerator_, op_l.denominator_, numerator, denominator);

        return Fraction(numerator, denominator);
    }

    Fraction operator-(Fraction op_l) {
        int numerator = numerator_ * op_l.denominator_ - op_l.numerator_ * denominator_;
        int denominator = denominator_ * op_l.denominator_;

        check(numerator_, denominator_, op_l.numerator_, op_l.denominator_, numerator, denominator);

        return Fraction(numerator, denominator);
    }

    Fraction operator*(Fraction op_l) {
        int numerator = numerator_ * op_l.numerator_;
        int denominator = denominator_ * op_l.denominator_;

        check(numerator_, denominator_, op_l.numerator_, op_l.denominator_, numerator, denominator);

        return Fraction(numerator, denominator);
    }

    Fraction operator/(Fraction op_l) {
        int numerator = numerator_ * op_l.denominator_;
        int denominator = denominator_ * op_l.numerator_;

        check(numerator_, denominator_, op_l.numerator_, op_l.denominator_, numerator, denominator);
        return Fraction(numerator, denominator);
    }

    Fraction& operator++() {
        numerator_ = numerator_ + denominator_;
        return *this;
    }

    Fraction operator++(int) {
        numerator_ = numerator_ + denominator_;
        Fraction copy = *this;
        return copy;
    }

    Fraction& operator--() {
        numerator_ = numerator_ - denominator_;;
        return *this;
    }
    Fraction operator--(int) {
        Fraction copy = *this;
        --(*this);
        return copy;
    }
    void check(int  aa, int ab, int ba, int bb, int& ca, int& cb) {
        if ((ca) % ab == 0 && cb % ab == 0) {
            ca = ca / ab;
            cb = cb / ab;
        }
        else if (ca % bb == 0 && cb % bb == 0) {
            ca = ca / bb;
            cb = cb / bb;
        }
    }

    friend std::ostream& operator << (std::ostream& os, const Fraction& fra);
};

std::ostream& operator << (std::ostream& os, const Fraction& fra)
{
    if (fra.denominator_ == 1)
        os << fra.numerator_;
    else
        os << fra.numerator_ << "/" << fra.denominator_;

    return os;
}



int main()
{
    setlocale(LC_ALL, "rus");

    int aa, ab, ba, bb;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> aa;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> ab;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> ba;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> bb;



    Fraction f1(aa, ab);
    Fraction f2(ba, bb);
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    std::cout << "++" << f1 << " * " << f2 << " = ";
    std::cout << ++f1 * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;
    std::cout << f1 << "-- *" << f2 << " = ";
    std::cout << f1-- * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;
    return 0;
}