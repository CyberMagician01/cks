#ifndef __DATA_H__
#define __DATA_H__
#include "allfunc.h"



typedef struct{
	int x,y,f,dx,dy;
	void *buffer;
}OBSTACLE;

typedef enum {
    STOP,//休息
    MOVE,//无货移动
    LOAD,//多次装货中
    UNLOAD,//准备卸货中

}state;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
}direction;

typedef struct LOCATION
{
    int x;
    int y;
    struct LOCATION *next;
}locate;

typedef struct storedata {
    char name[20];
    char number[20];
    int quantity;
    float placex;
    float placey;
    float placez;
} store;//存放商品数据结构

typedef struct orderdata {
    char name[20];
    char number[20];
    int quantity;
} order;//入库订单数据结构

typedef struct outdata {
    char name[20];
    char number[20];
    int quantity;
} out;//出库订单数据结构

typedef struct robot
{
    int floor;
    store goods[3];
    int goods_num;
    int direction;
    int state;
    int x;
    int y;
    int dx;
    int dy;
    void *buffer;
    locate *head;
    
}ROBOT;//机器人数据结构

#endif