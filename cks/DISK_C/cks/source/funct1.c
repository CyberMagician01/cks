#include "allfunc.h"

void draw_cat(int *funct_strl,USER *user)
{
    mouse_off(&mouse);
    draw_cat_back();
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(300,160,450,275)==1)//��żè
        {
            user->cat=1;
            *funct_strl=1;
            break;
        }
        else if(mouse_press(630,285,890,366)==1)//�𽥲�
        {
            user->cat=2;
            *funct_strl=1;
            break;
        }
        else if(mouse_press(41,415,381,465)==1)//������
        {
            user->cat=3;
            *funct_strl=1;
            break;
        }
        else if(mouse_press(700,437,988,503)==1)//��ëè
        {
            user->cat=4;
            *funct_strl=1;
            break;
        }
        else if(mouse_press(408,437,621,537)==1)//������һҳ
        {
            *funct_strl=0;
            break;
        }
    }
}

void draw_cat_back(void)
{
    bar1(0,0,1024,768,0x5F9EA0);
    Readbmp64k(0,0,"bmp\\cat0.bmp");
    Readbmp64k(592,0,"bmp\\cat1.bmp");
    Readbmp64k(0,384,"bmp\\cat2.bmp");
    Readbmp64k(680,470,"bmp\\cat3.bmp");

    draw_botton(300,160,450,275,0xFFDAB9,0xFFD700);
    puthz(166,37,"��żè",48,50,0x00FF);
    puthz(330,195,"ѡ��",48,50,0x00FF);

    draw_botton(630,285,890,366,0xFFDAB9,0xFFD700);
    puthz(720,30,"�𽥲�",48,50,0x00FF);
    puthz(678,300,"ѡ��",48,50,0x00FF);
    
    draw_botton(41,415,381,465,0xFFDAB9,0xFFD700);
    puthz(36,696,"������",48,50,0x00FF);
    puthz(43,420,"ѡ��",48,50,0x00FF);

    draw_botton(700,437,988,503,0xFFDAB9,0xFFD700);
    puthz(500,600,"Ӣ����ëè",48,50,0x00FF);
    puthz(750,446,"ѡ��",48,50,0x00FF);

    draw_botton(408,437,621,537,0xFFFFF0,0xfffff0);
    puthz(400,467,"�ص���һҳ",48,50,0x000000);
}