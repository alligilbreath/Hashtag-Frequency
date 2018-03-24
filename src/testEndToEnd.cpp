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
  
    return false;
}
