#include"allfunc.h"

void rigister_login(int *func)
{
    struct USER temp={0};
    char judge[10]="\0";

    mouse_off(&mouse);
    bar1(470,300,1024,445,0xFFFFFF);
    bar1(470,400,1024,700,0xFFFFFF);
    bar1(470,706,1024,750,0xFFFFFF);
    bar1(470,142,1000,190,0xFFA500);
    bar1(470,274,1024,306,0xffffff);
    bar1(470,678,1024,741,0xffffff);
    puthz(567,140,"ע��",48,50,0x000000);
    puthz(670,140,"����ϵͳ",48,50,0x00FF);
    draw_commoninput(480,280,"���趨�����ߵ��û���");
    draw_commoninput(495,340,"���趨��������");
    draw_commoninput(495,400,"��ȷ����������");
    draw_botton(540,510,870,581,0xFFC0CB,0xADD8E6);//���ص�¼���ο�
    draw_confirmbotton(573,512,"���ص�½");
    draw_botton(540,610,870,681,0xFFC0CB,0xDDDD);//����ע����ο�
    draw_confirmbotton(573,612,"����ע��");
    prt_hz16_size(485,695, 2, 2, "���Ķ���ͬ��", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(670,695, 2, 2, "������ϵͳ��˽���ߡ�", 0x00FF, "HZK\\HZK16s");
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(498,287,870,326)==1)
        {
            mouse_off(&mouse);
            bar1(470,282,1100,332,0xffffff);
            strcpy(temp.name,"\0");
            Getinfo(498,300,temp.name,10,498,287,870,326);
            mouse_on(mouse);

        }
        else if(mouse_press(498,347,870,386)==1)    //��������
        {
	    mouse_off(&mouse);
	    bar1(498,342,900,392,0xffff);
	    strcpy(temp.code,"\0");
	    Getcode(498,370,temp.code,10,498,347,870,386);
	    mouse_on(mouse);
        }
        else if(mouse_press(498,407,870,446)==1)     //������������
        {
	    mouse_off(&mouse);
	    bar1(500,402,1100,450,0xffff);
	    strcpy(judge,"\0");
	    Getcode(498,419,judge,10,498,407,870,446);
	    mouse_on(mouse);
        }
        if(mouse_press(545,610,835,670)==1)     //���ȷ�ϼ�
        {
            if(strcmp(temp.name,"\0")!=0)
            {
                if(strcmp(temp.code,"\0")!=0)
                {
                    if(strcmp(temp.code,judge)==0)
                    {
                        if(save_user(temp)==0)
                        {
                            prt_hz24(570,575,"ע��ɹ���",0,"HZK\\Hzk24h");
                            delay(1500);
                            bar1(570,575,800,600,0xffff);
                            *func=2;
                            break;
                        }
                        else
                        {
                            prt_hz24(570,575,"ע��ʧ�ܣ��û����ѱ�ע��",10,"HZK\\Hzk24h");
                            delay(1500);
                            bar1(570,575,800,600,0xffff);
                        }
                    }
                    else
                    {
                        prt_hz24(570,575,"�������벻��ͬ��",0,"HZK\\Hzk24h");
                        delay(1500);
                        bar1(570,575,800,600,0xffff);
                    }
                }
                else
                {
                    prt_hz24(570,575,"����Ϊ�գ�",0,"HZK\\Hzk24h");
                    delay(1500);
                    bar1(570,575,800,600,0xffff);
                }
            }
            else
            {
            prt_hz24(570,575,"�û���Ϊ�գ�",0,"HZK\\Hzk24h");
            delay(1500);
            bar1(570,575,800,600,0xffff);
            }
        }
        if(mouse_press(545,510,835,570)==1)     //������ؼ�
        {
            *func=0;
            break;
        }
    }
}


//������ͨ������
void draw_commoninput(int x1,int y1,char *s)
{
    Line_Thick(x1,y1,x1+380,y1,1,0xBD32);
    puthz(x1+14,y1+4,s,48,55,0x000000);
}

//����ȷ�ϰ�ť
void draw_confirmbotton(int x1,int y1,char *s)
{
    //draw_button(x1,y1,x1+236,y1+55,0xFFFFFF,0x00FF);
    puthz(x1+12,y1+4,s,48,55,0x000000);
}

void user_login(int *func,int *unum)
{
    char name[10]="\0";
    char code[10]="\0";
    int i=-5;
    UserList UL={0};
    InitUList(&UL);
    ReadAllUser(&UL);

    mouse_off(&mouse);
    bar1(470,300,1024,445,0xFFFFFF);
    bar1(470,400,1024,700,0xFFFFFF);
    bar1(470,706,1024,750,0xFFFFFF);
    bar1(470,142,1000,190,0xFFA500);
    bar1(470,274,1024,306,0xffffff);
    bar1(470,678,1024,741,0xffffff);
    puthz(600,140,"����ϵͳ",48,50,0x00FF);
    puthz(470,300,"�����ϼ�",32,34,0xBD32);
    Line_Thick(615,290,615,345,1,0xFFA500);
    puthz(625,300,"�˻���",32,34,0x000000);
    draw_commoninput(495,400,"����������ߵ��˺�");
    draw_commoninput(495,472,"����������ߵ�����");
    puthz(480,535,"ע��",24,24,0x0000ff);
    prt_hz16_size(485,695, 2, 2, "���Ķ���ͬ��", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(670,695, 2, 2, "������ϵͳ��˽���ߡ�", 0x00FF, "HZK\\HZK16s");
    draw_botton(573,612,809,667,0xFFDAB9,0xFFDAB9);
    puthz(640,615,"��¼",48,50,0x006400);

    puthz(497,140,"��¼",48,50,0x006400);

    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(495,400,870,445)==1)//����˺ſ� 
        {
    	    mouse_off(&mouse);
	         strcpy(name,"\0");
	        bar1(495,405,1100,455,0xffff);
	        Getinfo(497,422,name,10,495,400,870,445);//�õ��˺� 
	        mouse_on(mouse);
        }
        else if(mouse_press(495,475,870,520)==1)//�������� 
        {
	        mouse_off(&mouse);
	        strcpy(code,"\0");
	        bar1(495,475,900,525,0xffff);
	        Getcode(497,497,code,10,495,475,870,520);//�õ����� 
	        mouse_on(mouse);
        }
        else if(mouse_press(573,612,809,667)==1)//�����¼
        {
             i=Check_info(UL,name,code);
            if(i>=0)
	        {
	    	    *unum=i;
		        DestroyUList(&UL);
    		    *func=5;      //����������
                break;
	        }
	         if(i==-2)//����������� 
	        {
	    	    prt_hz24(570,550,"�������",0,"HZK\\Hzk24h");
    	        delay(1500);
	    	    bar1(570,550,690,574,0xffff);
	        }
    	    if(i==-3)//�û������� 
	        {
    		    prt_hz24(570,550,"�û������ڣ�",0,"HZK\\Hzk24h");
	            delay(1500);
		        bar1(570,550,570+144,574,0xffff);
	        }    
        }
        else if(mouse_press(470,300,615,335)==1)
        {
            *func=0;
             break;
        }
        else if(mouse_press(480,533,526,558)==1)
        {
            *func=3;
            break;
        }
    }
}