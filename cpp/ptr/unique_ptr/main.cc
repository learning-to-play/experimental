#include <memory>
#include <iostream>

using namespace std;

int main()
{
    unique_ptr<int> unique_ptr0 = make_unique<int>(42);
    int* raw_ptr = unique_ptr0.get();
    cout << "*unique_ptr0:" << *unique_ptr0 << endl;
    cout << "unique_ptr:" << unique_ptr0 << endl;
    cout << "&unique_ptr:" << &unique_ptr0 << endl;
    cout << "*raw_ptr:" << *raw_ptr << endl;
    cout << "raw_ptr:" << raw_ptr << endl;
    cout << "&raw_ptr:" << &raw_ptr << endl;
 
    unique_ptr<int> unique_ptr1 = move(unique_ptr0);
    cout << "*unique_ptr1:" << *unique_ptr1 << endl;
    cout << "unique_ptr1:" << unique_ptr1 << endl;
    cout << "&unique_ptr1:" << &unique_ptr1 << endl;
    # No output!
    cout << "*unique_ptr0:" << *unique_ptr0 << endl;
    cout << "unique_ptr:" << unique_ptr0 << endl;
    cout << "&unique_ptr:" << &unique_ptr0 << endl;

    return 0;
}
