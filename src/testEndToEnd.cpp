//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "Trending.h"
#include <algorithm>

using namespace std;

void EndToEndTester::RunTests(){
    for(int i = 0; i < 10; i++){
        cout << "Running file test " << i << endl;
        TestFile(i);
    }
}


/*
 * @requirement pass if all lines in files are the exact same (strcmp returns 0) AND output files can be opened properly
 * @return pass: 1, fail: 0
 */
int EndToEndTester::TestFile(int testNum){
    stringstream startHashtagsPath;
    startHashtagsPath << TEST_FILE_RELATIVE_PATH << "/startHashtags" << testNum << ".txt";
    
    stringstream endHashtagsPath;
    endHashtagsPath << TEST_FILE_RELATIVE_PATH << "/endHashtags" << testNum << ".txt";
    
    stringstream outputPath;
    outputPath << TEST_FILE_RELATIVE_PATH << "/output" << testNum << ".txt";
    
    stringstream myOutputPath;
    myOutputPath << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum << ".txt";
    
    //Create trending object
    Trending myTrend(startHashtagsPath.str(), endHashtagsPath.str(), myOutputPath.str());
    
    
    //Read start of hashtags
   // myTrend.ReadStartHashtag();
    
    //Write the hashtag to the file
 //   myTrend.WriteHashTag();
    
    
    ifstream myOutputStream;
    ifstream outputStream;
    
  
    return false;
}
