#ifndef BONE_H
#define BONE_H

#include "transformation.h"


class Bone : public Transformation
{
public:
    Bone(QString id);



private:
    QString boneID;
};

#endif // BONE_H
