#include "allfunc.h"
void in_page(int *funct_strl);
void draw_in_page(void);
void in_page(int *funct_strl) {
    mouse_off(&mouse);
    draw_in_page();
    mouse_on(mouse);
    while (1) {
        mouse_show(&mouse);
        if (mouse_press(964, 0, 1024, 60) == 1) {
            mouse_off(&mouse);
            *funct_strl = 0;
            break;
        }
    }
}
void draw_in_page(void){//��ҳ
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    //���˳���
	bar1(964, 0, 1024, 60,0xFAF0E6);
	Line_Thick(974, 15, 1014, 45,3,0x6A5ACD);
	Line_Thick(974, 45, 1014, 15,3,0x6A5ACD);
    puthz(25, 25, "���", 32, 33, 0x000000);
    bar2(160,110,880,660,0x000000);
    Line2(520,110,520,660,0x000000);
    Line2(340,110,340,660,0x000000);
    Line2(700,110,700,660,0x000000);
    puthz(170,120,"��Ʒ����",16,16,0x000000);
    puthz(350,120,"�������",16,16,0x000000);
    puthz(530,120,"���ų̶�",16,16,0x000000);
    puthz(710,120,"�������",16,16,0x000000);
    bar1(0,705,205,768,0xFFFFE0);
    puthz(35,730,"����ⶩ��",16,16,0x000000);
    bar1(840,705,1024,768,0xBC8F8F);
    puthz(885,725,"ȷ�����",16,16,0x000000);
   
}