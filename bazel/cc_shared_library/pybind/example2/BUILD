cc_library(
    name = "_pyext",
    srcs = ["pyext.cc"],
    deps = [
        "@pybind11",
        "@local_config_python//:python_headers",
    ],
)

cc_shared_library(
    name = "pyext",
    roots = [":_pyext"],
    static_deps = [
        "@pybind11//:__subpackages__",
        "@local_config_python//:__subpackages__",
    ],
)

# TODO: Replace genrule with shared_lib_name
genrule(
    name = "copy_so_to_pyd",
    srcs = [":pyext"],
    outs = ["libpyext.pyd"],
    cmd = "cp $< $@",
)

py_library(
    name = "mymodule",
    srcs = ["mymodule.py"],
    data = select({
        "//:windows": [":libpyext.pyd"],
        "//conditions:default": [":pyext"],
    }),
)

py_test(
    name = "mymodule_test",
    srcs = ["mymodule_test.py"],
    deps = [":mymodule"],
)
