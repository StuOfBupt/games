#include"Map.h"
#include"Person.h"
using namespace std;
/*
	墙壁：'■'='a'
	箱子：'□'='b'
	人  ：'♀'='c'
	点  ：'·'='d'
*/
Map::Map(const map<int, set<int>> &corrd, const map<int, set<int>> &WALL, const vector<pair<int, int>> &box, const pair<int, int> &per,const pair<int,int> &rc)
	:corrd_target(corrd), wall(WALL), init_person(per), init_Box(box), row(rc.first), col(rc.second)
{
	Box = box;
	person=per;
	/*初始化界面*/
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			screen[i][j] = ' ';
}
void Map::getPerson(Person &per) {
	person = per.corrd;
}
bool Map::iswin() {
	bool iswin = 1;
	for (auto m : corrd_target) {
		for (auto n : m.second)
			if (screen[m.first][n] != 'b')
				iswin = 0;
	}
	return iswin;
}
void Map::print() {
	int i, j;
	updateScreen();
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			switch (screen[i][j]) {
			case 'a':cout << "■"; break;
			case 'b':cout << "□"; break;
			case 'c':cout << "♀"; break; 
			case 'd':cout << "·"; break;
			default :cout << "  "; break;
			}
		cout << endl;
	}
		
}
void Map::updatabox(const pair<pair<int,int>,pair<int,int>> &box) {
	for (auto &vec : Box) {
		if (vec == box.first) 
			vec = box.second;			
	}
}
void Map::updateScreen() {
	/*初始化界面*/
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			screen[i][j] = ' ';
	/*生成墙壁*/
	for (auto m : wall) {
		for (auto n : m.second)
			screen[m.first][n] = 'a';          //'■'墙
	}
	/*生成目标点*/
	for (auto m : corrd_target) {
		for (auto n : m.second)
			screen[m.first][n] = 'd';          //'·'
	}
	/*生成箱子*/
	for (auto m : Box) {
		screen[m.first][m.second] = 'b';       //'□'
	}
	/*生成人*/
	screen[person.first][person.second] = 'c'; //'♀'
}