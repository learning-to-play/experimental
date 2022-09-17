#include "center.h"
#include <string>

std::string center() {
  return "center " + std::to_string((int64_t)&center);  // Adds function address to confirm there is a single copy at execution.
}

static bool init = [] {
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
