# Examples:
# source build_target.sh hello_world:hello-world-shared

bazelisk build \
  -c dbg \
  --experimental_cc_shared_library \
  --experimental_link_static_libraries_once=true \
  --experimental_cc_shared_library_debug \
  --output_groups=rule_impl_debug_files \
  --experimental_debug_spawn_scheduler \
  --subcommands=pretty_print \
  --verbose_failures \
  $@
