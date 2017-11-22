#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>
#include "keyframeboneinfo.h"


class Keyframe
{
public:
    Keyframe(c_time timeAfterLast);
    void addBoneInfo(KeyframeBoneInfo* info);
    void setNext(Keyframe* kf);
    void setLast(Keyframe* kf);
    Keyframe* getNext();
    Keyframe* getLast();

private:
    QList<KeyframeBoneInfo*> boneInfos;
    c_time timeAfterLast;
    Keyframe* next,last;
};

#endif // KEYFRAME_H
