#include"Person.h"
#include"Map.h"
using namespace std;
Person::Person(pair<int,int> &person) :init_corrd(person) {
	corrd = person;
}
void Person::walk(Map &screen) {
	pair<int, pair<int, int>> flag;
	pair<int, int> box;//前方（若是）箱子的坐标
	flag = forward(corrd.first,corrd.second,screen);
	switch(flag.first){
	case 1:						   //前方可以前进
		corrd=flag.second;
		screen.getPerson(*this);
		break;
	case 0:                        //前方为箱子，需要继续判断箱子前方
	{
		box=flag.second;		   //箱子现位置
		flag=forward(box.first,box.second,screen);
		switch(flag.first){
		case 1:                   //箱子前方为空
				screen.updatabox({box,flag.second});//更新箱子位置
				corrd=box;        //人推箱子
				screen.getPerson(*this);//更新人位置
				break;
		default :break;//箱子前方有墙或者箱子
		}
	}
	case -1:break;                //前方是墙，保持不动
	default :break;
	}
	
}
pair<int,pair<int,int>> Person::forward(int row,int col,Map &screen) {
	pair<int, pair<int, int>> flag;
	switch (direction) {//前方位置（row,col）
	case'w':row--; break;
	case's':row++; break;
	case'a':col--; break;
	case'd':col++; break;
	default:break;
	}
	switch(screen.screen[row][col]){
	case 'a':                //前方是墙
		flag={-1,{row,col}};
		break; 
	case 'b':               //前方是箱子
		flag={0 ,{row,col}};
		break;
	default:flag={1,{row,col}};break;//前方可以前进
	}
	
	return flag;
}
void Person::getdirection(char dir) {
	direction = dir;
}
void Person::Start_again(Map &screen) {
	corrd = init_corrd;
	screen.Box = screen.init_Box;
	screen.person = screen.init_person;
	screen.updateScreen();
}