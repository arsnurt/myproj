#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void fill(int ** a, int n);
void print(int ** a, int n);
int minDiagSum(int ** a, int n);
int columnWithoutGreater(int ** a, int n, int x);
int sumAbs(int ** a, int n);

int main(){
    cout << "Given a square matrix of size M*M.\nThe program determines:\nthe minimum among the sums of the diagonal elements;\nthe number of the column that does not contain a single element greater than the specified number." << endl;
    cout << "It also calculates S = Σ |a[i][j]| ,  a[i][j] < 0" << endl;
    int M;
    cout << "Enter the size of matrix M (integer M > 0): ";
    cin >> M;
    if ((M <= 0) || (M >=20)){cout << "Error! Invalid size!" << endl; return 1;}
    int ** A = new int*[M];
    for (int i = 0; i < M; i++){A[i] = new int[M];}
    fill(A, M);
    print(A, M);
    int minDiag = minDiagSum(A, M);
    cout << "\nMinimum among the sums of the diagonals = " << minDiag << endl;
    int X;
    cout << "\nEnter the integer number X: ";
    cin >> X;
    int col = columnWithoutGreater(A, M, X);
    if (col == -1){cout << "No columns without elements " << X << " found" << endl;}
    else {cout << "Column number (from 1): " << col << endl;}
    int S = sumAbs(A, M);
    cout << "\nSum of negative element modules = " << S << endl;
    for (int i = 0; i < M; i++){delete[] A[i];}
    delete[] A;
    return 0;
}

void fill(int ** a, int n){
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 201 - 100;
}

void print(int ** a, int n){
    cout << "\nМатрица:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){cout.width(5); cout << a[i][j];}
        cout << endl;
    }
}

int minDiagSum(int ** a, int n){
    int mainSum = 0;
    int sideSum = 0;
    for (int i = 0; i < n; i++){mainSum += a[i][i]; sideSum += a[i][n - 1 - i];}
    return (mainSum < sideSum) ? mainSum : sideSum;
}

int columnWithoutGreater(int ** a, int n, int x){
    for (int j = 0; j < n; j++){
        bool ok = true;
        for (int i = 0; i < n; i++){
            if (a[i][j] > x){ok = false; break;}
        }
        if (ok){return j + 1;}
    }
    return -1;
}

int sumAbs(int ** a, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] < 0){sum += abs(a[i][j]);}
        }
    }
    return sum;
}
