#include "allfunc.h"

void guizi(int x1,int y1,int num)
{
    int x=0;
    bar1(x1+4,y1+60,x1+300,y1+180,0xffffff);
    
    //���Ӷ�����ɫ
    for(x=x1;x<=x1+40;x++)
    {
        Line_Thick(x1+40,y1+30,x,y1+60,1,0xF5DEB3);
    }
    bar1(x1+40,y1+30,x1+260,y1+60,0xF5DEB3);
    for(x=x1+260;x<=x1+300;x++)
    {
        Line_Thick(x1+260,y1+30,x,y1+60,1,0xF5DEB3);
    }
    //����
    Line3(x1+300,y1+30,x1+300,y1+200,4,0x000000);
    Line3(x1+2,y1+30,x1+2,y1+200,4,0x000000);
    Line3(x1+150,y1+60,x1+150,y1+182,4,0x000000);
    Line3(x1+75,y1+60,x1+75,y1+182,4,0x000000);
    Line3(x1+225,y1+60,x1+225,y1+182,4,0x000000);
    Line3(x1+40,y1+0,x1+40,y1+30,4,0x000000);
    Line3(x1+260,y1+0,x1+260,y1+30,4,0x000000);
    //����
    Line3(x1+0,y1+60,x1+300,y1+60,4,0x000000);
    Line3(x1+0,y1+90,x1+300,y1+90,4,0x000000);
    Line3(x1+0,y1+120,x1+300,y1+120,4,0x000000);
    Line3(x1+0,y1+150,x1+300,y1+150,4,0x000000);
    Line3(x1+0,y1+180,x1+300,y1+180,4,0x000000);
    Line3(x1+40,y1+30,x1+260,y1+30,4,0x000000);
    //��б��
    Line2(x1+40,y1+30,x1+0,y1+60,0x000000);
    Line2(x1+39,y1+30,x1+0,y1+59,0x000000);
    Line2(x1+38,y1+30,x1+0,y1+58,0x000000);
    Line2(x1+41,y1+30,x1+1,y1+61,0x000000);
    Line2(x1+42,y1+30,x1+1,y1+62,0x000000);
    //��б��
    Line2(x1+260,y1+30,x1+300,y1+60,0x000000);
    Line2(x1+261,y1+30,x1+300,y1+59,0x000000);
    Line2(x1+262,y1+30,x1+300,y1+58,0x000000);
    Line2(x1+259,y1+30,x1+299,y1+61,0x000000);
    Line2(x1+258,y1+30,x1+299,y1+62,0x000000);
    //��ͷ
    down_arrow1(x1+80,y1+35,x1+105,y1+55,0xFFB366);
    up_arrow1(x1+205,y1+35,x1+230,y1+55,0xFFB366);
    puthz(x1+235,y1+37,"��",16, 27,0x73B839);
    puthz(x1+55,y1+37,"��", 16, 27, 0x73B839);
    //����
    Circlefill(x1+157,y1+45,10,0x000000);
    Circlefill(x1+157,y1+45,9,0xFFD700);
    if(num==1)
    puthz(x1+150,y1+37,"һ",16, 27,0x000000);
    else if(num==2)
    puthz(x1+150,y1+37,"��",16, 27,0x000000);
    else if(num==3)
    puthz(x1+150,y1+37,"��",16, 27,0x000000);
    else if(num==4)
    puthz(x1+150,y1+37,"��",16, 27,0x000000);
    else if(num==5)
    puthz(x1+150,y1+37,"��",16, 27,0x000000);
    else if(num==6)
    puthz(x1+150,y1+37,"��",16, 27,0x000000);

}

//�п��ϼ�ͷ(��һ��color1Ϊ��ͷ��ɫ���ڶ���color2Ϊ������ɫ)
void up_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int x=0;
    bar1(x1,y1,x2,y2,color2);
    //��������
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

//�޿��ϼ�ͷ
void up_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{   
    //��������
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

//�п��¼�ͷ(��һ��color1Ϊ��ͷ��ɫ���ڶ���color2Ϊ������ɫ)
void down_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int x=0;
    bar1(x1,y1,x2,y2,color2);
    //��������
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

//�޿��¼�ͷ
void down_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{    
    //��������
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

//�п����ͷ(��һ��color1Ϊ��ͷ��ɫ���ڶ���color2Ϊ������ɫ)
void left_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int y=0;
    bar1(x1,y1,x2,y2,color2);   
    //��������
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

//�޿����ͷ
void left_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{
    //��������
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

//�п��Ҽ�ͷ(��һ��color1Ϊ��ͷ��ɫ���ڶ���color2Ϊ������ɫ)
void right_arrow(int x1,int y1,int x2,int y2,int color1,int color2)
{
    int y=0;
    bar1(x1,y1,x2,y2,color2);
    //��������
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

//�޿��Ҽ�ͷ
void right_arrow1(int x1,int y1,int x2,int y2,unsigned int color)
{
    //��������
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

//���˻�����
//void robot(int x1,int y1,int x2,int y2)