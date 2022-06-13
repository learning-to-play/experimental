#include "center.h"
#include "diamond2/left/left.h"
#include "diamond2/right/right.h"
#include <iostream>

int main() {
  std::cout << "main>" << left() << std::endl;
  std::cout << "main>" << right() << std::endl;
  std::cout << "main>" << center() << std::endl;
  return 0;
}

static bool init = [] {
  fprintf(stderr, "Init %s %p\n", __FILE__, &init);
  return true;
}();
