#pragma once

// Size du world
// Peut être casser si le world bound est trop grand dans le render console
#define WORLDBOUND Vector2D {80, 40};

// Coord du spawn du player à faire attention qu'elle soit compris dans les bordure du world
#define PLAYERSPAWN Vector2D {80/2, 40-5};

#define FRAMERATE 60

// Nombre d'alien dans le niveau
#define NBRALIEN 2

// Nombre de point de vie du player
#define PLAYERHEALTH 2

// Nombre de laser du player
#define NBRPLAYERLASER 5

// Nombre de Roche dans le monde
#define NBRROCK 150

// Nombre de laser Alien max
#define NBRALIENLASER 10

// Data de l'alien A
#define AALIENHEALTH 1
// Energy de l'alien A
#define AALIENENERGY 0
// Direction de l'alien A
#define AALIENDIRECTION 1
// Velocity de l'alien A
#define AALIENVELOCITY 0.5f


// Data de l'alien B
#define BALIENHEALTH 1
// Energy de l'alien B
#define BALIENENERGY 0
// Direction de l'alien B
#define BALIENDIRECTION 1
// Velocity de l'alien B
#define BALIENVELOCITY 0.5f
