#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include"声明.h"
#include"easyx.h"
#include<tchar.h>
using namespace std;
#define START_X 100
#define START_Y 100
#define _CRT_SECURE_NO_WARNINGS 1
//#define SPACE 2
//#define WALL 1
//#define BOX 3
//#define PLAYER 5
//#define DEST 4
enum _PROPS
{
	END,
	WALL,//墙
	SPACE,//土地
	BOX,//箱子
	DEST,//目的地
	PLAYER,//玩家
	ALL
};
IMAGE images[ALL];
struct start {
	//主界面开始游戏按钮横坐标
	int start_x;// 开始游戏按钮纵坐标，
	int start_y;// 开始游戏按钮
	int start_length;// 开始游戏按钮长
	int start_width;// 开始游戏按钮宽
}start1;
//开始游戏(370, 140, 540, 190）
struct leven {//主界面选择关卡按钮参数
	int leven_x;
	int leven_y;
	int leven_length;
	int leven_width;
}leven1;
//选择关卡(370, 200, 540, 250)

struct score {//主界面游戏排行榜按钮
	int score_x;
	int score_y;
	int score_length;
	int score_width;
}score1;
//排行榜（370, 260, 540, 310）
struct help {//主界面游戏说明按钮参数，
	int  help_x;
	int help_y;
	int help_length;
	int help_width;
}help1;
//游戏说明（370, 320, 540, 370）
struct exit {//主界面退出游戏按钮参数
	int  exit_x;
	int exit_y;
	int exit_length;
	int exit_width;
}exit1;
//退出游戏（370, 380, 540, 430）
struct musicon {//主界面播放音乐按钮参数，
	int  musicon_x;
	int musicon_y;
	int musicon_length;
	int musicon_width;
}musicon1;
//播放音乐（370, 440, 540, 490）
struct musicoff {//主界面关闭音乐按钮参数，
	int  musicoff_x;
	int musicoff_y;
	int musicoff_length;
	int musicoff_width;
}musicoff1;
//关闭音乐（370, 500, 540, 550）
struct gamereturn {//游戏界面返回按钮参数，
	int  return_x;
	int return_y;
	int return_length;
	int return_width;
}gamereturn1;
//游戏步数矩形框(100，650，200，700)
struct playerstep {
	int step_x;//显示玩家步数的矩形框的位置横坐标
	int step_y;//显示玩家步数的矩形框位置纵坐标
	int step_length; //矩形框的长
	int step_width;// 矩形框的宽
}playerstep1;
//游戏步数位置(150.700.175.725)
struct showplayerstep {
	int showstep_x;//显示玩家步数的位置横坐标
	int showstep_y;//显示玩家步数的位置纵坐标}showplayerstep1
};
/*struct selectgameleven {//关卡选择界面各关卡按钮参数(375.145.385.155)
	int l1_x;//第一关按钮横坐标375
	int l1_y;//第一关按钮纵坐标145
	int l1_length;//按钮长度10
	int l1_width;//按钮宽度10
	int level1 = 1;// (390.160.400.170)
	int  l2_x = 390;
	int l2_y = 160;
	int l2_length = 10;
	int l2_width = 10;
	int level2 = 2;// (405.180.415.190)
	int  l3_x = 405;
	int l3_y = 180;
	int l3_length = 10;
	int l3_width = 10;
	int level3 = 3; //(420.195.430.205)
	int  l4_x = 420;
	int l4_y = 195;
	int l4_length = 10;
	int l4_width = 10;
	int level4 = 4;
}selectleven1;
*/
struct selectgameleven {//关卡选择界面各关卡按钮参数
	int l1_x = 200;//第一关按钮横坐标
	int l1_y = 120;//第一关按钮纵坐标
	int l1_length = 250;//按钮长度
	int l1_width = 60;//按钮宽度
	int level1 = 1;
	int  l2_x = 200; //以下类同
	int l2_y = 200;
	int l2_length = 250;
	int l2_width = 60;
	int level2 = 2;
	int  l3_x = 200;
	int l3_y = 280;
	int l3_length = 250;
	int l3_width = 60;
	int level3 = 3;
	int  l4_x = 200;
	int l4_y = 360;
	int l4_length = 250;
	int l4_width = 60;
	int level4 = 4;
}selectleven1;

