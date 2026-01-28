// main.cpp
#include "Person.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== 1. Constructeur Parametre ===" << std::endl;
    Person p1(1, "Jean", 25, "Dupont", 1998);
    p1.afficher();

    std::cout << "\n=== 2. Constructeur par Copie (Deep Copy) ===" << std::endl;
    // Crée p2 comme une copie de p1
    Person p2 = p1; 
    p2.afficher();
    
    // Modification de p2 pour prouver que c'est une copie profonde 
    // (p1 ne doit pas changer, sauf le shared_ptr qui est partagé)
    std::cout << "... Modification de p2 (reaffectation)..." << std::endl;
    p2 = Person(2, "Marie", 30, "Curie", 1867); // Utilise constructeur param + affectation mouvement
    p2.afficher();
    std::cout << "Verif p1 (doit etre intact) : ";
    p1.afficher();

    std::cout << "\n=== 3. Semantique de Mouvement (Move) ===" << std::endl;
    // std::move force l'utilisation du constructeur de déplacement
    Person p3 = std::move(p1); 
    
    std::cout << "p3 (apres vol des ressources de p1) : ";
    p3.afficher();
    
    std::cout << "p1 (apres avoir ete deplace - etat valide mais vide) : ";
    p1.afficher(); // Devrait afficher des données vides ou nulles

    std::cout << "\n=== 4. Utilisation dans un vecteur (Gestion auto) ===" << std::endl;
    std::vector<Person> groupe;
    groupe.push_back(Person(10, "Aymard", 22, "Student", 2001)); // Déplacement implicite souvent optimisé
    groupe.push_back(std::move(p2)); // On déplace p2 dans le vecteur

    std::cout << "\n--- Fin du main ---" << std::endl;
    return 0;
}