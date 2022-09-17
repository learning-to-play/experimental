cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

# Generates file libhello_greet1.so.so.
cc_shared_library(
    name = "hello_greet1.so",
    roots = [":hello_greet"],
)

# Generates file hello_greet2.so.
cc_shared_library(
    name = "hello_greet2.so",
    roots = [":hello_greet"],
    shared_lib_name = "hello_greet2.so",
)

# Target hello_greet3_so generates file hello_greet3.so.
cc_shared_library(
    name = "hello_greet3_so",
    roots = [":hello_greet"],
    shared_lib_name = "hello_greet3.so",
)
alias(
    name = "hello_greet3.so",  # Target hello_greet3.so is alias for target hello_greet3_so.
    actual = "hello_greet3_so",
)

cc_binary(
    name = "hello_world_dynamic_deps",
    srcs = ["hello_world.cc"],
    dynamic_deps = [":hello_greet1.so"],
    deps = [":hello_greet"],
)

cc_binary(
    name = "hello_world_srcs",
    srcs = [
        "hello_world.cc",
        "hello_greet.h",
        "hello_greet2.so",
    ],
)

filegroup(
    name = "hello_greet_so_filegroup",
    srcs = ["hello_greet.so"],
    output_group = "custom_name_shared_library",
)

# genrule(
#     name = "hello_greet_so_copy",
#     srcs = ["hello_greet_so_filegroup"],
#     outs = ["hello_greet.pyd"],
#     cmd = "cp $< $@",
#     output_to_bindir = True,
# )
