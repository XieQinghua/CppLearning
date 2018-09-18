#include<iostream>
#include<algorithm>

using namespace std;

int fire[2001];

bool cmp(int a,int b){
	return a<b;
}

bool isSJX(int a,int b,int c){
	bool issjx = false;
	if((a+b>c)&&(a+c>b)&&(b+c>a)){
		issjx = true;
	}
	return issjx;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&fire[j]);
		}
		sort(fire,fire+num,cmp);
		int count = 0;
		for(int first=0;first<num-2;first++){
			for(int second=first+1;second<num-1;second++){
				int high = num-1;
				if(isSJX(fire[first],fire[second],fire[second+1])){
					if(isSJX(fire[first],fire[second],fire[high])){
						count+=(high-second);
						//cout<<"first = "<<first<<" second = "<<second<<" high = "<<high<<endl;
						continue;
					}else{
						while(second<high){
							if(isSJX(fire[first],fire[second],fire[high])){
								count+=	(high-second);
								//cout<<"first = "<<first<<" second = "<<second<<" high = "<<high<<endl;
								break;	
							}else{
								high--;
							}
						}
					}
				}else{
					continue;	
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
