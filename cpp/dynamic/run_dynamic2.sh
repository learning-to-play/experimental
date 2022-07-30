OUTDIR="/tmp/hello_world_$(date +"%Y%m%d_%H%M%S")"
mkdir -p "${OUTDIR}"
g++ -c hello_world/hello_world.cc hello_world/hello_greet.cc
g++ -shared -o libhello_greet.so hello_greet.o
g++ hello_world.o libhello_greet.so -o hello_world.out
LD_LIBRARY_PATH="${PWD}" ./hello_world.out

