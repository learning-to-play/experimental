cc_binary(
    name = "a1",
    srcs = [
        "a.cc",
        "a.h",
    ],
    linkshared = True,
)

cc_binary(
    name = "a2",
    srcs = [
        "a.cc",
        "a.h",
        ":a1"
    ],
    linkshared = True,
)

cc_binary(
    name = "a3",
    srcs = [
        "a.cc",
        "a.h",
        ":a2"
    ],
    linkshared = True,
)
