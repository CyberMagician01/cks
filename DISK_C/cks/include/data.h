#ifndef __DATA_H__
#define __DATA_H__
#include "allfunc.h"



typedef struct{
	int x,y,f,dx,dy;
	void *buffer;
}OBSTACLE;

typedef enum {
    STOP,//��Ϣ
    MOVE,//�޻��ƶ�
    LOAD,//���װ����
    UNLOAD,//׼��ж����

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
} store;//�����Ʒ���ݽṹ

typedef struct orderdata {
    char name[20];
    char number[20];
    int quantity;
} order;//��ⶩ�����ݽṹ

typedef struct outdata {
    char name[20];
    char number[20];
    int quantity;
} out;//���ⶩ�����ݽṹ

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
    
}ROBOT;//���������ݽṹ

#endif