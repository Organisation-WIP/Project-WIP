#ifndef TILE_H
#define TILE_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"

class Tile : public Model
{
public:
    Tile();
    ~Tile();

    virtual void translate(float tx, float ty, float tz);
    virtual void scale(float sx, float sy, float sz);

protected:
    TriangleMesh *m_PlaneMesh;
    Drawable *m_Plane;
    Bone *m_PlaneTrans;
};

#endif // TILE_H
