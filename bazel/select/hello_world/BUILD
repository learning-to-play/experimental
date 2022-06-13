load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

string_flag(name = "message", build_setting_default = "regular")

cc_binary(
    name = "hello_world",
    srcs = select({
        ":lowercase_message": ["hello_world_lowercase.cc"],
        ":capital_message": ["hello_world_capital.cc"],
        "//conditions:default": ["hello_world_regular.cc"],
        ":define_lowercase": ["hello_world_lowercase.cc"],
        ":define_capital": ["hello_world_capital.cc"],
    }),
)

config_setting(
    name = "lowercase_message",
    flag_values = {":message": "lowercase"},
)

config_setting(
    name = "capital_message",
    flag_values = {":message": "capital"},
)

config_setting(
    name = "define_lowercase",
    define_values = {"lowercase": "true"},
)

config_setting(
    name = "define_capital",
    define_values = {"capital": "true"},
)
