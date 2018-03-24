//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef TRENDING_H
#define TRENDING_H

#include <string>
#include <vector>
#include "Hashtag.h"

class Trending{
private:
    std::string _startHashtagFilePath;
    std::string _endHashtagFilePath;
    std::string _outputHashtagFilePath;
    std::vector<Hashtag> _hashtags;
    
public:
    Trending(std::string startHashtagFilePath, std::string endHashtagFilePath, std::string outputHashtagFilePath);
    void Run();
};
#endif /* Trending_hpp */
