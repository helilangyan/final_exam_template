// FILE NAME: main.cpp
#include <iostream>
#include "Mtx.h"
#include "mtx_t.h"
using namespace std;
int main(){
    // b. Instantiate  integer matrices  A, B, C to have 8 rows & 8 columns
    Mtx_t<int> A(8, 8, 0);
    Mtx_t<int> B(8, 8, 0);
    Mtx_t<int> C(8, 8, 0);

    // c. Initialize Matrix  element A[i][j] to be equal to (int)(i*j)
    for(int i = 0; i < A.numrows(); i++){
        for(int j = 0; j < A.numcols(); j++){
            A[i][j] = i * j;
        }
    }

    // d. Initialize Matrix elements B[i][j] to be equal to (int)(i+j)
    for(int i = 0; i < B.numrows(); i++){
        for(int j = 0; j < B.numcols(); j++){
            B[i][j] = i + j;
        }
    }

    // e. Calculate the following expression:   C = A + B
    C = A + B;

    //Instantiate  float matrices  D, E, F to have 8 rows & 8 columns
    Mtx_t<float> D(8, 8, 0.0);
    Mtx_t<float> E(8, 8, 0.0);
    Mtx_t<float> F(8, 8, 0.0);

    
    for(int i = 0; i < D.numrows(); i++){
        for(int j = 0; j < D.numcols(); j++){
            //Initialize Matrix  element D[i][j] to be equal to (float)( i*j)
            D[i][j] = (float)i * (float)j;

            //Initialize Matrix elements E[i][j] to be equal to (float)(i+j)
            E[i][j] = (float)i + (float)j;
        }
    }

    // Calculate the following expression:   F = D + E
    F = D + E;


    // verify them
    cout << "A";
    A.print();
    cout << "B";
    B.print();
    cout << "C";
    C.print();
    cout << "D";
    D.print();
    cout << "E";
    E.print();
    cout << "F";
    F.print();


    return 0;
}
/*
a.	Create a template for the above class and corresponding definitions 
b.	Instantiate  integer matrices  A, B, C to have 8 rows & 8 columns 
c.	Initialize Matrix  element A[i][j] to be equal to (int)(i*j)
d.	Initialize Matrix elements B[i][j] to be equal to (int)(i+j)
e.	Calculate the following expression:   C = A + B
f.	Instantiate  float matrices  D, E, F to have 8 rows & 8 columns 
g.	Initialize Matrix  element D[i][j] to be equal to (float)( i*j)
h.	Initialize Matrix elements E[i][j] to be equal to (float)(i+j)
i.	Calculate the following expression:   F = D + E

*/