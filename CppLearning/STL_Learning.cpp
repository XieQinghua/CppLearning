#include"STL_Learning.h"

void use_multiset() {
	multiset<int,greater<int>> ms{ 1,2,3,4,5,6 };
	ms.insert({ 7,8,9,10 });
	ms.emplace(11);
	for (auto it : ms) {
		cout << it << " ";
	}
	/*multiset<string> ms{ "apple","xiaomi","huawei","vivo","oppo" };
	for (auto&elem : ms) {
		cout << elem << " ";
	}
	cout << endl;
	for (auto it = ms.cbegin(); it != ms.cend(); it++) {
		cout << *it << " ";
	}*/
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
	coll.insert(Person("jack", "chen"));
	coll.insert(Person("apple", "lee"));

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

void use_multimap()
{
	multimap<int, string> mmp{
		pair<int,string>(1,"jack"),
		pair<int,string>(2,"jason"),
		pair<int,string>(2,"joe"),
		pair<int,string>(3,"stack"),
		{5,"test" },{5,"test"},{5,"jason"}
	};

	mmp.insert(pair<int,string>(10,"hello"));

	for (multimap<int, string>::iterator it = mmp.begin(); it != mmp.end();it++) {
		cout << it->first << "," << it->second << endl;
	}

	mmp.erase(5);

	for (multimap<int, string>::iterator it = mmp.begin(); it != mmp.end(); it++) {
		cout << it->first << "," << it->second << endl;
	}
	/*map<int, float> m1;
	map<int, int> m2;
	if (m1 == m2) {

	}*/
}

void compare_map()
{
	/*set<int, greater<int>> s{ 1,2,3,4,5,6 };

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}*/

	set<Person/*,PersonSortCriterion*/> ss{
		Person("Jason","Lee"),
		Person("Jack","Chen"),
		Person("Alpha","Lee"),
		Person("Alience","Steven"),
		Person("Luffy","Lily")
	};
	for (auto&elem : ss) {
		cout << elem << endl;
	}

	//auto vcmp = mp.value_comp();
}

void use_RTCMP()
{
	set<int, RT_CMP> s1 = { 123,458,645,784,894 };
	for (auto elem : s1) {
		cout << elem << " ";
	}
	cout << endl;

	// 指定降序排序规则
	RT_CMP reverse_order(RT_CMP::reverse);
	set<int, RT_CMP> s2(reverse_order);
	s2 = { 123,458,645,784,894 };
	for (auto elem : s2) {
		cout << elem << " ";
	}
	cout << endl;

	if (s1.key_comp() == s2.key_comp()) {
		cout << "s1 and s2 have the same sorting criterion." << endl;
	}
	else {
		cout << "s1 and s2 have a different sorting criterion." << endl;
	}

	s1 = s2;
	if (s1.key_comp() == s2.key_comp()) {
		cout << "s1 and s2 have the same sorting criterion." << endl;
	}
	else {
		cout << "s1 and s2 have a different sorting criterion." << endl;
	}
}

ostream &operator<<(ostream&out,const Person & p)
{
	// TODO: insert return statement here
	cout << p.firstname << " " << p.lastname;
	return out;
}

bool Person::operator<(const Person & p) const
{
	return this->firstname < p.firstname ||
		(this->firstname == p.firstname&&this->lastname < p.lastname);
}
