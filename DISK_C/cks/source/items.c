#include "allfunc.h"

void guizi(int x1,int y1,int num)
{
    int x=0;
    bar1(x1+4,y1+60,x1+300,y1+180,0xffffff);
    
    //柜子顶部颜色
    for(x=x1;x<=x1+40;x++)
    {
        Line_Thick(x1+40,y1+30,x,y1+60,1,0xF5DEB3);
    }
    bar1(x1+40,y1+30,x1+260,y1+60,0xF5DEB3);
    for(x=x1+260;x<=x1+300;x++)
    {
        Line_Thick(x1+260,y1+30,x,y1+60,1,0xF5DEB3);
    }
    //竖线
    Line3(x1+300,y1+30,x1+300,y1+200,4,0x000000);
    Line3(x1+2,y1+30,x1+2,y1+200,4,0x000000);
    Line3(x1+150,y1+60,x1+150,y1+182,4,0x000000);
    Line3(x1+75,y1+60,x1+75,y1+182,4,0x000000);
    Line3(x1+225,y1+60,x1+225,y1+182,4,0x000000);
    Line3(x1+40,y1+0,x1+40,y1+30,4,0x000000);
    Line3(x1+260,y1+0,x1+260,y1+30,4,0x000000);
    //横线
    Line3(x1+0,y1+60,x1+300,y1+60,4,0x000000);
    Line3(x1+0,y1+90,x1+300,y1+90,4,0x000000);
    Line3(x1+0,y1+120,x1+300,y1+120,4,0x000000);
    Line3(x1+0,y1+150,x1+300,y1+150,4,0x000000);
    Line3(x1+0,y1+180,x1+300,y1+180,4,0x000000);
    Line3(x1+40,y1+30,x1+260,y1+30,4,0x000000);
    //左斜线
    Line2(x1+40,y1+30,x1+0,y1+60,0x000000);
    Line2(x1+39,y1+30,x1+0,y1+59,0x000000);
    Line2(x1+38,y1+30,x1+0,y1+58,0x000000);
    Line2(x1+41,y1+30,x1+1,y1+61,0x000000);
    Line2(x1+42,y1+30,x1+1,y1+62,0x000000);
    //右斜线
    Line2(x1+260,y1+30,x1+300,y1+60,0x000000);
    Line2(x1+261,y1+30,x1+300,y1+59,0x000000);
    Line2(x1+262,y1+30,x1+300,y1+58,0x000000);
    Line2(x1+259,y1+30,x1+299,y1+61,0x000000);
    Line2(x1+258,y1+30,x1+299,y1+62,0x000000);
    //箭头
    down_arrow1(x1+80,y1+35,x1+105,y1+55,0xFFB366);
    up_arrow1(x1+205,y1+35,x1+230,y1+55,0xFFB366);
    puthz(x1+235,y1+37,"反",16, 27,0x73B839);
    puthz(x1+55,y1+37,"正", 16, 27, 0x73B839);
    //文字
    Circlefill(x1+157,y1+45,10,0x000000);
    Circlefill(x1+157,y1+45,9,0xFFD700);
    if(num==1)
    puthz(x1+150,y1+37,"一",16, 27,0x000000);
    else if(num==2)
    puthz(x1+150,y1+37,"二",16, 27,0x000000);
    else if(num==3)
    puthz(x1+150,y1+37,"三",16, 27,0x000000);
    else if(num==4)
    puthz(x1+150,y1+37,"四",16, 27,0x000000);
    else if(num==5)
    puthz(x1+150,y1+37,"五",16, 27,0x000000);
    else if(num==6)
    puthz(x1+150,y1+37,"六",16, 27,0x000000);

}

