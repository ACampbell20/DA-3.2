#include "Polynomial.h"

Polynomial::Polynomial()
{
    terms = nullptr;
    numberOfTerms = 0;
}

Polynomial::Polynomial(Term termArray[], int size)
{
    numberOfTerms = size;
    terms = new Term[numberOfTerms];

    for (int i = 0; i < numberOfTerms; i++)
    {
        terms[i] = termArray[i];
    }
}

Polynomial::Polynomial(const Polynomial& other)
{
    numberOfTerms = other.numberOfTerms;
    terms = new Term[numberOfTerms];

    for (int i = 0; i < numberOfTerms; i++)
    {
        terms[i] = other.terms[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] terms;
}

Term* Polynomial::getTerms() const
{
    return terms;
}

int Polynomial::getNumberOfTerms() const
{
    return numberOfTerms;
}

void Polynomial::setTerms(Term termArray[], int size)
{
    delete[] terms;

    numberOfTerms = size;
    terms = new Term[numberOfTerms];

    for (int i = 0; i < numberOfTerms; i++)
    {
        terms[i] = termArray[i];
    }
}

void Polynomial::setNumberOfTerms(int size)
{
    numberOfTerms = size;
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this != &other)
    {
        delete[] terms;

        numberOfTerms = other.numberOfTerms;
        terms = new Term[numberOfTerms];

        for (int i = 0; i < numberOfTerms; i++)
        {
            terms[i] = other.terms[i];
        }
    }

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
    Polynomial result;

    result.numberOfTerms = numberOfTerms + other.numberOfTerms;
    result.terms = new Term[result.numberOfTerms];

    int index = 0;

    for (int i = 0; i < numberOfTerms; i++)
        result.terms[index++] = terms[i];

    for (int i = 0; i < other.numberOfTerms; i++)
        result.terms[index++] = other.terms[i];

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
    Polynomial result;

    result.numberOfTerms = numberOfTerms + other.numberOfTerms;
    result.terms = new Term[result.numberOfTerms];

    int index = 0;

    for (int i = 0; i < numberOfTerms; i++)
        result.terms[index++] = terms[i];

    for (int i = 0; i < other.numberOfTerms; i++)
    {
        Term temp = other.terms[i];
        temp.setCoefficient(-temp.getCoefficient());
        result.terms[index++] = temp;
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polynomial result;

    result.numberOfTerms = numberOfTerms * other.numberOfTerms;
    result.terms = new Term[result.numberOfTerms];

    int index = 0;

    for (int i = 0; i < numberOfTerms; i++)
    {
        for (int j = 0; j < other.numberOfTerms; j++)
        {
            result.terms[index++] = terms[i] * other.terms[j];
        }
    }

    return result;
}

bool Polynomial::operator==(const Polynomial& other) const
{
    if (numberOfTerms != other.numberOfTerms)
        return false;

    for (int i = 0; i < numberOfTerms; i++)
    {
        if (!(terms[i] == other.terms[i]))
            return false;
    }

    return true;
}

ostream& operator<<(ostream& out, const Polynomial& poly)
{
    for (int i = 0; i < poly.numberOfTerms; i++)
    {
        double coeff = poly.terms[i].getCoefficient();
        int exp = poly.terms[i].getExponent();

        if (i > 0 && coeff >= 0)
            out << "+";

        out << coeff;

        if (exp > 0)
        {
            out << poly.terms[i].getVariable();

            if (exp > 1)
                out << "^" << exp;
        }

        if (i < poly.numberOfTerms - 1)
            out << " ";
    }

    return out;
}
