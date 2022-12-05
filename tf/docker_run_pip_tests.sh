sudo docker exec tf /usertools/setup_venv_test.sh bazel_pip "/tf/pkg/tf_nightly*.whl"
sudo docker exec tf bazel --bazelrc=/usertools/cpu.bazelrc \
  test --config=sigbuild_local_cache \
  --config=pip
