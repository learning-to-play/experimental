# Example script to build with shared libraries.
# Reference: Shared Libraries: Understanding Dynamic Loading
# (https://amir.rachum.com/blog/2016/09/17/shared-libraries/)

OUTDIR="/tmp/hello_world_$(date +"%Y%m%d_%H%M%S")"
mkdir -p ${OUTDIR}
g++ -c hello_world/hello_world.cc -o ${OUTDIR}/hello_world.o
g++ -c hello_world/hello_greet.cc -o ${OUTDIR}/hello_greet.o
g++ -shared -o ${OUTDIR}/libhello_greet.so ${OUTDIR}/hello_greet.o
# -L only affect the search path when linking (ie compiling), not during runtime (ie loading).
# -Wl passes the comma-separated flags -rpath,"\$ORIGIN" to the linker which
# adds the directory to the search for dependency at runtime.
g++ -o ${OUTDIR}/hello_world ${OUTDIR}/hello_world.o -lhello_greet -L${OUTDIR} -Wl,-rpath,"\$ORIGIN"
${OUTDIR}/hello_world

readelf -h ${OUTDIR}/hello_world | grep "Type"
readelf -l ${OUTDIR}/hello_world | grep "DYNAMIC"
readelf -S ${OUTDIR}/hello_world | grep ".dynamic"

readelf -d ${OUTDIR}/hello_world | grep "NEEDED\|path"
LD_DEBUG=libs ldd ${OUTDIR}/hello_world | grep "hello_greet"
ldd -d ${OUTDIR}/hello_world

