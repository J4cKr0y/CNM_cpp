#include <iostream>
#include "Person.h"

int main() {
    Person p;
    p.mat = 123;
    p.nom = "Dupont";

    std::cout << p.mat << " - " << p.nom << std::endl;
    return 0;
}
