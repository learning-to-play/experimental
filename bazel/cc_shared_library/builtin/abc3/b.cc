#include "a.h"
#include "b.h"
#include <string>

std::string b() {
  return "b>" + a();
}
