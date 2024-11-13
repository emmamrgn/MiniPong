1. Emm4

2. objectif de l'application et comment l'utiliser (touches, but de l'app, etc.) :

    but de l'app : 
        ping pong a deux joueurs


    touches :
        touche Z/S  pour déplacer la raquette de gauche
        fleche haut/bas pour déplacer la raquette de droite

        espace pour lancer la balle
        p pour remettre les compteurs à 0 = recommencer partie



3. des explications en français de comment votre code fait les choses :

    Les Raquettes et la Balle sont des elements du Monde.
    La position des raquettes et de la balle et la vitesse de la balle sont des vecteurs.

    Les Raquettes bougent en fonction de leurs positions en y, x est fixe.
    La balle bouge en fonction de sa vitesse et accelere a chaque fois qu'elle rebondit sur une raquette.
    Lorsque la touche ESPACE est pressée, la balle part aléatoirement à gauche ou a droite.

    Le score (element du Monde aussi) est incrémenté a chaque fois que la 
    balle ne touche pas les raquettes sur les bords gauche et droit.

    Les scores sont remis a zero lorsque la touche P est pressée.




4. des références vers des documents qui vous ont servis :
    -> Pong Game (https://www.ponggame.org/)
    -> Page Web GrAPic (https://perso.liris.cnrs.fr/alexandre.meyer/grapic/html/_grapic_8h.html)



5. l'historique des évolutions :

    - 1ere semaine :
        -operateur
        -initialisation du monde avec les raquettes et la balle

    - 2eme semaine :
        -update balle pour la faire bouger
        -collisions avec les bords haut et bas

    - 3eme semaine :
        -update de la balle qui rebondit sur les raquettes => balle rebondit toujours pas
            -> fonctionne pas, la balle est bugué

        -lundi 9/05: init score + incrémentation score -> bug

    - derniere semaine :
        -finalisation, ajustement des vitesses de la balle
        -balle rebondit enfin sur les raquettes 

         
