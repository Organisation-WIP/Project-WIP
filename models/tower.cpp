#include "tower.h"

Tower::Tower()
{
    TriangleMesh *m_BotMesh, *m_MidMesh, *m_TopMesh;
    Drawable *m_Bot, *m_Mid, *m_Top;
    Transformation *m_BotTrans, *m_MidTrans, *m_TopTrans;

    QString path(SRCDIR);

    m_BotMesh = new TriangleMesh(path+"/Object/towerbot.obj");
    m_MidMesh = new TriangleMesh(path+"/Object/towermid.obj");
    m_TopMesh = new TriangleMesh(path+"/Object/towertop.obj");

    m_Bot = new Drawable(m_BotMesh);
    m_Mid = new Drawable(m_MidMesh);
    m_Top = new Drawable(m_TopMesh);

    m_BotTrans = new Transformation;
    m_MidTrans = new Transformation;
    m_TopTrans = new Transformation;

    m_MidTrans->translate(0.0, 2.0, 0.0);
    m_TopTrans->translate(0.0, 2.0, 0.0);


    Node* botTransNode = new Node(m_BotTrans);
    botTransNode->addChild(new Node(m_Bot));

    Node* midTransNode = new Node(m_MidTrans);
    midTransNode->addChild(new Node(m_Mid));
    botTransNode->addChild(midTransNode);

    Node* topTransNode = new Node(m_TopTrans);
    topTransNode->addChild(new Node(m_Top));
    midTransNode->addChild(topTransNode);

    this->addChild(botTransNode);
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

