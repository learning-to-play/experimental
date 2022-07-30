g++ -c hello_world/hello_world.cc hello_world/hello_greet.cc
ar cr libhello_greet.a hello_greet.o
g++ hello_world.o -L. -lhello_greet -o hello_world.out
./hello_world.out

