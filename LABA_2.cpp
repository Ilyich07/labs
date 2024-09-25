#include <iostream>
using namespace std;
#include <cstdlib> // random numbers
#include <ctime>
#include <cmath>


int main() { 
    const int max = 20;
    int count;
    int k;
    cout << "Enter the number of elements in the array from 1 to " <<max << ":  ";
    cin >> count;
    for ( ;!( 1 <= count && count <= max); ) {
        cout << "Enter the number of elements in the array from 1 to " << max << ":  ";
        cin >> count;
    }
    int* arr = new int[count];


    cout << "Select the method of filling the array: 1 - auto, 2 - manual: ";
    cin >> k;

    
    for ( ; k != 1 && k != 2 ; ) {
         cout << "Select the method of filling the array: 1 - auto, 2 - manual: ";
         cin >> k;
    }

    srand(time(0));
    if (k==1) {
        int a;
        int b;
        int ost; 
        cout << "Input min element of array:";
        cin >> a;
        cout << "Input max element of array:";
        cin >> b;
        ost = b-a+1; 
        for ( int i = 0; i <= count ; ++i ) {
            int elem;
            int rnd = rand();
            rnd = rnd % ost; 
            elem = a + rnd;
            arr[i]=elem;
        }
    } 
    if (k==2) {
        cout << "Input elements of array:";
        for ( int i = 0; i < count ; ++i ) {
            cin >> arr[i];
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << arr[i]<< "\t" ;
    }

    int min_el = arr[0];
    int num_el = 0;

    for (int i = 1; i < count; ++i ) {
        if (fabs (min_el) >= fabs(arr [i]) ) {
            min_el = arr[i];
            num_el = i;
        }
    }
    cout << endl << "Number of the minimum element by module: " << num_el << endl;

    int sum = 0;
    int f=0;
    while (arr[f]>=0) {
        ++f;
    }
    for (; f+1 < count; ++f) {
        sum = sum + arr[f+1];
    }
    cout << "Sum of elements after the first negative element: "<< sum <<endl;


    int p;
    cout << "Input p: ";
    cin >> p;
    int s = 0;
    for (; s < count; ++s) {
        if (arr[s] == p) {
            for (int i = s; i < count-1 ; ++i) {
                arr[i]=arr[i+1];
            }
            arr[count-1] = 0; 
            --s;
        }
    }
    for (int i = 0; i < count; ++i) {
        cout << arr[i]<< "\t";
    }
    delete []arr;
}