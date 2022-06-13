# Shows that both liba1.so and liba2.so are directly linked to liba3.so.
bazelisk build transitive_link:a3
ldd bazel-bin/transitive_link/liba3.so | grep 'liba1.so\|liba2.so\|$'
