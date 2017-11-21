#ifndef KEYFRAMEBONEINFO_H
#define KEYFRAMEBONEINFO_H

#include <qstring.h>


class KeyframeBoneInfo
{
public:
    KeyframeBoneInfo(QString id);

    void setTransX(float x);
    void setTransY(float y);
    void setTransZ(float z);
    void setRotX(float x);
    void setRotY(float y);
    void setRotZ(float z);
    void setScalX(float x);
    void setScalY(float y);
    void setScalZ(float z);

private:
    QString boneID;
    bool transX=false,transY=false,transZ=false;
    float trans [3];
    bool rotX=false,rotY=false,rotZ=false;
    float rot [3];
    bool scalX=false,scalY=false,scalZ=false;
    float scal[3];
};

#endif // KEYFRAMEBONEINFO_H
