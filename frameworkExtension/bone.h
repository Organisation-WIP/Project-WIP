#ifndef BONE_H
#define BONE_H

#include "node.h"
#include "transformation.h"

class Model;

class Bone : public Node
{
public:
    Bone(QString id, Model* model);
    virtual ~Bone();

    void translate(float tx, float ty, float tz);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float x, float y, float z);
    void scale(float sx, float sy, float sz);
    void resetTrafo();

    void getTranslation(float* arr);
    void getRotation(float* arr);
    void getScale(float* arr);

private:
    QString boneID;
    Transformation* transformation;
    float trans[3];
    float rot[4];
    float scal[3];
};

#endif // BONE_H
