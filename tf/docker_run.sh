WHEEL_DIR="/tmp/packages"
TF_DIR="${PWD}"
CACHE_DIR="/tmp/cache/bazel${PWD}"

echo "-v ${WHEEL_DIR}:/tf/pkg \\"
echo "-v ${TF_DIR}:/tf/tensorflow \\"
echo "-v ${CACHE_DIR}:/tf/cache \\"

sudo docker run --name tf -w /tf/tensorflow -it -d \
  -v "${WHEEL_DIR}:/tf/pkg" \
  -v "${TF_DIR}:/tf/tensorflow" \
  -v "${CACHE_DIR}:/tf/cache" \
  $@ \
  bash
