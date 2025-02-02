#ifndef _____LRU__
#define _____LRU__

#include <stdio.h>
#include <list>
#include <unordered_map>

class LRU{
public:
    LRU(int cacheSize);
    ~LRU();
    
    void add(int page);
    bool contains(int page);

    void setCacheSize(int cacheSize);
    void moveToBack(int page);
    void removePage(int page);
    
    int getSize() { return size; };

    float getHitRatio();
private:
    std::list<int> cache;
    std::unordered_map<int, bool> currPages;
    std::unordered_map<int, std::list<int>::iterator> itLocs;
    int cacheSize, numHits, numRequests, size;
    float hitRatio;
    
    void calculateHitRatio();
    void replacePage(int page);
};

#endif
