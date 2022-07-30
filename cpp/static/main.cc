#include "module.h"
#include <iostream>

int main() {
  func1();
  func2();
  func1();
  func2();
  return 0;
}

static bool init = [] {
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
