py_library(
    name = "module",
    srcs = ["module.py"],
)

py_test(
    name = "module_test",
    size = "small",
    srcs = ["module_test.py"],
    deps = [":module"],
    data = [":hello_world_text_file"],
)

genrule(
    name = "hello_world_text_file",
    srcs = [],
    outs = ["hello_world.txt"],
    cmd = "echo \"Hello, World!\" > $@",
)
