def center():
    native.cc_library(
        name = "center",
        srcs = ["center.cc"],
        hdrs = ["center.h"],
    )
    return ":center"