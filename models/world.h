#ifndef WORLD_H
#define WORLD_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"
#include "tile.h"
#include "tileplane.h"
#include "tilewithsquare.h"
#include <QVector>
#include <QList>

class World : public Model
{

public:
    World();

    void translate(float tx, float ty, float tz);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float x, float y, float z);
    void scale(float sx, float sy, float sz);

private:
    Bone* worldTrans_;
    QVector<Tile*> tile_;
};

#endif // WORLD_H
