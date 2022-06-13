#include "a.h"
#include "b.h"
#include "c.h"
#include <string>

std::string c() {
  return "c>(" + b() + "," + a() + ")";
}
