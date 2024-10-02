#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

// функция подсчёта суммы модулей отрицательных нечётных элемнтов столбца 
int chr(int f, const int n, int **mat ){
        int sum = 0;
        for(int i = 0; i < n; i = i + 2){
            if ( (mat[i][f]<0) & (mat[i][f]% 2 != 0)){
            sum = sum + fabs(mat[i][f]);
            }
        }
        return sum;
    }
//функция поиска суммы элементов в столбцах с хотя бы одиним отрицательным элементом
int sum_column(int j, const int m, int **mat){
    int sum_cl=0;
    bool isNegative = false;
        for (int i = 0; !isNegative && i < m; ++i){
            isNegative = mat[i][j] < 0;
        }
        if (isNegative == true){
                for (int g =0; g < m; ++g){
                sum_cl += mat[g][j];
            }
        } 
    return sum_cl;   
}

int main(){
    int m;
    int n;
    do{
        cout << "Input the number of rows in the matrix, m<=10: ";
        cin >> m;  
    }
    while ((0>m) || (m>=10));
    do{
        cout << "Input the number of columns in the matrix, n<=10: ";
        cin >> n;  
    }
    while ((0>n) || (n>=10));

    int **mat = new int*[m];
    for (int i = 0; i < m; ++i){
        mat[i] = new int[n];
    }


    int a_mn;
    cout<< "Input a[m,n]: ";
    cin>>a_mn;

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if ( (i+j)%2 == 0){
                mat[i][j] = a_mn;
            }
        }
    }



    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout<< mat[i][j]<< "\t";
        }
        cout<<endl;
    }

    for(int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (mat[i][j] != a_mn){
                cout<< "Input a["<<i+1<<","<<j+1 <<"]: ";
                cin>> mat[i][j];
            }
        }
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout<< mat[i][j]<< "\t";
        }
        cout<<endl;
    }

    //сортировка столбцов
    for (int j = 1; j < n; ++j){
        if (chr(j, m, mat)<chr(j-1, m, mat)){
            for ( int i = 0; i < m; ++i){
                int a = mat[i][j];
                int b = mat[i][j-1];
                mat[i][j] = b;
                mat[i][j-1] = a;
            }
            j = 1;
        }
    } 
    cout<<endl;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout<< mat[i][j]<< "\t";
        }
        cout<<endl;
}

for (int i = 0; i<n; ++i){
    if (sum_column(i, m, mat) != 0){
        cout<< "The sum of the elements of column number "<<i+1<<" = "<<sum_column(i, m, mat)<<endl;
    }
}
 for(int i = 0; i < m; ++i){
        delete[]mat[i];
    }
    delete[]mat;
 return 0;

}