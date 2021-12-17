// FILE NAME: mtx_t.h
#include<iostream>
using namespace std;
template <class T = int>
class Mtx_t {                              // class for matrix
  int nrows;                             // number of rows
  int ncols;                             // number of columns
  T ** ets;                             // poTer to array of (T) poTers
public:
  void print(){
    cout << "============================" << endl;
    for(int i = 0; i < this->nrows; i++){
      for(int j = 0; j < this->ncols; j++)
        cout << this->ets[i][j] << "  ";
      cout << endl;
    }
    cout << "============================" << endl;
  }
  Mtx_t(int n, int m, T** dbp)                              // construct a matrix
  {     // define members in Mtx 
    this->nrows = n;
    this->ncols = m;
    this->ets = new T* [nrows];               // array of T poTers to nrows
    for (int i =  0; i < nrows; i++) {
      ets[i] = new T[ncols];            //create array of size [cols]
      for (int j = 0; j < ncols; j++)
          ets[i][j] = dbp[i][j];          //fill array with external array
    }
  }
  Mtx_t(int n, int m, T a)                            // construct a matrix
  { 
    ets = new T* [this->nrows = n]; 
    for (int i =  0; i< nrows; i++) {
      ets[i] = new T[this->ncols = m];
      for (int j = 0; j < ncols; j++) ets[i][j] = a;    //constant value
    }
  }
  Mtx_t(const Mtx_t & old)                                  // copy constructor
  {
    for(int i = 0; i < this->nrows; i++)
      for(int j = 0; j < this->ncols; j++)
        this->ets[i][j] = old.ets[i][j];
  }
  ~Mtx_t()                                            // destructor
  {                                         // destructor
    for (int i = 0; i< nrows; i++) delete[]  ets[i];  //delete ith row
    delete[] ets;                                    //delete array of poTers
  }
  int numrows() const { return this->nrows; }              // return number of rows
  int numcols() const { return this->ncols; }              // return number of columns
  T* operator[](int i)const { return this->ets[i]; } // returns row i
  void swap(int i, int j)                          //swap rows
  {
    T * temp = this->ets[i];
    this->ets[i] = this->ets[j];
    this->ets[j] = temp;
  }
//
  Mtx_t<T> & operator=(const Mtx_t<T>& rhs);              //Assignement overloaded operator
  Mtx_t<T>  operator+(const Mtx_t<T> &rhs);               //overloaded + operator
};
// end of matrix class
/*
//member function definitions
template <class T = int>
Mtx_t::Mtx_t(int n, int m, T** dbp) {     // define members in Mtx 
  nrows = n;
  ncols = m;
  ets = new T* [nrows];               // array of T poTers to nrows
  for (T i =  0; i < nrows; i++) {
    ets[i] = new T[ncols];            //create array of size [cols]
    for (T j = 0; j < ncols; j++)
        ets[i][j] = dbp[i][j];          //fill array with external array
  }
}
template <typename T>
Mtx_t::Mtx_t(T n, T m, T a) { 
  ets = new T* [nrows = n]; 
  for (T i =  0; i< nrows; i++) {
    ets[i] = new T[ncols = m];
    for (T j = 0; j < ncols; j++) ets[i][j] = a;    //constant value
  }
}
template <class T = int>
Mtx_t::~Mtx_t(){                                         // destructor
    for (int i = 0; i< nrows; i++) delete[]  ets[i];  //delete ith row
    delete[] ets;                                    //delete array of poTers
}
template <class T = int>*/
template <class T>
Mtx_t<T> & Mtx_t<T>::operator=(const Mtx_t<T>& rhs){
        if(this != &rhs){
                delete []ets;
                nrows = rhs.nrows;
                ncols = rhs.ncols;
                ets = new T* [nrows];                 // array of T poTers to nrows
                for (int i =  0; i < nrows; i++) {
                        ets[i] = new T[ncols];        //create array of size [cols]
                        for (int j = 0; j < ncols; j++)
                                ets[i][j] = rhs[i][j];   //fill array with external array
                }
        }
        return *this;
}
template <class T>
Mtx_t<T> Mtx_t<T>::operator+(const Mtx_t<T>& rhs){
                if(rhs.nrows != this->nrows || rhs.ncols != ncols){
                        cout << "Matrix Sizes don't match" << endl;
                        exit(1);
                }
                Mtx_t<T> Temp(nrows, ncols, this->ets[0][0]);         //create temp matrix
                for (int i =  0; i < nrows; i++) {
                    for (int j = 0; j < ncols; j++)
                        Temp.ets[i][j] = ets[i][j] + rhs[i][j];  //add matrix components
                }
        return Temp;
}
/*
a.	Create a template for the above class and corresponding definitions 
b.	Instantiate  Teger matrices  A, B, C to have 8 rows & 8 columns 
c.	Initialize Matrix  element A[i][j] to be equal to (T)(i*j)
d.	Initialize Matrix elements B[i][j] to be equal to (T)(i+j)
e.	Calculate the following expression:   C = A + B
f.	Instantiate  float matrices  D, E, F to have 8 rows & 8 columns 
g.	Initialize Matrix  element D[i][j] to be equal to (float)( i*j)
h.	Initialize Matrix elements E[i][j] to be equal to (float)(i+j)
i.	Calculate the following expression:   F = D + E

*/
