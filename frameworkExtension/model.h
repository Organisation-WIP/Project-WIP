#ifndef MODEL_H
#define MODEL_H

#include "node.h"
#include <QList>
#include "bone.h"


class Model : public Node
{
public:
    Model();

private:
    QList<Bone*> rig;
};

#endif // MODEL_H
