# Examples:
# source build_target.sh hello_world:hello-world-shared

# To create a debug file add: --experimental_cc_shared_library_debug \
# Alternative way(s) to run Bazel:
#   USE_BAZEL_VERSION=rolling bazelisk build \
#   USE_BAZEL_VERSION=last_green bazelisk build \
#   ~/Workspace/bazel/bazel/bazel-bin/src/bazel build \
USE_BAZEL_VERSION=last_green bazelisk build \
  -c dbg \
  --experimental_cc_shared_library \
  --experimental_link_static_libraries_once=true \
  --experimental_cc_shared_library_debug \
  --experimental_debug_spawn_scheduler \
  --subcommands=pretty_print \
  --verbose_failures \
  $@
