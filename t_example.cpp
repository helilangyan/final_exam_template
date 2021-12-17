//Program to demonstrate a function template.
#include <iostream>
#include <string>
using namespace std;

//Interchanges the values of variable1 and variable2.
//The assignment operator must work for the type T.
template<class T>
void swapValues(T& variable1, T& variable2)
{
      T temp;

      temp = variable1;
      variable1 = variable2;
      variable2 = temp;
}

int main( )
{
    int integer1 = 1, integer2 = 2;
    cout << "Original integer values are "
         << integer1 << " " << integer2 << endl;
    swapValues(integer1, integer2);
    cout << "Swapped integer values are "
         << integer1 << " " << integer2 << endl;

    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character values are: "
         << symbol1 << " " << symbol2 << endl;
    swapValues(symbol1, symbol2);
    cout << "Swapped character values are: "
         << symbol1 << " " << symbol2 << endl;

    string S1("to be or not to be");
    string S2 = "that is the question";
    cout << "Original Strings: "
         << "S1 = " << S1 << " << S2 = " << S2 << endl;
    swap(S1,S2);
    cout << "Final Strings: "
         << "S1 = " << S1 << " << S2 = " << S2 << endl;

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {11,12,13,14,15,16,17,18,19,20};


    cout << "&a[0] = " << &a[0] << "  " << "&b[0] = " << &b[0] << endl;
    cout << "Initial array: " << endl;
        for(int i = 0; i < 10; ++i)
         cout << "a[i] = " << a[i] << " " << "b[i] = " << b[i] << endl;

    swap(a,b);
    cout << "&a[0] = " << &a[0] << "  " << "&b[0] = " << &b[0] << endl;
    cout << "Final array: " << endl;
        for(int i = 0; i < 10; ++i)
         cout << "a[i] = " << a[i] << " " << "b[i] = " << b[i] << endl;

    return 0;
}
/***************** Results ******************
./a.out
Original integer values are 1 2
Swapped integer values are 2 1
Original character values are: A B
Swapped character values are: B A
Original Strings: S1 = to be or not to be << S2 = that is the question
Final Strings: S1 = that is the question << S2 = to be or not to be
Initial array: 
a[i] = 0 b[i] = 11
a[i] = 1 b[i] = 12
a[i] = 2 b[i] = 13
a[i] = 3 b[i] = 14
a[i] = 4 b[i] = 15
a[i] = 5 b[i] = 16
a[i] = 6 b[i] = 17
a[i] = 7 b[i] = 18
a[i] = 8 b[i] = 19
a[i] = 9 b[i] = 20
Final array: 
a[i] = 11 b[i] = 0
a[i] = 12 b[i] = 1
a[i] = 13 b[i] = 2
a[i] = 14 b[i] = 3
a[i] = 15 b[i] = 4
a[i] = 16 b[i] = 5
a[i] = 17 b[i] = 6
a[i] = 18 b[i] = 7
a[i] = 19 b[i] = 8
a[i] = 20 b[i] = 9


****/
