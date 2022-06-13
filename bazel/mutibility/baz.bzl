load(":foo.bzl", "append_file")

append_file('file1.txt') # runtime error, append_file() attempts to modify a frozen list.