#include <iostream>

using namespace std;

int main()
{
    int value = 42;
    int* raw_ptr0 = &value;
    cout << "raw_ptr0:" << raw_ptr0 << endl;
    cout << "*raw_ptr0:" << *raw_ptr0 << endl;
 
    int* raw_ptr1 = new int[2];
    raw_ptr1[0] = 0;
    raw_ptr1[1] = 1;
    cout << "raw_ptr1:" << raw_ptr1 << endl;
    cout << "*raw_ptr1:" << *raw_ptr1 << endl;
    cout << "&raw_ptr1[0]:" << &raw_ptr1[0] << endl;
    cout << "&raw_ptr1[1]:" << &raw_ptr1[1] << endl;
    cout << "&raw_ptr1[2]:" << &raw_ptr1[2] << endl;

    return 0;
}
