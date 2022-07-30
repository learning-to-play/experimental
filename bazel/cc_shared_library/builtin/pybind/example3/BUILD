cc_library(
    name = "_cppmodule",
    hdrs = ["cppmodule.h"],
    srcs = ["cppmodule.cc"],
)

cc_shared_library(
    name = "cppmodule",
    roots = ["_cppmodule"],
)

cc_library(
    name = "_pyext",
    srcs = ["pyext.cc"],
    deps = [
        "@pybind11",
        "@local_config_python//:python_headers",
        ":_cppmodule"
    ],
)

cc_shared_library(
    name = "pyext",
    roots = [":_pyext"],
    dynamic_deps = [":cppmodule"],
    static_deps = [
        "@pybind11//:__subpackages__",
        "@local_config_python//:__subpackages__",
    ],
)

py_library(
    name = "pymodule",
    srcs = ["pymodule.py"],
    data = [":pyext"],
)

py_test(
    name = "pymodule_test",
    srcs = ["pymodule_test.py"],
    deps = [":pymodule"],
)