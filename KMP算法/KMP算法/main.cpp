//
//  main.cpp
//  KMP算法
//
//  Created by baimo on 2021/7/18.
//  Copyright © 2021 baimo. All rights reserved.
//

#include <iostream>
using namespace std;

void KMP(int pos,string atrs,string atrt, int nextval[]);

int main(int argc, const char * argv[]) {
    
    string mainstr;
    string str;
    int position;
    cout<<"请输入主字符串：";
    cin >> mainstr;
    cout <<"请输入子串：";
    cin >> str;
    cout <<"请输入一个位置序号：";
    cin >> position;
   
    // 计算next数组dasdsad
    int next[100];
    next[1] = 0;
    int str_i = 1;
    int j = 0;
    while(str_i<str.length())
    {
        if(j==0 || str[str_i-1] == str[j-1])  // string 数组下标与字符的实际位置相差一，所以要减去一
        {
            ++str_i;
            ++j;
            next[str_i] = j;
        }else{
            j = next[j];
        }
    }
    
    // 计算nextval数组
    int nextval[100];
    nextval[1] = 0;
    int val_i = 1;
    int val_j = 0;
    while(val_i<str.length())
    {
        if(val_j == 0 || str[val_i-1] == str[val_j-1]) // 同理
        {
            val_i++;
            val_j++;
            if(str[val_i-1] != str[val_j-1])  // 同理
            {
                nextval[val_i] = val_j;
            }
            else
            {
                nextval[val_i] = nextval[val_j];
            }
        }else
        {
            val_j = nextval[val_j];
        }
    }
 
    
    cout << "字符串："<<str <<endl;
    cout<< "next数组：";
    for (int i=1;i<=str.length();i++)
    {
        cout <<next[i];
    }
   
    cout <<endl;
    cout <<"nextval数组：";
    for (int i=1;i<=str.length();i++)
    {
        cout <<nextval[i];
    }
    cout << endl;
    
    KMP(position,mainstr,str,nextval);
    
    return 0;
}
void KMP(int pos,string atrs,string atrt, int nextval[])
{
    int i= pos;
    int j = 1;
    while(j<=atrt.length()&& i<=atrs.length())
    {
        if (j == 0 || atrs[i-1] == atrt[j-1])
        {
            i++;
            j++;
        }else{
            j = nextval[j];
        }
    }
    if(j>atrt.length())
    {
        cout <<"在第"<<pos<<"位以后，第一次相同的位置是 "<< i-atrt.length()<<" "<<endl;
    }
    else{
        cout <<" 子串在第" << pos <<"位之后，并未出现！！！"<<endl;
    }
    
    
}
