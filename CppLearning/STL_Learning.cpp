#include"STL_Learning.h"

void use_multiset() {
	multiset<string> ms{ "apple","xiaomi","huawei","vivo","oppo" };
	for (auto&elem : ms) {
		cout << elem << " ";
	}
	cout << endl;
	for (auto it = ms.cbegin(); it != ms.cend(); it++) {
		cout << *it << " ";
	}
	/*cout << "multiset:" << endl;
	multiset<string> ms{ "B","C","A","A","A" };
	for (auto&it : ms) {
		cout << it << " ";
	}
	cout << endl << "set:" << endl;
	set<string> s{ "B","C","A","A" };
	for (auto&it : s) {
		cout << it << " ";
	}
*/
	/*set<Person, PersonSortCriterion> coll;
	coll.insert(Person("jason", "lee"));
	coll.insert(Person("Jack", "chen"));
	coll.insert(Person("apple", "lee"));
	Person p("K", "L");
	cout << p << endl;

	for (auto it = coll.begin(); it != coll.end(); it++) {
		cout << *it << endl;
	}*/

	/*multiset<string> sss{
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
	}*/
}

void use_search_set()
{
	multiset<int> ms{ 1,1,1,2,2,2,3,3,4,5,6,7,8 };
	cout << "ms.count(1) = " << ms.count(1) << endl;
	multiset<int>::iterator it1 = ms.find(2);
	cout << "ms.find(2) :" << endl << *it1 << endl;
	pair<multiset<int>::iterator,multiset<int>::iterator> it2 = ms.equal_range(3);
	cout << "ms.equal_range(3) :" << endl << *it2.first << " " << *it2.second << endl;
}

ostream &operator<<(ostream&out,const Person & p)
{
	// TODO: insert return statement here
	cout << p.firstname << " " << p.lastname;
	return out;
}
