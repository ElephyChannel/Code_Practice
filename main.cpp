//HW2 第一題
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

char sen[7][7];
int a1,a2,a3,a4,b1,b2,b3,b4;

void decode();
void encode();


int main()
{
    int i,j,k;
    int n;
    char ope;
    cin >>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
    cin >>n;

    //單純用來數次數，不能用來跑其他迴圈

    for(i=0;i<n;i++){

        cin >> ope;
        for(j=1;j<=6;j++){
            for(k=1;k<=6;k++){
                cin >> sen[j][k];
            }
        }


        if(ope=='d') encode();
        else if(ope =='e')decode();

    }

    return 0;
}

void decode(){

    char temp;
    int i,j,k;
    // step 1
    for(i=1;i<=6;i++){
            temp = sen[i][a1];
            sen[i][a1] = sen[i][b1];
            sen[i][b1] = temp;
    }
    //step 2
    for(i=1;i<=6;i++){
            temp = sen[a2][i];
            sen[a2][i] = sen[b2][i];
            sen[b2][i] = temp;
    }
    //step3
    for(i=1;i<=6;i++){
            temp = sen[i][a3];
            sen[i][a3] = sen[i][b3];
            sen[i][b3] = temp;
    }
    //step 4
    for(i=1;i<=6;i++){
            temp = sen[a4][i];
            sen[a4][i] = sen[b4][i];
            sen[b4][i] = temp;
    }

    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            cout << sen[i][j];
        }
    }
    cout << endl;
}


void encode(){

    char temp;
    int i,j,k;
     //step 4
    for(i=1;i<=6;i++){
            temp = sen[a4][i];
            sen[a4][i] = sen[b4][i];
            sen[b4][i] = temp;
    }


    //step3
    for(i=1;i<=6;i++){
            temp = sen[i][a3];
            sen[i][a3] = sen[i][b3];
            sen[i][b3] = temp;
    }


    //step 2
    for(i=1;i<=6;i++){
            temp = sen[a2][i];
            sen[a2][i] = sen[b2][i];
            sen[b2][i] = temp;
    }

    // step 1
    for(i=1;i<=6;i++){
            temp = sen[i][a1];
            sen[i][a1] = sen[i][b1];
            sen[i][b1] = temp;
    }
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            cout << sen[i][j];
        }
    }
    cout << endl;

}
*/

//HW2 2048題
/*
//PREPEND BEGIN

#include<iostream>

using namespace std;

struct GAME{

    int score;
    int table[4][4];

};

void show(GAME &g){

    for(int i=0;i<4;++i){

        for(int j=0;j<4;++j){

            cout<<g.table[i][j]<<",";

        }
    cout<<"\n";

    }

    cout<<"score : " << g.score<<"\n";

}

//PREPEND END

//TEMPLATE BEGIN

void up(GAME &g){


    //TODO:
    int i, j, k;
    int temp;
    // set map
    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
            if(g.table[i][j]==0&&i<=2){
                for(k=i+1;k<4;k++){
                    if(g.table[k][j]!=0){
                        temp = g.table[k][j];
                        g.table[k][j] = g.table[i][j];
                        g.table[i][j] = temp;
                        break;
                    }
                }
            }
        }
    }

    //adding
    for(j=0;j<4;j++){
        if(g.table[0][j]==g.table[1][j]){
            if(g.table[2][j]==g.table[3][j]){
                    g.table[0][j] *=2;
                    g.table[1][j] = g.table[3][j]*2;
                    g.table[2][j] = 0;
                    g.table[3][j] = 0;
                    g.score += g.table[0][j];
                    g.score += g.table[1][j];
             }
            else{
                g.table[0][j] *=2;
                g.table[1][j] = g.table[2][j];
                g.table[2][j] = g.table[3][j];
                g.table[3][j] = 0;
                g.score += g.table[0][j];
            }
        }
        else if(g.table[1][j] == g.table[2][j]){
            g.table[1][j] *=2;
            g.table[2][j] = g.table[3][j];
            g.table[3][j] = 0;
            g.score += g.table[1][j];
        }
        else if (g.table[2][j]==g.table[3][j]){
            g.table[2][j] *= 2;
            g.table[3][j] = 0;
            g.score += g.table[2][j];
        }
    }

}

void right(GAME &g){

    //TODO:
    //change the code for up to right
    int i, j, k;
    int temp;
    // set map
    for(i=0;i<4;i++){
        for(j=3;j>=0;j--){
            if(g.table[i][j]==0&&j>=1){
                for(k=j-1;k>=0;k--){
                    if(g.table[i][k]!=0){
                        temp = g.table[i][k];
                        g.table[i][k] = g.table[i][j];
                        g.table[i][j] = temp;
                        break;
                    }
                }
            }
        }
    }


    //adding

    for(i=0;i<4;i++){

        if(g.table[i][3]==g.table[i][2]){
            if(g.table[i][1]==g.table[i][0]){
                    g.table[i][3] *=2;
                    g.table[i][2] = g.table[i][0]*2;
                    g.table[i][1] = 0;
                    g.table[i][0] = 0;
                    g.score += g.table[i][3];
                    g.score += g.table[i][2];
             }
            else{

                g.table[i][3] *=2;
                g.table[i][2] = g.table[i][1];
                g.table[i][1] = g.table[i][0];
                g.table[i][0] = 0;
                g.score += g.table[i][3];
            }
        }
        else if(g.table[i][2] == g.table[i][1]){
            g.table[i][2] *=2;
            g.table[i][1] = g.table[i][0];
            g.table[i][0] = 0;
            g.score += g.table[i][2];
        }
        else if (g.table[i][1]==g.table[i][0]){
            g.table[i][1] *= 2;
            g.table[i][0] = 0;
            g.score += g.table[i][1];
        }
    }


}

//TEMPLATE END

//APPEND BEGIN

int main() {

    GAME g;

    cin>>g.score;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j) cin>>g.table[i][j];
    }

    up(g);
    show(g);
    cout<<"------------------------------\n";

    right(g);
    show(g);
    cout<<"------------------------------\n";

    return 0;

}

//APPEND END
*/

//HW2 縮寫題
/*
#include<iostream>
#include<cstring>
using namespace std;

int n ;
char ** word ;
char sen[1000];
//APPEND BEGIN

void cut();
void shorter();

int main() {


    int i, j, k;


    cin >> n;

    word = new char * [n];

    //為甚麼此處不能直接把字直接弄到指標裡面?

    for(i=0;i<n;i++){
        word[i] = new char[20];
        cin >> word[i];
    }
    cin >> sen;
    cut();
    shorter();

    return 0;

}

//對於處理字串還是很不熟練
void cut(){

    int start = 0;
    int i, j, k;
    int flag = 0;
    //flag = 1代表要切掉

    //i用來控制cut的次數
    for(i=0;i<n;i++){

        while(1){

            for(j=start;j<strlen(sen);j++){
                for(k=0;k<strlen(word[i]);k++){

                }
            }
            start++;
            if(){
                start = 0;
                break;
            }
        }


    }

}

void shorter(){

    // 前面不能動到底線，因為這裡用底線判斷
    int stop;
    int flag = 0;
    int i, j, k;
    for(i=0;i<strlen(sen);i++){
        if(flag == 0&&sen[i]!='_'){
            cout <<(char)(sen[i]-32);
            flag = 1;
        }
        else if (flag == 1){
            if(sen[i]=='_') flag = 0;
        }b
}
*/

//HW2 幾A幾B



