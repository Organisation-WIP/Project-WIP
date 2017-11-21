#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qstring.h>


class Keyframe
{
    struct BoneInfo
    {
        QString boneID;
        int translate;
        int rotate;
        int scale;
    };

public:
    Keyframe();


};

#endif // KEYFRAME_H
