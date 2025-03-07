#include "allfunc.h"

void draw_information(int *funct_strl,USER *user)
{
    mouse_off(&mouse);
    bar1(0,0,1024,768,0xFFFFFF);
    clear_right_all();
    Readbmp64k(0,0,"bmp\\logo.bmp");
    draw_botton(300,300,830,380,0x36454F,0xC0C0C0);
    puthz(300,320,"这是一个查看猫猫的程序",48,50,0x00FF);
    draw_botton(800,500,1000,620,0x36454F,0xC0C0C0);
    puthz(820,520,"返回",48,50,0x00FF);
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(830,500,1000,620)==1)
        {
            *funct_strl=0;
            break;
        }
        if(mouse_press(500,300,720,380)==1)
        {
            if(user->cat==1)
            {
                Readbmp64k(0,0,"bmp\\cat0.bmp");
                puthz(0,100,"你的猫猫是布偶猫",48,50,0x00FF);

            }
            else if(user->cat==2)
            {
                Readbmp64k(0,0,"bmp\\cat1.bmp");
                puthz(0,100,"你的猫猫是金渐层",48,50,0x00FF);

            }
            else if(user->cat==3)
            {
                Readbmp64k(0,0,"bmp\\cat2.bmp");
                puthz(0,100,"你的猫猫是银渐层",48,50,0x00FF);

            }
            else if(user->cat==4)
            {
                Readbmp64k(0,0,"bmp\\cat3.bmp");
                puthz(0,100,"你的猫猫是英国短毛猫",48,50,0x00FF);

            }
            else
            {
                puthz(0,100,"你还没有猫猫哦",48,50,0x00FF);
            }
            delay(3000);
            *funct_strl=5;
            break;
        }
    }
}