#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include "../../common/xrand.h"
#include "constraints.hpp"
using namespace std;
using lint = long long int;

lint minN = MIN_N;
lint maxN = MAX_N;

int main() {
    for(lint casenum=minN;casenum<MAX_N;++casenum){
            std::string file_name="10_all_N_"+std::to_string(casenum)+".in";
            std::ofstream output(file_name);
            output<<casenum<<endl;
            output.close();
    }
    return 0;
}
