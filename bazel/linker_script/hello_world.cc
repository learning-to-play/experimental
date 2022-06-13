#include <ctime>
#include <iostream>
#include <string>

std::string get_greet() {
  return "Hello, World!";
}

void print_localtime() {
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char** argv) {
  std::cout << get_greet() << std::endl;
  print_localtime();
  return 0;
}
