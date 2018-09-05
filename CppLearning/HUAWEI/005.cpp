#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char add1[1000000];
char add2[1000000];
char output[1000000];
int main(){
	cin>>add1>>add2;
	int index1 = strlen(add1) - 1;
	int index2 = strlen(add2) - 1;
	int index3 = 0;
	int flag = 0;
	int addnum = 0;
	while(add1[index1]!='\0'&&add2[index2]!='\0'){
		addnum = (flag + (add1[index1--] - 'a') + (add2[index2--] - 'a'));
		flag = addnum/26;
		addnum%=26;
		output[index3++] = addnum + 'a';
	}
	while(add1[index1]!='\0'){
		addnum = (flag + (add1[index1--]-'a'));
		flag = addnum/26;
		addnum%=26;
		output[index3++] = addnum+'a';
	}
	while(add2[index2]!='\0'){
		addnum = (flag + (add2[index2--]-'a'));
		flag = addnum/26;
		addnum%=26;
		output[index3++] = addnum+'a';
	}
	if(flag){
		output[index3++] = flag + 'a';
	}
	output[index3] = '\0';
	for(int i=index3-1;i>=0;i--){
		cout<<output[i];
	}
	return 0;
}
