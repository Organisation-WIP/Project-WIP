#ifndef MODEL_H
#define MODEL_H

#include <QMap>
#include <QString>
#include "node.h"
#include "bone.h"


class Model : public Node
{
public:
    Model();
    Bone* getBone(QString boneID);

private:
    QMap<QString, Bone*> rig;
};

#endif // MODEL_H
