//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include <string>
#include <iostream>
#include "Hashtag.h"

using namespace std;

Hashtag::Hashtag(std::string content)
{
    this->_startCount = 0;
    this->_endCount = 0;
    this->_startRank = 0;
    this->_endRank = 0;
    this->_content = content;
}
std::string Hashtag::GetContent(){ return _content;}
//bool operator <(const Hashtag& rhs) const;
unsigned int Hashtag::GetStartCount(){ return _startCount;}
unsigned int Hashtag::GetStartRank(){ return _startRank;}
unsigned int Hashtag::GetEndCount(){ return _endCount;}
unsigned int Hashtag::GetEndRank(){ return _endRank;}
void Hashtag::SetStartCount(int newStartCount){ _startCount = newStartCount;}
void Hashtag::SetStartRank(int newStartRank){ _startRank = newStartRank;}
void Hashtag::SetEndCount(int newEndCount){ _endCount = newEndCount;}
void Hashtag::SetEndRank(int newEndRank){ _endRank = newEndRank;}

//bool Card::operator<(const Card& rhs) const{
//    return rhs.GetContent().length() > _content.length();
//}

bool Hashtag::operator<(const Hashtag& rhs) const{
    
    if(_endCount != 0 || rhs._endCount!= 0){
        //if they're the same
        if(_endCount == rhs._endCount){
            return _content < rhs._content;
        }
        return rhs._endCount < _endCount;
    }
    
    else if(_startCount == rhs._startCount){
        return _content < rhs._content;
    }
    return rhs._startCount < _startCount;
}

