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
	- J'ai aussi rangé les fichiers pour éviter de mettre `../` sur certain de mes includes.
	- J'ai mis le controllerInput du PlayField en private et du coup ajout d'un Getter et un Setter.

- J'ai notifier aussi que mes ennemies spawn tous sur la même ligne parce qu'on ne set pas leur Y mais que leurs X dans le Main.

- J'ai du crée une fonction dans le PlayField qui récup le rGen que je définie dans le main pour ensuite pouvoir le récup dans le .cpp des inputs.

- J'ai déplacer le destroy des gameObject dans le parents pour évité de le refaire à chaque fois.
	- Ajout de la fonction IsType dans game Object pour plus avoir à faire la comparaison partout.

- Les touches peuvent être changer dans le fichier PlayerBind.h
	- Je les ai mis en dur voilà
	- J'ai mis aussi la touche échape pour sortir 

- ~Changement de `strcpy` en `strcpy_s` cause j'avais une error qui me disait que c'était "_unsafe_".~
	- ~ça n'a pas fonctionner du coup j'ai du mettre `#pragma warning(disable : 4996)` sur le fichier qui ne fonctionner pas.~
		- Ok c'est parce que j'avais changer la norme du language en 20 et lorsque je le remet à 14 ça passe.

- Ajout d'un exit lorsque le player  meurt. parce que.

- Lock player en world bound.

- Utilisation des macro pour set les stats un peu partout.
	- J'imagine que c'est pas ouf d'utiliser des macro pour ça mais... oui pardon
	- Les datas peuvent être modifier dans le fichier `GameStat.h`
	- Du coup j'utilise un `#include "Game/GameStat.h"` pour avoir toutes mes variables après je les undef avec mon `#include "Game/UndefAllStat.h"`

- Ajout de la destruction des Aliens avec le laser du player.
	- J'aurais voulu avoir une fonction qui ne return que les aliens mais j'ais vite give up parce que il ne me renvoyait qu'un tableau vide.

- Ajout de la class ARock
	- Ajout de l'enum dans le render RS_Rock.
	- Ajout de la collision entre le laser et le rock.
	```
	for (const auto& Object : world.GameObjects())
	{
		if (strcmp(Object->m_objType, "Rock") == 0)
		{
			if (pos.IntCmp(Object->pos))
			{
				deleted = true;
				break;
			}
		}
	}
	```

- Decrease Health de l'alien parce dans le Laser.
	- j'ai convertie la fonction decreaseHealth en fonction virtuel pour l'override dans le Alien et le Player.
	- Ajout aussi d'une variable vie dans le PlayerShip et AlienShip.

- J'ai déplacer les differents Spawn dans le playfield.

- J'ai voulu ajouter un thread pour spawn les aliens en differer mais j'avais une erreur
	- j'avais try un ça mais il a vraiment pas aimer `std::thread t1(&PlayField::SpawnAlien<Alien>, GetWorld());`
	![image error](/ImgREADME/ThreadError.jpg)

#### Ajout de SFML
- Succée j'arrivais pas parce que je m'étais projectDir et non pas solutionDir.

- Ajout de la musique je les mis à 20 de base parce que un peu fort pour moi.

- J'ai transformer le render pour qu'il puisse être passer de SFML à console.
	- Du coup j'ai passer l'enum dans une classe à part pour que les objects soit indepant du render
	- pour le moment vers 500 alien le sfml tiens bien 👍
	- Le World bound s'adapte à la size de l'écran de SFML.