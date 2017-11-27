#include "bone.h"
#include "model.h"

Bone::Bone(QString id, Model* model)
    :Node(transformation = new Transformation())
{
    boneID = id;
    model->rig.insert(boneID, this);

    for(int i=0;i<3;i++)
    {
        trans[i] = 0;
        rot[i] = 0;
        scal[i] = 1;
    }
    rot[3] = 0;
}
Bone::~Bone()
{
    delete transformation;
}

void Bone::translate(float tx, float ty, float tz)
{
    trans[0] = tx;
    trans[1] = ty;
    trans[2] = tz;
    transformation->translate(tx,ty,tz);
}
void Bone::rotate(float angle, const QVector3D& axis)
{
    rot[0] = angle;
    rot[1] = axis.x();
    rot[2] = axis.y();
    rot[3] = axis.z();
    transformation->rotate(angle, axis);
}
void Bone::rotate(float angle, float x, float y, float z)
{
    rot[0] = angle;
    rot[1] = x;
    rot[2] = y;
    rot[3] = z;
    transformation->rotate(angle, x, y, z);
}
void Bone::scale(float sx, float sy, float sz)
{
    scal[0] = sx;
    scal[1] = sy;
    scal[2] = sz;
    transformation->scale(sx,sy,sz);
}
void Bone::resetTrafo()
{
    for(int i=0;i<3;i++)
    {
        trans[i] = 0;
        rot[i] = 0;
        scal[i] = 1;
    }
    rot[3] = 0;
    transformation->resetTrafo();
}


void Bone::getTranslation(float* arr)
{
    for(int i=0;i<3;i++)
        arr[i] = trans[i];
}
void Bone::getRotation(float* arr)
{
    for(int i=0;i<4;i++)
        arr[i] = rot[i];
}
void Bone::getScale(float* arr)
{
    for(int i=0;i<3;i++)
        arr[i] = scal[i];
}
