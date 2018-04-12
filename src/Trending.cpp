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

void Trending::ReadStartHashtag()
{
    //need to read procedure
    ifstream startHashtagFile;
    startHashtagFile.open(_startHashtagFilePath);
    std::string hashtagInfo;
  //  std::string currentString;
    char currentChar;
    
    if(!startHashtagFile.is_open())
    {
        cout << "Could not open" << _startHashtagFilePath;
        return;
    }
    std::string currentString {istreambuf_iterator<char>(startHashtagFile),istreambuf_iterator<char>()};
   // while(!startHashtagFile.eof())
    //{
        //getline(startHashtagFile, currentString);
        for(unsigned int i = 0; i < currentString.length(); i++)
        {
            currentChar = currentString[i];
            if(currentChar != '\r' && currentChar != '\n' && currentChar != ' ' && currentChar != '\t')
            {
                hashtagInfo += currentChar;
            }
            else
            {
                hashtagInfo = lowerCaseConversion(hashtagInfo);
                if(hashtagInfo != "")
                {
                    bool isDuplicate = false;
                    for(unsigned int j = 0; j < _hashtags.size(); j++)
                    {
                        if(hashtagInfo == _hashtags[j].GetContent())
                        {
                            isDuplicate = true;
                            _hashtags[j].SetStartCount(_hashtags[j].GetStartCount() + 1);
                            hashtagInfo = "";
                        }
                    }
                    if(isDuplicate == false)
                    {
                        _hashtags.push_back(Hashtag(hashtagInfo));
                        _hashtags.back().SetStartCount(1);
                        hashtagInfo = "";
                    }
                } //end of if empty hashtagInfo
            }//end of else
        } //end of for loop
    std::sort(_hashtags.begin(), _hashtags.end());
    if(_hashtags.size() == 0)
    {
        return;
    }
    //
    
   // } //end of while loop
    
    
}
