#include<iostream>
using namespace std;

char S[101][101]; /*入力用*/
int all[2]; /*全体のoとxの個数*/
int area1[2]; /*area1のoとxの個数*/
int area2[2]; /*area2のoとxの個数*/

/*areaの個数を0に初期化*/
void init(){
    for(int i = 0; i < 2; i++){
        area1[i] = 0;
        area2[i] = 0;
    }
}

int main(){
    int N, M;
    cin >> N >> M; /*入力*/

    all[0] = 0; all[1]; /*初期化*/
    /*oとxを入力し，その個数をallに格納*/
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> S[i][j];
            if(S[i][j] == 'o') all[0] += 1;
            else all[1] += 1;
        }
    }

    /*変数area1，area2の初期化*/
    init();
    int ans_yoko = 0;
    /*横に線を引いていく*/
    for(int i = 0; i < N-1; i++){
        /*area1の計算(上)*/
        for(int j = 0; j < M; j++){
            if(S[i][j] == 'o') area1[0] += 1;
            else area1[1] += 1;
        }
        /*area2の計算*/
        area2[0] = all[0] - area1[0];
        area2[1] = all[1] - area1[1];
        ans_yoko = min(area1[0]+area2[1], area1[1]+area2[0]);
    }

    /*変数area1，area2の初期化*/
    init();
    int ans_tate = 0;
    /*縦に線を引いていく*/
    for(int i = 0; i < M-1; i++){
        /*area1の計算(左)*/
        for(int j = 0; j < N; j++){
            if(S[j][i] == 'o') area1[0] += 1;
            else area1[1] += 1;
        }
        /*area2の計算*/
        area2[0] = all[0] - area1[0];
        area2[1] = all[1] - area1[1];
        ans_tate = min(area1[0]+area2[1], area1[1]+area2[0]);
    }

    cout << min(ans_yoko, ans_tate) << endl;
}
