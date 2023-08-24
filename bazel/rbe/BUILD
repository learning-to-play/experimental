load("@rules_cc//cc:defs.bzl", "cc_toolchain", "cc_toolchain_suite")
load(":cc_toolchain_config.bzl", "cc_toolchain_config")
package(default_visibility = ["//visibility:public"])

toolchain(
    name = "cc-toolchain",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
        "@bazel_tools//tools/cpp:clang",
    ],
    target_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    toolchain = ":cc-compiler-k8",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

cc_toolchain_suite(
    name = "toolchain",
    toolchains = {
        "k8|clang": ":cc-compiler-k8",
        "k8": ":cc-compiler-k8",
    },
)

cc_toolchain(
    name = "cc-compiler-k8",
    toolchain_identifier = "linux_gnu_x86",
    toolchain_config = ":linux_gnu_x86",
    all_files = ":compiler_deps",
    ar_files = ":compiler_deps",
    as_files = ":compiler_deps",
    compiler_files = ":compiler_deps",
    dwp_files = ":empty",
    linker_files = ":compiler_deps",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 1,
)

filegroup(
    name = "compiler_deps",
    srcs = glob(["extra_tools/**"], allow_empty = True) + [":builtin_include_directory_paths"],
)

cc_toolchain_config(
    name = "linux_gnu_x86",
    cpu = "k8",
    compiler = "clang",
    toolchain_identifier = "linux_gnu_x86",
    host_system_name = "i686-unknown-linux-gnu",
    target_system_name = "x86_64-unknown-linux-gnu",
    target_libc = "glibc_2.19",
    abi_version = "clang",
    abi_libc_version = "glibc_2.19",
    cxx_builtin_include_directories = [
        "/usr/local/include",
        "/usr/local/lib/clang/11.0.0/include",
        "/usr/include/x86_64-linux-gnu",
        "/usr/include",
        "/usr/local/lib/clang/11.0.0/share",
        "/usr/include/c++/5.4.0",
        "/usr/include/x86_64-linux-gnu/c++/5.4.0",
        "/usr/include/c++/5.4.0/backward",
        "/usr/local/include/c++/v1",
    ],
    tool_paths = {
        "ar": "/usr/bin/ar",
        "ld": "/usr/bin/ld",
        "llvm-cov": "/usr/local/bin/llvm-cov",
        "llvm-profdata": "/usr/local/bin/llvm-profdata",
        "cpp": "/usr/bin/cpp",
        "gcc": "/usr/local/bin/clang-11",
        "dwp": "/usr/bin/dwp",
        "gcov": "/dev/null",
        "nm": "/usr/bin/nm",
        "objcopy": "/usr/bin/objcopy",
        "objdump": "/usr/bin/objdump",
        "strip": "/usr/bin/strip",
    },
    compile_flags = [
        "-fstack-protector",
        "-Wall",
        "-Wthread-safety",
        "-Wself-assign",
        "-fcolor-diagnostics",
        "-fno-omit-frame-pointer",
    ],
    opt_compile_flags = [
        "-g0",
        "-O2",
        "-D_FORTIFY_SOURCE=1",
        "-DNDEBUG",
        "-ffunction-sections",
        "-fdata-sections",
    ],
    dbg_compile_flags = ["-g"],
    cxx_flags = ["-std=c++0x"],
    link_flags = [
        "-fuse-ld=/usr/bin/ld.gold",
        "-Wl,-no-as-needed",
        "-Wl,-z,relro,-z,now",
        "-B/usr/local/bin",
    ],
    link_libs = [
        "-lstdc++",
        "-lm",
    ],
    opt_link_flags = ["-Wl,--gc-sections"],
    unfiltered_compile_flags = [
        "-no-canonical-prefixes",
        "-Wno-builtin-macro-redefined",
        "-D__DATE__=\"redacted\"",
        "-D__TIMESTAMP__=\"redacted\"",
        "-D__TIME__=\"redacted\"",
    ],
    coverage_compile_flags = ["--coverage"],
    coverage_link_flags = ["--coverage"],
    supports_start_end_lib = True,
)

platform(
    name = "platform",
    parents = ["@local_config_platform//:host"],
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
        "@bazel_tools//tools/cpp:clang",
    ],
    exec_properties = {
        "container-image": "docker://l.gcr.io/google/rbe-ubuntu16-04@sha256:f6568d8168b14aafd1b707019927a63c2d37113a03bcee188218f99bd0327ea1",
        "OSFamily": "Linux",
    },
)
