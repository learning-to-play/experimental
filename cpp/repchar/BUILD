cc_library(
    name = "repchar",
    hdrs = ["repchar.h"],
    srcs = ["repchar.cc"],
)

cc_test(
    name = "repchar_test",
    size = "small",
    srcs = ["repchar_test.cc"],
    deps = [
        ":repchar",
        "@com_google_googletest//:gtest_main",
    ]
)