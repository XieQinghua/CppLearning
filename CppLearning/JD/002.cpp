#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct goods{
	int a;
	int b;
	int c;
	long long total;
	
	void add(){
		total = (long long)a+(long long)b+(long long)c;
	}
};

goods gg[500000];

bool cmp(goods a,goods b){
	return a.total<b.total;
}
int main(){

	int N;
	cin>>N;
	int count = 0;
	for(int i=0;i<N;i++){
		cin>>gg[i].a>>gg[i].b>>gg[i].c;
		gg[i].add();
	}
	sort(gg,gg+N,cmp);
	bool over = false;
	for(int i=0;i<N;i++){
		for(int j=N-1;j>i;j--){
			if(gg[i].total>gg[j].total){
				over = true;
				break;
			}else{
				if(gg[i].a<gg[j].a&&gg[i].b<gg[j].b&&gg[i].c<gg[j].c){
					count++;
					break;
				}
			}
		}
		if(over) break;
	}
	cout<<count<<endl;
	
	return 0; 
} 
