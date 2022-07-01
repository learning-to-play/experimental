# BEGIN_CC_BINARY_IMPLEMENTATION
# cc_binary(
#     name = "_pywrap_tensorflow_internal.so",
#     srcs = ["pywrap_tensorflow_internal.cc"],
#     linkstatic = True,
#     linkshared = True,
# )

# filegroup(
#     name = "get_pywrap_tensorflow_import_lib_file",
#     srcs = [":_pywrap_tensorflow_internal.so"],
#     output_group = "interface_library",
# )
# END_CC_BINARY_IMPLEMENTATION

# BEGIN_CC_SHARED_LIBRARY_IMPLEMENTATION
cc_library(
    name = "pywrap_tensorflow_internal",
    srcs = ["pywrap_tensorflow_internal.cc"],
    linkstatic = True,
)

cc_shared_library(
    name = "_pywrap_tensorflow_internal.so",
    roots = ["pywrap_tensorflow_internal"],
    shared_lib_name = "_pywrap_tensorflow_internal.so",
)

filegroup(
    name = "get_pywrap_tensorflow_import_lib_file",
    srcs = [":_pywrap_tensorflow_internal.so"],
    output_group = "interface_library",
)
# END_CC_SHARED_LIBRARY_IMPLEMENTATION

genrule(
    name = "pywrap_tensorflow_import_lib_file",
    srcs = [":get_pywrap_tensorflow_import_lib_file"],
    outs = ["_pywrap_tensorflow_internal.lib"],
    cmd = "cp -f $< $@",
)

cc_import(
    name = "pywrap_tensorflow_import_lib",
    interface_library = ":pywrap_tensorflow_import_lib_file",
    system_provided = 1,
)

cc_binary(
    name = "python/ops/_audio_microfrontend_op.so",
    srcs = ["audio_microfrontend_op.cc"],  # + [":libtensorflow_framework.so"]
    deps = [":pywrap_tensorflow_import_lib"],
    linkshared = True,
)
