#include "animation.h"

Animation::Animation()
    :replay(false), replayReverse(false)
{

}
void Animation::setReplay(bool replay, bool reverse)
{
    this->replay = replay;
    replayReverse = reverse;
}

void Animation::doIt()
{

}