/*struct selectretrun {//选择关卡界面返回按钮参数，(370.140.385.150)
	int  select_x = 370;
	int select_y = 140;
	int select_length = 15;
	int select_width = 10;
}selectretrun1;
*/
struct selectretrun {//选择关卡界面返回按钮参数，
	int  select_x = 500;
	int select_y = 430;
	int select_length = 100;
	int select_width = 40;
}selectretrun1;
struct showscore {//排行榜界面返回按钮参数(525.360.540.370)
	int  showscore_x = 525;
	int showscore_y = 360;
	int showscore_length = 15;
	int showscore_width = 10;
}showscore1;
struct showhelp {//游戏说明界面返回按钮参数(525.300.540.310)
	int  showhelp_x = 525;
	int showhelp_y = 300;
	int showhelp_length = 15;
	int showhelp_width = 10;
}showhelp1;
int  playerscore[4] = { 500,500,500,500 };//排行榜记录存档，初始化为5 00；
int box[4] = { 2,4,3,3 };
int goal[4] = { 2,4,3,3 };//剩余未到达箱子数
struct playersize
{//玩家位置;
	int x;
	int y;
}playersize1;


int main()
{
	ShowMenu();






	return 0;
}
void initmap()
{
	for (int i = 0; i < 4; ++i)
		goal[i] = box[i];
	if (nowleven == 1) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map1[i][j] = map10[i][j];
			}
		}
	}
	else if (nowleven == 2) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map2[i][j] = map20[i][j];
			}
		}
	}
	else if (nowleven == 3) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map3[i][j] = map30[i][j];
			}
		}
	}
	else if (nowleven == 4) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map4[i][j] = map40[i][j];
			}
		}
	}
}
void  DoMouse1() {
	ExMessage m;
	int a1 = 0;
	while (true) {
		m = getmessage(EM_MOUSE);
		switch (m.message) {
		case WM_LBUTTONDOWN://左键按下
			if (m.x >= 263 && m.x <= 384 && m.y >= 100 && m.y <= 135) {  //开始游戏
				Normalgame();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 142 && m.y <= 178) {  //选择关卡
				Selectgame();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 185 && m.y <= 220) {  //显示排行榜
				ShowGameScore();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 228 && m.y <= 262) {  //游戏说明
				ShowGameHelp();
				DoMouse5();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 271 && m.y <= 304) {  //退出游戏
				exit(0);//printf("已经进入退出游戏\n");
				a1 = 1;
				break;
			}
			/*else if (m.x >= 263 && m.x <= 384 && m.y >= 314 && m.y <= 346) {  //播放音乐
				//printf("已经进入播放音乐\n");
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 357 && m.y <= 388) {  //关闭音乐
				//printf("已经进入关闭音乐\n");
				break;
			}*/
		}
		if (a1)
			break;
	}
}
void DoMouse5()//游戏说明界面返回
{
	ExMessage m;
	int a1 = 0;
	while (true) {
		m = getmessage(EM_MOUSE);
		switch (m.message) {
		case WM_LBUTTONDOWN://左键按下
			if (m.x >= 57 && m.x <= 128 && m.y >= 356 && m.y <= 391) {
				ShowMenu();
				a1 = 1;
				break;
			}
		}
		if (a1)
			break;
	}
	closegraph();
}
void DefineMove(int map[10][10])//判断移动是否合法
{
	switch (PlayerInput)
	{
	case'w':
		if (map[playersize1.x - 1][playersize1.y] == 1)//如果是墙，令moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x - 1][playersize1.y] == 2)//判断是否为地板，是的话令moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x - 1][playersize1.y] == 3)//是否为箱子，如果是箱子，是否能推动，  如果不能推动，令moveway = 2，如果能推动，令moveway = 3，
		{
			if (map[playersize1.x - 2][playersize1.y] == 1|| map[playersize1.x - 2][playersize1.y] == 3)
			{
				moveway = 2;
			}
			else if (map[playersize1.x - 2][playersize1.y] == 2 || map[playersize1.x - 2][playersize1.y] == 4)
			{
				moveway = 3;
			}
		}
		else if (map[playersize1.x - 1][playersize1.y] == 4)//如果人下一步走的是目标位置，令moveway=4
		{
			moveway = 4;
		}
		break;
	case's':
		if (map[playersize1.x + 1][playersize1.y] == 1)//如果是墙，令moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x + 1][playersize1.y] == 2)//判断是否为地板，是的话令moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x + 1][playersize1.y] == 3)//是否为箱子，如果是箱子，是否能推动，  如果不能推动，令moveway = 2，如果能推动，令moveway = 3，
		{
			if (map[playersize1.x + 2][playersize1.y] == 1 || map[playersize1.x + 2][playersize1.y] == 3)
			{
				moveway = 2;
			}
			else if (map[playersize1.x + 2][playersize1.y] == 2 || map[playersize1.x + 2][playersize1.y] == 4)
			{
				moveway = 3;
			}
		}
		else if (map[playersize1.x + 1][playersize1.y] == 4)//如果人下一步走的是目标位置，令moveway=4
		{
			moveway = 4;
		}
		break;
	case'd':
		if (map[playersize1.x][playersize1.y + 1] == 1)//如果是墙，令moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x][playersize1.y + 1] == 2)//判断是否为地板，是的话令moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x][playersize1.y + 1] == 3)//是否为箱子，如果是箱子，是否能推动，  如果不能推动，令moveway = 2，如果能推动，令moveway = 3，
		{
			if (map[playersize1.x][playersize1.y + 2] == 1 || map[playersize1.x  ][playersize1.y + 2] == 3)
			{
				moveway = 2;
			}
			else if (map[playersize1.x][playersize1.y + 2] == 2 || map[playersize1.x  ][playersize1.y + 2] == 4)
			{
				moveway = 3;
			}
		}
		else if (map[playersize1.x][playersize1.y + 1] == 4)//如果人下一步走的是目标位置，令moveway=4
		{
			moveway = 4;
		}
		break;
	case'a':
		if (map[playersize1.x][playersize1.y - 1] == 1)//如果是墙，令moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x][playersize1.y - 1] == 2)//判断是否为地板，是的话令moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x][playersize1.y - 1] == 3)//是否为箱子，如果是箱子，是否能推动，  如果不能推动，令moveway = 2，如果能推动，令moveway = 3，
		{
			if (map[playersize1.x][playersize1.y - 2] == 1 || map[playersize1.x  ][playersize1.y - 2] == 3)
			{
				moveway = 2;
			}
			else if (map[playersize1.x][playersize1.y - 2] == 2 || map[playersize1.x ][playersize1.y - 2] == 4)
			{
				moveway = 3;
			}
		}
		else if (map[playersize1.x][playersize1.y - 1] == 4)//如果人下一步走的是目标位置，令moveway=4
		{
			moveway = 4;
		}
		break;
	}
	return;
}

