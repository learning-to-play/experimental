# The fuzzing mode runs a single specified fuzz test with sanitizer and coverage
# instrumentation. It keeps running the test with different input values until
# it finds a crash or it is explicitly terminated by the user.
bazelisk run --config=fuzztest :example_fuzz_test -- \
    --fuzz=MyTestSuite.IntegerAdditionCommutes
