# Generates RBE toolchain configs for a Docker image
git clone https://github.com/bazelbuild/bazel-toolchains.git

cd bazel-toolchains

docker run --rm -v $PWD:/srcdir -w /srcdir golang:1.16 go build -o rbe_configs_gen ./cmd/rbe_configs_gen/rbe_configs_gen.go


cat > /tmp/cc.json << EOF
{"CC": "/usr/lib/llvm-16/bin/clang"}
EOF

./rbe_configs_gen \
  --toolchain_container=us-central1-docker.pkg.dev/tensorflow-devel/tensorflow-devel-testing-private/cross-compile:latest \
  --output_tarball=/tmp/rbe_default.tar \
  --exec_os=linux \
  --target_os=linux \
  -cpp_env_json=/tmp/cc.json \
  -generate_java_configs=false

mkdir -p /tmp/rbe_default && tar -xf /tmp/rbe_default.tar -C /tmp/rbe_default

mv /tmp/rbe_default/* .

# Builds using RBE
bazelisk clean --expunge

bazelisk --bazelrc=.bazelrc test //hello_world2:say_hello_test \
  --config=remote \
  --remote_instance_name=projects/tensorflow-devel/instances/metric_instance \
  --noremote_accept_cached \
  --cache_test_results=no \
  --subcommands \
  --google_credentials=$HOME/.config/gcloud/application_default_credentials.json

