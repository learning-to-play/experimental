gcc -c -fPIC test.cc -o test.o
gcc -fPIC -shared test.o -o libtest.so
file test.o
file libtest.so
./test.o
./libtest.so 
