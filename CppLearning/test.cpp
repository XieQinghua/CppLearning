#include"Util.h"
#include"test.h"

#define MAX(a,b) \
(a>b?a:b)

using namespace std;

void call_test() {
	test14();
}

void change(const int*pt, int n) {
	int *pc = const_cast<int*>(pt);
	*pc += n;
}

void test1() {
	int a = 100;
	const int b = 1000;
	cout << "a = " << a << " b = " << b << endl;
	change(&b, a);
	cout << "a = " << a << " b = " << b << endl;
}

void test2() {
	const int b = 1;
	const int *a = &b;
	cout << *a << endl;
	//*a++;
	//cout << *a << endl;
	int*c = const_cast<int*>(a);
	*c = 2;
	cout << *c << endl;
	cout << b << endl;
}

void test3() {

	Util *u = new Tool();
	Tool *t = dynamic_cast<Tool*>(u);
	if (t != nullptr) {
		t->get_count();
	}
	else {
		cout << "failure!" << endl;
	}
	if (typeid(Util) == typeid(*u)) {
		cout << "typeid(Util) == typeid(u)" << endl;
	}
	else {
		cout << "typeid(Util) != typeid(u)" << endl;
	}

	if (typeid(Tool) == typeid(*u)) {
		cout << "typeid(Tool) == typeid(u)" << endl;
	}
	else {
		cout << "typeid(Tool) != typeid(u)" << endl;
	}
	cout << typeid(*u).name() << endl;
}


void test4() {
	int a = 10;
	int *i = &a;
	long pc = reinterpret_cast<long>(i);
	char *cr = reinterpret_cast<char*>(i);
	long *l = reinterpret_cast<long*>(i);

	cout << *i << endl;
	cout << hex << pc << endl;
	cout << cr << endl;
	cout << l << endl;
}

void test5() {
	int a = 1;
	int b = 3;
	cout << MAX(a, b) << endl;
}

void test6() {
	Util u;
	u.test_inline();
}

void test7() {
	float ff = 3.1415f;
	int i = (int)ff;
	cout << ff << endl;
	int a = static_cast<int>(ff);
	cout << a << endl;
}

void test8() {

	Util u;
	const Util u_const;
	u.test_const_function();
	u.test_const_function(100);
	u_const.test_const_function();
}

#define pi_define 3.1415f

const double pi_const = 3.1415926f;

void test9() {
	double pi = pi_const;
	cout << "double pi = " << pi << endl;
	pi = pi_define;
	cout << "double pi = " << pi << endl;

}

void test10() {
	const int a = 10;
	const int b = 20;
	const int *p = &a;
	cout << *p << endl;
	p = &b;
	cout << *p << endl;
	int c = 30;
	int* const ppp = &c;
	c = 40;
	cout << *ppp << endl;
}

void test11() {
	Base*base = new Derived;
	if (Derived* derived = dynamic_cast<Derived*>(base)) {
		cout << "基类指针转换派生类指针成功" << endl;
		derived->show();
	}
	else {
		cout << "基类指针转换派生类指针失败" << endl;
		//derived->show();
	}
	base = new Base;
	if (Derived* derived = dynamic_cast<Derived*>(base)) {
		cout << "基类指针转换派生类指针成功" << endl;
		derived->show();
	}
	else {
		cout << "基类指针转换派生类指针失败" << endl;
		derived->show();
	}

	int testttt = 1;
	float ffff = static_cast<float>(testttt);
	Base*b = new Derived;
	Derived *d = static_cast<Derived*>(new Base);

	/*char *a = "Hello";
	int a = static_cast<int>("");*/

	/*const int a = 1;
	int b = static_cast<int>(a);*/
}

void test12() {
	Base*base = static_cast<Base*>(new Derived);// 通过编译，且是安全的
	Derived*d = static_cast<Derived*>(new Base);// 通过编译，但是存在安全隐患
												//Another*a = static_cast<Base*>(new Base);// 没有任何关系的两个类，无法转换
	void *p = new Base;

}

void test13() {
	/*int temp;
	cin >> temp;*/
	cout << "请输入一个数：" << endl;
	int input;
	cin >> input;
	const int a = input;
	const int*pointer_const = &a;
	int*b = const_cast<int*>(pointer_const);
	*b = 20;
	//int a = 10;
	//int *b = &a;
	//*b = 20;
	cout << "b = " << *b << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "&a = " << &a << endl;
	//a = 50;
	cin.get();
}

