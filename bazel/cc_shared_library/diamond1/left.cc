#include "center.h"
#include "left.h"
#include <string>

std::string left() {
  return "left>" + center();
}
