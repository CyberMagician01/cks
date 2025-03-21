#ifndef __CRE_ROB_H__
#define __CRE_ROB_H__
#include "allfunc.h"

void draw_robot(int x,int y,int state,int direction);
void cre_rob(ROBOT *robot,int floor);
void remote_robot(int x,int y,int state,int direction,int *floor,int *funct_strl);

#endif