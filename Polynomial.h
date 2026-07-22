#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include <iostream>

using namespace std;

class Polynomial
{
private:
    Term* terms;
    int numberOfTerms;

public:

    Polynomial();
    Polynomial(Term terms[], int size);
    Polynomial(const Polynomial& other);


    ~Polynomial();


    Term* getTerms() const;
    int getNumberOfTerms() const;

    void setTerms(Term terms[], int size);
    void setNumberOfTerms(int size);


    Polynomial& operator=(const Polynomial& other);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    bool operator==(const Polynomial& other) const;

    friend ostream& operator<<(ostream& out, const Polynomial& poly);
};

#endif
