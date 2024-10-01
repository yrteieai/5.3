#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double t(const double x);

int main()
{
    double fp, fk;
    int n;

    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = "; cin >> n;

    double df = (fp - fk) / n;
    double f = fp;

    cout << "----------------------------------------------" << endl;
    cout << "|     f      |                               |" << endl;
    cout << "----------------------------------------------" << endl;

   
    for (int i = 0; i <= n; i++)
    {
      
        double z = t(f * f) + 2 * t(2 * f + 1) + sqrt(t(1));

        cout << "| " << setw(10) << fixed << setprecision(2) << f << " | "
            << setw(29) << fixed << setprecision(6) << z << " |" << endl;

        f += df;
    }

    cout << "----------------------------------------------" << endl;

    return 0;
}

double t(const double x)
{
    if (abs(x) >= 1)
    {
        // |x| >= 1
        return (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
    }
    else
    {
        // |x| < 1
        double S = 0;
        int j = 0;
        double a = x; 

        S = a;
        do
        {
            j++;
            double R = -(x * x) / ((2 * j) * (2 * j + 1));
            a *= R;
            S += a;
        } while (j < 5); 
        return S;
    }
}
