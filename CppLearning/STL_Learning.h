#pragma once
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

class Person{
public:
	Person(string str1, string str2):firstname(str1),lastname(str2) {}
	string firstname;
	string lastname;
	bool operator<(const Person&p) const;
	friend ostream& operator<<(ostream&out, const Person & p);
};

class PersonSortCriterion {
public:
	bool operator() (const Person&p1, const Person&p2) const {
		return p1.firstname < p2.firstname ||
			(p1.firstname == p2.firstname&&p1.lastname < p2.lastname);
	}
};

class UseVector {
public:
private:
};

class RT_CMP {
public:
	enum cmp_mode { normal, reverse };
private:
	cmp_mode mode;
public:
	RT_CMP(cmp_mode m = normal) :mode(m) {

	}

	template<class T>
	bool operator()(const T&t1, const T&t2) const {
		return mode == normal ? t1<t2
			: t1>t2;
	}

	bool operator==(const RT_CMP&rc) const {
		return mode == rc.mode;
	}
};

class UseSet {
public:
private:
};
// 本例是用来测试set和multiset的使用方法
void use_multiset();

// 展示set的查找函数的能力
void use_search_set();

// 本例是用来测试map和multimap的使用方法
void use_multimap();

// 本例是用来测试关联式容器的排序准则的
void compare_map();

// 本例是对RT_CMP的测试函数
void use_RTCMP();


class IntSequence {
private:
	int value;
public:
	IntSequence(int initialValue) :value(initialValue) {

	}

	int operator()() {
		return ++value;
	}
};

// 使用函数对象的例子
void use_function_object();


class MeanValue {
private:
	long num;
	long sum;

public:
	MeanValue() :num(0), sum(0) {};

	void operator()(int elem) {
		++num;
		sum += elem;
	}

	double value() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

// 使用for_each算法的例子
void use_for_each();