#include "world.h"

World::World()
{
    worldTrans_ = new Bone("world", this);

    Tile* tilesquare;
    int x = 0, z = 0;
    for(size_t i = 0; i < 20*5; i++, x++){
        if(x == 6){
            x = 0;
            z += 1;
        }
        tilesquare = new TileWithSquare;
        tilesquare->translate(x, 0, z);
        tile_.append(tilesquare);

        worldTrans_->addChild(tilesquare);
    }

    this->addChild(worldTrans_);
}
