#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath> 
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> input;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		input.push_back(tmp);
	}
	int K;
	cin>>K;
	int max=-1;
	for(int i=0;i<N;i++){
		int temp_max = input[i];
		int temp_sum = abs(input[i]);
		for(int j = i+1;j<N-1;j++){
			temp_sum+=(-input[j]);
			if(temp_sum>temp_max){
				
			}
		}
	}
	
	cout<<max<<endl;
	return 0;
}
