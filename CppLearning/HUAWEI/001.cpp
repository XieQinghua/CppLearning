#include<iostream>
#include<string>

using namespace std;

int main(){
	string input1,input2;
	string output;
	cin>>input1>>input2;
	int index1 = input1.length()-1;
	int index2 = input2.length()-1;
	output.resize(index1+index2);
	int index3 = 0;
	int addbydigt = 0;
	int flag = 0;
	while(index1>=0&&index2>=0){
		addbydigt = ((input1[index1] - 'a') + (input2[index2] - 'a')+flag)%26;
		flag = ((input1[index1--] - 'a') + (input2[index2--] - 'a'))/26;
		output[index3++] = addbydigt + 'a';
		//cout<<"index = "<<index3<<" ouput = "<<output[index3-1]<<endl;
	}
	
	while(index1>=0){
		if(flag){
			addbydigt = (input1[index1]+flag-'a')%26;
			flag = (input1[index1--]+flag-'a')/26;
			output[index3++] = addbydigt + 'a';
		}else{
			output[index3++] = input1[index1--];
		}
		
	}
	
	while(index2>=0){
		if(flag){
			addbydigt = (input2[index2]+flag -'a')%26;
			flag = (input2[index2--]+flag-'a')/26;
			output[index3++] = addbydigt + 'a';
		}else{
			output[index3++] = input2[index2--];
		}
	}
	if(flag){
		output[index3++] = flag+'a';
		flag = 0;
	}
	for(int i = index3-1;i>=0;i--){
		cout<<output[i];
	}
	return 0;
} 
