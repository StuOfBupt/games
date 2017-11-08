#pragma once
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include"Person.h"
using namespace std;
class Map {
	friend class Person;
public:
	Map(const map<int, set<int>>&, const map<int, set<int>>&, const vector<pair<int, int>>&, const pair<int, int>&,const pair<int,int>&);
	void updateScreen();                  //更新地图
	void print();
	bool iswin();						
private:
	const int row;                        //界面行数
	const int col;                        //界面列数
	char screen[30][30];
	const map<int, set<int>> corrd_target;//目标覆盖点位
	const map<int, set<int>> wall;        //墙坐标
	vector<pair<int,int>> Box;            //箱子位置
	const vector<pair<int, int>> init_Box;//箱子初始位置
	pair<int, int> person;                //人的坐标
	const pair<int, int> init_person;     //人的初始坐标;
	void updatabox(const pair<pair<int, int>, pair<int, int>>&);//更新箱子位置，第一个pair为原位置，第二个pair为现位置
	void getPerson(Person &);             //获取人坐标
	
};
