cc_binary(
    name = "pyext.so",
    srcs = ["pyext.cc"],
    deps = [
        "@pybind11",
        "@local_config_python//:python_headers"
    ],
    linkshared = True,
)

genrule(
    name = "copy_so_to_pyd",
    srcs = ["pyext.so"],
    outs = ["pyext.pyd"],
    cmd = "cp $< $@",
)

py_binary(
    name = "mymodule",
    srcs = ["mymodule.py"],
    data = select({
        "//:windows": [":pyext.pyd"],
        "//conditions:default": [":pyext.so"],
    }),
    deps = [
        "@absl_py//absl:app",
        "@six_archive//:six",
    ]
)