void Move(int map[10][10])//根据DefineMove中的说明，即根据moveway的值进行相应操作，
{
	switch (moveway)
	{
	case 0:       // 墙
		break;
	case 1:           //地板
		switch (nowleven)//关卡
		{
		case 1:
			if (map10[playersize1.x][playersize1.y] == 4)//从目标位置走到正常地板
			{
				switch (PlayerInput)//改变playersize对应横纵左标的值
				{
				case'a':
					map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);//目标图片改变
					map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
					putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
					//人物图片改变
					playersize1.y--;
					step++;
					break;
				case'w':
					map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
					//人物图片改变
					playersize1.x--;
					step++;
					break;
				case's':
					map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
					 //目标图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
					 //人物图片改变
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
					playersize1.x++;
					step++;
					break;
				case'd':
					map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
					//目标图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
					//人物图片改变
					putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y++;
					step++;
					break;
				}
			}
			else //正常走
			{
				switch (PlayerInput)//改变playersize对应横纵左标的值
				{
				case'a':
					map[playersize1.x][playersize1.y] = 2; // 地板恢复
					//地板改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				 //人物图片改变
					putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y--;
					step++;
					break;
				case'w':
					map[playersize1.x][playersize1.y] = 2; // 地板恢复
					 //地板改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
					 //人物图片改变
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
					playersize1.x--;
					step++;
					break;
				case's':
					map[playersize1.x][playersize1.y] = 2; // 地板恢复
					 //地板改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
					//人物图片改变
					step++;
					playersize1.x++;
					break;
				case'd':
					map[playersize1.x][playersize1.y] = 2; // 地板恢复
					 //地板改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
					putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y++;
					step++;
					break;
				}
			}
			break;
		case 2:  if (map20[playersize1.x][playersize1.y] == 4)//从目标位置走到正常地板
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
			 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
			 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
			 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
			 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				//人物图片改变
				step++;
				playersize1.y++;
				break;
			}
		}
			  else //正常走
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
			   //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				//人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				//人物图片改变
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		case 3:  if (map30[playersize1.x][playersize1.y] == 4)//从目标位置走到正常地板
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
			 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  else  //正常走
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				//地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				//人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				//地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
				//人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x+1][playersize1.y ] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y  * 50, START_X + (playersize1.x+1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				//地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		case 4:  if (map40[playersize1.x][playersize1.y] == 4)//从目标位置走到正常地板
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // 目标位置恢复
				 //目标图片改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				break;
			}

		}
			  else //正常走
		{
			switch (PlayerInput)//改变playersize对应横纵左标的值
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				//地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x + 1][playersize1.y] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // 地板恢复
				 //地板改变
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // 人走的地图改变
				 //人物图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		}
		break;
	case 2:            //墙
		break;
	case 3:            //推到箱子
		switch (nowleven)
		{
		case 1:         // 第一关
			switch (PlayerInput) // 移动方向
			{
			case 'a':
				if (map10[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map10[playersize1.x][playersize1.y - 1] == 4) //箱子下是目标位置
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//人的位置不是目标位置
				{
					if (map10[playersize1.x][playersize1.y - 1] == 4) //将箱子从目标位置推到地板
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//人离开原位置图片改变
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//人物坐标改变
				break;
			case 'd':
				if (map10[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map10[playersize1.x][playersize1.y + 1] == 4) //箱子下是目标位置
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map10[playersize1.x][playersize1.y + 1] == 4) //将箱子从目标位置推到地板
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变 
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//人物坐标改变
				break;
			case 's':
				if (map10[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map10[playersize1.x + 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map10[playersize1.x + 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//人物坐标改变
				break;
			case 'w':
				if (map10[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map10[playersize1.x - 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map10[playersize1.x - 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven-1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//人物坐标改变
				break;
			}
			break;

		case 2://第二关
			switch (PlayerInput) // 移动方向
			{
			case 'a':
				if (map20[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map20[playersize1.x][playersize1.y - 1] == 4) //箱子下是目标位置
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//人的位置不是目标位置
				{
					if (map20[playersize1.x][playersize1.y - 1] == 4) //将箱子从目标位置推到地板
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//人离开原位置图片改变
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//人物坐标改变
				break;
			case 'd':
				if (map20[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map20[playersize1.x][playersize1.y + 1] == 4) //箱子下是目标位置
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map20[playersize1.x][playersize1.y + 1] == 4) //将箱子从目标位置推到地板
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//人物坐标改变
				break;
			case 's':
				if (map20[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map20[playersize1.x + 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map20[playersize1.x + 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//人物坐标改变
				break;
			case 'w':
				if (map20[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map20[playersize1.x - 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;

						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map20[playersize1.x - 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
				}
				playersize1.x = playersize1.x - 1;//人物坐标改变
				break;
			}
			break;
		case 3:
			switch (PlayerInput) // 移动方向
			{
			case 'a':
				if (map30[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map30[playersize1.x][playersize1.y - 1] == 4) //箱子下是目标位置
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//人的位置不是目标位置
				{
					if (map30[playersize1.x][playersize1.y - 1] == 4) //将箱子从目标位置推到地板
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//人离开原位置图片改变
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//人物坐标改变
				break;
			case 'd':
				if (map30[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map30[playersize1.x][playersize1.y + 1] == 4) //箱子下是目标位置
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map30[playersize1.x][playersize1.y + 1] == 4) //将箱子从目标位置推到地板
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//人物坐标改变
				break;
			case 's':
				if (map30[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map30[playersize1.x + 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map30[playersize1.x + 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
				}
				playersize1.x = playersize1.x + 1;//人物坐标改变
				break;
			case 'w':
				if (map30[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map30[playersize1.x - 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map30[playersize1.x - 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//人物坐标改变
				break;
			}
			break;
		case 4:
			switch (PlayerInput) // 移动方向
			{
			case 'a':
				if (map40[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map40[playersize1.x][playersize1.y - 1] == 4) //箱子下是目标位置
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//人的位置不是目标位置
				{
					if (map40[playersize1.x][playersize1.y - 1] == 4) //将箱子从目标位置推到地板
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y - 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//人离开原位置图片改变
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//人物坐标改变
				break;
			case 'd':
				if (map40[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map40[playersize1.x][playersize1.y + 1] == 4) //箱子下是目标位置
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
						//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map40[playersize1.x][playersize1.y + 1] == 4) //将箱子从目标位置推到地板
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x][playersize1.y + 2] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//人物坐标改变
				break;
			case 's':
				if (map40[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map40[playersize1.x + 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map40[playersize1.x + 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x + 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//人物坐标改变
				break;
			case 'w':
				if (map40[playersize1.x][playersize1.y] == 4)//人的位置是目标位置
				{
					if (map40[playersize1.x - 1][playersize1.y] == 4) //箱子下是目标位置
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;

						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//人离开原位置地图改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//人的位置不是目标位置
				{
					if (map40[playersize1.x - 1][playersize1.y] == 4) //将箱子从目标位置推到地板
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) // 将箱子从推目标位置推到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到下一个目标位置地图改变
							//箱子到下一个目标位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							 //人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//将箱子从目标位置推到地板
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //箱子下不是目标位置
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) //将箱子推到目标位置
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到目标位置地图改变
							//箱子到目标图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //箱子推不到目标位置
						{
							map[playersize1.x - 2][playersize1.y] = 3;//箱子到地板地图改变
							//箱子到地板改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//人到箱子的原位置地图改变
							//人到箱子的原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//人离开原位置地图改变
							//人离开原位置图片改变
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//人物坐标改变
				break;
			}
			break;
		}
		break;
	case 4:          //人下一步走的是目标位置
		switch (nowleven)
		{
		case 1:
		{
			switch (PlayerInput)
			{
			case 'a':
				map[playersize1.x][playersize1.y - 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//人的下一步地图改变
			//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					step++;
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				}
				playersize1.x--;
				break;
			}
			break;
		}
		case 2:
		{
			switch (PlayerInput)
			{
			case 'a':
				map[playersize1.x][playersize1.y - 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//人的下一步地图改变
			//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					step++;
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				}
				playersize1.x--;
				break;
			}
			break;
		}
		case 3:
		{
			switch (PlayerInput)
			{
			case 'a':
				map[playersize1.x][playersize1.y - 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//人的下一步地图改变
			//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					step++;
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				}
				playersize1.x--;
				break;
			}
			break;
		}
		case 4:
		{
			switch (PlayerInput)
			{
			case 'a':
				map[playersize1.x][playersize1.y - 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//人的下一步地图改变
			//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//人的下一步地图改变
				//人的下一步图片改变
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//人原地的地图改变
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//人原地的地图改变
				   //人原地的图片改变
					step++;
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				}
				playersize1.x--;
				break;
			}
			break;
		}
		}
	}	
}
void DefineSuccess()//判断是否成功
{
	if (goal[nowleven-1] == 0)
	{
		ReNewScore();
		if (nowleven == playerleven && playerleven <= 3)
		{
			playerleven++;
			selectleven++;
		}
		else if(nowleven<playerleven)
		{
			selectleven++;
		}
		if (selectleven <= 4)
		{
			SelectGameStart();
		}
	}

}

void ShowMenu() {
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	TCHAR s1[] = _T("推箱子");
	TCHAR s2[] = _T("开始游戏");
	TCHAR s3[] = _T("选择关卡");
	TCHAR s4[] = _T("排行榜");
	TCHAR s5[] = _T("游戏说明");
	TCHAR s6[] = _T("退出游戏");
	//TCHAR s7[] = _T("播放音乐");
	//TCHAR s8[] = _T("关闭音乐");
	settextstyle(35, 18, _T("黑体"));
	outtextxy(270, 43, s1);//推箱子

	setcolor(RED);

	roundrect(263, 100, 384, 135, 10, 10);//roundrect(左部 x 坐标,顶部 y 坐标,右部 x 坐标,底部 y 坐标)
	settextstyle(18, 9, _T("黑体"));
	outtextxy(289, 108, s2); //开始游戏

	roundrect(263, 142, 384, 178, 10, 10);
	outtextxy(289, 151, s3);    //选择关卡

	roundrect(263, 185, 384, 220, 10, 10);
	outtextxy(298, 193, s4);    //排行榜

	roundrect(263, 228, 384, 262, 10, 10);
	outtextxy(289, 235, s5);    //游戏说明

	roundrect(263, 271, 384, 304, 10, 10);
	outtextxy(289, 277, s6);    //退出游戏

	//roundrect(263, 314, 384, 346, 10, 10);
	//outtextxy(289, 319, s7);    //播放音乐

	//roundrect(263, 357, 384, 388, 10, 10);
	//outtextxy(289, 361, s8);    //关闭音乐
	DoMouse1();
	//_getch();
	closegraph();
}
void ShowGameScore() {
	char num1[10];
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	TCHAR s1[] = _T("排行榜");
	TCHAR s2[] = _T("第一关卡最低步数：");
	TCHAR s3[] = _T("第二关卡最低步数：");
	TCHAR s4[] = _T("第三关卡最低步数：");
	TCHAR s5[] = _T("第四关卡最低步数：");
	TCHAR s6[] = _T("返回");
	settextstyle(35, 18, _T("黑体"));
	setcolor(BLACK);
	outtextxy(270, 43, s1);
	setcolor(RED);
	settextstyle(18, 9, _T("黑体"));
	outtextxy(228, 121, s2);
	outtextxy(228, 178, s3);
	outtextxy(228, 235, s4);
	outtextxy(228, 292, s5);
	settextstyle(21, 11, _T("黑体"));
	roundrect(57, 356, 128, 391, 10, 10);
	outtextxy(73, 363, s6);
	sprintf_s(num1, "%d", playerscore[0]);
	outtextxy(385, 120, num1);
	sprintf_s(num1, "%d", playerscore[1]);
	outtextxy(385, 177, num1);
	sprintf_s(num1, "%d", playerscore[2]);
	outtextxy(385, 234, num1);
	sprintf_s(num1, "%d", playerscore[3]);
	outtextxy(385, 291, num1);
	DoMouse4();
}
void ReNewScore() {
	if (step < playerscore[nowleven - 1])
		playerscore[nowleven - 1] = step;
}
void ShowGameHelp() {
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	TCHAR s1[] = _T("游戏说明");
	TCHAR s2[] = _T("在设定的游戏地图里面，箱子只可以推，不可以拉，而且一次只能推动一个");
	TCHAR s3[] = _T("且只能用wasd键移动");
	TCHAR s4[] = _T("返回");
	setcolor(BLACK);
	settextstyle(35, 18, _T("黑体"));
	outtextxy(270, 43, s1);
	setcolor(RED);
	settextstyle(12, 6, _T("黑体"));
	roundrect(107, 107, 604, 231, 10, 10);
	outtextxy(128, 142, s2);
	outtextxy(128, 164, s3);
	settextstyle(21, 11, _T("黑体"));
	roundrect(57, 356, 128, 391, 10, 10);
	outtextxy(73, 363, s4);

}
void DoMouse2()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EM_MOUSE);
		int a1 = 0;
		switch (msg.message)
		{
		case WM_LBUTTONDOWN://鼠标左键
			if (msg.x >= selectretrun1.select_x && msg.x <= selectretrun1.select_x + selectretrun1.select_length && msg.y >= selectretrun1.select_y && msg.y <= selectretrun1.select_y + selectretrun1.select_width)
			{
				a1 = 1;
				ShowMenu();
			}
			else if (msg.x >= selectleven1.l1_x && msg.x <= selectleven1.l1_x + selectleven1.l1_length && msg.y >= selectleven1.l1_y && msg.y <= selectleven1.l1_y + selectleven1.l1_width)
			{
				if (selectleven1.level1 <= playerleven) {
					selectleven = 1;
					a1 = 1;
					SelectGameStart();
				}
			}
			else if (msg.x >= selectleven1.l2_x && msg.x <= selectleven1.l2_x + selectleven1.l2_length && msg.y >= selectleven1.l2_y && msg.y <= selectleven1.l2_y + selectleven1.l2_width)
			{
				if (selectleven1.level2 <= playerleven) {
					selectleven = 2;
					a1 = 1;
					SelectGameStart();
				}
			}
			else if (msg.x >= selectleven1.l3_x && msg.x <= selectleven1.l3_x + selectleven1.l3_length && msg.y >= selectleven1.l3_y && msg.y <= selectleven1.l3_y + selectleven1.l3_width)
			{
				if (selectleven1.level3 <= playerleven) {
					selectleven = 3;
					a1 = 1;
					SelectGameStart();
				}
			}
			else if (msg.x >= selectleven1.l4_x && msg.x <= selectleven1.l4_x + selectleven1.l4_length && msg.y >= selectleven1.l4_y && msg.y <= selectleven1.l4_y + selectleven1.l4_width)
			{
				if (selectleven1.level4 <= playerleven) {
					selectleven = 4;
					a1 = 1;
					SelectGameStart();
				}
			}
		}
		if (a1)
			break;
	}
}
void DoMouse3()
{
	ExMessage msg;
	int a1 = 0;
	while (1)
	{
		msg = getmessage(EM_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN://鼠标左键
			if (msg.x >= gamereturn1.return_x && msg.x <= gamereturn1.return_x + gamereturn1.return_length && msg.y >= gamereturn1.return_y && msg.y <= gamereturn1.return_y + gamereturn1.return_width)
			{
				ShowMenu();
				a1 = 1;
				break;
			}
		}
		if (a1)
			break;
	}
}
void DoMouse4()//排行榜返回
{
	ExMessage msg;
	int a1 = 0;
	while (1)
	{
		msg = getmessage(EM_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN://鼠标左键
			if (msg.x >= 57 && msg.x <= 356 && msg.y >= 128 && msg.y <= 391)
			{
				a1 = 1;
				ShowMenu();
			}
		}
		if (a1)
			break;
	}

}
void FindPlayer(int map[10][10])
{
	int i = 0, j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 5) {
				playersize1.x = i;
				playersize1.y = j;
				break;
			}
		}
	}
}
void showmap(int map[10][10])
{
	IMAGE bg_img;
	initgraph(800, 800);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&bg_img, _T("墙1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("地板.jpg"), 50, 50, true);
	loadimage(&images[BOX], _T("box.jpg"), 50, 50, true);
	loadimage(&images[DEST], _T("dest.jpg"), 50, 50, true);
	loadimage(&images[PLAYER], _T("player.jpg"), 50, 50, true);

	//根据map输出照片
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			putimage(START_X + j * 50, START_X + i * 50, &images[map[i][j]]);
		}
	}
	//字体
	char num[10];
	settextcolor(BLACK);
	sprintf_s(num, "%d", step);
	settextstyle(40, 0, "黑体");
	//输出文字
	outtextxy(651, 44, "步数=");
	outtextxy(755, 44, num);
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "按m返回");

}
void NormalGameStart()
{

	nowleven = playerleven;
	for (int i = 0; i < 4; ++i)
		goal[i] = box[i];
	IMAGE bg_img;
	int step = 0;
	initgraph(800, 800);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&bg_img, _T("墙1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("地板.jpg"), 50, 50, true);
	loadimage(&images[BOX], _T("box.jpg"), 50, 50, true);
	loadimage(&images[DEST], _T("dest.jpg"), 50, 50, true);
	loadimage(&images[PLAYER], _T("player.jpg"), 50, 50, true);
	//根据nowleven给map赋值
	if (nowleven == 1) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map1[i][j] = map10[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map10[i][j]]);
			}
		}
	}
	else if (nowleven == 2) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map2[i][j] = map20[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map20[i][j]]);
			}
		}
	}
	else if (nowleven == 3) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map3[i][j] = map30[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map30[i][j]]);
			}
		}
	}
	else if (nowleven == 4) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map4[i][j] = map40[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map40[i][j]]);
			}
		}
	}

	//字体
	settextcolor(BLACK);
	settextstyle(40, 0, "黑体");
	//输出文字
	outtextxy(651, 44, "步数=");
	outtextxy(755, 44, "0");
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "按m返回");
}
void SelectGameStart() {
	nowleven = selectleven;
	for (int i = 0; i < 4; ++i)
		goal[i] = box[i];

	IMAGE bg_img;
	 step = 0;
	initgraph(800, 800);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&bg_img, _T("墙1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("地板.jpg"), 50, 50, true);
	loadimage(&images[BOX], _T("box.jpg"), 50, 50, true);
	loadimage(&images[DEST], _T("dest.jpg"), 50, 50, true);
	loadimage(&images[PLAYER], _T("player.jpg"), 50, 50, true);
	if (nowleven == 1) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map1[i][j] = map10[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map10[i][j]]);
				FindPlayer(map1);
			}
		}
	}
	else if (nowleven == 2) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map2[i][j] = map20[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map20[i][j]]);
				FindPlayer(map2);
			}
		}
	}
	else if (nowleven == 3) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map3[i][j] = map30[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map30[i][j]]);
				FindPlayer(map3);
			}
		}
	}
	else if (nowleven == 4) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map4[i][j] = map40[i][j];
				putimage(START_X + j * 50, START_X + i * 50, &images[map40[i][j]]);
				FindPlayer(map4);
			}
		}
	}
	//根据map输出照片
	//字体
	settextcolor(BLACK);
	settextstyle(40, 0, "黑体");
	//输出文字
	outtextxy(651, 44, "步数=");
	outtextxy(755, 44, "0");
	//fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "按m返回");
}

