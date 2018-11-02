#include"STL_Learning.h"

void use_multiset() {
	multiset<string> sss{
		"jkasd","djakf","teijo","adfae"
	};

	for (const auto&elem : sss) {
		cout << elem << endl;
	}

	sss.insert({ "hello","test" });

	for (auto it = sss.cbegin(); it != sss.cend(); it++) {
		cout << *it << endl;
	}

	multimap<int, string> sss2{{10, "Hello"}, { 2,"Apple" }};

	for (auto it = sss2.begin(); it != sss2.end();it++) {
		cout << it->first << " " << it->second << endl;
	}

	for (auto elem : sss2) {
		cout << elem.first << " " << elem.second << endl;
	}
}