//有框上箭头(第一个color1为箭头颜色，第二个color2为背景颜色)
void up_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int x=0;
    bar1(x1,y1,x2,y2,color2);
    //画三角形
    for (x=x1;x<=x2;x++)
    {
        Line_Thick((x1+x2)/2,y1,x,(y1+y2)/2,1,color1);
    }
    bar1((x2+x1*2)/3,(y1+y2)/2,(x1+x2*2)/3,y2,color1);
    Line2(x1,y1,x1,y2,0x000000);
    Line2(x1,y1,x2,y1,0x000000);
    Line2(x2,y1,x2,y2,0x000000);
    Line2(x1,y2,x2,y2,0x000000);
    Line2((x1+x2)/2,y1,x1,(y1+y2)/2,0x000000);
    Line2((x1+x2)/2,y1,x2,(y1+y2)/2,0x000000);
    Line2(x1,(y1+y2)/2,(x2+x1*2)/3,(y1+y2)/2,0x000000);
    Line2((2*x2+x1)/3,(y1+y2)/2,x2,(y1+y2)/2,0x000000);
    Line2(x2,(y1+y2)/2,(2*x2+x1)/3,(y1+y2)/2,0x000000);
    Line2((x1+x2*2)/3,(y1+y2)/2,(x1+x2*2)/3,y2,0x000000);
    Line2((2*x1+x2)/3,(y1+y2)/2,(2*x1+x2)/3,y2,0x000000);
    Line2((x2+x1*2)/3,y2,(x1+x2*2)/3,y2,0x000000);
}

//无框上箭头
void up_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{   
    //画三角形
    int x=0;
    for (x=x1;x<=x2;x++)
    {
        Line_Thick((x1+x2)/2,y1,x,(y1+y2)/2,1,color);
    }
    bar1((x2+x1*2)/3,(y1+y2)/2,(x1+x2*2)/3,y2,color);
    Line2((x1+x2)/2,y1,x1,(y1+y2)/2,0x000000);
    Line2((x1+x2)/2,y1,x2,(y1+y2)/2,0x000000);
    Line2(x1,(y1+y2)/2,(x2+x1*2)/3,(y1+y2)/2,0x000000);
    Line2((2*x2+x1)/3,(y1+y2)/2,x2,(y1+y2)/2,0x000000);
    Line2(x2,(y1+y2)/2,(2*x2+x1)/3,(y1+y2)/2,0x000000);
    Line2((x1+x2*2)/3,(y1+y2)/2,(x1+x2*2)/3,y2,0x000000);
    Line2((2*x1+x2)/3,(y1+y2)/2,(2*x1+x2)/3,y2,0x000000);
    Line2((x2+x1*2)/3,y2,(x1+x2*2)/3,y2,0x000000);
}

//有框下箭头(第一个color1为箭头颜色，第二个color2为背景颜色)
void down_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int x=0;
    bar1(x1,y1,x2,y2,color2);
    //画三角形
    for (x=x1;x<=x2;x++)
    {
        Line_Thick((x1+x2)/2,y2,x,(y1+y2)/2,1,color1);
    }
    bar1((x2+x1*2)/3,y1,(x1+x2*2)/3,(y1+y2)/2,color1);
    Line2(x1,y1,x1,y2,0x000000);
    Line2(x1,y1,x2,y1,0x000000);        
    Line2(x2,y1,x2,y2,0x000000);
    Line2(x1,y2,x2,y2,0x000000);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y2,x2,(y1+y2)/2,0x000000);
    Line2(x1,(y1+y2)/2,(x2+x1*2)/3,(y1+y2)/2,0x000000);
    Line2((2*x2+x1)/3,(y1+y2)/2,x2,(y1+y2)/2,0x000000);
    Line2(x2,(y1+y2)/2,(2*x2+x1)/3,(y1+y2)/2,0x000000);
    Line2((x1+x2*2)/3,(y1+y2)/2,(x1+x2*2)/3,y1,0x000000);
    Line2((2*x1+x2)/3,(y1+y2)/2,(2*x1+x2)/3,y1,0x000000);
    Line2((x2+x1*2)/3,y1,(x1+x2*2)/3,y1,0x000000);
}

//无框下箭头
void down_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{    
    //画三角形
    int x=0;
    for (x=x1;x<=x2;x++)
    {
        Line_Thick((x1+x2)/2,y2,x,(y1+y2)/2,1,color);
    }
    bar1((x2+x1*2)/3,y1,(x1+x2*2)/3,(y1+y2)/2,color);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y2,x2,(y1+y2)/2,0x000000);
    Line2(x1,(y1+y2)/2,(x2+x1*2)/3,(y1+y2)/2,0x000000);
    Line2((2*x2+x1)/3,(y1+y2)/2,x2,(y1+y2)/2,0x000000);
    Line2(x2,(y1+y2)/2,(2*x2+x1)/3,(y1+y2)/2,0x000000);
    Line2((x1+x2*2)/3,(y1+y2)/2,(x1+x2*2)/3,y1,0x000000);
    Line2((2*x1+x2)/3,(y1+y2)/2,(2*x1+x2)/3,y1,0x000000);
    Line2((x2+x1*2)/3,y1,(x1+x2*2)/3,y1,0x000000);
}