void test14() {
	/*Derived d;
	cout << "reinterpret_cast<Base*>(&d) = " << reinterpret_cast<Base*>(&d) << endl;
	cout << "static_cast<Base*>(&d) = " << static_cast<Base*>(&d) << endl;*/
	char s[] = "hello world!";
	long l = reinterpret_cast<long>(s);
	cout << "l = " << l << endl;
}

void test15() {
	union Data {
		struct {
			int x;
			int y;
		} s;
		int x;
		int y;
	}d;
	d.x = 1;
	d.y = 2;
	cout << d.x << endl << d.y << endl;
	d.s.x = d.x*d.x;
	d.s.y = d.y + d.y;
	cout << d.s.x << endl << d.s.y << endl;
	cout << d.x << endl << d.y << endl;
	cout << "sizeof = " << sizeof(d) << endl;
}

void test16() {
	const char*st = "How are you!!!!!";
	char a[11];
	strcpy(a, st);
	cout << a << endl;
}

void test_printf() {
	printf("%6d\n", 12345);
	printf("%06d\n", 12345);
	printf("%.6d\n", 12345);
	printf("%.6s\n", "Hello,printf");
	printf("%6s\n", "Hi");
	printf("%.8g\n", 12345678);
}

void test_scanf() {
	int i,j = 0;
	float f;
	char c;
	//printf("i = %d\n", i);
	scanf("%5d%f%c", &i,&f,&c);
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%f\n", f);
	printf("%c\n", c);
	cin.get();
	system("pause");
}

void test_sizeof_class() {
	cout << "空类：" << sizeof(AnotherUtil) << endl;
	cout << "只包含两个int成员的B类: " << sizeof(TestB) << endl;
	cout << "包含两个int成员和一个void成员函数的A类：" << sizeof(TestA) << endl;
	cout << "包含两个int成员和一个static成员的C类：" << sizeof(TestC) << endl;
	cout << "继承A类的D类：" << sizeof(TestD) << endl	;
	cout << "可能会引起字节对齐的E类：" << sizeof(TestE) << endl;
	cout << "继承自D和A的F类:" << sizeof(TestF) << endl;
	cout << "多继承的G类：" << sizeof(TestG) << endl;
}

void test_E_float() {
	cout << 1.E-5 << endl;
	cout << .2E-5 << endl;
	cout << 1.2E-5 << endl;
	cout << 1e5 << endl;
	cout << .1 << endl;
}

void test_fstream() {
	string str;
	fstream in_file("test.txt",ios::in);
	//in_file << str << endl;
	in_file >> str;
	cout << "str = " << str << endl;
}

void test_intref() {
	float fa = 1.0f;
	cout << (int&)fa << endl;
	float fb = 0.0f;
	cout << (int&)fb << endl;
}

void test_scanf_format()
{
	float f;
	scanf("%d", &f);
	printf("f = %d\n", f);
}

void memcpy(void * src, const void * dst, int len)
{

}

#include<vector>
void test_vector()
{
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		cout << "size = " << v.size() << "  capacity = " << v.capacity() << endl;
		v.push_back(i);
	}
	cout<< "size = " << v.size() << "  capacity = " << v.capacity() << endl;
}

