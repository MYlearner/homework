#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include"����.h"
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
	WALL,//ǽ
	SPACE,//����
	BOX,//����
	DEST,//Ŀ�ĵ�
	PLAYER,//���
	ALL
};
IMAGE images[ALL];
struct start {
	//�����濪ʼ��Ϸ��ť������
	int start_x;// ��ʼ��Ϸ��ť�����꣬
	int start_y;// ��ʼ��Ϸ��ť
	int start_length;// ��ʼ��Ϸ��ť��
	int start_width;// ��ʼ��Ϸ��ť��
}start1;
//��ʼ��Ϸ(370, 140, 540, 190��
struct leven {//������ѡ��ؿ���ť����
	int leven_x;
	int leven_y;
	int leven_length;
	int leven_width;
}leven1;
//ѡ��ؿ�(370, 200, 540, 250)

struct score {//��������Ϸ���а�ť
	int score_x;
	int score_y;
	int score_length;
	int score_width;
}score1;
//���а�370, 260, 540, 310��
struct help {//��������Ϸ˵����ť������
	int  help_x;
	int help_y;
	int help_length;
	int help_width;
}help1;
//��Ϸ˵����370, 320, 540, 370��
struct exit {//�������˳���Ϸ��ť����
	int  exit_x;
	int exit_y;
	int exit_length;
	int exit_width;
}exit1;
//�˳���Ϸ��370, 380, 540, 430��
struct musicon {//�����沥�����ְ�ť������
	int  musicon_x;
	int musicon_y;
	int musicon_length;
	int musicon_width;
}musicon1;
//�������֣�370, 440, 540, 490��
struct musicoff {//������ر����ְ�ť������
	int  musicoff_x;
	int musicoff_y;
	int musicoff_length;
	int musicoff_width;
}musicoff1;
//�ر����֣�370, 500, 540, 550��
struct gamereturn {//��Ϸ���淵�ذ�ť������
	int  return_x;
	int return_y;
	int return_length;
	int return_width;
}gamereturn1;
//��Ϸ�������ο�(100��650��200��700)
struct playerstep {
	int step_x;//��ʾ��Ҳ����ľ��ο��λ�ú�����
	int step_y;//��ʾ��Ҳ����ľ��ο�λ��������
	int step_length; //���ο�ĳ�
	int step_width;// ���ο�Ŀ�
}playerstep1;
//��Ϸ����λ��(150.700.175.725)
struct showplayerstep {
	int showstep_x;//��ʾ��Ҳ�����λ�ú�����
	int showstep_y;//��ʾ��Ҳ�����λ��������}showplayerstep1
};
/*struct selectgameleven {//�ؿ�ѡ�������ؿ���ť����(375.145.385.155)
	int l1_x;//��һ�ذ�ť������375
	int l1_y;//��һ�ذ�ť������145
	int l1_length;//��ť����10
	int l1_width;//��ť���10
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
struct selectgameleven {//�ؿ�ѡ�������ؿ���ť����
	int l1_x = 200;//��һ�ذ�ť������
	int l1_y = 120;//��һ�ذ�ť������
	int l1_length = 250;//��ť����
	int l1_width = 60;//��ť���
	int level1 = 1;
	int  l2_x = 200; //������ͬ
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

/*struct selectretrun {//ѡ��ؿ����淵�ذ�ť������(370.140.385.150)
	int  select_x = 370;
	int select_y = 140;
	int select_length = 15;
	int select_width = 10;
}selectretrun1;
*/
struct selectretrun {//ѡ��ؿ����淵�ذ�ť������
	int  select_x = 500;
	int select_y = 430;
	int select_length = 100;
	int select_width = 40;
}selectretrun1;
struct showscore {//���а���淵�ذ�ť����(525.360.540.370)
	int  showscore_x = 525;
	int showscore_y = 360;
	int showscore_length = 15;
	int showscore_width = 10;
}showscore1;
struct showhelp {//��Ϸ˵�����淵�ذ�ť����(525.300.540.310)
	int  showhelp_x = 525;
	int showhelp_y = 300;
	int showhelp_length = 15;
	int showhelp_width = 10;
}showhelp1;
int  playerscore[4] = { 500,500,500,500 };//���а��¼�浵����ʼ��Ϊ5 00��
int box[4] = { 2,4,3,3 };
int goal[4] = { 2,4,3,3 };//ʣ��δ����������
struct playersize
{//���λ��;
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
		case WM_LBUTTONDOWN://�������
			if (m.x >= 263 && m.x <= 384 && m.y >= 100 && m.y <= 135) {  //��ʼ��Ϸ
				Normalgame();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 142 && m.y <= 178) {  //ѡ��ؿ�
				Selectgame();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 185 && m.y <= 220) {  //��ʾ���а�
				ShowGameScore();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 228 && m.y <= 262) {  //��Ϸ˵��
				ShowGameHelp();
				DoMouse5();
				a1 = 1;
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 271 && m.y <= 304) {  //�˳���Ϸ
				exit(0);//printf("�Ѿ������˳���Ϸ\n");
				a1 = 1;
				break;
			}
			/*else if (m.x >= 263 && m.x <= 384 && m.y >= 314 && m.y <= 346) {  //��������
				//printf("�Ѿ����벥������\n");
				break;
			}
			else if (m.x >= 263 && m.x <= 384 && m.y >= 357 && m.y <= 388) {  //�ر�����
				//printf("�Ѿ�����ر�����\n");
				break;
			}*/
		}
		if (a1)
			break;
	}
}
void DoMouse5()//��Ϸ˵�����淵��
{
	ExMessage m;
	int a1 = 0;
	while (true) {
		m = getmessage(EM_MOUSE);
		switch (m.message) {
		case WM_LBUTTONDOWN://�������
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
void DefineMove(int map[10][10])//�ж��ƶ��Ƿ�Ϸ�
{
	switch (PlayerInput)
	{
	case'w':
		if (map[playersize1.x - 1][playersize1.y] == 1)//�����ǽ����moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x - 1][playersize1.y] == 2)//�ж��Ƿ�Ϊ�ذ壬�ǵĻ���moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x - 1][playersize1.y] == 3)//�Ƿ�Ϊ���ӣ���������ӣ��Ƿ����ƶ���  ��������ƶ�����moveway = 2��������ƶ�����moveway = 3��
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
		else if (map[playersize1.x - 1][playersize1.y] == 4)//�������һ���ߵ���Ŀ��λ�ã���moveway=4
		{
			moveway = 4;
		}
		break;
	case's':
		if (map[playersize1.x + 1][playersize1.y] == 1)//�����ǽ����moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x + 1][playersize1.y] == 2)//�ж��Ƿ�Ϊ�ذ壬�ǵĻ���moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x + 1][playersize1.y] == 3)//�Ƿ�Ϊ���ӣ���������ӣ��Ƿ����ƶ���  ��������ƶ�����moveway = 2��������ƶ�����moveway = 3��
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
		else if (map[playersize1.x + 1][playersize1.y] == 4)//�������һ���ߵ���Ŀ��λ�ã���moveway=4
		{
			moveway = 4;
		}
		break;
	case'd':
		if (map[playersize1.x][playersize1.y + 1] == 1)//�����ǽ����moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x][playersize1.y + 1] == 2)//�ж��Ƿ�Ϊ�ذ壬�ǵĻ���moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x][playersize1.y + 1] == 3)//�Ƿ�Ϊ���ӣ���������ӣ��Ƿ����ƶ���  ��������ƶ�����moveway = 2��������ƶ�����moveway = 3��
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
		else if (map[playersize1.x][playersize1.y + 1] == 4)//�������һ���ߵ���Ŀ��λ�ã���moveway=4
		{
			moveway = 4;
		}
		break;
	case'a':
		if (map[playersize1.x][playersize1.y - 1] == 1)//�����ǽ����moveway=0
		{
			moveway = 0;
		}
		else if (map[playersize1.x][playersize1.y - 1] == 2)//�ж��Ƿ�Ϊ�ذ壬�ǵĻ���moveway=1
		{
			moveway = 1;
		}
		else if (map[playersize1.x][playersize1.y - 1] == 3)//�Ƿ�Ϊ���ӣ���������ӣ��Ƿ����ƶ���  ��������ƶ�����moveway = 2��������ƶ�����moveway = 3��
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
		else if (map[playersize1.x][playersize1.y - 1] == 4)//�������һ���ߵ���Ŀ��λ�ã���moveway=4
		{
			moveway = 4;
		}
		break;
	}
	return;
}

void Move(int map[10][10])//����DefineMove�е�˵����������moveway��ֵ������Ӧ������
{
	switch (moveway)
	{
	case 0:       // ǽ
		break;
	case 1:           //�ذ�
		switch (nowleven)//�ؿ�
		{
		case 1:
			if (map10[playersize1.x][playersize1.y] == 4)//��Ŀ��λ���ߵ������ذ�
			{
				switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
				{
				case'a':
					map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);//Ŀ��ͼƬ�ı�
					map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
					putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
					//����ͼƬ�ı�
					playersize1.y--;
					step++;
					break;
				case'w':
					map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
					//����ͼƬ�ı�
					playersize1.x--;
					step++;
					break;
				case's':
					map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
					 //Ŀ��ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
					 //����ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
					playersize1.x++;
					step++;
					break;
				case'd':
					map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
					//Ŀ��ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
					//����ͼƬ�ı�
					putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y++;
					step++;
					break;
				}
			}
			else //������
			{
				switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
				{
				case'a':
					map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
					//�ذ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
					putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y--;
					step++;
					break;
				case'w':
					map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
					 //�ذ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
					 //����ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
					playersize1.x--;
					step++;
					break;
				case's':
					map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
					 //�ذ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
					//����ͼƬ�ı�
					step++;
					playersize1.x++;
					break;
				case'd':
					map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
					 //�ذ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
					putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
					playersize1.y++;
					step++;
					break;
				}
			}
			break;
		case 2:  if (map20[playersize1.x][playersize1.y] == 4)//��Ŀ��λ���ߵ������ذ�
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
			 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
			 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
			 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
			 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				//����ͼƬ�ı�
				step++;
				playersize1.y++;
				break;
			}
		}
			  else //������
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
			   //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				//����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				//����ͼƬ�ı�
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		case 3:  if (map30[playersize1.x][playersize1.y] == 4)//��Ŀ��λ���ߵ������ذ�
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
			 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  else  //������
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				//�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				//����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				//�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				//����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x+1][playersize1.y ] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y  * 50, START_X + (playersize1.x+1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				//�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		case 4:  if (map40[playersize1.x][playersize1.y] == 4)//��Ŀ��λ���ߵ������ذ�
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 4; // Ŀ��λ�ûָ�
				 //Ŀ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				break;
			}

		}
			  else //������
		{
			switch (PlayerInput)//�ı�playersize��Ӧ��������ֵ
			{
			case'a':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				//�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y - 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y--;
				step++;
				break;
			case'w':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x - 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				playersize1.x--;
				step++;
				break;
			case's':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x + 1][playersize1.y] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				playersize1.x++;
				step++;
				break;
			case'd':
				map[playersize1.x][playersize1.y] = 2; // �ذ�ָ�
				 //�ذ�ı�
				putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
				map[playersize1.x][playersize1.y + 1] = 5; // ���ߵĵ�ͼ�ı�
				 //����ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				playersize1.y++;
				step++;
				break;
			}
		}
			  break;
		}
		break;
	case 2:            //ǽ
		break;
	case 3:            //�Ƶ�����
		switch (nowleven)
		{
		case 1:         // ��һ��
			switch (PlayerInput) // �ƶ�����
			{
			case 'a':
				if (map10[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map10[playersize1.x][playersize1.y - 1] == 4) //��������Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map10[playersize1.x][playersize1.y - 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//���뿪ԭλ��ͼƬ�ı�
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//��������ı�
				break;
			case 'd':
				if (map10[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map10[playersize1.x][playersize1.y + 1] == 4) //��������Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map10[playersize1.x][playersize1.y + 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı� 
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//��������ı�
				break;
			case 's':
				if (map10[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map10[playersize1.x + 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map10[playersize1.x + 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//��������ı�
				break;
			case 'w':
				if (map10[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map10[playersize1.x - 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map10[playersize1.x - 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map10[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven-1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//��������ı�
				break;
			}
			break;

		case 2://�ڶ���
			switch (PlayerInput) // �ƶ�����
			{
			case 'a':
				if (map20[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map20[playersize1.x][playersize1.y - 1] == 4) //��������Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven-1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map20[playersize1.x][playersize1.y - 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//���뿪ԭλ��ͼƬ�ı�
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//��������ı�
				break;
			case 'd':
				if (map20[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map20[playersize1.x][playersize1.y + 1] == 4) //��������Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map20[playersize1.x][playersize1.y + 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//��������ı�
				break;
			case 's':
				if (map20[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map20[playersize1.x + 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map20[playersize1.x + 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//��������ı�
				break;
			case 'w':
				if (map20[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map20[playersize1.x - 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;

						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map20[playersize1.x - 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map20[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
				}
				playersize1.x = playersize1.x - 1;//��������ı�
				break;
			}
			break;
		case 3:
			switch (PlayerInput) // �ƶ�����
			{
			case 'a':
				if (map30[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map30[playersize1.x][playersize1.y - 1] == 4) //��������Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map30[playersize1.x][playersize1.y - 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//���뿪ԭλ��ͼƬ�ı�
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//��������ı�
				break;
			case 'd':
				if (map30[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map30[playersize1.x][playersize1.y + 1] == 4) //��������Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map30[playersize1.x][playersize1.y + 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//��������ı�
				break;
			case 's':
				if (map30[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map30[playersize1.x + 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map30[playersize1.x + 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
					}
				}
				playersize1.x = playersize1.x + 1;//��������ı�
				break;
			case 'w':
				if (map30[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map30[playersize1.x - 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map30[playersize1.x - 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map30[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//��������ı�
				break;
			}
			break;
		case 4:
			switch (PlayerInput) // �ƶ�����
			{
			case 'a':
				if (map40[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map40[playersize1.x][playersize1.y - 1] == 4) //��������Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map40[playersize1.x][playersize1.y - 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y - 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y - 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y - 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y - 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							//���뿪ԭλ��ͼƬ�ı�
							step++;
						}
					}
				}
				playersize1.y = playersize1.y - 1;//��������ı�
				break;
			case 'd':
				if (map40[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map40[playersize1.x][playersize1.y + 1] == 4) //��������Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
						//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map40[playersize1.x][playersize1.y + 1] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);

							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x][playersize1.y + 2] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x][playersize1.y + 2] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + (playersize1.y + 2) * 50, START_X + playersize1.x * 50, &images[3]);
							map[playersize1.x][playersize1.y + 1] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.y = playersize1.y + 1;//��������ı�
				break;
			case 's':
				if (map40[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map40[playersize1.x + 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map40[playersize1.x + 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x + 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x + 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 2) * 50, &images[3]);
							map[playersize1.x + 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x + 1;//��������ı�
				break;
			case 'w':
				if (map40[playersize1.x][playersize1.y] == 4)//�˵�λ����Ŀ��λ��
				{
					if (map40[playersize1.x - 1][playersize1.y] == 4) //��������Ŀ��λ��
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;

						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							step++;
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}


						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 4;//���뿪ԭλ�õ�ͼ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
							step++;
						}

					}
				}
				else//�˵�λ�ò���Ŀ��λ��
				{
					if (map40[playersize1.x - 1][playersize1.y] == 4) //�����Ӵ�Ŀ��λ���Ƶ��ذ�
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) // �����Ӵ���Ŀ��λ���Ƶ�Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ���һ��Ŀ��λ�õ�ͼ�ı�
							//���ӵ���һ��Ŀ��λ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							 //���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else//�����Ӵ�Ŀ��λ���Ƶ��ذ�
						{
							goal[nowleven - 1]++;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
					else //�����²���Ŀ��λ��
					{
						if (map40[playersize1.x - 2][playersize1.y] == 4) //�������Ƶ�Ŀ��λ��
						{
							goal[nowleven - 1]--;
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ�Ŀ��λ�õ�ͼ�ı�
							//���ӵ�Ŀ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
						else //�����Ʋ���Ŀ��λ��
						{
							map[playersize1.x - 2][playersize1.y] = 3;//���ӵ��ذ��ͼ�ı�
							//���ӵ��ذ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 2) * 50, &images[3]);
							map[playersize1.x - 1][playersize1.y] = 5;//�˵����ӵ�ԭλ�õ�ͼ�ı�
							//�˵����ӵ�ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
							map[playersize1.x][playersize1.y] = 2;//���뿪ԭλ�õ�ͼ�ı�
							//���뿪ԭλ��ͼƬ�ı�
							putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
							step++;
						}
					}
				}
				playersize1.x = playersize1.x - 1;//��������ı�
				break;
			}
			break;
		}
		break;
	case 4:          //����һ���ߵ���Ŀ��λ��
		switch (nowleven)
		{
		case 1:
		{
			switch (PlayerInput)
			{
			case 'a':
				map[playersize1.x][playersize1.y - 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
			//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map10[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
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
				map[playersize1.x][playersize1.y - 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
			//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map20[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
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
				map[playersize1.x][playersize1.y - 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
			//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map30[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
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
				map[playersize1.x][playersize1.y - 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y - 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y--;
				break;
			case 'd':
				map[playersize1.x][playersize1.y + 1] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + (playersize1.y + 1) * 50, START_X + playersize1.x * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.y++;
				break;
			case 's':
				map[playersize1.x + 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
			//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x + 1) * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[2]);
					step++;
				}
				playersize1.x++;
				break;
			case 'w':
				map[playersize1.x - 1][playersize1.y] = 5;//�˵���һ����ͼ�ı�
				//�˵���һ��ͼƬ�ı�
				putimage(START_X + playersize1.y * 50, START_X + (playersize1.x - 1) * 50, &images[5]);
				if (map40[playersize1.x][playersize1.y] == 4)
				{
					map[playersize1.x][playersize1.y] = 4;//��ԭ�صĵ�ͼ�ı�
					putimage(START_X + playersize1.y * 50, START_X + playersize1.x * 50, &images[4]);
					step++;
				}
				else
				{
					map[playersize1.x][playersize1.y] = 2;//��ԭ�صĵ�ͼ�ı�
				   //��ԭ�ص�ͼƬ�ı�
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
void DefineSuccess()//�ж��Ƿ�ɹ�
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
	TCHAR s1[] = _T("������");
	TCHAR s2[] = _T("��ʼ��Ϸ");
	TCHAR s3[] = _T("ѡ��ؿ�");
	TCHAR s4[] = _T("���а�");
	TCHAR s5[] = _T("��Ϸ˵��");
	TCHAR s6[] = _T("�˳���Ϸ");
	//TCHAR s7[] = _T("��������");
	//TCHAR s8[] = _T("�ر�����");
	settextstyle(35, 18, _T("����"));
	outtextxy(270, 43, s1);//������

	setcolor(RED);

	roundrect(263, 100, 384, 135, 10, 10);//roundrect(�� x ����,���� y ����,�Ҳ� x ����,�ײ� y ����)
	settextstyle(18, 9, _T("����"));
	outtextxy(289, 108, s2); //��ʼ��Ϸ

	roundrect(263, 142, 384, 178, 10, 10);
	outtextxy(289, 151, s3);    //ѡ��ؿ�

	roundrect(263, 185, 384, 220, 10, 10);
	outtextxy(298, 193, s4);    //���а�

	roundrect(263, 228, 384, 262, 10, 10);
	outtextxy(289, 235, s5);    //��Ϸ˵��

	roundrect(263, 271, 384, 304, 10, 10);
	outtextxy(289, 277, s6);    //�˳���Ϸ

	//roundrect(263, 314, 384, 346, 10, 10);
	//outtextxy(289, 319, s7);    //��������

	//roundrect(263, 357, 384, 388, 10, 10);
	//outtextxy(289, 361, s8);    //�ر�����
	DoMouse1();
	//_getch();
	closegraph();
}
void ShowGameScore() {
	char num1[10];
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	TCHAR s1[] = _T("���а�");
	TCHAR s2[] = _T("��һ�ؿ���Ͳ�����");
	TCHAR s3[] = _T("�ڶ��ؿ���Ͳ�����");
	TCHAR s4[] = _T("�����ؿ���Ͳ�����");
	TCHAR s5[] = _T("���Ĺؿ���Ͳ�����");
	TCHAR s6[] = _T("����");
	settextstyle(35, 18, _T("����"));
	setcolor(BLACK);
	outtextxy(270, 43, s1);
	setcolor(RED);
	settextstyle(18, 9, _T("����"));
	outtextxy(228, 121, s2);
	outtextxy(228, 178, s3);
	outtextxy(228, 235, s4);
	outtextxy(228, 292, s5);
	settextstyle(21, 11, _T("����"));
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
	TCHAR s1[] = _T("��Ϸ˵��");
	TCHAR s2[] = _T("���趨����Ϸ��ͼ���棬����ֻ�����ƣ���������������һ��ֻ���ƶ�һ��");
	TCHAR s3[] = _T("��ֻ����wasd���ƶ�");
	TCHAR s4[] = _T("����");
	setcolor(BLACK);
	settextstyle(35, 18, _T("����"));
	outtextxy(270, 43, s1);
	setcolor(RED);
	settextstyle(12, 6, _T("����"));
	roundrect(107, 107, 604, 231, 10, 10);
	outtextxy(128, 142, s2);
	outtextxy(128, 164, s3);
	settextstyle(21, 11, _T("����"));
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
		case WM_LBUTTONDOWN://������
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
		case WM_LBUTTONDOWN://������
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
void DoMouse4()//���а񷵻�
{
	ExMessage msg;
	int a1 = 0;
	while (1)
	{
		msg = getmessage(EM_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN://������
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
	loadimage(&bg_img, _T("ǽ1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("�ذ�.jpg"), 50, 50, true);
	loadimage(&images[BOX], _T("box.jpg"), 50, 50, true);
	loadimage(&images[DEST], _T("dest.jpg"), 50, 50, true);
	loadimage(&images[PLAYER], _T("player.jpg"), 50, 50, true);

	//����map�����Ƭ
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			putimage(START_X + j * 50, START_X + i * 50, &images[map[i][j]]);
		}
	}
	//����
	char num[10];
	settextcolor(BLACK);
	sprintf_s(num, "%d", step);
	settextstyle(40, 0, "����");
	//�������
	outtextxy(651, 44, "����=");
	outtextxy(755, 44, num);
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "��m����");

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
	loadimage(&bg_img, _T("ǽ1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("�ذ�.jpg"), 50, 50, true);
	loadimage(&images[BOX], _T("box.jpg"), 50, 50, true);
	loadimage(&images[DEST], _T("dest.jpg"), 50, 50, true);
	loadimage(&images[PLAYER], _T("player.jpg"), 50, 50, true);
	//����nowleven��map��ֵ
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

	//����
	settextcolor(BLACK);
	settextstyle(40, 0, "����");
	//�������
	outtextxy(651, 44, "����=");
	outtextxy(755, 44, "0");
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "��m����");
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
	loadimage(&bg_img, _T("ǽ1.jpg"), 800, 800, true);
	putimage(0, 0, &bg_img);
	loadimage(&images[WALL], _T("wall.jpg"), 50, 50, true);
	loadimage(&images[SPACE], _T("�ذ�.jpg"), 50, 50, true);
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
	//����map�����Ƭ
	//����
	settextcolor(BLACK);
	settextstyle(40, 0, "����");
	//�������
	outtextxy(651, 44, "����=");
	outtextxy(755, 44, "0");
	//fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	fillrectangle(gamereturn1.return_x, gamereturn1.return_y, gamereturn1.return_x + gamereturn1.return_length, gamereturn1.return_y + gamereturn1.return_width);
	outtextxy(651, 700, "��m����");
}

void SelectGameLeven()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(40, 0, "����");
	settextcolor(BLACK);
	outtextxy(245, 44, "�ؿ�ѡ��");
	setlinecolor(BLACK);
	rectangle(selectleven1.l1_x, selectleven1.l1_y, selectleven1.l1_x + selectleven1.l1_length, selectleven1.l1_y + selectleven1.l1_width);//��һ���м��20 ��250 ��60
	rectangle(selectleven1.l2_x, selectleven1.l2_y, selectleven1.l2_x + selectleven1.l2_length, selectleven1.l2_y + selectleven1.l2_width);//�ڶ���
	rectangle(selectleven1.l3_x, selectleven1.l3_y, selectleven1.l3_x + selectleven1.l3_length, selectleven1.l3_y + selectleven1.l3_width);//������
	rectangle(selectleven1.l4_x, selectleven1.l4_y, selectleven1.l4_x + selectleven1.l4_length, selectleven1.l4_y + selectleven1.l4_width);//���Ĺ�
	rectangle(selectretrun1.select_x, selectretrun1.select_y, selectretrun1.select_x + selectretrun1.select_length, selectretrun1.select_y + selectretrun1.select_width);//����
	settextstyle(25, 0, "����");
	outtextxy(290, 140, "��һ��");
	outtextxy(290, 220, "�ڶ���");
	outtextxy(290, 300, "������");
	outtextxy(290, 380, "���Ĺ�");
	outtextxy(525, 436, "����");
	DoMouse2();
}
void ShowStep()
{
	char num[10000];
	char s[] = "����=";
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