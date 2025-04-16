#include <iostream>

using namespace std;

int main()
{
    char* data;
    data = new char[5];
    data[0] = 'a';
    data[1] = 'b';
    data[3] = 'd';
    data[10] = 'j';

    cout << data << endl;
    cout << data[0] << endl;
    cout << data[1] << endl;
    cout << data[2] << endl;
    cout << data[3] << endl;
    cout << data[10] << endl;
 
    return 0;
}