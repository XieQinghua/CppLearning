/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/
#pragma once

#include<iostream>
#include<string>

using namespace std;

class Util {
private:
	int id;
	string name;

public:
	Util();
	Util(int id, string name);
	~Util();
	void show();
};

class Tool :public Util {
private:
	int function;
	string typeclass;
public:
	Tool();
	~Tool();
	void show();
};
