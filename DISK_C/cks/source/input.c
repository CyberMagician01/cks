#include "allfunc.h"
#include "input.h"

/************************************************************************
FUNCTION:input_method
DESCRIPTION: �������뷨����
INPUT:x,y,str,value,py
RETURN:1:������֣�2�������ĸ��3������ո�
************************************************************************/
void hzinput(int x, int y){
	int value= 0, asc,len=0;
	char str[64] = {0}; // ������ʱ��Ÿ�����Ķ���
	char py[64] = {0};	// ���ƴ���ַ�����Ӣ���ַ���
	while (bioskey(1)) // ������̻�����  ��ֹ������
	{
		bioskey(0);
	}
	while (1)
	{
		if (kbhit())
		{
			value = bioskey(0);
			if (value == ENTER)
			{
				break;
			}
			else if (value == BACK && len > 0)
			{
				bar1(x+len*16, y , x + (len+1)*16, y + height,0xFFFFFF);//��Ҫ��
				len-=1;
				continue;
			}
			asc = value & 0xff;
			if (asc >= 97 && asc <= 122)//����ĸ
			{
				pyFrm(x, y + height, x + width, y + height +60);
				input_method(x, y + height, str, value, py);
				len++;
				memset(py, '\0', 64);
				memset(str, '\0', 64);
			}
		}
		delay(40);
	}
}
int input_method(int x, int y, char *str, int value, char *py)
{
	FILE *fp = NULL, *oldfp = NULL;
	int fJudge = FAIL;
	int help=1;
	// char *p = py;
	int p = 0;
	char temphz[5][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}}, temp[3];
	int fposition = 0;
	int hznow = 0, hznum = 0;
	int asc, i;
	int PyStartx = x + 8, PyStarty = y + 4;
	int HzStartx = x + 8, HzStarty = y + 22;
	char *ABpath = "pinyin\\"; // ����ƴ��������׼·��
	char pypath[45];		   // ����ƴ���������·��
	// settextjustify(LEFT_TEXT, CENTER_TEXT);
	strcpy(pypath, "pinyin\\");
	while (1)
	{
		if (help||kbhit()) // ��һ�ν����Զ����� �Ժ�������
		{
			help=0;
			value = bioskey(0);
			asc = value & 0xff;
			switch (value)
			{
			case BACK:
				if (p > 0)
				{
				bar1(PyStartx+p*16, PyStarty, PyStartx + (p+1)*16, PyStarty + 16,0xFFFFFF);
				p--;
				py[p]= '\0';
				
				}
				if (py[0] == '\0')
				{
					str[0] = '\0';
					if (oldfp)
						fclose(oldfp);
					if (fp)
						fclose(fp);
					return 3;
				}
				break;
			case SPACE:
				strcpy(str, temphz[hznow]);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 1;
			case ENTER:
				strcpy(str, py);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 2;
			case LASTLINE:
				if (fposition >= 8) // �������ض�λ�ļ�ָ��ǰ�˸��ֽڣ��ĸ����֣�
				{
					fposition -= 8;
				}
				break;
			case NEXTLINE:
				if (!feof(fp)) // �������ض�λ�ļ�ָ���˸��ֽڣ��ĸ����֣�
				{
					fposition += 8;
				}
				break;
			case LEFT: // ���ƶ�һ��
				if (hznow)
				{
					hznow--;
				}
				else if (fposition >= 8) // ��Ҫ��ҳ
				{
					fposition -= 8;
					hznow = 3;
				}
				break;
			case RIGHT:
				if (hznow < hznum - 1) // ͬ��
				{
					hznow++;
				}
				else if (!feof(fp))
				{
					fposition += 8;
					hznow = 0;
				}
				break;
				/*�����ּ�ѡ�����뺺��*/
			case FIRST:
				strcpy(str, temphz[0]);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 1;
			case SECOND:
				strcpy(str, temphz[1]);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 1;
			case THIRD:
				strcpy(str, temphz[2]);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 1;
			case FOURTH:
				strcpy(str, temphz[3]);
				if (oldfp)
					fclose(oldfp);
				if (fp)
					fclose(fp);
				return 1;
			}
			if (asc > 31 && asc < 127 && strlen(py) < MAXPY && asc != '[' && asc != ']') // ��Ч����ʱ��λ
			{
				py[p]= asc;
				p++;
				fposition = 0;
				hznow = 0;
			}
			put_asc16_size(PyStartx, PyStarty, 2, 2, py, BLUE);
			strcat(pypath, py);
			strcat(pypath, ".txt");
			if (fJudge) // ����ǰ�ļ�ָ�뱣�� ͬʱ�ر���һ���ļ�  Ϊ���������ַ�׼��
			{
				if (oldfp)
				{
					fclose(oldfp);
				}
				oldfp = fp;
			}
			if ((fp = fopen(pypath, "r")) == NULL) // �����ַ�����  ������һ���ļ��������
			{
				fJudge = FAIL;
				fp = oldfp;
			}
			else
			{
				fJudge = SUCCESS;
			}
			if (fp)
			{
				fseek(fp, fposition, SEEK_SET);
				for (i = 0; i < 5; i++)
				{
					fread(temphz[i], 2, 1, fp); // ����һ������
					if (feof(fp))				// �����ļ�β
					{
						hznum = i; // ������˴��ļ�β���һ�� ��Ҫ��һ  Ȼ���˴�����һ��Ч������
						break;
					}
				}
				if (!feof(fp)) // δ�����ļ�β ȫ�Ժ���
				{
					hznum = 4;
				}
				for (i = 0; i < hznum; i++)
				{
					put_asc16_size(HzStartx + i * 50, HzStarty + 5, 2, 2, itostr(i + 1, temp), DARKGRAY);
					puthz(HzStartx+i*50+16,HzStarty,temphz[i],16,16,DARKGRAY);
				}
				puthz(HzStartx + hznow * 50 + 16, HzStarty, temphz[hznow], 16, 16, 0xFFFAFA); // ��ʾѡ�к���
			}
		}
		strcpy(pypath, ABpath); // ����·����ԭ�������٣�
		value = 0;
		delay(40);
	}
}

/************************************************************************
FUNCTION:itostr
DESCRIPTION: ���ֱ��
INPUT:a,s
RETURN:����s
************************************************************************/

char *itostr(int a, char *s)
{
	switch (a)
	{
	case 1:
		strcpy(s, "1.");
		return s;
	case 2:
		strcpy(s, "2.");
		return s;
	case 3:
		strcpy(s, "3.");
		return s;
	case 4:
		strcpy(s, "4.");
		return s;
	}
	return s;
}

/************************************************************************
FUNCTION:pyFrm
DESCRIPTION: ���뷨С��
INPUT:x1,y1,x2,y2
RETURN:��
************************************************************************/

void pyFrm(int x1, int y1, int x2, int y2)
{
	bar1(x1, y1, x2, y2,0xFFFFFF);
	Line2(x1 + 5, y1 + 40, x2 - 5, y1 + 40, BLUE);
	bar2(x1, y1, x2, y2, DARKGRAY);
}