//有框左箭头(第一个color1为箭头颜色，第二个color2为背景颜色)
void left_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int y=0;
    bar1(x1,y1,x2,y2,color2);   
    //画三角形
    for (y=y1;y<=y2;y++)
    {
        Line_Thick(x1,(y1+y2)/2,(x2+x1)/2,y,1,color1);
    }
    bar1((x1+x2)/2,(y1*2+y2)/3,x2,(y2*2+y1)/3,color1);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y1,0x000000);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y1,(x1+x2)/2,(y1*2+y2)/3,0x000000);
    Line2((x1+x2)/2,(y1*2+y2)/3,x2,(y1*2+y2)/3,0x000000);
    Line2(x2,(y1*2+y2)/3,x2,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,x2,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,(x1+x2)/2,y2,0x000000);
}

//无框左箭头
void left_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{
    //画三角形
    int y=0;
    for (y=y1;y<=y2;y++)
    {
        Line_Thick(x1,(y1+y2)/2,(x2+x1)/2,y,1,color);
    }
    bar1((x1+x2)/2,(y1*2+y2)/3,x2,(y2*2+y1)/3,color);
    Line2(x1,y1,x2,y1,0x000000);
    Line2(x1,y1,x1,y2,0x000000);
    Line2(x1,y2,x2,y2,0x000000);
    Line2(x2,y1,x2,y2,0x000000);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y1,0x000000);
    Line2(x1,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y1,(x1+x2)/2,(y1*2+y2)/3,0x000000);
    Line2((x1+x2)/2,(y1*2+y2)/3,x2,(y1*2+y2)/3,0x000000);
    Line2(x2,(y1*2+y2)/3,x2,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,x2,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,(x1+x2)/2,y2,0x000000);
   
}

//有框右箭头(第一个color1为箭头颜色，第二个color2为背景颜色)
void right_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int y=0;
    bar1(x1,y1,x2,y2,color2);
    //画三角形
    for (y=y1;y<=y2;y++)
    {
        Line_Thick(x2,(y1+y2)/2,(x2+x1)/2,y,1,color1);
    }
    bar1(x1,(y1*2+y2)/3,(x1+x2)/2,(y2*2+y1)/3,color1);
    Line2(x1,y1,x2,y1,0x000000);
    Line2(x1,y1,x1,y2,0x000000);
    Line2(x1,y2,x2,y2,0x000000);
    Line2(x2,y1,x2,y2,0x000000);
    Line2(x2,(y1+y2)/2,(x1+x2)/2,y1,0x000000);
    Line2(x2,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y1,(x1+x2)/2,(y1*2+y2)/3,0x000000);
    Line2((x1+x2)/2,(y1*2+y2)/3,x1,(y1*2+y2)/3,0x000000);
    Line2(x1,(y1*2+y2)/3,x1,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,x1,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,(x1+x2)/2,y2,0x000000);
}

//无框右箭头
void right_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{
    //画三角形
    int y=0;
    for (y=y1;y<=y2;y++)
    {
        Line_Thick(x2,(y1+y2)/2,(x2+x1)/2,y,1,color);
    }
    bar1(x1,(y1*2+y2)/3,(x1+x2)/2,(y2*2+y1)/3,color);
    Line2(x2,(y1+y2)/2,(x1+x2)/2,y1,0x000000);
    Line2(x2,(y1+y2)/2,(x1+x2)/2,y2,0x000000);
    Line2((x1+x2)/2,y1,(x1+x2)/2,(y1*2+y2)/3,0x000000);
    Line2((x1+x2)/2,(y1*2+y2)/3,x1,(y1*2+y2)/3,0x000000);
    Line2(x1,(y1*2+y2)/3,x1,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,x1,(y2*2+y1)/3,0x000000);
    Line2((x1+x2)/2,(y2*2+y1)/3,(x1+x2)/2,y2,0x000000);
    
}

//搬运机器人
//void robot(int x1,int y1,int x2,int y2)