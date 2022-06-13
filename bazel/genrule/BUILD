py_binary(
    name = "main",
    srcs = ["main.py"],
    data = [":hello_world"],
)

genrule(
    name = "hello_world",
    srcs = [],
    outs = ["hello_world.txt"],
    cmd = "echo \"Hello, World!\" > $@",
)
