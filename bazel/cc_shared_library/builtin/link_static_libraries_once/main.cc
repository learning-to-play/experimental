#include "a.h"
#include "b.h"
#include "c.h"
#include <iostream>

int main() {
  std::cout << "main>" << c() << std::endl;
  std::cout << "main>" << b() << std::endl;
  std::cout << "main>" << a() << std::endl;
  return 0;
}
