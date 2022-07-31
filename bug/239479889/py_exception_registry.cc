#include "py_exception_registry.h"
#include <iostream>

int PyExceptionRegistry::singleton_ = -1;

void PyExceptionRegistry::Init() {
  if (singleton_ == -1) {
    std::cout << "PyExceptionRegistry::Init() already called" << std::endl;
  }
  singleton_ = 0;
}

int PyExceptionRegistry::Lookup() {
  if (singleton_ != -1) {
    std::cout << "Must call PyExceptionRegistry::Init() before PyExceptionRegistry::Lookup()" << std::endl;
  }
  return 1;
}
