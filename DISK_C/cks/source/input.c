#include "allfunc.h"
#include "input.h"

/************************************************************************
FUNCTION:input_method
DESCRIPTION: 汉字输入法调入
INPUT:x,y,str,value,py
RETURN:1:输出汉字；2：输出字母；3：输出空格
************************************************************************/
void hzinput(int x, int y){
	int value= 0, asc,len=0;
	char str[64] = {0}; // 用于临时存放刚输入的东西
	char py[64] = {0};	// 存放拼音字符串或英文字符串
	while (bioskey(1)) // 清除键盘缓冲区  防止误输入
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
				bar1(x+len*16, y , x + (len+1)*16, y + height,0xFFFFFF);//还要改
				len-=1;
				continue;
			}
			asc = value & 0xff;
			if (asc >= 97 && asc <= 122)//打字母
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
	char *ABpath = "pinyin\\"; // 汉语拼音检索标准路径
	char pypath[45];		   // 汉语拼音检索相对路径
	// settextjustify(LEFT_TEXT, CENTER_TEXT);
	strcpy(pypath, "pinyin\\");
	while (1)
	{
		if (help||kbhit()) // 第一次进入自动触发 以后均需键盘
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
				if (fposition >= 8) // 接下来重定位文件指针前八个字节（四个汉字）
				{
					fposition -= 8;
				}
				break;
			case NEXTLINE:
				if (!feof(fp)) // 接下来重定位文件指针后八个字节（四个汉字）
				{
					fposition += 8;
				}
				break;
			case LEFT: // 左移动一个
				if (hznow)
				{
					hznow--;
				}
				else if (fposition >= 8) // 需要左换页
				{
					fposition -= 8;
					hznow = 3;
				}
				break;
			case RIGHT:
				if (hznow < hznum - 1) // 同左
				{
					hznow++;
				}
				else if (!feof(fp))
				{
					fposition += 8;
					hznow = 0;
				}
				break;
				/*按数字键选中输入汉字*/
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
			if (asc > 31 && asc < 127 && strlen(py) < MAXPY && asc != '[' && asc != ']') // 有效输入时则复位
			{
				py[p]= asc;
				p++;
				fposition = 0;
				hznow = 0;
			}
			put_asc16_size(PyStartx, PyStarty, 2, 2, py, BLUE);
			strcat(pypath, py);
			strcat(pypath, ".txt");
			if (fJudge) // 将当前文件指针保存 同时关闭上一个文件  为输入特殊字符准备
			{
				if (oldfp)
				{
					fclose(oldfp);
				}
				oldfp = fp;
			}
			if ((fp = fopen(pypath, "r")) == NULL) // 特殊字符存在  保留上一个文件检索结果
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
					fread(temphz[i], 2, 1, fp); // 读入一个汉字
					if (feof(fp))				// 读到文件尾
					{
						hznum = i; // 按道理此处文件尾多读一次 需要减一  然而此处不减一的效果更好
						break;
					}
				}
				if (!feof(fp)) // 未读到文件尾 全显汉字
				{
					hznum = 4;
				}
				for (i = 0; i < hznum; i++)
				{
					put_asc16_size(HzStartx + i * 50, HzStarty + 5, 2, 2, itostr(i + 1, temp), DARKGRAY);
					puthz(HzStartx+i*50+16,HzStarty,temphz[i],16,16,DARKGRAY);
				}
				puthz(HzStartx + hznow * 50 + 16, HzStarty, temphz[hznow], 16, 16, 0xFFFAFA); // 显示选中汉字
			}
		}
		strcpy(pypath, ABpath); // 绝对路径复原（不可少）
		value = 0;
		delay(40);
	}
}

/************************************************************************
FUNCTION:itostr
DESCRIPTION: 数字标号
INPUT:a,s
RETURN:数字s
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
DESCRIPTION: 输入法小框
INPUT:x1,y1,x2,y2
RETURN:无
************************************************************************/

void pyFrm(int x1, int y1, int x2, int y2)
{
	bar1(x1, y1, x2, y2,0xFFFFFF);
	Line2(x1 + 5, y1 + 40, x2 - 5, y1 + 40, BLUE);
	bar2(x1, y1, x2, y2, DARKGRAY);
}

