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

Trending::Trending(std::string starthashtagFilePath, std::string endhashtagFilePath, std::string outputhashtagFilePath){
    _startHashtagFilePath = starthashtagFilePath;
    _endHashtagFilePath = endhashtagFilePath;
    _outputHashtagFilePath = outputhashtagFilePath;
}

void Trending::Run(){
    ReadStartHashtag();
    ReadEndHashtag();
    WriteHashtag();
}

void Trending::ReadStartHashtag(){
    
    ifstream hashtagStream {_startHashtagFilePath};
    std::string hashtagInfo;
    char currentChar;
    bool duplicate = false;
    
    if(!hashtagStream.is_open()){
        return;
    }
    
    std::string inputString {istreambuf_iterator<char>(hashtagStream),istreambuf_iterator<char>()};
    
    for(unsigned int i = 0; i < inputString.length(); i++){
        
        currentChar = inputString[i];
        
        if(currentChar != '\r' && currentChar != '\n' && currentChar != ' ' && currentChar != '\t'){
            
            hashtagInfo += currentChar;
        }
        else{
            
            hashtagInfo = lowerCaseConversion(hashtagInfo);
            
            if(hashtagInfo != ""){
                
                duplicate = false;
                
                for(unsigned int j = 0; j < _hashtags.size(); j++){
                    
                    _hashtags[j];
                    
                    if(hashtagInfo == _hashtags[j].GetContent()){
                        
                        duplicate = true;
                        
                        _hashtags[j].SetStartCount(_hashtags[j].GetStartCount() + 1);
                        
                        hashtagInfo.clear();
                    }
                }
                if(duplicate == false){
                    
                    _hashtags.push_back(Hashtag(hashtagInfo));
                    _hashtags.back().SetStartCount(1);
                    
                    hashtagInfo.clear();
                }
            }
        }
    }
    
    std::sort(_hashtags.begin(), _hashtags.end());
    
    if(_hashtags.size() == 0){
        return;
    }
    
    Hashtag previoushashtag = _hashtags[0];
    
    int currentRank = 1;
    
    for (unsigned int i = 0; i < _hashtags.size(); i++) {
        
        if (i != 0 && _hashtags[i].GetStartCount() == previoushashtag.GetStartCount()){
            
            _hashtags[i].SetStartRank(previoushashtag.GetStartRank());
            
        }
        else {
            _hashtags[i].SetStartRank(currentRank); currentRank++;
            
        }
        previoushashtag = _hashtags[i];
        
    }
}

void Trending::ReadEndHashtag(){
    
    ifstream hashtagStream {_endHashtagFilePath};
    string hashtagInfo;
    char currentChar;
    bool duplicate = false;
    
    if(!hashtagStream.is_open()){
        return;
    }
    
    string inputString {istreambuf_iterator<char>(hashtagStream),istreambuf_iterator<char>()};
    
    for(unsigned int i = 0; i < inputString.length(); i++){
        
        currentChar = inputString[i];
        
        if(currentChar != '\r' && currentChar != '\n' && currentChar != ' ' && currentChar != '\t'){
            
            hashtagInfo += currentChar;
        }
        else{
            
            hashtagInfo = lowerCaseConversion(hashtagInfo);
            
            if(hashtagInfo != ""){
                
                duplicate = false;
                
                for(unsigned int j = 0; j < _hashtags.size(); j++){
                    
                    
                    if(hashtagInfo == _hashtags[j].GetContent()){
                        
                        duplicate = true;
                        
                        _hashtags[j].SetEndCount(_hashtags[j].GetEndCount() + 1);
                        
                        hashtagInfo.clear();
                    }
                }
                if(duplicate == false){
                    
                    _hashtags.push_back(Hashtag(hashtagInfo));
                    _hashtags.back().SetEndCount(1);

                    hashtagInfo.clear();
                }
            }
        }
    }
    
    for(unsigned int k = 0; k < _hashtags.size() ; k++){
        
        if(_hashtags[k].GetEndCount() == 0){
            
            _hashtags.erase(_hashtags.begin() + k);
        }
    }
    
    std::sort(_hashtags.begin(), _hashtags.end());
    
    if(_hashtags.size() == 0){
        return;
    }
    
    Hashtag previoushashtag = _hashtags[0];
    
    int currentRank = 1;
    
    for (unsigned int i = 0; i < _hashtags.size(); i++) {
        
        if (i != 0 && _hashtags[i].GetEndCount() == previoushashtag.GetEndCount()){
            
            _hashtags[i].SetEndRank(previoushashtag.GetEndRank());
            
        }
        else {
            _hashtags[i].SetEndRank(currentRank); currentRank++;
            
        }
        previoushashtag = _hashtags[i];
        
    }
}

void Trending::WriteHashtag(){
    
    ofstream myOutputhashtag;
    myOutputhashtag.open(_outputHashtagFilePath);
    
    
    if(!myOutputhashtag.is_open()){
        cout << "file failed to open" << endl;
        return;
    }
    
    for(unsigned int i = 0; i < _hashtags.size(); i++){
        
        if(_hashtags[i].GetEndCount() != 0){
            
            if((i != 0 && _hashtags[i].GetEndRank() == _hashtags[i - 1].GetEndRank()) || (i != _hashtags.size() - 1 && _hashtags[i + 1].GetEndRank() == _hashtags[i].GetEndRank())){
                
                myOutputhashtag << "T";
            }
            
            myOutputhashtag << _hashtags[i].GetEndRank() << ": " << _hashtags[i].GetContent() << " (" ;
            
            int changeInRank = _hashtags[i].GetStartRank() - _hashtags[i].GetEndRank();
            
            if(changeInRank >= 0){
                myOutputhashtag << "+";
            }
            
            if(_hashtags[i].GetStartCount() == 0){
                myOutputhashtag << "new";
            }
            else{
                myOutputhashtag << changeInRank;
            }
            myOutputhashtag << ")" << endl;
        }
        
    }
    myOutputhashtag.close();
}


string Trending::lowerCaseConversion(string currentLine){
    
    for(unsigned int i = 0; i < currentLine.length(); i++){
        
        currentLine[i] = tolower(currentLine[i]);
        
    }
    return currentLine;
}

