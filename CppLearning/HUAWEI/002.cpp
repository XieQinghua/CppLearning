#include<iostream>
#include<string>
using namespace std;

int main(){
	string input1,input2;
	int flag[26];
	fill(flag,flag+26,0);
	cin>>input1>>input2;
	bool yes = true;
	for(auto it = input1.begin();it!=input1.end();it++){
		flag[*it - 'A']++;
	//	cout<<"index = "<<*it - 'A'<<" it = "<<*it<<endl;
	}
	for(auto it=input2.begin();it!=input2.end();it++){
		if(flag[*it-'A']==0){
			yes = false;
			break;
		}
	}
	cout<<(yes?"true":"false")<<endl;
	return 0;
} 
