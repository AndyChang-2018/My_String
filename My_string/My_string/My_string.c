#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"My_string.h"



//˼·�� 1 ��ѭ���ж�λ���ַ��Ƿ�Ϊ'\0'�� �������1 ���񣬼����жϡ�����ֵ��
int My_strlen(const char *a)
{
	int num = 0; //ͳ�Ʊ�ʶ
	while (*a) //*a������0��ִ��ѭ��
	{
		num++;  // ��ʶ++
		a++;    //�ַ���λ�ƺ���Ϊ
	}

	return num;
}

// ˼·�� 1 �� ���ٸ���ָ�������
//       2 �� �ƶ�����ָ��λ��ָ�� һ��ָ�����ַ��������һ���ַ�λ�ã�����һ��ָ���ַ�����λ�ӡ�
//       3 �� ѭ���Ѹ��ַ����ַ� ��ֵ �����ַ�������ָ�롣
//       4 �� ���ַ����������'\0' ��
void My_strcat(char *allstr, char *addstr)
{

	int allstrlen = My_strlen(allstr);  //��ȡĿ���ַ�������
	int addstrlen = My_strlen(addstr);  // ��ȡ�ϲ��ַ�������

	char *pall = allstr;   // ���帨��ָ�룬����ԭָ��
	pall += allstrlen;     // ָ��ָ���ƶ����ַ�������棬�ȴ�����ַ���

	char *padd = addstr;   // ���帨��ָ�룬����ԭָ��

	while (*padd)
	{
		*pall++ = *padd++;  //һ��һ�������ַ�
	}
	*(padd + 1) = '\0'; //��β��ӽ�������

}
//�ص㣺ѭ����Ʒ���������һ������flag�ǹؼ�������break��������ѭ����
//˼·��1 �� ��������ָ������ӹ�ʵ�ε�ַ��
//     2 �� ���˫ѭ�������������ַ���

char *My_strstr(char *allstr, char *str)  //�����ַ�����ָ���ַ����е�һ�γ��ֵ�λ��
{
	char *p = NULL;
	char *ptemp_a = allstr;
	char *ptemp_b = str;

	//˫ѭ���������ַ���
	for (int i = 0; i < (int)(strlen(ptemp_a) - strlen(ptemp_b)); i++)
	{
		int flag = 1;                                               //��־λ��������㷨���ص㣬��Ҫ��⡣2016.11.23�Լ����˫ѭ��ʱ����û���ǵ���flag
		for (int j = 0; j < (int)strlen(ptemp_b); j++)
		{
			if (ptemp_a[i + j] != *(ptemp_b + j))                //�ж��Ƿ���ͬ
			{
				flag = 0;
				break;                                          //��λ�ò�һ���������ڲ�ѭ��
			}
		}
		if (flag == 1)                                          //���û�в�һ���ģ���flag = 1 �����ҵ��ַ���λ����
		{
			p = ptemp_a + i;
			break;                                            // ֻ��һ�Σ��ҵ����������ѭ��
		}
	}

	return p;
}


int My_strstr_mul(char *allstr, char *str, char **p_arr, int *p_count)  //�����ַ�����ָ���ַ����г��ֵ�λ��,��������
{
	char *p = NULL;
	char *ptemp_a = allstr;
	char *ptemp_b = str;

	//˫ѭ���������ַ���
	for (int i = 0; i <= (int)(strlen(ptemp_a) - strlen(ptemp_b)); i++)
	{
		int flag = 1;                                               //��־λ��������㷨���ص㣬��Ҫ��⡣2016.11.23�Լ����˫ѭ��ʱ����û���ǵ���flag
		for (int j = 0; j < (int)strlen(ptemp_b); j++)
		{
			if (ptemp_a[i + j] != *(ptemp_b + j))                //�ж��Ƿ���ͬ
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			p_arr[*p_count] = ptemp_a + i;
			*p_count += 1;
			i = i + strlen(ptemp_b) - 1;
		}
	}

	return 0;
}



int My_strcount(char *allstr, char *str)
{
	int allstr_strlen = My_strlen(allstr);
	int str_strlen = My_strlen(str);

	char *p = NULL;
	int num = 0;

	for (int i = 0; i < allstr_strlen - str_strlen; i++)
	{
		int flag = 1;
		for (int j = 0; j < str_strlen; j++)
		{
			if (*(allstr + i + j) != *(str + j))
			{
				flag = 0;
				break;
			}

		}
		if (flag == 1)
		{
			p = allstr + i;
			num++;
		}

	}


	return num;



}

//�ص㣺 C�淶��,ASCI C��ʵ��˼·������ʽֵ��ѧϰ��
//�ַ����Աȣ���ͬ���� 0 . p_fir ˳������p_sec �����ظ��� �� p_fir����p_sec������������
int My_strcmp(const char *allstr, const char *str)
{
	char *p_fir = allstr;
	char *p_sec = str;


	if (*p_fir != *p_sec || strlen(p_fir) != strlen(p_sec))
	{
		if (*p_fir < *p_sec)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}


	for (int i = 1; i < (int)strlen(p_fir); i++)
	{
		if (p_fir[i] != p_sec[i])                //�ж��Ƿ���ͬ
		{
			if (p_fir[i] < p_sec[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}                                     //��λ�ò�һ���������ڲ�ѭ��
		}

	}

	return 0;
}



/*

//�˰汾�������ڣ��ɷ��ص�һ������ͬ��ĸ���������֡�
int strcmp(p1,p2)
{
    const char *p1;
    const char *p2;
 
    register const unsignedchar *s1=(const unsignedchar*)p1;
    register const unsignedchar *s2=(const unsignedchar*)p2;
    unsigned reg_char c1,c2;           //reg_char �� ����Ҳû����ض������Ƿ�Ϊ���߱���
    do{
        c1=(unsigned char)*s1++;
        c2=(unsigned char)*s2++;
        if(c1=='\0')
            return c1-c2;
    }while(c1==c2);
    return c1-c2;
} 

//C�淶��,ASCI C��������.��ʵ�֣������"ABCDEFG"�͡�ABCDEF"�Ƚϣ���Ч�ʵ�һ�㣬��Ϊ����ȻҪѭ�������һ����һ�����ַ��ٽ�����
int(strap)(const char *sl, const char *s2)
{
//compare unsigned char sl[],s2[]
	for (; *sl == *s2; ++sl, ++s2)
	{
		if (*sl == '\0')
			return(0);
	}
	return((*(unsigned char*)sl<*(unsigned char*)s2) ? -1 : +1);
}

	
//����Լ��(Calling convention) .�������������ݣ�
//1)����������ѹջ˳��
//2)�ɵ����߻��Ǳ������߰Ѳ�������ջ��
//3)�Լ����������������ķ����� 
// __cdecl C����Ĭ�ϵĺ������÷���.  ���в������ҵ���������ջ����Щ�����ɵ��������.
int __cdecl strcmp(const char *src,const char *dst)  
{
    int ret=0;

    while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
        ++src,++dst;

    if(ret<0)
        ret=-1;
    else if(ret>0)
        ret=1;

    return(ret);
}
	
int strcmp(const char *str1,const char *str2)
{
	//������while(*str1++==*str2++)���Ƚϣ��������ʱ�Ի�ִ��һ��++��return���صıȽ�ֵʵ��������һ���ַ���Ӧ��++�ŵ�ѭ�����н��С�
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return0;

		str1++;
		str2++;
	}

	return *str1 - *str2;
}

	
	
	
*/