void SelectGameLeven()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(40, 0, "黑体");
	settextcolor(BLACK);
	outtextxy(245, 44, "关卡选择");
	setlinecolor(BLACK);
	rectangle(selectleven1.l1_x, selectleven1.l1_y, selectleven1.l1_x + selectleven1.l1_length, selectleven1.l1_y + selectleven1.l1_width);//第一关中间差20 长250 宽60
	rectangle(selectleven1.l2_x, selectleven1.l2_y, selectleven1.l2_x + selectleven1.l2_length, selectleven1.l2_y + selectleven1.l2_width);//第二关
	rectangle(selectleven1.l3_x, selectleven1.l3_y, selectleven1.l3_x + selectleven1.l3_length, selectleven1.l3_y + selectleven1.l3_width);//第三关
	rectangle(selectleven1.l4_x, selectleven1.l4_y, selectleven1.l4_x + selectleven1.l4_length, selectleven1.l4_y + selectleven1.l4_width);//第四关
	rectangle(selectretrun1.select_x, selectretrun1.select_y, selectretrun1.select_x + selectretrun1.select_length, selectretrun1.select_y + selectretrun1.select_width);//返回
	settextstyle(25, 0, "宋体");
	outtextxy(290, 140, "第一关");
	outtextxy(290, 220, "第二关");
	outtextxy(290, 300, "第三关");
	outtextxy(290, 380, "第四关");
	outtextxy(525, 436, "返回");
	DoMouse2();
}
void ShowStep()
{
	char num[10000];
	char s[] = "步数=";
	sprintf_s(num, "%d", step);
	outtextxy(755, 44, num);
}
void PlayerMusic()
{

}
void CloseMusic()
{

}

