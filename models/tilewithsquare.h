#ifndef TILEWITHSQUARE_H
#define TILEWITHSQUARE_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"
#include "tile.h"

class TileWithSquare : public Tile
{
public:
    TileWithSquare();
    ~TileWithSquare();

    void translate(float tx, float ty, float tz);
    void scale(float sx, float sy, float xz);
};

#endif // TILEWITHSQUARE_H
