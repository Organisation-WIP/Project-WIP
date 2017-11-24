#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>


class Keyframe
{
public:
    Keyframe(clock_t timestamp, float value);
    ~Keyframe();
    void setNext(Keyframe* kf);
    void appendKeyframe(Keyframe* kf);
    Keyframe* getNext();

    clock_t getTime();
    float getValue(clock_t currTime);
    bool isFinished(clock_t currTime);
    clock_t getDuration();

private:
    clock_t timestamp;
    float value;
    Keyframe* next;
};

#endif // KEYFRAME_H
