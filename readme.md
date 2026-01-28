# Centralized Name Management (C++ OOP)

## Projet

Implémentation avancée d'une classe `Person` en C++17, illustrant la gestion manuelle et automatique de la mémoire, la sémantique de mouvement et les principes fondamentaux de la Programmation Orientée Objet (POO).

## Objectifs Pédagogiques

Ce projet sert de support pour démontrer la maîtrise de la Forme Canonique de Coplien (Règle des 5) et l'intégration de mécanismes modernes comme les Smart Pointers.

* **Gestion de la mémoire** : Utilisation mixte de pointeurs bruts (`int*`, `char*`) et de pointeurs intelligents (`std::shared_ptr`).
* **RAII** : Garantie que chaque ressource acquise est libérée automatiquement.
* **Optimisation** : Implémentation de la sémantique de mouvement pour éviter les copies coûteuses.

## Technologies Utilisées

* **Langage** : C++17
* **Build System** : CMake 3.16+
* **Compilateur** : GCC / Clang
* **Tests** : Assertions natives (C-style)

## Architecture du Projet

Le projet adopte une structure modulaire séparant l'interface, l'implémentation et les tests :
```
.
├── CMakeLists.txt           # Configuration racine
├── include/                 # En-têtes (Interface publique)
│   └── Person.h
├── src/                     # Code source (Logique métier)
│   └── Person.cpp
├── lib/                     # Configuration de la bibliothèque
│   └── CMakeLists.txt
├── app/                     # Application principale
│   ├── main.cpp
│   └── CMakeLists.txt
└── tests/                   # Suite de tests unitaires
    ├── test_person.cpp
    └── CMakeLists.txt
```

## Fonctionnalités Clés

* **Règle des 5** : Implémentation complète (Constructeurs/Assignations par copie et déplacement, Destructeur).
* **Deep Copy** : Mécanisme garantissant l'indépendance des données lors de la duplication d'objets.
* **Smart Pointers** : Utilisation de `std::shared_ptr` pour la gestion partagée de l'année de naissance.
* **Encapsulation** : Protection des données membres (`id`, `name`, `age`, `lastName`) via des accesseurs sécurisés.

## Compilation et Exécution

### Prérequis

* Un compilateur supportant le C++17 (GCC 7+, Clang 5+)
* CMake 3.16 ou supérieur

### Instructions

1. Créer le répertoire de compilation :
```bash
mkdir build && cd build
```

2. Configurer et compiler :
```bash
cmake ..
cmake --build .
```

3. Lancer l'application principale :
```bash
./app/CNM
```

4. Lancer les tests unitaires :
```bash
./tests/test_person
```

## Documentation Technique

Le projet est documenté par un rapport détaillé divisé en deux sections majeures :

* **Partie 1 : Fondamentaux** : Analyse de la Règle de 3/5, différence entre Shallow et Deep Copy.
* **Partie 2 : Modern C++** : Explication du RAII, des types de Smart Pointers et de la sémantique de mouvement (L-Values vs R-Values).