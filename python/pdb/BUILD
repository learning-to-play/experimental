# PDB tutorial.

py_library(
    name = "mymodule",
    srcs = ["mymodule.py"],
    srcs_version = "PY3",
)

py_binary(
    name = "myscript",
    srcs = ["myscript.py"],
    python_version = "PY3",
    deps = [":mymodule"],
)
