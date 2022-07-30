cc_binary(
    name = "pyext.so",
    srcs = ["pyext.cc"],
    deps = [
        "@pybind11",
        "@local_config_python//:python_headers"
    ],
    linkshared = True,
)

py_binary(
    name = "mymodule",
    srcs = ["mymodule.py"],
    data = [":pyext.so"],
)
