#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>


class Keyframe
{
public:
    Keyframe(c_time time, float value);
    void setNext(Keyframe* kf);
    Keyframe* getNext();
    float getValue();

    float getValue(clock_t currTime);

private:
    clock_t time;
    Keyframe* next;
    float value;
};

#endif // KEYFRAME_H
