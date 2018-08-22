
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>	
using namespace std;
bool gameover;
int tailx[50],taily[50];
int nTail;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;

enum edirection
	{
		STOP=0,LEFT,RIGHT,UP,DOWN
	};
edirection dir;

void visual()
{
	system("cls");
	for(int i=0;i<width+2;i++)
	{
		cout<<"#";
	}
	cout<<endl; 
	for(int k=0;k<width;k++)
	{
		for(int j=0;j<width;j++)
		{
		if(j==0) cout<<"#";
		if(k==y &&j==x) cout<<"0";
		else if(k == fruity && j==fruitx ) cout<<"*";
		else
		{
			bool printail=false;
			for(int p=0;p<nTail;p++)
			{
				if(tailx[p]==j &&taily[p]==k){
				cout<<"o";printail=true;}
			}
			if(!printail)
		cout<<" ";}
		if (j==width-1){
		cout<<"#";	}
		}cout<<endl;
	} 
		for(int i=0;i<width+2;i++)
	{
		cout<<"#";
	}
	
}
void settings() 
{
	gameover=false; 
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand() %width;
    fruity=rand() %height;
    score=0;
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':dir=LEFT;break;
			case 'd':dir=RIGHT;break;
			case 'w':dir=UP;break;
			case 's':dir=DOWN;break;
			case 'p':gameover=true;break;			
		}

	}
	
}
void logic()
{
	int prevX=tailx[0];
	int prevY=taily[0];
	int prev2X,prev2Y;
	tailx[0]=x;taily[0]=y;
	for(int i=1;i<nTail;i++)	
	{ 
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}		
	switch(dir)
	{
		case  LEFT:x--;break;
		case RIGHT:x++;break; 
		case UP:y--;break;
		case DOWN:y++;break;
		default:break;
	}
	if(x>=width)x=0;
	else if (x<0) x=width-1;
	if(y>=height) y=0;
	else if (y<0) y=height-1;

	for(int i=0;i<nTail;i++)
	{
		if(tailx[i]==x &&taily[i]==y)
		{
			gameover=true;
		}
	}

	if(x == fruitx && y==fruity)
	{
		score++; 
		fruitx=rand() %width;
    	fruity=rand() %height;
		nTail++;
	}
}
int main()
{
	settings();
	while(!gameover)
	{
		visual();
		input();
		logic();
		cout<<endl; 
		cout<<"score is  "<<score<<endl;
		Sleep(123);
	}
}