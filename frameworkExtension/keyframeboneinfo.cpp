#include "keyframeboneinfo.h"

KeyframeBoneInfo::KeyframeBoneInfo(QString id)
{
    boneID = id;
}

void KeyframeBoneInfo::setTransX(float x)
{
    transX = true;
    trans[0] = x;
}
void KeyframeBoneInfo::setTransY(float y)
{
    transY = true;
    trans[1] = y;
}
void KeyframeBoneInfo::setTransZ(float z)
{
    transZ = true;
    trans[2] = z;
}
void KeyframeBoneInfo::setRotX(float x)
{
    rotX = true;
    rot[0] = x;
}
void KeyframeBoneInfo::setRotY(float y)
{
    rotY = true;
    rot[1] = y;
}
void KeyframeBoneInfo::setRotZ(float z)
{
    rotZ = true;
    rot[2] = z;
}
void KeyframeBoneInfo::setScalX(float x)
{
    scalX = true;
    scal[0] = x;
}
void KeyframeBoneInfo::setScalY(float y)
{
    scalY = true;
    scal[1] = y;
}
void KeyframeBoneInfo::setScalZ(float z)
{
    scalZ = true;
    scal[2] = z;
}
