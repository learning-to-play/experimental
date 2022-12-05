BASH_SOURCE_DIR="$(dirname "${BASH_SOURCE}")"

sudo rm -rf bazel-*
sudo rm -rf /tmp/packages/*

source ${BASH_SOURCE_DIR}/docker_config.sh
source ${BASH_SOURCE_DIR}/docker_pull.sh ${DOCKER_IMAGE}
source ${BASH_SOURCE_DIR}/docker_run.sh ${DOCKER_IMAGE}
# source ${BASH_SOURCE_DIR}/docker_update_version_nightly.sh
source ${BASH_SOURCE_DIR}/docker_build_target_disk_cache.sh \
  tensorflow/tools/pip_package:build_pip_package

if ${BUILD_PIP_PACKAGE}; then
  source ${BASH_SOURCE_DIR}/docker_construct_pip_package.sh
  source ${BASH_SOURCE_DIR}/docker_rename_and_verify_wheels.sh
fi

if ${BUILD_PIP_PACKAGE} && ${RUN_PIP_TESTS}; then
  source ${BASH_SOURCE_DIR}/docker_run_pip_tests.sh
fi

if ${RUN_NONPIP_TESTS}; then
  source ${BASH_SOURCE_DIR}/docker_run_nonpip_tests.sh
fi

if ${BUILD_PIP_PACKAGE} && ${INSTALL_PIP_PACKAGE}; then
  pip install "/tmp/packages/tensorflow-${TF_VERSION}-cp39-cp39-linux_x86_64.whl"
  pip install numpy==${NUMPY_VERSION} # See https://github.com/freqtrade/freqtrade/issues/4281

  python ${BASH_SOURCE_DIR}/keras_beginner.py
fi

source ${BASH_SOURCE_DIR}/docker_stop.sh
source ${BASH_SOURCE_DIR}/docker_remove.sh
