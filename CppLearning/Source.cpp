#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Data {
	string str;
	int times;
};

Data d[10000];

bool cmp(Data&a, Data&b) {
	return a.times<b.times;
}
int main() {
	string input, output;
	cin >> input;
	int index = 0;
	int length = input.length();
	int index_data = 0;
	while (index<length) {
		//string substr;
		//string num;

		int index_sub = 0;
		int sum = 0;
		while (input[index] >= 'a'&&input[index] <= 'z') {
			//cout<<input[index]<<endl;
			d[index_data].str[index_sub++] = input[index++];
			cout << d[index_data].str[index_sub - 1] << " " << index_sub << endl;
		}

		cout << d[index_data].str << endl;
		cout << "length = " << d[index_data].str.length() << endl;
		while (input[index] >= '0'&&input[index] <= '9') {
			//substr[index_num++] = input[index++];
			sum = sum * 10 + (input[index++] - '0');
		}
		d[index_data++].times = sum;
	}

	sort(d, d + index_data, cmp);
	for (int i = 0; i<10; i++) {
		//		if(d[i].str.length()==0){
		//			cout<<"0";
		//		}
		cout << d[i].str << " " << d[i].times << endl;
	}
	cin.get();
	return 0;
}