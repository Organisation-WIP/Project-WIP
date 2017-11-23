#include "model.h"

Model::Model()
{

}

Bone* Model::getBone(QString boneID)
{
    return rig.value(boneID, 0);
}
