sudo docker exec tf bazel --bazelrc=/usertools/cpu.bazelrc \
  test --config=sigbuild_local_cache \
  $@
