#include "Person.h"
#include <cassert>

int main() {
    Person p;
    p.mat = 42;
    p.nom = "Test";

    assert(p.mat == 42);
    assert(p.nom == "Test");

    return 0;
}
