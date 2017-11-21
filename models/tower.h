#ifndef TOWER_H
#define TOWER_H

#include "node.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"

class Tower : public Node
{
public:
    Tower();
    ~Tower();

    void translate(float tx, float ty, float tz);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float x, float y, float z);

private:
    TriangleMesh *m_BotMesh, *m_MidMesh, *m_TopMesh;
    Drawable *m_Bot, *m_Mid, *m_Top;
    Transformation *m_BotTrans, *m_MidTrans, *m_TopTrans;
};

#endif // TOWER_H
