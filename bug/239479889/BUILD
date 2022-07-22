cc_library(
    name = "tensorflow_framework",
    srcs = ["tensorflow_framework.cc"],
)

cc_shared_library(
    name = "libtensorflow_framework.so.2.10.0",
    roots = [":tensorflow_framework"],
    shared_lib_name = "libtensorflow_framework.so.2.10.0",
)

filegroup(
    name = "libtensorflow_framework.so.2.10.0_filegroup",
    srcs = [":libtensorflow_framework.so.2.10.0"],
    output_group = "main_shared_library_output",
)

genrule(
        name = "libtensorflow_framework.so.2_sym",
        outs = ["libtensorflow_framework.so.2"],
        srcs = ["libtensorflow_framework.so.2.10.0_filegroup"],
        output_to_bindir = 1,
        cmd = "ln -sf $$(basename $<) $@",
    )

cc_library(
    name = "_pywrap_tensorflow_internal.so_cclib",
    srcs = ["pywrap_tensorflow_internal.cc"],
    deps = ["tensorflow_framework"],
    linkstatic = True,
)

cc_shared_library(
    name = "_pywrap_tensorflow_internal.so",
    roots = [":_pywrap_tensorflow_internal.so_cclib"],
    dynamic_deps = ["libtensorflow_framework.so.2.10.0"],
    shared_lib_name = "_pywrap_tensorflow_internal.so",
)

genrule(
    name = "lib_pywrap_tensorflow_internal.so_rule",
    srcs = [":_pywrap_tensorflow_internal.so"],
    outs = ["lib_pywrap_tensorflow_internal.so"],
    cmd = "cp $< $@",
)

cc_import(
    name = "_pywrap_tensorflow_internal_linux",
    shared_library = ":lib_pywrap_tensorflow_internal.so",
)

# cc_binary implementation
# cc_binary(
#     name = "_pywrap_py_exception_registry.so",
#     srcs = [
#         "pywrap_py_exception_registry.cc",
#         ":libtensorflow_framework.so.2",
#     ],
#     deps = [":_pywrap_tensorflow_internal_linux"],
#     linkshared = True,
# )

# cc_shared_library implementation
# cc_library(
#     name = "_pywrap_py_exception_registry.so_cclib",
#     srcs = ["pywrap_py_exception_registry.cc"],
#     deps = [
#         "_pywrap_tensorflow_internal.so_cclib",
#         ":_pywrap_tensorflow_internal_linux",
#     ],
# )

# cc_shared_library(
#     name = "_pywrap_py_exception_registry.so",
#     shared_lib_name = "_pywrap_py_exception_registry.so",
#     roots = [":_pywrap_py_exception_registry.so_cclib"],
#     dynamic_deps = [":libtensorflow_framework.so.2.10.0"],
#     static_deps = ["//:__subpackages__"],
# )

# cc_shared_library_implementation 2
cc_library(
    name = "_pywrap_py_exception_registry.so_cclib",
    srcs = ["pywrap_py_exception_registry.cc"],
    deps = ["_pywrap_tensorflow_internal.so_cclib"],
)

cc_shared_library(
    name = "_pywrap_py_exception_registry.so",
    shared_lib_name = "_pywrap_py_exception_registry.so",
    roots = [":_pywrap_py_exception_registry.so_cclib"],
    dynamic_deps = [
        ":libtensorflow_framework.so.2.10.0",
        ":_pywrap_tensorflow_internal.so",
    ],
    static_deps = ["//:__subpackages__"],
)