void GetInput()
{
	PlayerInput = _getch();
	if (PlayerInput == 'm')
		ShowMenu();
}
void Normalgame()
{
	NormalGameStart();
	switch (nowleven)
	{
	case 1:
	{
		FindPlayer(map1);
		break;
	}
	case 2:
	{
		FindPlayer(map2);
		break;
	}
	case 3:
	{
		FindPlayer(map3);
		break;
	}
	case 4:
	{   FindPlayer(map4);
	break;
	}
	}
	while (1)
	{
		GetInput();
		switch (nowleven)
		{
		case 1:
		{
			DefineMove(map1);
			Move(map1);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 2:
		{
			DefineMove(map2);
			Move(map2);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 3:
		{
			DefineMove(map3);
			Move(map3);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 4:
		{
			DefineMove(map4);
			Move(map4);
			ShowStep();
			DefineSuccess();
			break;
		}
		
		}
	}
}
void Selectgame()
{
	SelectGameLeven();

	switch (nowleven)
	{
	case 1:
	{
		FindPlayer(map1);
		break;
	}
	case 2:
	{
		FindPlayer(map2);
		break;
	}
	case 3:
	{
		FindPlayer(map3);
		break;
	}
	case 4:
	{
		FindPlayer(map4);
		break;
	}
	}
	while (1)
	{
		GetInput();
		switch (nowleven)
		{
		case 1:
		{
			DefineMove(map1);
			Move(map1);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 2:
		{
			DefineMove(map2);
			Move(map2);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 3:
		{
			DefineMove(map3);
			Move(map3);
			ShowStep();
			DefineSuccess();
			break;
		}
		case 4:
		{
			DefineMove(map4);
			Move(map4);
			ShowStep();
			DefineSuccess();
			break;
		}
		 
		}
	}
}