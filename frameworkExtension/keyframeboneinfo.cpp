#include "keyframeboneinfo.h"

KeyframeBoneInfo::KeyframeBoneInfo(QString id, bool relative)
    :relative(relative), boneID(id)
{}
bool KeyframeBoneInfo::isRelative()
{
    return relative;
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


QString KeyframeBoneInfo::getID(){return boneID;}
bool KeyframeBoneInfo::transX(){return transX;}
float KeyframeBoneInfo::getTransX(){return trans[0];}
bool KeyframeBoneInfo::transY(){return transY;}
float KeyframeBoneInfo::getTransY(){return trans[1];}
bool KeyframeBoneInfo::transZ(){return transZ;}
float KeyframeBoneInfo::getTransZ(){return trans[2];}
bool KeyframeBoneInfo::rotX(){return rotX;}
float KeyframeBoneInfo::getRotX(){return rot[0];}
bool KeyframeBoneInfo::rotY(){return rotY;}
float KeyframeBoneInfo::getRotY(){return rot[1];}
bool KeyframeBoneInfo::rotZ(){return rotZ;}
float KeyframeBoneInfo::getRotZ(){return rot[2];}
bool KeyframeBoneInfo::scalX(){return scalX;}
float KeyframeBoneInfo::getScalX(){return scal[0];}
bool KeyframeBoneInfo::scalY(){return scalY;}
float KeyframeBoneInfo::getScalY(){return scal[1];}
bool KeyframeBoneInfo::scalZ(){return scalZ;}
float KeyframeBoneInfo::getScalZ(){return scal[2];}
