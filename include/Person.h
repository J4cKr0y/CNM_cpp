// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory> // Pour std::shared_ptr
#include <iostream>

class Person {
private:
    int id;
    std::string name;
    int* age;                  // Raw pointer (gestion manuelle)
    char* lastName;            // Raw C-string (gestion manuelle)
    std::shared_ptr<int> birthYear; // Smart pointer

public:
    // 1. Constructeur par défaut
    Person();

    // 2. Constructeur paramétré (pour initialiser facilement)
    Person(int id, std::string name, int ageVal, const char* lName, int bYear);

    // 3. Destructeur
    ~Person();

    // 4. Constructeur par copie (Deep Copy)
    Person(const Person& other);

    // 5. Opérateur d'affectation par copie (Deep Copy)
    Person& operator=(const Person& other);

    // 6. Constructeur par déplacement (Move Constructor)
    Person(Person&& other) noexcept;

    // 7. Opérateur d'affectation par déplacement (Move Assignment)
    Person& operator=(Person&& other) noexcept;

    // Méthode utilitaire pour afficher l'objet
    void afficher() const;
};

#endif