#ifndef ARC
#define ARC

#include <stdio.h>
#include <algorithm>
#include "lru.h"

class ARC{
    enum Adjustment{
        MIN, MAX
    };
public:
    ARC(int cacheSize);
    ~ARC();
    
    void add(int page);
    
    float getHitRatio();
    int getNumHits() { return numHits; };
    int getNumRequests() { return numRequests; };
    int getNumMisses() { return numMisses; };
private:
    LRU *t1, *t2, *b1, *b2;
    float hitRatio;
    int numHits, numRequests, numMisses, cacheSize, p;
    
    bool checkCaseOne(int page);
    bool checkCaseTwo(int page);
    bool checkCaseThree(int page);
    bool checkCaseFour(int page);
    
    void replace(int page);
    void adjust(int page, Adjustment adjType);
    void calculateHitRatio();
};
#endif
