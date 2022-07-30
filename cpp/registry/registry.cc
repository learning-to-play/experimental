// https://godbolt.org/z/7P3PM86jT

#include <map>
#include <string>
#include <iostream>
class Foo;
std::map<std::string, Foo *> registry;

struct Foo {
    Foo(std::string name, int value) :
        value(value) {
            if (registry.count(name)) {
                std::cerr << "Double registration for " << name << "\n";
                exit(1);
            }
            registry[name] = this;
        }
    int value;
};
Foo foo1("foo1", 10);
Foo graph_opt_metric_collector("graph_opt", 0);

Foo graph_opt_metric_collector2("graph_opt", 0);

void graph_optimization() {
    registry.find("graph_opt")->second->value += 1;
}

int main() {
    for (auto entry : registry) std::cerr << entry.first << " has value " << entry.second->value << "\n";
}

