sudo docker exec tf \
  ./bazel-bin/tensorflow/tools/pip_package/build_pip_package \
  /tf/pkg \
  --cpu \
  --nightly_flag
