#include "tower.h"

Tower::Tower(float hoehe)
{
    QString path(SRCDIR);

    m_BotMesh = new TriangleMesh(path+"/Object/towerbot.obj");
    m_MidMesh = new TriangleMesh(path+"/Object/towermid.obj");
    m_TopMesh = new TriangleMesh(path+"/Object/towertop.obj");

    m_Bot = new Drawable(m_BotMesh);
    m_Mid = new Drawable(m_MidMesh);
    m_Top = new Drawable(m_TopMesh);

    m_BotTrans = new Bone("bot", this);
    m_MidTrans = new Bone("mid", this);
    m_TopTrans = new Bone("top", this);

    m_MidTrans->translate(0.0, 2.0, 0.0);
    m_MidTrans->scale(1.0, hoehe, 1.0);
    m_TopTrans->translate(0.0, 2.0 + hoehe, 0.0);

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

void Tower::setHoehe(float hoehe){
    m_MidTrans->scale(1.0, hoehe, 1.0);
    m_TopTrans->translate(0.0, 2.0 + hoehe, 0.0);
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

