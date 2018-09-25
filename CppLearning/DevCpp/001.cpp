#include<iostream>
using namespace std;

int return_data(){
	return 100;
} 

int& return_ref(int&a){
	a*=100;
	return a;
}

int &return_local_ref(){
	int local = 100;
	return local;
}

int main(){
	
	int data = 100;
	//int a = return_data();
	const int &a = return_data();
	int &a_ref = return_ref(data);
	cout<<"a = "<<a<<endl;
	//cout<<"a_ref = "<<a_ref<<endl;
	int &b = return_local_ref();
	//cout<<b<<endl;
	return 0;
}
