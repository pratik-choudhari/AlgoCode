/*
Format: m n mth-term nth-term p
Input: 6 10 12 20 5
Output: 10
*/

#include <iostream>
using namespace std;

pair<double, double> findAD(double m, double n, double mth, double nth)
{
    double a, d, pth;
    d = (mth - nth) / (m - n);
    a = mth - ((m - 1) * d);
    return make_pair(a, d);
}

double pthTerm(double m, double n, double mth, double nth, double p)
{
    pair<double, double> values;
    values = findAD(m, n, mth, nth);
    return (values.first + (p - 1) * values.second);
}

double sum(double m, double n, double mth, double nth, double p)
{
    pair<double, double> values;
    values = findAD(m, n, mth, nth);
    return ((p * (2 * values.first + (p - 1) * values.second)) / 2);
}

int main()
{
    double m, n, mth, nth, p, result;
    int choice;
    do
    {
        cout << "\nMain Menu\n"
             << "1. Find the pth Term\n"
             << "2. Sum of pth terms\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin >> m >> n >> mth >> nth >> p;
        switch (choice)
        {
        case 1:
            result = pthTerm(m, n, mth, nth, p);
            cout << "pth Term: " << result << endl;
            break;
        case 2:
            result = sum(m, n, mth, nth, p);
            cout << "Sum of pth Terms: " << result << endl;
            break;
        default:
            break;
        }
    } while (choice != 3);
    return 0;
}