#include "center.h"
#include "left.h"
#include <string>

std::string left() {
  return "left>" + center();
}

static bool init = [] {
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
