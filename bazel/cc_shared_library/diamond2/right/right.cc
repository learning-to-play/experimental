#include "center.h"
#include "right.h"
#include <string>

std::string right() {
  return "right>" + center();
}

static bool init = [] {  // `init` will show twice if there is an ODR issue.
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
