#include <iostream>
using namespace std;

template <class T = int>
class Pair{
public:
        Pair(T First, T Second);
    ~Pair();
        T getFirst()const{return first;}
        T getSecond( )const{return second;}
private:
        T first;
        T second;
        T** pter;
};

int main()
{
    Pair <>C(1,2);
    Pair <float>D(5.0, 10.0);
    Pair <char>F('A', 'Z');
    cout << "first = " << C.getFirst() << endl;
    cout << "first = " << D.getFirst() << endl;
    cout << "first = " << F.getFirst() << endl;

    return 0;
}
template <class  T> 
Pair<T>::Pair(T First, T Second){
    first = First;
    second = Second;
}
template <class T>
Pair<T>::~Pair(){cout << "destructor" << endl;}
/** Results **
./a.out
first = 1
first = 5
first = A
**/