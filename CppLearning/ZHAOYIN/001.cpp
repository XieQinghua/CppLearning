#include <iostream>
#include <string>
using namespace std;

void func(float x){
    string str = "abcdefghijklmnopqrstuvwxyz";
    string strRet = "";
//判断正负数
    int flag = ; 
    x = flag?x:-x;
//n为整数 m为小数部分
    long n = (long)x;
    int m = _______【2】__________;
//整数部分处理
    while(n){
        strRet =strRet+str[n%26];
        n =;
   }
//小数部分处理
    string str2 = "";
    if(m>0){
        while(m){
            str2 =________【5】__________;
            m =________【6】__________;
        }
        strRet = strRet + "." + str2;
    }
    strRet = (flag?"":"-") + strRet;
    cout << strRet << endl;
}
