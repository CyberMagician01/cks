#include"allfunc.h"

void welcome(int *func)
{
	int floor=0;
	mouse_off(&mouse);

	draw_basic_logging();//����¼��ע�����ر�����Ԫ��
	draw_welcome();//����ӭ���������Ԫ��

	
	
	mouse_on(mouse);

	while(1)
	{
		mouse_show(&mouse);

		if(mouse_press(535,395,855,485)==1)
		{
			*func=2;
			break;
		}
		if(mouse_press(535,540,855,630)==1)
		{
			*func=3;
			break;
		}
	}
}


//����¼��ע�����ر�����Ԫ��
void draw_basic_logging()
{
	bar1(0, 0, 1024, 768, 0x87CEFA);
	//�ϲ�ȦȦ
	Circlefill(580, 60, 40, 0x00FF00);
	Circlefill(755, 40, 45, 0xFFAAAA);
	Circlefill(380, 240, 60, 0xBDBD00);
	Circlefill(675, 105, 35, 0x00BD2E);
	//draw_workbox();
	Readbmp64k(0, 0, "bmp\\logoo.bmp");

	puthz(500, 230, "��Ʒ�Ǽ�", 32, 27, 0x000000);
	puthz(630, 230, "�Զ����", 32, 27, 0x000000);
	puthz(760, 230, "��������", 32, 27, 0x000000);
	puthz(890, 230, "��װ����", 32, 27, 0x000000);
	
}

void draw_botton(int x1,int y1,int x2,int y2,int Cowercolor,int Bordercolor)
{
	Cirbar(x1, y1, x2, y2, Bordercolor);
	Cirbar(x1,y1+2,x2,y2-2,Cowercolor);
}
//����ӭ���������Ԫ��


void draw_welcome()
{
    //����
	puthz(660,50,"��ӭ����", 48,50, 0x800080);
	puthz(490,140,"���人������ִ��������ġ�", 32,40, 0x00FF);

	//ѡ���
    draw_botton(535,393,855,487,0xFFC0CB,0xADD8E6);//��¼���ο�
    draw_botton(535,538,855,632,0xFFC0CB,0xDDDD);//ע����ο�

	//д��
	prt_hz16_size(650,420, 3, 3, "��¼", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(650,565, 3, 3, "ע��", 0xFFFFFF, "HZK\\HZK16s");
    
}

