#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    float x;
    int k;
    int n;
    int i = 1;
    double sum = 0;
    cout << " Input -1 < X < 1:  ";
    cin >> x;
    cout << " Input natural number k > 1: ";
    cin >> k;
    float a = x;
    while (a >= pow(10, -k) ){
        a = pow(a,i)/i;
        sum = sum + 2*a;
        i = i + 2;
    }
    double result = log ((1+x)/(1-x));
    cout << " Sum = " << " " << sum << endl;
    cout << " Sum of function = " << " " << result << endl;
    double dfr = sum - result;
    cout << " Difference = " << abs(dfr) << endl;
    return 0;
}