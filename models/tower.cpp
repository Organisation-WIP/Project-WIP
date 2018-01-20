#include "tower.h"

Tower::Tower(float hoehe)
{
    QString path(SRCDIR);

    //MESH
    m_BotMesh = new TriangleMesh(path+"/Object/towerbot.obj");
    m_MidMesh = new TriangleMesh(path+"/Object/towermid.obj");
    m_TopMesh = new TriangleMesh(path+"/Object/towertop.obj");

    //DRAWABLE
    m_Bot = new Drawable(m_BotMesh);
    m_Mid = new Drawable(m_MidMesh);
    m_Top = new Drawable(m_TopMesh);

    //BONE
    m_BotTrans = new Bone("bot", this);
    m_MidTrans = new Bone("mid", this);
    m_TopTrans = new Bone("top", this);

    //TEXTURE
    m_BotTexture = m_Bot->getProperty<Texture>();
    m_BotTexture->loadPicture(path + QString("/Texture/test.png"));

    m_MidTexture = m_Mid->getProperty<Texture>();
    m_MidTexture->loadPicture(path + QString("/Texture/test.png"));

    m_TopTexture = m_Top->getProperty<Texture>();
    m_TopTexture->loadPicture(path + QString("/Texture/test.png"));

    //SHADER
    m_Shader = ShaderManager::getShader(path + QString("/Shader/texture.vert"),
                                        path + QString("/Shader/texture.frag"));
    m_Bot->setShader(m_Shader);
    m_Mid->setShader(m_Shader);
    m_Top->setShader(m_Shader);

    //TRANSFORMATION
    m_MidTrans->translate(0.0, 2.0, 0.0);
    m_MidTrans->scale(1.0, hoehe, 1.0);
    m_TopTrans->translate(0.0, 2.0 + hoehe, 0.0);

    //SCENEGRAPH-TREE
    m_BotTrans->addChild(new Node(m_Bot));

    m_MidTrans->addChild(new Node(m_Mid));
    m_BotTrans->addChild(m_MidTrans);

    m_TopTrans->addChild(new Node(m_Top));
    m_BotTrans->addChild(m_TopTrans);

    this->addChild(m_BotTrans);
}

Tower::~Tower()
{
    delete m_BotMesh;
    delete m_MidMesh;
    delete m_TopMesh;

    delete m_Bot;
    delete m_Mid;
    delete m_Top;

    delete m_BotTrans;
    delete m_MidTrans;
    delete m_TopTrans;
}

void Tower::translate(float tx, float ty, float tz)
{
    m_BotTrans->translate(tx, ty, tz);
}

void Tower::rotate(float angle, const QVector3D &axis)
{
    m_BotTrans->rotate(angle, axis);
}

void Tower::rotate(float angle, float x, float y, float z)
{
    m_BotTrans->rotate(angle, x, y, z);
}

