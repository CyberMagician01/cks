#include "allfunc.h"
void out_page(int *funct_strl,char *s);
void draw_out_page(void);
void out_page(int *funct_strl,char *s){
    int len=10;
    mouse_off(&mouse);
    draw_out_page();
    mouse_on(mouse);
    while (1) {
        mouse_show(&mouse);
        if (mouse_press(964, 0, 1024, 60) == 1) {//退出键
            mouse_off(&mouse);
            *funct_strl = 0;
            break;
        }
        if (mouse_press(190,135,805,215) == 1) {//搜索键
            mouse_off(&mouse);
            bar1(200,170,800,210,0xFFFFFF);
            hzinput(200,170);
            mouse_on(mouse);
            break;   
        }
    }  
}
void draw_out_page(void){
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    //画退出键
	bar1(964, 0, 1024, 60,0xFAF0E6);
	Line_Thick(974, 15, 1014, 45,3,0x6A5ACD);
	Line_Thick(974, 45, 1014, 15,3,0x6A5ACD);
    puthz(25, 25, "出库", 32, 33, 0x000000);
    bar2(115,135,805,215,0x000000);//输入框
    Line2(190,135,190,215,0x000000);
    Line2(155,175,180,200,0x000000);
    Circle(155,175,20,0x000000);
    puthz(200,170,"请输入要出库的物品",16,16,LIGHTGRAY);  
    bar2(830,135,950,215,0x000000);
    puthz(860,165,"搜索",16,16,0x000000);
    Line_Thick(0,225,1024,225,3,0x000000);
    bar2(0,705,205,768,0x000000);
    puthz(35,730,"待出库订单",16,16,0x000000);
    bar2(840,705,1024,768,0x000000);
    puthz(885,725,"确认出库",16,16,0x000000);
    
}