#     main binary
#    /           \
#   /             \
# left-so       right (not so)
#   \             /
#    \           /
#    center (not so)
#
# We'd like the main binary to include `right` as a static archive
# and link to `left-so`, but not pull in `center` as a static archive
# since it is "reexported" by `left-so`.
# Note than `right` is statically linked to `main`. If instead `main` was
# dynamically linked to a `right-so`, `right-so` should either statically
# link `center` using `static_deps`, or dynamically link `center-so`, or
# `left-so` using `dynamic_deps`, because `right-so` is built before `main`.

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    dynamic_deps = ["//diamond2/left:left-so"],
    deps = [
        "//diamond2/left:left",
        "//diamond2/right:right",
    ],
)

