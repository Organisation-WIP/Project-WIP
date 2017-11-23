#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>


class Keyframe
{
public:
    Keyframe(c_time time, float value);
    ~Keyframe();
    void setNext(Keyframe* kf);
    Keyframe* getNext();

    clock_t getTime();
    float getValue(clock_t currTime);
    float isFinished(clock_t currTime);

private:
    clock_t time;
    Keyframe* next;
    float value;
};

#endif // KEYFRAME_H
