# SpaceInvaderCpp-MJ1V
VONGUE KEANU

## Treshold 0
- Ajout d'une variable RndInput dans le world parce que c'était vide.
- Changement de la création de laser de l'alien pour que ce soit juste avec des pointeurs.
- Il manquer des parenthèses lors de la création du player.
- J'ai retiré un cast dans le laser de l'alien parce que c'est déjà un game object de base.
- Dans la fonction GetPlayer du playfield Le non était incorect.
- J'ai mis le Update du GameObject de base à 0. Utilité? je sais pas.¯|_(ツ)_/¯

## Treshold 1
- Separation des class pour éviter que tous soit dans un seul fichier.
- J'ai du mettre le rGen en static pour qu'il soit dans les inputs et dans le main.
- J'ai mis le controllerInput du PlayField en private et du coup ajout d'un Getter et un Setter.