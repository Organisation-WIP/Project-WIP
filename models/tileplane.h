#ifndef TILEPLANE_H
#define TILEPLANE_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"
#include "tile.h"

class TilePlane : public Tile
{
public:
    TilePlane();
    ~TilePlane();

    void translate(float tx, float ty, float tz);
    void scale(float sx, float sy, float xz);
};

#endif // TILEPLANE_H
