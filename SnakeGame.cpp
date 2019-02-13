#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <conio.h>
#include <stdio.h>  
 

//2015-11-13

//THis is a Simple snake game based on concole created by Praneeth Jayarathna :)

void GotoXY(int x, int y);
void animation();
void gameSleep();
void moveRight();
void moveLeft();
void moveUp();
void moveDown();
void direction();
void food();
void marks();
void startup();
static char snake='*';
static char foods='@';
static int bordwidth=30;
static int bordheight=30;
static int count=0;
static int life=3;
static bool exists=false;
int a=3;
int b=3;

char key;
int bend_no;
bool stop=false;
struct coord{
	int x;
	int y;
	int direction;
	char shape;
};

coord snakeBody,foodBody;

int main(){
snakeBody.direction=0;

startup();
  
 
	return 0;
}
void startup(){
	
	do{
	system("cls");
	printf("%s","__________________________________________________________________");
	printf("\n %s","\t   Tiny Snake Game");
	printf("\n %s","\t   Game controll");
	printf("\n %s","\t   Up: w ");
	printf("\n %s","\t   Down: s ");
	printf("\n %s","\t   Left: a ");
	printf("\n %s","\t   Right: d ");
	printf("\n %s","\t   Press any key to Start");
	printf("\n %s","__________________________________________________________________");
	}while(!kbhit());

 	
	
	 
	animation();
 
}
void animation(){
 
do 
{
 
			
	if(snakeBody.direction==0){
 	moveRight();
  
	}else if(snakeBody.direction==1){
	 	moveLeft();
	 	 
	}else if(snakeBody.direction==2){
	 	moveUp();
	 	 
	}else if(snakeBody.direction==3){
 	moveDown();
 	 
	}
	
} while(!kbhit());

	  	 
	

}

void direction(){
		

	int	keys=getch();
 //std::cout<<keys;

		 if(keys==119 || keys==87){
	  	snakeBody.direction=2;
	  
			 moveUp();
	}
	  // printf("%i",keys);
	 else if(keys==115 || keys==83){
	
	  	snakeBody.direction=3;
   
			 moveDown();
	}
	  
	   else if(keys==100 || keys==68){
	  	 
		  snakeBody.direction=0;
   
		  moveRight();
	}   
	 
	 else if(keys==97 || keys==65){
	  	snakeBody.direction=1;
	   
    
 
			 moveLeft();
	} else{
		system("pause");
	}
 
}

void marks(){
		GotoXY(5,0);
//std::cout<<"Marks = "+count;
printf("Marks %i",count);
printf(" Lifes %i",life);

if(life==0){
	while(true){
	
	system("cls");
	 
	printf("%s","your lifes are over your mark is ");
	printf("%i",count);
}
}

}
void food(){


if(exists==false){
	
foodBody.x=rand()%70;
foodBody.y=rand()%20;
foodBody.y+=2;
	exists=true;
}
 
	
	GotoXY(foodBody.x,foodBody.y);
	foodBody.shape=foods;
	std::cout<<foodBody.shape;	
 
	
 
	if(foodBody.x==snakeBody.x&&foodBody.y==snakeBody.y){
	Beep (330,100);
		exists=false;
		count++;
		
	}

}

void moveRight(){
	
 a=snakeBody.x;
 b=snakeBody.y;
   while(!kbhit()){
	food();
 
   a++;
	 
	gameSleep();
	GotoXY(a,b);
	snakeBody.shape=snake;
	system("Color 1A");
	std::cout<<snakeBody.shape;	
	snakeBody.x=a;
	snakeBody.y=b;
	
 if(snakeBody.x>=80){
 life--;
 	moveLeft();
 	
 }
 	 // }
	
//}
	
}
 
 direction();
 
//moveLeft();
}
void moveLeft(){
	
 a=snakeBody.x;
  b=snakeBody.y;
	   while(!kbhit()){
	//	for(a=snakeBody.x;a>0;a--)	{
food();
	 a--;
gameSleep();
	GotoXY(a,b);
	snakeBody.shape=snake;
	std::cout<<snakeBody.shape;
	snakeBody.x=a;
	snakeBody.y=b;
	  	  if(snakeBody.x<=3){
 			life--;
		 moveRight();
 	
 }

	}
direction();
}

 

void moveUp(){
	
	 a=snakeBody.x;
  b=snakeBody.y;
	
	while(!kbhit()){
	  food();
	 b--;
	gameSleep();
	GotoXY(a,b);
	snakeBody.shape=snake;
	std::cout<<snakeBody.shape;
	snakeBody.x=a;
	snakeBody.y=b;
	  	  if(snakeBody.y<=0){
 	life--;
	 	moveDown();
 		
 }
	}
direction();
}


void moveDown(){
	
	 a=snakeBody.x;
	  b=snakeBody.y;
	 
	while(!kbhit()){
	 food();
	 b++;
gameSleep();
	GotoXY(a,b);
	snakeBody.shape=snake;
	std::cout<<snakeBody.shape;
		snakeBody.x=a;
	snakeBody.y=b;
	  	  	  if(snakeBody.y>=25){
 	life--;
	 	moveUp();
 		
 }
	}
direction();
}

void gameSleep(){
		 usleep(30000);
		 
	system("cls");
	marks();
}
 
void GotoXY(int x, int y)
{
    

	HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
 
