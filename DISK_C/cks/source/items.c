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

void draw_guizi2(int number,int x1,int y1) {
    int x2, y2, x3, y3, x4, x5;
    y2 = y1 + 70;
    x2 = x1 + 180;
    y3=(y1+y2)/2;
    x3=(x1+x2)/2;
    x4=(x1+x3)/2;
    x5=(x3+x2)/2;
    bar1(x1, y1, x2, y2, 0x6A5ACD);
    Line2(x1, y3, x2, y3, 0x000000);
    Line2(x3, y1, x3, y2, 0x000000);
    Line2(x4, y1, x4, y2, 0x000000);
    Line2(x5, y1, x5, y2, 0x000000);
    if(number!=0){
    puthz(x5, y1-15, "反",16,16, 0x000000);
    puthz(x5, y2+5, "正",16,16, 0x000000);
    Circlefill(x1,y1-22,20,0xF5F5F5);
    }
    if(number==1){
    put_asc16_size(x1-10,y1-30,2,2,"1",0x000000);
    }
    else if(number==2){
    put_asc16_size(x1-10,y1-30,2,2,"2",0x000000);
    }
    else if(number==3){ 
    put_asc16_size(x1-10,y1-30,2,2,"3",0x000000);
    }
    else if(number==4){
    put_asc16_size(x1-10,y1-30,2,2,"4",0x000000);
    }
    else if(number==5){
    put_asc16_size(x1-10,y1-30,2,2,"5",0x000000);
    }
    else if(number==6){
    put_asc16_size(x1-10,y1-30,2,2,"6",0x000000);
    }
}

//画包裹
void draw_goods(int x,int y)
{
    int x1=0;
    for(x1=0;x1<=10;x1++)
    {
        Line_Thick(x+10,y+0,x+x1,y+11,1,0xADFF2F);
    }
    for(x1=41;x1<=51;x1++)
    {
        Line_Thick(x+41,y+0,x+x1,y+11,1,0xADFF2F);
    }

    bar1(x+10,y+0,x+41,y+11,0xADFF2F);
    bar1(x+0,y+11,x+51,y+36,0x32CD32);
    bar1(x+1,y+12,x+50,y+35,0xADFF2F);
    bar1(x+32,y+27,x+49,y+33,0x32CD32);
    bar1(x+33,y+28,x+48,y+32,0xffffff);

    Line_Thick(x+0,y+11,x+10,y+0,1,0x32CD32);
    Line_Thick(x+10,y+0,x+41,y+0,1,0x32CD32);
    Line_Thick(x+41,y+0,x+51,y+11,1,0x32CD32);
    Line_Thick(x+5,y+5,x+46,y+5,1,0x32CD32);
    
}