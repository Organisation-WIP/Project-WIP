#include "animationbonekeyframe.h"

AnimationBoneKeyframe::AnimationBoneKeyframe()
{

}


bool AnimationBoneKeyframe::isRelative()
{
    return relative;
}

void AnimationBoneKeyframe::setTransX(float x)
{
    transX = true;
    trans[0] = x;
}
void AnimationBoneKeyframe::setTransY(float y)
{
    transY = true;
    trans[1] = y;
}
void AnimationBoneKeyframe::setTransZ(float z)
{
    transZ = true;
    trans[2] = z;
}
void AnimationBoneKeyframe::setRotX(float x)
{
    rotX = true;
    rot[0] = x;
}
void AnimationBoneKeyframe::setRotY(float y)
{
    rotY = true;
    rot[1] = y;
}
void AnimationBoneKeyframe::setRotZ(float z)
{
    rotZ = true;
    rot[2] = z;
}
void AnimationBoneKeyframe::setScalX(float x)
{
    scalX = true;
    scal[0] = x;
}
void AnimationBoneKeyframe::setScalY(float y)
{
    scalY = true;
    scal[1] = y;
}
void AnimationBoneKeyframe::setScalZ(float z)
{
    scalZ = true;
    scal[2] = z;
}

QString AnimationBoneKeyframe::getID()
{
    return boneID;
}
bool AnimationBoneKeyframe::isSetTransX()
{
    return transX;
}
float AnimationBoneKeyframe::getTransX()
{
    return trans[0];
}
bool AnimationBoneKeyframe::isSetTransY()
{
    return transY;
}
float AnimationBoneKeyframe::getTransY()
{
    return trans[1];
}
bool AnimationBoneKeyframe::isSetTransZ()
{
    return transZ;
}
float AnimationBoneKeyframe::getTransZ()
{
    return trans[2];
}
bool AnimationBoneKeyframe::isSetRotX()
{
    return rotX;
}
float AnimationBoneKeyframe::getRotX()
{
    return rot[0];
}
bool AnimationBoneKeyframe::isSetRotY()
{
    return rotY;
}
float AnimationBoneKeyframe::getRotY()
{
    return rot[1];
}
bool AnimationBoneKeyframe::isSetRotZ()
{
    return rotZ;
}
float AnimationBoneKeyframe::getRotZ()
{
    return rot[2];
}
bool AnimationBoneKeyframe::isSetScalX()
{
    return scalX;
}
float AnimationBoneKeyframe::getScalX()
{
    return scal[0];
}
bool AnimationBoneKeyframe::isSetScalY()
{
    return scalY;
}
float AnimationBoneKeyframe::getScalY()
{
    return scal[1];
}
bool AnimationBoneKeyframe::isSetScalZ()
{
    return scalZ;
}
float AnimationBoneKeyframe::getScalZ()
{
    return scal[2];
}
