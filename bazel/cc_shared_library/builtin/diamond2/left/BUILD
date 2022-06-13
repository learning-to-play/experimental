# `left` library depends on a third_party `center` library.
cc_library(
  name = "left",
  srcs = ["left.cc"],
  hdrs = ["left.h"],
  deps = ["@diamond2_center//:center"],
  visibility = ["//visibility:public"],
)

# Exposes a shared version of `left` and exports `center`.
cc_shared_library(
  name = "left-so",
  roots = ["left"],
  exports_filter=["@diamond2_center//:center"],  # This line can be replaced by and is equivalent to `static_deps = ["@diamond2_center//:center"],`
  visibility = ["//visibility:public"],
)
