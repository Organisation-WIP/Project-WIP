#ifndef TOWER_H
#define TOWER_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "transformation.h"
#include "texture.h"
#include "shader.h"
#include "shadermanager.h"

class Tower : public Model
{
public:
    Tower(float hoehe = 1.0f);
    ~Tower();

    void setHoehe(float hoehe);

    void translate(float tx, float ty, float tz);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float x, float y, float z);

private:
    TriangleMesh *m_BotMesh, *m_MidMesh, *m_TopMesh;
    Drawable *m_Bot, *m_Mid, *m_Top;
    Texture *m_BotTexture, *m_MidTexture, *m_TopTexture;
    Shader* m_Shader;
    Bone *m_BotTrans, *m_MidTrans, *m_TopTrans;
};

#endif // TOWER_H
