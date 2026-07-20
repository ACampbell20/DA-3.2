#ifndef TERM_H
#define TERM_H

using namespace std;

class Term
{
private:
    double coefficient;
    char variable;
    int exponent;

public:
    Term();
    Term(double coeff, char var = 'x', int exp = 0);
    Term(const Term& other);

    double getCoefficient() const;
    char getVariable() const;
    int getExponent() const;

    void setCoefficient(double coeff);
    void setVariable(char var);
    void setExponent(int exp);

    Term& operator=(const Term& other);

    Term operator+(const Term& other) const;
    Term operator-(const Term& other) const;
    Term operator*(const Term& other) const;

    bool operator==(const Term& other) const;
};

#endif
