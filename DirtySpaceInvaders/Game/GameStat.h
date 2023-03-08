#pragma once

// Size du world
#define WORLDBOUND Vector2D {160, 90};

// Coord du spawn du player à faire attention qu'elle soit compris dans les bordure du world
#define PLAYERSPAWN Vector2D {160/2,90-5};

// Nombre d'alien A dans le niveau
#define NBRAALIEN 300

// Nombre d'alien B qui spawn dans le niveau
#define NBRBALIEN 10

#define PLAYERHEALTH 2
#define NBRPLAYERLASER 50

#define NBRROCK 200

#define NBRALIENLASER 150

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
