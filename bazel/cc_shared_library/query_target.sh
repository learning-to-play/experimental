# Generates a text representation of the dependencys graph.
# Visualize by pasting the text into GraphViz (www.webgraphviz.com).
~/Workspace/bazel/bazel/bazel-bin/src/bazel query \
  --notool_deps \
  --noimplicit_deps \
  --output=graph \
  "deps(//$1)"

