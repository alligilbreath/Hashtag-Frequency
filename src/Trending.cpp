//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Trending.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Trending::Trending(std::string startHashtagFilePath, std::string endHashtagFilePath, std::string outputHashtagFilePath){
    this->_startHashtagFilePath = startHashtagFilePath;
    this->_endHashtagFilePath = endHashtagFilePath;
    this->_outputHashtagFilePath = outputHashtagFilePath;
}

void Trending::Run(){
    ReadStartHashtag();
    ReadEndHashtag();
    WriteHashtag();
}

void Trending::ReadStartHashtag(){
    
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
    
    ifstream hashTagStream {_endHashtagFilePath};
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
                        _hashtags[j].SetEndCount(_hashtags[j].GetEndCount() + 1);
                        
                        hashTag = "";
                    }
                }
                if(duplicate == false){
                    
                    // adding string onto vector
                    _hashtags.push_back(Hashtag(hashTag));
                    _hashtags.back().SetEndCount(1);
                    
                    // setting string back to blank
                    hashTag = "";
                }
            }
        }
    }
    
    // for loop to erase any hashtag that doesn't exist
    for(unsigned int g = 0; g < _hashtags.size() ; g++){
        
        if(_hashtags[g].GetEndCount() == 0){
            
            _hashtags.erase(_hashtags.begin() + g);
        }
    }
    
    std::sort(_hashtags.begin(), _hashtags.end());
    
    if(_hashtags.size() == 0){
        return;
    }
    
    Hashtag previousHashtag = _hashtags[0];
    
    int currentRank = 1;
    
    // for loop to set rank
    for (unsigned int i = 0; i < _hashtags.size(); i++) {
        
        if (i != 0 && _hashtags[i].GetEndCount() == previousHashtag.GetEndCount()){
            
            _hashtags[i].SetEndRank(previousHashtag.GetEndRank());
            
        }
        else {
            _hashtags[i].SetEndRank(currentRank); currentRank++;
            
        }
        previousHashtag = _hashtags[i];
        
    }
}

void Trending::WriteHashtag(){
    
    // create file stream to write
    ofstream myOutputHashtag;
    myOutputHashtag.open(_outputHashtagFilePath);
    
    
    if(!myOutputHashtag.is_open()){
        cout << "file failed to open" << endl;
        return;
    }
    
    for(unsigned int k = 0; k < _hashtags.size(); k++){
        
        if(_hashtags[k].GetEndCount() != 0){
            
            if((k != 0 && _hashtags[k].GetEndRank() == _hashtags[k - 1].GetEndRank())|| (k != _hashtags.size() - 1 && _hashtags[k + 1].GetEndRank() == _hashtags[k].GetEndRank())){
                
                myOutputHashtag << "T";
            }
            
            myOutputHashtag << _hashtags[k].GetEndRank() << ": " << _hashtags[k].GetContent() << " (" ;
            
            int changeInRank = _hashtags[k].GetStartRank() - _hashtags[k].GetEndRank();
            
            if(changeInRank >= 0){
                myOutputHashtag << "+";
            }
            
            if(_hashtags[k].GetStartCount() == 0){
                myOutputHashtag << "new";
            }
            else{
                myOutputHashtag << changeInRank;
            }
            myOutputHashtag << ")" << endl;
        }
        
    }
    myOutputHashtag.close();
}


string Trending::lowerCaseConversion(string conversion){
    
    for(unsigned int k = 0; k < conversion.length(); k++){
        
        conversion[k] = tolower(conversion[k]);
        
    }
    return conversion;
}

