sudo docker exec tf bazel --bazelrc=/usertools/cpu.bazelrc \
  build --config=sigbuild_local_cache \
  $@
