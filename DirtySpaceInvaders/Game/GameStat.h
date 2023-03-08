#pragma once

#define WORLDSEED 50

// Size du world
// Peut �tre casser si le world bound est trop grand dans le render console
#define WORLDBOUND Vector2D {80, 25};

// Coord du spawn du player � faire attention qu'elle soit compris dans les bordure du world
#define PLAYERSPAWN Vector2D {80/2, 25-5};

#define FRAMERATE 120

// Nombre d'alien dans le niveau
#define NBRALIEN 50

// Nombre de point de vie du player
#define PLAYERHEALTH 2

// Nombre de laser du player
#define NBRPLAYERLASER 150

// Nombre de Roche dans le monde
#define NBRROCK 150

// Nombre de laser Alien max
#define NBRALIENLASER 0

// Data de l'alien A
#define AALIENHEALTH 1
// Energy de l'alien A
#define AALIENENERGY 0
// Direction de l'alien A
#define AALIENDIRECTION 1
// Velocity de l'alien A
#define AALIENVELOCITY 0.5f


// Data de l'alien B
#define BALIENHEALTH 2
// Energy de l'alien B
#define BALIENENERGY 0
// Direction de l'alien B
#define BALIENDIRECTION 1
// Velocity de l'alien B
#define BALIENVELOCITY 1.f
