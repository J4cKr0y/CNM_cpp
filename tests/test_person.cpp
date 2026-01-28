#include "Person.h"
#include <cassert>
#include <iostream>
#include <cstring> // pour strcmp

void test_constructeur_et_getters() {
    std::cout << "[TEST] Constructeur et Getters... ";
    Person p(1, "Alice", 30, "Wonderland", 1990);

    assert(p.getId() == 1);
    assert(p.getName() == "Alice");
    assert(p.getAge() == 30);
    assert(strcmp(p.getLastName(), "Wonderland") == 0);
    assert(p.getBirthYear() == 1990);
    
    std::cout << "OK" << std::endl;
}

void test_deep_copy() {
    std::cout << "[TEST] Deep Copy (Copie Profonde)... ";
    Person p1(2, "Bob", 40, "Builder", 1980);
    
    // Test du Constructeur par Copie
    Person p2 = p1; 

    // 1. Vérifier que les valeurs sont identiques
    assert(p2.getName() == p1.getName());
    assert(p2.getAge() == p1.getAge());

    // 2. CRUCIAL : Vérifier que les adresses mémoires sont DIFFERENTES
    // Si p1.age et p2.age pointent au même endroit, c'est une Shallow Copy (erreur !)
    assert(p1.getAgePtr() != p2.getAgePtr());

    // 3. Modifier p2 ne doit pas impacter p1
    // On ne peut pas modifier via getter, mais le test des adresses ci-dessus suffit
    // pour garantir l'indépendance.

    std::cout << "OK (Adresses memoire bien distinctes)" << std::endl;
}

void test_move_semantics() {
    std::cout << "[TEST] Move Semantics (Deplacement)... ";
    
    Person pSource(3, "Charlie", 20, "Chaplin", 1889);
    const int* oldAddr = pSource.getAgePtr(); // On sauvegarde l'adresse mémoire
    
    // On déplace pSource vers pDest
    Person pDest = std::move(pSource);

    // 1. Vérifier que pDest a récupéré les données
    assert(pDest.getName() == "Charlie");
    assert(pDest.getAge() == 20);
    
    // 2. Vérifier que l'adresse mémoire a été conservée (vol de pointeur)
    // pDest doit pointer exactement là où pSource pointait avant
    assert(pDest.getAgePtr() == oldAddr);

    // 3. Vérifier que la source est vide/nulle (pour éviter le double free)
    // Dans ton implémentation, move met age à nullptr
    assert(pSource.getAgePtr() == nullptr); 
    // Note: pSource.getName() est valide mais état indéfini ("" ou autre selon std::string)

    std::cout << "OK (Ressources volees avec succes)" << std::endl;
}

int main() {
    std::cout << "=== LANCEMENT DES TESTS ===" << std::endl;
    
    test_constructeur_et_getters();
    test_deep_copy();
    test_move_semantics();

    std::cout << "=== TOUS LES TESTS SONT PASSES ! ===" << std::endl;
    return 0;
}