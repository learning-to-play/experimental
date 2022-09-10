cc_binary(  # Note "T" in "0000000100002f24 T __Z9get_greetv"
    name = "hello_world0",
    srcs = ["//:hello_world.cc"],
)

cc_binary(  # Note "t" in "0000000100002f24 t __Z9get_greetv"
    name = "hello_world1",
    srcs = ["//:hello_world.cc"],
    additional_linker_inputs = [":version_script.lds"],
    linkopts = [
        "-Wl,-rename_section,__TEXT,text_env,__TEXT,__text",
        "-Wl,-unexported_symbols_list,$(location :version_script.lds)",
    ],
)
