cc_binary(
    name = "_pywrap_tensorflow_internal.so",
    srcs = ["pywrap_tensorflow_internal.cc"],
    linkshared = True,
)

cc_import(
    name = "_pywrap_tensorflow_internal",
    shared_library = ":_pywrap_tensorflow_internal.so",
)

cc_binary(
    name = "_pywrap_py_exception_registry1",
    deps = [":_pywrap_tensorflow_internal"],
    linkshared = True,
)

cc_library(
    name = "_pywrap_tensorflow_internal2",
    deps = ["_pywrap_tensorflow_internal"],
)

cc_shared_library(
    name = "_pywrap_py_exception_registry2",
    roots = [":_pywrap_tensorflow_internal2"],
)

py_library(
    name = "pywrap_py_exception_registry",
    srcs = ["pywrap_py_exception_registry.py"],
    data = [
        # "_pywrap_py_exception_registry1",
        "_pywrap_py_exception_registry2",
    ],
)
