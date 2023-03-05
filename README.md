# SpaceInvaderCpp-MJ1V
VONGUE KEANU

## Treshold 0
- Ajout d'une variable RndInput dans le world parce que c'était vide.
- Changement de la création de laser de l'alien pour que ce soit juste avec des pointeurs.
```
AlienLaser& Laser = (new AlienLaser);
world.AddObject(*Laser);
```
to
```
AlienLaser* Laser = new AlienLaser();
world.AddObject(Laser);
```
- Il manquer des parenthèses lors de la création du player.
- J'ai retiré un cast dans le laser de l'alien parce que c'est déjà un game object de base.
- Dans la fonction GetPlayer du playfield Le nom "PlayerShip" était incorect.
- J'ai mis le Update du GameObject de base à 0. Utilité? je sais pas.¯\ (ツ) /¯
- Du coup j'ai notify que la boucle for se casser si on la modifier dans la boucle et du coup j'ai ajouté 2 variables pour savoir les objets à ajouté à la prochaine frame.
Et la liste des objets à supprimer à la prochaine frame.
- Du coup finalement trouver y avait un delete dans le player laser et du coup lorsque je demande à mon manager de delete il y a une erreur.

## Treshold 1
- Separation des class pour éviter que tous soit dans un seul fichier.
	- J'ai aussi rangé les fichiers pour éviter de mettre ```../``` sur certain de mes includes.
	- J'ai mis le controllerInput du PlayField en private et du coup ajout d'un Getter et un Setter.
- J'ai notifier aussi que mes ennemies spawn tous sur la même ligne parce qu'on ne set pas leur Y mais que leurs X dans le Main.
- J'ai du crée une fonction dans le PlayField qui récup le rGen que je définie dans le main pour ensuite pouvoir le récup dans le .cpp des inputs.
- J'ai déplacer le destroy des gameObject dans le parents pour évité de le refaire à chaque fois.
- Les touches peuvent être changer dans le fichier PlayerBind.h
	- Je les ai mis en dur voilà
	- J'ai mis aussi la touche échape pour sortir 
- ~Changement de ```strcpy``` en ```strcpy_s``` cause j'avais une error qui me disait que c'était "_unsafe_".~
	- ça n'a pas fonctionner du coup j'ai du mettre ```#pragma warning(disable : 4996)``` sur le fichier qui ne fonctionner pas.
- Ajout de la destruction des Aliens avec le laser du player.
	- J'aurais voulu avoir une fonction qui ne return que les aliens mais j'ais vite give up parce que il ne me renvoyait qu'un tableau vide.
- Ajout de la class ARock
	- Ajout de l'enum dans le render RS_Rock.
	- Ajout de la collision entre le laser et le rock.
	```
	if(strcmp(CurrentObject->m_ObjectType, "Rock") == 0)
	```

#### Ajout de SFML
- Succée j'arrivais pas parce que je m'étais projectDir et non pas solutionDir.
