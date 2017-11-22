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
    bool transX();
    float getTransX();
    bool transY();
    float getTransY();
    bool transZ();
    float getTransZ();
    bool rotX();
    float getRotX();
    bool rotY();
    float getRotY();
    bool rotZ();
    float getRotZ();
    bool scalX();
    float getScalX();
    bool scalY();
    float getScalY();
    bool scalZ();
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
