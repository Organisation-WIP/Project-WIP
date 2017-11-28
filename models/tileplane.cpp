#include "tileplane.h"

TilePlane::TilePlane()
{
    QString path(SRCDIR);
    m_PlaneMesh = new TriangleMesh(path+"/Object/plane.obj");
    m_Plane = new Drawable(m_PlaneMesh);
    m_PlaneTrans = new Bone("plane", this);
    m_PlaneTrans->addChild(new Node(m_Plane));

    this->addChild(m_PlaneTrans);
}

TilePlane::~TilePlane()
{
    delete m_PlaneMesh;
    delete m_Plane;
    delete m_PlaneTrans;
}

void TilePlane::translate(float tx, float ty, float tz)
{
    m_PlaneTrans->translate(tx, ty, tz);
}

void TilePlane::scale(float sx, float sy, float sz)
{
    m_PlaneTrans->scale(sx, sy, sz);
}
