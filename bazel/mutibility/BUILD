load(":foo.bzl", "data_files")
# load(":bar.bzl", "data_files")  # runtime error
# load(":baz.bzl", "data_files")  # runtime error

py_library(
    name = "data",
    data = data_files,
)

py_binary(
    name = "main",
    srcs = ["main.py"],
    data = ["//:data"],
    python_version = "PY3",
)