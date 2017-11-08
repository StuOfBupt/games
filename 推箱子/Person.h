#pragma once
#include<iostream>
#include<map>
#include"Map.h"
using namespace std;
class Person {
	friend class Map;
public:
	Person(pair<int,int>&);
	void walk(Map&);
	void getdirection(char);
	void Start_again(Map&);
private:
	pair<int, int> corrd;                      //人坐标
	const pair<int, int> init_corrd;		   //人初始坐标
	char direction;                            //移动方向
	pair<int, pair<int, int>> forward(int,int,Map&);//前方路况
};
