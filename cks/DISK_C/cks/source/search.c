#include "allfunc.h"
void search_page(int *funct_strl);
void draw_search_page(void);
void lightup(int x1, int y1,int y2);
void search_page(int *funct_strl) {
    mouse_off(&mouse);
    draw_search_page();
    mouse_on(mouse);
    while (1) {
        mouse_show(&mouse);
        if(MouseIn(30,225,210,260)==1) {
            lightup(30,225,225);
            if(mouse_press(30,225,210,260)==1) {
                break;
            }
        }
        if(MouseIn(30,260,210,295)==1) {
            lightup(30,260,225);
            if(mouse_press(30,260,210,295)==1) {
                break;
            }
        }
        if(MouseIn(30,400,210,435)==1) {
            lightup(30,400,400);
            if(mouse_press(30,400,210,435)==1) {
                break;
            }
        }
        if(MouseIn(30,435,210,470)==1) {
            lightup(30,435,400);
            if(mouse_press(30,435,210,470)==1) {
                break;
            }
        }
        if(MouseIn(30,575,210,610)==1) {
            lightup(30,575,575);
            if(mouse_press(30,575,210,610)==1) {
                break;
            }
        }
        if(MouseIn(30,610,210,645)==1) {
            lightup(30,610,575);
            if(mouse_press(30,610,210,645)==1) {
                break;
            }
        }
        if(MouseIn(235,225,415,260)==1) {
            lightup(235,225,225);
            if(mouse_press(235,225,415,260)==1) {
                break;
            }
        }
        if(MouseIn(235,260,415,295)==1) {
            lightup(235,260,225);
            if(mouse_press(235,260,415,295)==1) {
                break;
            }
        }
        if(MouseIn(235,400,415,435)==1) {
            lightup(235,400,400);
            if(mouse_press(235,400,415,435)==1) {
                break;
            }
        }
        if(MouseIn(235,435,415,470)==1) {
            lightup(235,435,400);
            if(mouse_press(235,435,415,470)==1) {
                break;
            }
        }
        if(MouseIn(235,575,415,610)==1) {
            lightup(235,575,575);
            if(mouse_press(235,575,415,610)==1) {
                break;
            }
        }
        if(MouseIn(235,610,415,645)==1) {
            lightup(235,610,575);
            if(mouse_press(235,610,415,645)==1) {
                break;
            }
        } 
        if (mouse_press(964, 0, 1024, 60) == 1) {
            mouse_off(&mouse);
            *funct_strl = 0;
            break;
        }
    }  
}
void draw_search_page(void) {
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    //画退出键
	bar1(964, 0, 1024, 60,0xFAF0E6);
	Line_Thick(974, 15, 1014, 45,3,0x6A5ACD);
	Line_Thick(974, 45, 1014, 15,3,0x6A5ACD);
    //画柜子
    draw_guizi2(1, 30, 225);
    draw_guizi2(2, 235, 225);
    draw_guizi2(3, 30, 400);
    draw_guizi2(4, 235 , 400);
    draw_guizi2(5, 30, 575);
    draw_guizi2(6, 235, 575);
    puthz(25, 25, "查看", 32, 33, 0x000000);
    bar2(140, 30,360, 120, 0x000000);
    bar2(405, 30, 625, 120, 0x000000);
    bar2(670, 30, 890,120, 0x000000);
    put_asc16_size(230, 50, 2, 2, "1F", 0x000000);
    put_asc16_size(495, 50, 2, 2, "2F", 0x000000);
    put_asc16_size(760, 50, 2, 2, "3F", 0x000000);
}
void lightup(int x1, int y1,int y2) {
    bar1(x1, y1, x1+180, y1+35, 0xFFFFE0);
    delay(200);
    draw_guizi2(0, x1, y2);
    delay(200);
}