#include"allfunc.h"

void welcome(int *func)
{
	int floor=0;
	mouse_off(&mouse);

	draw_basic_logging();//画登录、注册界面必备基本元素
	draw_welcome();//画欢迎界面的特有元素

	
	
	mouse_on(mouse);

	while(1)
	{
		mouse_show(&mouse);

		if(mouse_press(535,395,855,485)==1)
		{
			*func=2;
			break;
		}
		if(mouse_press(535,540,855,630)==1)
		{
			*func=3;
			break;
		}
	}
}


//画登录、注册界面必备基本元素
void draw_basic_logging()
{
	bar1(0, 0, 1024, 768, 0x87CEFA);
	//上层圈圈
	Circlefill(580, 60, 40, 0x00FF00);
	Circlefill(755, 40, 45, 0xFFAAAA);
	Circlefill(380, 240, 60, 0xBDBD00);
	Circlefill(675, 105, 35, 0x00BD2E);
	//draw_workbox();
	Readbmp64k(0, 0, "bmp\\logoo.bmp");

	puthz(500, 230, "物品登记", 32, 27, 0x000000);
	puthz(630, 230, "自动入库", 32, 27, 0x000000);
	puthz(760, 230, "订单分配", 32, 27, 0x000000);
	puthz(890, 230, "包装出库", 32, 27, 0x000000);
	
}

void draw_botton(int x1,int y1,int x2,int y2,int Cowercolor,int Bordercolor)
{
	Cirbar(x1, y1, x2, y2, Bordercolor);
	Cirbar(x1,y1+2,x2,y2-2,Cowercolor);
}
//画欢迎界面的特有元素


void draw_welcome()
{
    //标题
	puthz(660,50,"欢迎来到", 48,50, 0x800080);
	puthz(490,140,"《武汉市立体仓储管理中心》", 32,40, 0x00FF);

	//选项框
    draw_botton(535,393,855,487,0xFFC0CB,0xADD8E6);//登录矩形框
    draw_botton(535,538,855,632,0xFFC0CB,0xDDDD);//注册矩形框

	//写字
	prt_hz16_size(650,420, 3, 3, "登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(650,565, 3, 3, "注册", 0xFFFFFF, "HZK\\HZK16s");
    
}