void test_map()
{
	map<int, string> map_test;
	//string name[] = { "I","AM","Jason","Lee" };
	for (int index = 0; index < 100; index++) {
		map_test.insert(pair<int, string>(index, to_string(index) + "test"));
	}

	for (auto it = map_test.begin(); it != map_test.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	auto it = map_test.find(5);
	cout << it->first << " " << it->second << endl;
}

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void function_object_ref(Util &a) {
	cout << "function_object_ref have called." << endl;
}

void function_ref_array(int(&ref_arr)[10]) {
	for (int i = 0; i < 10; i++) {
		cout << ref_arr[i] << " ";
	}
}

int &return_ref(int &a) {
	a *= 100;
	return a;
}

int return_data(int a) {
	return a * 100;
}

int &return_local_ref() {
	int data = 100;
	int &local = data;
	return local;
}

int* &return_new_ref() {
	int *a = new int[5];
	int *(&a_ref) = a;
	return a_ref;
}

void test_ref()
{
	Derived d;
	Base &b = d;
	b.show();

	/*int*ptr = return_new_ref();
	for (int i = 0; i < 5; i++) {
		cout << ptr[i] << " ";
	}
	delete [] ptr;*/

	/*int data = 100;
	int &a = return_ref(data);
	cout << a << endl;
	int &b = return_local_ref();
	cout << b << endl;
*/
	struct ref_mem {
		int a = 0;
		int&b = a;
	};

	ref_mem rm;
	//cout << "sizeof = " << sizeof(rm) << endl;

	/*int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int (&b)[10] = a;*/
	/*for (int i = 0; i < 10; i++) {
		cout << "&b[" << i << "] = " << &b[i] << " "
			<< "&a[" << i << "] = " << &a[i] << " "
			<< "b[" << i << "] = " << b[i] << endl;
	}*/

	/*int data = 100;
	int *pointer = &data;
	int*&ptr_ref = pointer;
	cout << "*pointer = " << *pointer 
		<< "  pointer = " << pointer << endl;
	cout << "*ptr_ref = " << *ptr_ref 
		<< "  ptr_ref = " << ptr_ref << endl;*/

	/*int data = 100;
	const int &const_ref = data;
	cout << "const_ref = "<< const_ref << endl;
	int &ref = const_cast<int&>(const_ref);
	ref = 200;
	cout << "data = " << data << endl;

	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swap(a, b);
	cout << "call swap(a, b) function" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;*/
	/*Util test;
	function_object_ref(test);*/

	/*int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	function_ref_array(a);*/
}

void use_vector()
{
	vector<int> v(10,1);
	cout << "sizeof(v)= " << sizeof(v) << endl;
	/*for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}*/
	v.push_back(100);
	for (auto&ele : v) {
		cout << ele << " ";
	}
	//cout << endl;
	cout << "v.size() = " << v.size() << endl;
	cout << "v.capacity() = " << v.capacity() << endl;

	
	vector<int> v2(v);
	v.clear();
	cout << v2[0] << endl;
}

void use_vector1()
{
	/*vector<int> v*//*{ 1,2,3,4,5,6,7,8,9 }*/;
	//for (int i=0; i < 20; i++) {
	//	v.push_back(i);
	//	//cout<<"i = "<<i
	//	//	<< " size = " << v.size()
	//	//	<< " capacity = " << v.capacity() 
	//	//	/*<< " sizeof(v) = "<<sizeof(v)*/
	//	//	/*<< " max_size = " << v.max_size() */<< endl;
	//}

	/*vector<int> v1(10);
	cout << "size = " << v1.size() << " capacity = " << v1.capacity() << endl;*/
	/*vector<int> v2(v.begin(), v.end());
	vector<int> v3 = move(v2);
	for (const auto&elem : v3) {
		cout << elem << " ";
	}
	cout << static_cast<int>(v.empty()) << endl;
	cout << v[10] << endl;
	v.clear();
	cout << v.front() << endl;*/

	/*for (auto it = v.cbegin(); it != v.cend();it++) {
		cout << *it << " ";
	}
	cout << endl;*/
	/*for (auto it = v.crbegin(); it != v.crend(); it++) {
		cout << *it << " ";
	}*/
	/*cout << endl;
	for (auto it = v.cend()-1; it != v.cbegin(); --it) {
		cout << *it << " ";
	}*/
	/*v.resize(1);
	for (auto it = v.crbegin(); it != v.crend(); it++) {
	cout << *it << " ";
	}
	try {
		cout << v[5] << endl;
	}
	catch (exception e) {
		cout << "catch it" << endl;
	}*/
	vector<int>v;
	vector<int>v2{ -1,-2,-3,-4 };
	cout << "Source data:";
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for (const auto&elem : v) {
		cout << elem << " ";
	}
	
	cout << endl << "insert vector 2:";
	v.insert(v.end(), v2.begin(), v2.end());
	for (const auto&elem : v) {
		cout << elem << " ";
	}
	
	cout << endl << "remove vector 2:";
	auto begin_it = v.begin();
	while (*begin_it != *v2.begin()) {
		begin_it++;
	}
	v.erase(begin_it, v.end());
	for (const auto&elem : v) {
		cout << elem << " ";
	}
}

// deque使用举例
void use_deque()
{
	deque<int> c{ 1,2,3,4,5,6,7,8,9 };
	cout << "c.empty() = " << c.empty() << endl
		<< "c.size() = " << c.size() << endl
		<< "c.max_size()" << c.max_size() << endl;
	for (auto it = c.cbegin(); it != c.cend(); it++) {
		cout << *it << " ";
	}
	deque<int> c2;
	c2 = c;
	c.clear();
	for (auto it = c2.cbegin(); it != c2.cend(); it++) {
		cout << *it << " ";
	}
}

void random_number()
{
	ofstream output("./data.txt",ios::app);
	for (size_t i = 1; i <= 100; i++)
	{
		if (i % 5 == 0 && i != 0) {
			output << rand() % 100 << endl;
		}
		else {
			output << rand() % 100 << ",";
		}
	}
}
