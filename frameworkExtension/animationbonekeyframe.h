#ifndef ANIMATIONBONEKEYFRAME_H
#define ANIMATIONBONEKEYFRAME_H

#include <qstring.h>


class AnimationBoneKeyframe
{
public:
    AnimationBoneKeyframe(QString id, bool relative = false);
    bool isRelative();

    void setTransX(float x);
    void setTransY(float y);
    void setTransZ(float z);
    void setRotX(float x);
    void setRotY(float y);
    void setRotZ(float z);
    void setScalX(float x);
    void setScalY(float y);
    void setScalZ(float z);

    QString getID();
    bool isSetTransX();
    float getTransX();
    bool isSetTransY();
    float getTransY();
    bool isSetTransZ();
    float getTransZ();
    bool isSetRotX();
    float getRotX();
    bool isSetRotY();
    float getRotY();
    bool isSetRotZ();
    float getRotZ();
    bool isSetScalX();
    float getScalX();
    bool isSetScalY();
    float getScalY();
    bool isSetScalZ();
    float getScalZ();

private:
    QString boneID;
    bool relative;
    bool transX=false,transY=false,transZ=false;
    float trans [3];
    bool rotX=false,rotY=false,rotZ=false;
    float rot [3];
    bool scalX=false,scalY=false,scalZ=false;
    float scal[3];
};

#endif // ANIMATIONBONEKEYFRAME_H
