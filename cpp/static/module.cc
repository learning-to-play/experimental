#include "module.h"
#include <iostream>
#include <string>

void func1() {
  fprintf(stderr, "func1 %p=%s\n", &func1, std::to_string((int64_t)&func1).c_str());
}

void func2() {
  fprintf(stderr, "func2 %p=%s\n", &func2, std::to_string((int64_t)&func2).c_str());
}

static bool init = [] {
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
