#include"allfunc.h"

void Main_function(int unum,int *func)
{
    int funct_strl=0;
    int floor=1;
    USER user={0};            //用户
    UserList UL={0};          //线性表
    InitUList(&UL);           //创建线性表
    ReadAllUser(&UL);         //获取所有用户  
    user=UL.elem[unum];       //得到当前用户 

    DestroyUList(&UL);        //销毁线性表 

    while(1)
    {
        switch (funct_strl)
        {
        case 0:
            draw_choose(&funct_strl,&floor);
            break;
        case 1:
            //draw_cat(&funct_strl,&user);
            break;
        case 2:
            //draw_feed(&funct_strl);
            break;
        case 3:
            //draw_play(&funct_strl);
            break;
        case 4:
            Readbmp64k(0, 0, "bmp\\exit.bmp");
            delay(1500);
            CloseSVGA();
            exit(1);
            break;
        case 5:
            //draw_information(&funct_strl,&user);
            break;
        case -1:
        {
            *func=0;
            break;
        }
        }
        if(*func==0)
        {
            break;
        }
    }
}

//画主界面
void draw_main(int *floor)
{
    int x=0,y=0;
	bar1(0,0,1024,768,0xF5F5DC);
	bar1(0,0,145,768,0xffffff);
	//logo
	Readbmp64k(0, 0, "bmp\\sign.bmp");
	down_arrow(0,343,142,697,0xFFB366,0x8B4513);
	//查看按钮
	bar1(0,145,145,210,0xCD5C5C);
	puthz(15,157, "查看", 48, 55, 0x000000);
	//出库按钮
	bar1(0,210,145,275,0xCD5C5C);
	puthz(15,222, "出库", 48, 55, 0x000000);
	//入库按钮
	bar1(0,275,145,340,0xCD5C5C);
	puthz(15,287, "入库", 48, 55, 0x000000);
	//退出按钮
	bar1(0,700,145,768,0xC0C0C0);
	puthz(15,712, "退出", 48, 55, 0x000000);
	//画线
	Line3(0,275,145,275,3,0x000000);
	Line3(0,700,145,700,3,0x000000);
	Line3(0,210,145,210,3,0x000000);
	Line3(0,340,145,340,3,0x000000);
	Line3(145,0,145,768,3,0x000000);
	Line3(0,145,145,145,3,0x000000);
	//画柜子
	guizi(240,68,1);
	guizi(630,68,2);
	guizi(240,293,3);
	guizi(630,293,4);
	guizi(240,518,5);
	guizi(630,518,6);
	//电梯
	bar1(540,0,630,70,0x000000);
	bar1(542,2,628,68,0xE0FFFF);
	Line_Thick(585, 0, 585, 70, 1, 0x000000);
	up_arrow(500,10,530,60,0xAFDFE4,0x00477D);
	bar1(640,10,690,60,0xADD8E6);
    //传送带
    if(*floor==1)
    {
        //左边传送带
        bar1(145,680,170,742,0x000000);
        Circlefill(170, 690, 10, 0x000000);
        bar1(160,690,180,742,0x000000);
        bar1(148,732,170,752,0xffffff);
        Circlefill(170, 742, 10, 0xF0F8FF);
        Circlefill(170, 742, 2, 0x000000);
        left_arrow1(200,720,250,760,0xC0C0C0);
        //右边传送带
        bar1(999,680,1024,742,0x000000);
        Circlefill(999, 690, 10, 0x000000);
        bar1(989,690,999,742,0x000000);
        bar1(999,732,1024,752,0xffffff);
        Circlefill(999, 742, 10, 0xF0F8FF);
        Circlefill(999, 742, 2, 0x000000);
        right_arrow1(920,720,970,760,0xC0C0C0);
    }
	switch (*floor)
	{
	case 1:
		put_asc16_number_size(650, 7, 4, 4, 1, 0x000000);
		break;
	case 2:
		put_asc16_number_size(650, 7, 4, 4, 2, 0x000000);
		break;
	case 0:
		put_asc16_number_size(644, 13, 3, 3, -1, 0x000000);
	default:
		break;
	}
	
	down_arrow(700,10,730,60,0xAFDFE4,0x00477D);
}

void draw_choose(int *funct_strl,int *floor)
{
    mouse_off(&mouse);
    draw_main(floor);
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        //查看按钮
        if(mouse_press(0,145,145,210)==1)
        {
            mouse_off(&mouse);
            *funct_strl=1;
            break;
        }
        //出库按钮
        if(mouse_press(0,210,145,275)==1)
        {
            mouse_off(&mouse);
            *funct_strl=2;
            break;
        }
        //入库按钮
        if(mouse_press(0,275,145,340)==1)
        {
            mouse_off(&mouse);
            *funct_strl=3;
            break;
        }
        //退出按钮
        if(mouse_press(0,700,145,768)==1)
        {
            mouse_off(&mouse);
            *funct_strl=4;
            break;
        }
        //电梯上按钮
        if(mouse_press(500,10,530,60)==1)
        {
            mouse_off(&mouse);
            if(*floor<=1)
            {
                (*floor)++;
            }
            *funct_strl=0;
        }
        //电梯下按钮
        if(mouse_press(700,10,730,60)==1)
        {
            if(*floor>=1)
            {
                (*floor)--;
            }
            mouse_off(&mouse);
            *funct_strl=0;
            break;
        }
        delay(15);
    }
}
