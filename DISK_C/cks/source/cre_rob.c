#include "allfunc.h"

void cre_rob(ROBOT *robot,int floor)
{
    robot->floor = floor;
    robot->goods_num = 0;
    robot->direction = 0;
    robot->state = 0;

}

//画机器人
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