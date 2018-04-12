//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef HASHTAG_H
#define HASHTAG_H

#include <string>

class Hashtag {
private:
    std::string _content;             // The hashtag itself
    unsigned int _startCount;         // Number of occurrences in start file
    unsigned int _endCount;           // Number of occurrences in end file
    unsigned int _startRank;          // Rank in start file
    unsigned int _endRank;            // Rank in end file
    
public:
    Hashtag(std::string content);
    std::string GetContent();
    bool operator <(const Hashtag& rhs) const;
    unsigned int GetStartCount();
    unsigned int GetStartRank();
    unsigned int GetEndCount();
    unsigned int GetEndRank();
    void SetStartCount(int newStartCount);
    void SetStartRank(int newStartRank);
    void SetEndCount(int newEndCount);
    void SetEndRank(int newEndRank);
    
};

//--------------------------------------------------------------------------------------

#endif // HASHTAG_H
