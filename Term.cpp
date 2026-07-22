#include "Term.h"

Term::Term()
{
    coefficient = 0;
    variable = 'x';
    exponent = 0;
}

Term::Term(double coeff, char var, int exp)
{
    coefficient = coeff;
    variable = var;
    exponent = exp;
}

Term::Term(const Term& other)
{
    coefficient = other.coefficient;
    variable = other.variable;
    exponent = other.exponent;
}

double Term::getCoefficient() const
{
    return coefficient;
}

char Term::getVariable() const
{
    return variable;
}

int Term::getExponent() const
{
    return exponent;
}

void Term::setCoefficient(double coeff)
{
    coefficient = coeff;
}

void Term::setVariable(char var)
{
    variable = var;
}

void Term::setExponent(int exp)
{
    exponent = exp;
}

Term& Term::operator=(const Term& other)
{
    if (this != &other)
    {
        coefficient = other.coefficient;
        variable = other.variable;
        exponent = other.exponent;
    }

    return *this;
}

Term Term::operator+(const Term& other) const
{
    if (exponent != other.exponent || variable != other.variable)
        return *this;

    return Term(coefficient + other.coefficient, variable, exponent);
}

Term Term::operator-(const Term& other) const
{
    if (exponent != other.exponent || variable != other.variable)
        return *this;

    return Term(coefficient - other.coefficient, variable, exponent);
}

Term Term::operator*(const Term& other) const
{
    return Term(
        coefficient * other.coefficient,
        variable,
        exponent + other.exponent
    );
}

bool Term::operator==(const Term& other) const
{
    return coefficient == other.coefficient &&
           variable == other.variable &&
           exponent == other.exponent;
}
