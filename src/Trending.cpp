//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Trending.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Trending::Trending(std::string startHashtagFilePath, std::string endHashtagFilePath, std::string outputHashtagFilePath)
{
    _startHashtagFilePath = startHashtagFilePath;
    _endHashtagFilePath = endHashtagFilePath;
    _outputHashtagFilePath = outputHashtagFilePath;
}

void Trending::Run(){
    ReadStartHashtag();
    ReadEndHashtag();
    WriteHashtag();

}

void Trending::ReadStartHashTag(){
    
    ifstream hashTagStream {_startHashtagFilePath};
    string hashTag;
    
    if(!hashTagStream.is_open()){
        return;
    }
    
    string inputString {istreambuf_iterator<char>(hashTagStream),istreambuf_iterator<char>()};
    
    for(unsigned int i = 0; i < inputString.length(); i++){
        
        // creating a test character for the for loop to iterate
        char testChar = inputString[i];
        
        // test condition for character to not be \r, \n, \t, or whitespace
        if(testChar != '\r' && testChar != '\n' && testChar != ' ' && testChar != '\t'){
            
            // adding character onto string
            hashTag += testChar;
        }
        else{
            
            hashTag = lowerCaseConversion(hashTag);
            
            // while iterating to next set of words, testing for whitespace
            if(hashTag != ""){
                
                bool duplicate = false;
                
                for(unsigned int j = 0; j < _hashtags.size(); j++){
                    
                    _hashtags[j];
                    
                    if(hashTag == _hashtags[j].GetContent()){
                        
                        duplicate = true;
                        
                        // incrementing the count of hashtag
                        _hashtags[j].SetStartCount(_hashtags[j].GetStartCount() + 1);
                        
                        hashTag = "";
                    }
                }
                if(duplicate == false){
                    
                    // adding string onto vector
                    _hashtags.push_back(Hashtag(hashTag));
                    _hashtags.back().SetStartCount(1);
                    
                    // setting string back to blank
                    hashTag = "";
                }
            }
        }
    }
    
    // after overloading the sort operator, calling it to sort hashtag vector
    std::sort(_hashtags.begin(), _hashtags.end());
    
    if(_hashtags.size() == 0){
        return;
    }
    
    // setting the first hastag to 1 so it go through the for loop
    Hashtag previousHashtag = _hashtags[0];
    
    int currentRank = 1;
    
    for (unsigned int i = 0; i < _hashtags.size(); i++) {
        
        if (i != 0 && _hashtags[i].GetStartCount() == previousHashtag.GetStartCount()){
            
            _hashtags[i].SetStartRank(previousHashtag.GetStartRank());
            
        }
        else {
            _hashtags[i].SetStartRank(currentRank); currentRank++;
            
        }
        previousHashtag = _hashtags[i];
        
    }
}

void Trending::ReadEndHashtag(){
    return;

}

void Trending::WriteHashtag(){
    return;

}
