// Person.cpp
#include "Person.h"
#include <cstring> // Pour strlen, strcpy
#include <utility> // Pour std::move

// 1. Constructeur par défaut
Person::Person() 
    : id(0), name("Inconnu"), age(nullptr), lastName(nullptr), birthYear(nullptr) {
    std::cout << "-> Constructeur par defaut" << std::endl;
}

// 2. Constructeur paramétré
Person::Person(int id, std::string name, int ageVal, const char* lName, int bYear)
    : id(id), name(name) {
    
    // Allocation dynamique pour age (int*)
    age = new int(ageVal);

    // Allocation dynamique pour lastName (char*)
    if (lName) {
        lastName = new char[strlen(lName) + 1];
        strcpy(lastName, lName);
    } else {
        lastName = nullptr;
    }

    // Initialisation du smart pointer
    birthYear = std::make_shared<int>(bYear);

    std::cout << "-> Constructeur parametre pour " << name << std::endl;
}

// 3. Destructeur
Person::~Person() {
    // Nettoyage des raw pointers
    delete age;
    delete[] lastName;
    
    // birthYear (shared_ptr) se nettoie tout seul !
    std::cout << "-> Destructeur appele pour " << name << std::endl;
}

// 4. Constructeur par copie (DEEP COPY)
Person::Person(const Person& other) 
    : id(other.id), name(other.name), birthYear(other.birthYear) {
    // Note: birthYear est partagé (shared_ptr), mais age et lastName sont dupliqués proprement.

    // Copie profonde de age
    if (other.age) {
        age = new int(*other.age);
    } else {
        age = nullptr;
    }

    // Copie profonde de lastName
    if (other.lastName) {
        lastName = new char[strlen(other.lastName) + 1];
        strcpy(lastName, other.lastName);
    } else {
        lastName = nullptr;
    }

    std::cout << "-> Constructeur par COPIE (Deep Copy) de " << name << std::endl;
}

// 5. Opérateur d'affectation par copie
Person& Person::operator=(const Person& other) {
    if (this == &other) return *this; // Auto-affectation

    // Nettoyage des ressources existantes
    delete age;
    delete[] lastName;

    // Copie des données simples et smart pointers
    id = other.id;
    name = other.name;
    birthYear = other.birthYear; // Partage de propriété

    // Copie profonde (Deep Copy) des pointeurs bruts
    if (other.age) {
        age = new int(*other.age);
    } else {
        age = nullptr;
    }

    if (other.lastName) {
        lastName = new char[strlen(other.lastName) + 1];
        strcpy(lastName, other.lastName);
    } else {
        lastName = nullptr;
    }

    std::cout << "-> Operateur d'AFFECTATION par copie" << std::endl;
    return *this;
}

// 6. Constructeur par déplacement (Move Constructor)
Person::Person(Person&& other) noexcept
    : id(other.id), name(std::move(other.name)), 
      age(other.age), lastName(other.lastName), birthYear(std::move(other.birthYear)) {
    
    // On a "volé" les pointeurs ci-dessus. Maintenant, on annule ceux de la source
    // pour éviter que le destructeur de 'other' ne supprime la mémoire.
    other.age = nullptr;
    other.lastName = nullptr;
    // other.birthYear est déjà nullifié par std::move()

    std::cout << "-> Constructeur par DEPLACEMENT (Move) de " << name << std::endl;
}

// 7. Opérateur d'affectation par déplacement (Move Assignment)
Person& Person::operator=(Person&& other) noexcept {
    if (this == &other) return *this;

    // 1. Nettoyer nos propres ressources
    delete age;
    delete[] lastName;

    // 2. Voler les ressources de l'autre
    id = other.id;
    name = std::move(other.name);
    age = other.age;
    lastName = other.lastName;
    birthYear = std::move(other.birthYear);

    // 3. Mettre l'autre dans un état valide mais vide
    other.age = nullptr;
    other.lastName = nullptr;

    std::cout << "-> Operateur d'AFFECTATION par DEPLACEMENT" << std::endl;
    return *this;
}

void Person::afficher() const {
    std::cout << "   [ID: " << id << "] " << name;
    if (lastName) std::cout << " " << lastName;
    if (age) std::cout << ", Age: " << *age;
    if (birthYear) std::cout << ", Annee: " << *birthYear;
    std::cout << std::endl;
}

int Person::getId() const { return id; }
std::string Person::getName() const { return name; }

int Person::getAge() const {
    if (age) return *age;
    return -1; // Valeur par défaut si nul
}

const char* Person::getLastName() const {
    return lastName ? lastName : "";
}

int Person::getBirthYear() const {
    if (birthYear) return *birthYear;
    return 0;
}

const int* Person::getAgePtr() const {
    return age; // Retourne l'adresse mémoire (pour vérifier qu'elle change lors de la copie)
}