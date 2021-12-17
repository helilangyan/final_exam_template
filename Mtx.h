#include<iostream>
using namespace std;
class Mtx {                              // class for matrix
  int nrows;                             // number of rows
  int ncols;                             // number of columns
  int** ets;                             // pointer to array of (int) pointers
public:
  Mtx(int, int, int**);                              // construct a matrix
  Mtx(int, int, int = 0);                            // construct a matrix
  Mtx(const Mtx &);                                  // copy constructor
  ~Mtx();                                            // destructor
  int numrows() const { return nrows; }              // return number of rows
  int numcols() const { return ncols; }              // return number of columns
  int* operator[](int i)const { return ets[i]; } // returns row i
  void swap(int i, int j);                          //swap rows
//
  Mtx & operator=(const Mtx &rhs);              //Assignement overloaded operator
  Mtx  operator+(const Mtx &rhs);               //overloaded + operator
};
// end of matrix class

//member function definitions
Mtx::Mtx(int n, int m, int** dbp) {     // define members in Mtx 
  nrows = n;
  ncols = m;
  ets = new int* [nrows];               // array of int pointers to nrows
  for (int i =  0; i < nrows; i++) {
    ets[i] = new int[ncols];            //create array of size [cols]
    for (int j = 0; j < ncols; j++)
        ets[i][j] = dbp[i][j];          //fill array with external array
  }
}

Mtx::Mtx(int n, int m, int a) { 
  ets = new int* [nrows = n]; 
  for (int i =  0; i< nrows; i++) {
    ets[i] = new int[ncols = m];
    for (int j = 0; j < ncols; j++) ets[i][j] = a;    //constant value
  }
}
Mtx::~Mtx(){                                         // destructor
    for (int i = 0; i< nrows; i++) delete[]  ets[i];  //delete ith row
    delete[] ets;                                    //delete array of pointers
}
Mtx & Mtx::operator=(const Mtx &rhs){
        if(this != &rhs){
                delete []ets;
                nrows = rhs.nrows;
                ncols = rhs.ncols;
                ets = new int* [nrows];                 // array of int pointers to nrows
                for (int i =  0; i < nrows; i++) {
                        ets[i] = new int[ncols];        //create array of size [cols]
                        for (int j = 0; j < ncols; j++)
                                ets[i][j] = rhs[i][j];   //fill array with external array
                }
        }
        return *this;
}
Mtx Mtx::operator+(const Mtx &rhs){
                if(rhs.nrows != nrows || rhs.ncols != ncols){
                        cout << "Matrix Sizes don't match" << endl;
                        exit(1);
                }
                Mtx T(nrows, ncols, 0);         //create temp matrix
                for (int i =  0; i < nrows; i++) {
                    for (int j = 0; j < ncols; j++)
                        T.ets[i][j] = ets[i][j] + rhs[i][j];  //add matrix components
                }
        return T;
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
