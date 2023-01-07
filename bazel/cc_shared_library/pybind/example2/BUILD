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
    shared_lib_name = select({
        "//:windows": "libpyext.pyd",
       "//conditions:default": "libpyext.so",
    }),
    roots = [":_pyext"],
    static_deps = [
        "@pybind11//:__subpackages__",
        "@local_config_python//:__subpackages__",
    ],
)

py_library(
    name = "mymodule",
    srcs = ["mymodule.py"],
    data = [":pyext"],
)

py_test(
    name = "mymodule_test",
    srcs = ["mymodule_test.py"],
    deps = [":mymodule"],
)
