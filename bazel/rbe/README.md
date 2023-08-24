bazelisk --bazelrc=.bazelrc test //hello_world:say_hello_test \
  --config=remote \
  --remote_instance_name=projects/tensorflow-devel/instances/metric_instance \
  --google_credentials=$HOME/.config/gcloud/application_default_credentials.json
