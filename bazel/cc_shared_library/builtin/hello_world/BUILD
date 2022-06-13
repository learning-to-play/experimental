cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_binary(
    name = "hello_world_static",
    srcs = ["hello_world.cc"],
    deps = [":hello_greet"],
)

cc_shared_library(
    name = "hello_greet_cc_shared_library",
    roots = ["hello_greet"],
)

# Compare the outputs of
# $ nm -D bazel-bin/hello_world/hello_world_shared | grep 'greet'
# >>>                  U _Z9get_greetRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
# $ nm -D bazel-bin/hello_world/libhello_greet_cc_shared_library.so | grep 'greet'
# >>> 0000000000000e49 T _Z9get_greetRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
cc_binary(
    name = "hello_world_shared",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_cc_shared_library"],
    deps = ["hello_greet"],
)

cc_shared_library(
    name = "hello_greet_cc_shared_library.so", # Generates libhello_greet_cc_shared_library.so.so
    roots = ["hello_greet"],
)

cc_binary(
    name = "hello_greet_cc_binary_linkshared",  # Generates libhello_greet_cc_binary_linkshared.so.
    deps = ["hello_greet"],
    linkshared = True,
    linkstatic = True,
)

cc_binary(
    name = "hello_greet_cc_binary_linkshared.so",  # Generates hello_greet_cc_binary_linkshared.so, because name ends in .so.
    deps = ["hello_greet"],
    linkshared = True,
    linkstatic = True,
)

filegroup(
    name = "hello_greet_headers_filegroup",  # Generates no objects.
    srcs = ["hello_greet.h"],
)

cc_library(
    name = "hello_greet_headers_cc_library",  # Generates no objects.
    textual_hdrs = ["hello_greet.h"],
)

cc_binary(
    name = "hello_world_shared_srcs",
    srcs = [
        "hello_world.cc",
        "hello_greet.h",  # The header file is required for compilation.
        ":hello_greet_cc_shared_library",  # Places shared library in srcs.
    ],
)

cc_library(
    name = "hello_greet_alwayslink",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
    alwayslink = True,
)

cc_binary(
    name = "hello_greet_alwayslink_cc_binary_linkshared",
    deps = ["hello_greet"],
    linkshared = True,
    linkstatic = True,
)

cc_import(
  name = "hello_greet_cc_import",
  hdrs = ["hello_greet.h"],  # Required for compiling hello_world/hello_world.cc (later)
  # shared_library = ":hello_greet_cc_shared_library",  # ERROR: '//hello_world:hello_greet_cc_shared_library' must produce a single file
  # shared_library = ":hello_greet_cc_binary_linkshared",  # Fails because alwayslink is False by default.
  shared_library = "hello_greet_alwayslink_cc_binary_linkshared",
)

cc_binary(
    name = "hello_world_shared_deps",
    srcs = ["hello_world.cc"],
    deps = [":hello_greet_cc_import"],  # Places shared library in deps
)
