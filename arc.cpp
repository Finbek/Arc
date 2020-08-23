#include "arc.h"

ARC::ARC(int cacheSize){
    p = 0;
    numHits = 0;
    numRequests = 0;
    numMisses = 0;
    hitRatio = 0;
    this->cacheSize = cacheSize;
    
    t1 = new LRU(cacheSize);
    t2= new LRU(cacheSize);

    b1 = new LRU(cacheSize);
    b2 = new LRU(cacheSize);

}

ARC::~ARC(){
    
}
