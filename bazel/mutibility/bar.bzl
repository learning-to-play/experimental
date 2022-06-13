load(":foo.bzl", "data_files")

data_files.append('file1.txt')  # runtime error, the list stored in data_files is frozen.