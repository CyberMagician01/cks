#include "allfunc.h"

//画出主操作栏矩形按钮
void draw_main_toolbotton(int x,int color,char*s1,char*s2)
{
	bar1(x,0,x+158,90,0xFFFFFF);
	Line_Thick(x,91,x+158,91, 1, 0x000000 );
	Line_Thick(x, 0,x,89, 1, 0xBD32 );
	Line_Thick(x+158,0,x+158,89, 1, 0xBD32 );
	Line_Thick(x+8,95,x+150,95, 2, color );

	puthz(x+41,7,s1, 32,40, 0x000000);
	puthz(x+41,9,s1, 32,40, 0x000000); 
	puthz(x+43,7,s1, 32,40, 0x000000); 
	puthz(x+43,9,s1, 32,40, 0x000000); 
	puthz(x+42,8,s1, 32,40, color); 

	puthz(x+41,48,s2, 32,40, 0x000000);
	puthz(x+41,50,s2, 32,40, 0x000000);
	puthz(x+43,48,s2, 32,40, 0x000000);
	puthz(x+43,50,s2, 32,40, 0x000000);
	puthz(x+42,49,s2, 32,40, color);
}

int rand0_7()
{
    //srand(time(NULL));
    return rand() % 11; // 生成0到7的随机数
}

//工作区所有内容清除函数
void clear_right_all(void)
{
	srand(time(NULL));
	bar1(238,99,1024,768,0xFFFFFF);

    Circle(899,790,140,0xBDBD00);
    Circle(866,755,40,0xBDBD00);
    Circlefill(866,755,40,0xFFFFAA);  

    Circlefill(1080,800,rand0_7()+200-5,0x7397FA);
    Circle(1080,800,rand0_7()+250-5,0xFEFF);
    Circle(1080,800,rand0_7()+247-5,0xBDBD);
    Circle(1080,800,rand0_7()+248-5,0xFEFF);
    Circle(1080,800,rand0_7()+258-5,0xBDBD);
    Circle(1080,800,rand0_7()+180-5,0x00FF00);
    Circlefill(1080,800,rand0_7()+170-5,0x7397F4);
    Circle(1080,800,rand0_7()+150-5,0xBDBD);

    Circle(720,875,200,0x00FF00);
    Circle(720,875,180,0xFEFF);
    Circle(720,875,180,0x7397F2);
    Circle(720,875,160,0x00FF00);
    Circle(720,875,140,0x7397FE);
    Circle(720,875,130,0x7397F4);
    Circlefill(720,875,80,0xFEFF);

    Circlefill(275,757,rand0_7(),0xFFAAAA); 
    Circlefill(332,760,rand0_7(),0xBDBD);   
    Circlefill(405,681,rand0_7(),0x00FF);   
    Circlefill(493,747,rand0_7(),0x00FF00); 
    Circlefill(549,724,rand0_7(),0xFFAA);   
    Circlefill(605,608,rand0_7(),0xFFFFBB);
    Circlefill(737,637,rand0_7(),0x00BD2E); 
    Circlefill(813,667,rand0_7(),0xFFA0F0); 
    Circlefill(926,614,rand0_7(),0x00FF00);
    Circlefill(962,525,rand0_7(),0xBDBD00); 
    Circlefill(962,525,rand0_7(),0xBD32);   
    Circlefill(880,703,rand0_7(),0xFF19);   
    Circlefill(429,705,rand0_7(),0xBBBB);

    Circlefill(833,162,rand0_7()+3,0xA7E6CF); 
    Circlefill(870,130,rand0_7()+3,0xF9C4C4);
    Circlefill(999,121,rand0_7()+3,0xC8A2C8);
    Circlefill(950,140,rand0_7()+3,0xFFF0C9);
    Circlefill(872,222,rand0_7()+2,0xFFD8B1);
    Circlefill(1008,243,rand0_7()+2,0xADD8E6); 
    Circlefill(992,294,rand0_7()+2,0xFFB6C1);
    Circlefill(1017,422,rand0_7()+1,0xFFDAB9);
    Circlefill(1024,324,rand0_7()+1,0xE0BBE4);
    Circlefill(775,137,rand0_7()+1,0x90EE90);
    prt_hz16_size(362,235,7,7,"洛邑猫咖",0x7397FE,"HZK\\HZK16s");
    prt_hz16_size(362,435,3,4,"纵　享　欢　乐　时　光",0x7397FE,"HZK\\HZK16K");
}