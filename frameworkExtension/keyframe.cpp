#include "keyframe.h"

Keyframe::Keyframe(c_time timeAfterLast)
    :next(0),last(0),timeAfterLast(timeAfterLast)
{}

Keyframe::addBoneInfo(KeyframeBoneInfo *info)
{
    boneInfos.append(info);
}

void Keyframe::setNext(Keyframe *kf)
{
    next = kf;
}
void Keyframe::setLast(Keyframe *kf)
{
    last = kf;
}
Keyframe* Keyframe::getNext()
{
    return next;
}
Keyframe* Keyframe::getLast()
{
    return last;
}
