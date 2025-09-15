#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
    int16_t value = 42;
    int16_t* raw_ptr0 = &value;
    cout << "&value:" << &value << endl;
    cout << "raw_ptr0:" << raw_ptr0 << endl;
    cout << "*raw_ptr0:" << *raw_ptr0 << endl;

    // = operator copies value
    int16_t value_copy = value;
    cout << "&value_copy:" << &value_copy << endl;

    int16_t* raw_ptr1 = new int16_t[2];
    raw_ptr1[0] = 0;
    raw_ptr1[1] = 1;
    cout << "raw_ptr1:" << raw_ptr1 << endl;
    cout << "*raw_ptr1:" << *raw_ptr1 << endl;
    cout << "&raw_ptr1[0]:" << &raw_ptr1[0] << endl;
    cout << "&raw_ptr1[1]:" << &raw_ptr1[1] << endl;
    cout << "&raw_ptr1[2]:" << &raw_ptr1[2] << endl;

    return 0;
}
