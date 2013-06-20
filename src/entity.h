#ifndef ENTITY_H
#define ENTITY_H

#include "tile.h"

class Entity : public Tile
{
public:
    unsigned char hp;
};

#endif
