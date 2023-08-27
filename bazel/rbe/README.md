bazelisk clean --expunge

bazelisk --bazelrc=.bazelrc test //hello_world:say_hello_test \
  --config=remote \
  --remote_instance_name=projects/tensorflow-devel/instances/metric_instance \
  --noremote_accept_cached \
  --cache_test_results=no \
  --google_credentials=$HOME/.config/gcloud/application_default_credentials.json
