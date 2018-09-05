#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct data{
	char str[200];
	int times;
};

data d[100000];

bool cmp(data&a,data&b){
	if(a.times!=b.times){
		return a.times<b.times;
	}else{
		return strcmp(a.str,b.str);
	}
}
int main(){
	string input,output;
	cin>>input;
	int index = 0;
	int length = input.length();
	int index_data = 0;
	while(index<length){
		//string substr;
		//string num;
		
		int index_sub = 0;
		int sum = 0;
		while((input[index]>='a'&&input[index]<='z')||(input[index]>='A'&&input[index]<='Z')){
			//cout<<input[index]<<endl;
			d[index_data].str[index_sub++] = input[index++];
			//cout<<d[index_data].str[index_sub-1]<<" "<<index_sub<<endl;
		}
		d[index_data].str[index_sub] = '\0';
				
		while(input[index]>='0'&&input[index]<='9'){
			//substr[index_num++] = input[index++];
			sum = sum*10 + (input[index++] - '0');
		} 
		d[index_data++].times = sum;	
	}
	
	sort(d,d+index_data,cmp);
	
	//char *output = new char[total+1];
	for(int i=0;i<index_data;i++){
		for(int j = 0;j<d[i].times;j++){
			output+=d[i].str;
		}
	}
	cout<<output;
	return 0;
} 
