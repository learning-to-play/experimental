#include "center.h"
#include "left.h"
#include "right.h"
#include <iostream>

int main() {
  std::cout << "main>" << left() << std::endl;
  std::cout << "main>" << right() << std::endl;
  std::cout << "main>" << center() << std::endl;
  return 0;
}
