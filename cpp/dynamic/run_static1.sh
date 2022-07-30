# For detailed documentation refer to:
# https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/developing_c_and_cpp_applications_in_rhel_8/building-code-with-gcc_creating-c-or-c-applications

g++ -c hello_world/hello_world.cc hello_world/hello_greet.cc
g++ hello_world.o hello_greet.o -o hello_world.out
./hello_world.out
