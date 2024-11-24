PROJET C, RUOYU CHEN, SAFIANE RAS EL QDIM, CLEMENT ROUVRAIS

Lien dépôt GIT : https://github.com/JOJUCHEN/PROJET-F2-

- Projet Rover Run
Ce projet contient des implémentations diverses de structures de données (piles, files, arbres) et de gestion de déplacements sur une carte simulant le déplacement d'un robot dans un environnement déterminé.

- **Fonctionnalités** :
    - main : Le point d'entrée du projet où sont initialisées les cartes et où le programme principal est exécuté.
    - queue : Implémentation des méthodes pour gérer les files.
    - stack : Implémentation des méthodes pour gérer les piles.
    - tree : Implémentation des méthodes pour gérer les arbres, notamment la création et la gestion des noeuds.
    - map : Implémentation des méthodes pour lire et créer des cartes, calculer les coûts, et afficher les cartes.
    - loc : Implémentation des méthodes pour initialiser et mettre à jour la localisation du robot.
    - moves : Implémentation des mouvements du robot (avant, arrière, rotations).
    - nodequeue : Implémentation des méthodes pour gérer les files de noeuds, utilisées pour parcourir les arbres.
    - path : Implémentation des méthodes pour calculer le meilleur chemin pour minimiser le coût de déplacement

Installation et Exécution :
    - Ouvrir le projet dans CLion.
    - Placer votre fichier de carte dans le dossier `maps/`.
    - Modifier le chemin de fichier dans le fichier `main.c` : t_map map = createMapFromFile("..\\maps\\example1.map");
    


