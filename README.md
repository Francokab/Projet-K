# Projet K
 Jeu dont vous êtes le héros

# Information pour compiler
    Tous les fichiers .cpp sont dans src
    Tous les fichiers .h sont dans include
    Le programme va chercher les ficher textes dans le dossier text, et ouvre 0.txt en premier
    Le compilateur que nous avons utiliser est GCC 13.1.0 x86_64-w64-mingw32 (ucrt64)
    Vous pouvez utiliser CMAKE pour compiler
        Mais purger le dossier build si vous changer des fichiers texte car on utilise GLOB et c'est pas bien

# TODO
    - Separer JoueurHumain et JoueurMonstre dans leur propre fichier
    - Ajouter des check pour verfier les Inputs dans Narateur
    - Implementer correctement tous les delete

    - Re-re-equilibrer le jeu de sorte à ce que les PV et dégats infligées semble plus réaliste et ait un meilleur feeling
    - Faire des tests avec une classe test ?
        - tester les combats
    - ajouter plus d'option dans creation de personnage
        - plus de classe
        - choix d'atribut
        - choix de race
        - choix de magie

# Nom des variables, Classe et autre
    UneClasse
    UnFichier.cpp
    unAtribut
    uneMethod