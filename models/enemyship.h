#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"


class EnemyShip : public Model
{
    EnemyShip();
    ~EnemyShip();

    void translate(float tx, float ty, float tz);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float x, float y, float z);

private:
    TriangleMesh *m_ShipMesh;
    Drawable *m_ShipDraw;
    Bone *m_ShipBone;
};

#endif // ENEMYSHIP_H
