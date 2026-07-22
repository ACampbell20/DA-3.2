#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    Term poly1Terms[3] =
    {
        Term(3, 'x', 2),
        Term(4, 'x', 1),
        Term(2, 'x', 0)
    };

    Term poly2Terms[3] =
    {
        Term(5, 'x', 2),
        Term(-6, 'x', 1),
        Term(7, 'x', 0)
    };

    Polynomial p1(poly1Terms, 3);
    Polynomial p2(poly2Terms, 3);

    cout << "Polynomial 1:" << endl;
    cout << p1 << endl << endl;

    cout << "Polynomial 2:" << endl;
    cout << p2 << endl << endl;

    Polynomial sum = p1 + p2;
    cout << "p1 + p2:" << endl;
    cout << sum << endl << endl;

    Polynomial difference = p1 - p2;
    cout << "p1 - p2:" << endl;
    cout << difference << endl << endl;

    Polynomial product = p1 * p2;
    cout << "p1 * p2:" << endl;
    cout << product << endl << endl;

    if (p1 == p2)
        cout << "p1 and p2 are equal." << endl;
    else
        cout << "p1 and p2 are NOT equal." << endl;

    cout << endl;

    Polynomial copy(p1);

    cout << "Copy of p1:" << endl;
    cout << copy << endl << endl;

    Polynomial assigned;
    assigned = p2;

    cout << "Assigned Polynomial:" << endl;
    cout << assigned << endl << endl;

    if (assigned == p2)
        cout << "Assignment operator works correctly." << endl;
    else
        cout << "Assignment operator failed." << endl;

}
