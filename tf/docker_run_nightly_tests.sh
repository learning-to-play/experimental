BASH_SOURCE_DIR="$(dirname "${BASH_SOURCE}")"

sudo rm -rf bazel-*
sudo rm -rf /tmp/packages/*

source ${BASH_SOURCE_DIR}/docker_config.sh
source ${BASH_SOURCE_DIR}/docker_pull.sh ${DOCKER_IMAGE}
source ${BASH_SOURCE_DIR}/docker_run.sh ${DOCKER_IMAGE}

if ${BUILD_PIP_PACKAGE}; then
  # source ${BASH_SOURCE_DIR}/docker_update_version_nightly.sh
  source ${BASH_SOURCE_DIR}/docker_build_target_disk_cache.sh \
    tensorflow/tools/pip_package:build_pip_package
  source ${BASH_SOURCE_DIR}/docker_construct_pip_package.sh
  source ${BASH_SOURCE_DIR}/docker_rename_and_verify_wheels.sh
fi

if ${RUN_TESTS}; then
  source ${BASH_SOURCE_DIR}/docker_test_target_disk_cache.sh --config=nonpip
fi

if ${BUILD_PIP_PACKAGE} && ${INSTALL_PIP_PACKAGE}; then
  pip install "/tmp/packages/tensorflow-${TF_VERSION}-cp39-cp39-linux_x86_64.whl"
  pip install numpy==${NUMPY_VERSION} # See https://github.com/freqtrade/freqtrade/issues/4281

  python ${BASH_SOURCE_DIR}/keras_beginner.py
fi

source ${BASH_SOURCE_DIR}/docker_stop.sh
source ${BASH_SOURCE_DIR}/docker_remove.sh
