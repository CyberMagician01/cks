#ifndef __LOGIN_H__
#define __LOGIN_H__
#include "allfunc.h"

void rigister_login(int *func);
void draw_commoninput(int x1, int y1, char *s);
void draw_confirmbotton(int x1, int y1, char *s);
void user_login(int *func,int *unum);

#endif