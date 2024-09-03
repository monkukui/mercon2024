#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;


int main(){
    registerValidation();
    
    //Nの制約を確認します．
    int N = inf.readInt(MIN_N, MAX_N);
    //空白
    inf.readSpace();
    //Kの制約を確認します．
    int K = inf.readInt(MIN_K, MAX_K);
    inf.readEoln(); // 改行
    
    //aの制約を確認します．
    for(int i = 1; i <= N; ++i){
        int a_i = inf.readInt(MIN_a, MAX_a);
        //i=1,2,...,N-1なら空白を確認，そうでなければ改行
        if(i < N) inf.readSpace();
        else inf.readEoln(); // 改行
    }
    
    //pの制約を確認します．
    for(int i = 2; i <= N; ++i){
        int p_i = inf.readInt(MIN_p, i-1); //piの最大値はi-1となることに注意
        //i=2,...,N-1なら空白を確認，そうでなければ改行
        if(i < N) inf.readSpace();
        else inf.readEoln(); // 改行
    }
    inf.readEof();
    return 0;
}
