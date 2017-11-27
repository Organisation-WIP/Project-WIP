#include "enemyship.h"

EnemyShip::EnemyShip()
{
  QString path(SRCDIR);

  m_ShipMesh = new TriangleMesh(path+"/Object/enemyship.obj");
  m_ShipDraw = new Drawable(m_ShipMesh);
  m_ShipBone = new Bone("ship", this);

  Node* TransNode = new Node(m_ShipBone);
  TransNode->addChild(new Node(m_ShipDraw));

  this->addChild(TransNode);
}

EnemyShip::~EnemyShip()
{
  delete m_ShipMesh;
  delete m_ShipDraw;
  delete m_ShipBone;
}

void EnemyShip::translate(float tx, float ty, float tz)
{
    m_ShipBone->translate(tx, ty, tz);
}

void EnemyShip::rotate(float angle, const QVector3D &axis)
{
    m_ShipBone->rotate(angle, axis);
}

void EnemyShip::rotate(float angle, float x, float y, float z)
{
    m_ShipBone->rotate(angle, x, y, z);
}

