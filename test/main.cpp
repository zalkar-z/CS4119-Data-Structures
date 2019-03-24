#include <iostream>

using namespace std;

int main() {


    int x = 10;

    int *ptr = &x;

    int **pptr = &ptr;

    x = 15;

    cout << x << endl;

    cout << *ptr << endl;
    cout << ptr << endl;

    cout << **pptr << endl;
    cout << pptr << endl;



    return 0;
}