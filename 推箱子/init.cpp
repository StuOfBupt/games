#include"init.h"
#include<string>
using namespace std;
pair<int,int> initmap(string c,map<int,set<int>> &corrd_target,map<int,set<int>> &wall,vector<pair<int,int>> &Box,pair<int,int> &person) {
	string s("map" + c+".txt");
	ifstream mapfile(s);
	string line;
	int row = 0, col = 0;//图形坐标
	int ROW, COL;
	while (getline(mapfile, line)) {
		for (char ch : line) {
			switch (ch) {
			case'a':wall[row].insert(col); break;
			case'b':Box.push_back({ row,col }); break;
			case'c':person.first = row; person.second = col; break;
			case'd':corrd_target[row].insert(col); break;
			default:break;
			}
			col++;
		}
		//读取下一行
		row++;
		COL = col;
		col = 0;
	}
	ROW = row;
	mapfile.close();
	return {ROW,COL};
}