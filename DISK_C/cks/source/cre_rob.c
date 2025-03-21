#include "allfunc.h"

void cre_rob(ROBOT *robot,int floor)
{
    robot->floor = floor;
    robot->goods_num = 0;
    robot->direction = 0;
    robot->state = 0;

}

//画不规则机器人
void draw_robot(int x,int y,int state,int direction)//x=50,y=50
{
    int x1=0;
    for(x1=x-50;x1<=x-30;x1++)
    {
        Line_Thick(x-30,y-30,x1,y,1,0xFAF0E6);
    }
    for(x1=x+30;x1<=x+50;x1++)
    {
        Line_Thick(x+30,y-30,x1,y,1,0xFAF0E6);
    }
    bar1(x-30,y-30,x+30,y+30,0xFAF0E6);
    bar1(x-40,y,x+40,y+30,0x000000);
    bar1(x-37,y,x+37,y+27,0xFFFFE0);
    //轮子和探测器
    Circle(x-25,y+15,6,0x000000);
    Circle(x+25,y+15,6,0x000000);
    Circlefill(x-25,y+15,3,0x73B839);
    Circlefill(x+25,y+15,3,0x73B839);

    Circlefill(x-25,y+38,8,0x000000);
    Circlefill(x+25,y+38,8,0x000000);
    Circlefill(x-25,y+38,3,0xffffff);
    Circlefill(x+25,y+38,3,0xffffff);


    //方向指示器
    switch (direction)
    {
    case 0:
        up_arrow(x-10,y+5,x+10,y+25,0xCD5C5C,0xFFFFFF);
        break;
    case 1:
        down_arrow(x-10,y+5,x+10,y+25,0xCD5C5C,0xFFFFFF);
        break;
    case 2:
        left_arrow(x-10,y+5,x+10,y+25,0xCD5C5C,0xFFFFFF);
        break;
    case 3:
        right_arrow(x-10,y+5,x+10,y+25,0xCD5C5C,0xFFFFFF);
        break;
    }
    


    Line_Thick(x-30,y-30,x-50,y,1,0x000000);
    Line_Thick(x-30,y-30,x+30,y-30,1,0x000000);
    Line_Thick(x+30,y-30,x+50,y,1,0x000000);
    Line_Thick(x-50,y,x+50,y,1,0x000000);
    
    //画包裹
    if(state!=0||state!=1)
    {
        draw_goods(x-25,y-50);
    }
}


//遥控机器人
void remote_robot(int x,int y,int state,int direction,int *floor,int *funct_strl)
{

    while(1)
    {
        int x1=0;
        int y1=0;
        x1=x;
        y1=y;
        if(kbhit())
            switch(getch())
            {
                case 'w':
                    direction=0;
                    if(direction==0)
                    {
                        y-=5;
                    }
                    continue;
                case's':
                    direction=1;
                    if(direction==1)
                    {
                        y+=5;
                    }
                    continue;
                case 'a':
                    direction=2;
                    if(direction==2)
                    {
                        x-=5;
                    }
                    continue;
                case 'd':
                    direction=3;
                    if(direction==3)
                    {
                        x+=5;
                    }
                    continue;
                case 'q':
                    *funct_strl=1;
                    break;
            }
        if(x1!=x||y1!=y)
            draw_main(floor);
        
        draw_robot(x,y,state,direction);
        delay(500);
    }
}

/*//画机器人简易版
void draw_robot_simple(int x,int y,int state,int direction)//x=50,y=50
{
    bar1(x-30,y-30,x+30,y+30,0xFAF0E6);
    //画包裹
    if(state!=0||state!=1)
    {
        draw_goods(x-25,y-50);
    }
}*/