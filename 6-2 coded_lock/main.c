#include <REGX52.H>  // ����51��Ƭ���ļĴ�������
#include "Delay.h"    // ������ʱ������ͷ�ļ�
#include "LCD1602.h"  // ����LCD1602��ʾ��������������ͷ�ļ�
#include "MatrixKey.h"// ����������̵�����������ͷ�ļ�

void main()
{
    unsigned char KeyNum = 0;  // �洢�������
    unsigned char u_KeyNum = 0; // �洢δ�õİ������

    unsigned char count = 0;  // ��������λ��������
    unsigned char u_count = 0; // �û���������λ��������
    unsigned char show_flag = 0; // ��ʾ��־λ
    unsigned int flag = 0; // ��־λ

    unsigned char step = 0; // ״̬�������

    unsigned int passwd = 0; // �洢���õ�����
    unsigned int passwd_1 = 0; // ����ĵ�һλ
    unsigned int passwd_2 = 0; // ����ĵڶ�λ
    unsigned int passwd_3 = 0; // ����ĵ���λ
    unsigned int passwd_4 = 0; // ����ĵ���λ

    unsigned int u_passwd = 0; // �û����������
    unsigned int u_passwd_1 = 0; // �û���������ĵ�һλ
    unsigned int u_passwd_2 = 0; // �û���������ĵڶ�λ
    unsigned int u_passwd_3 = 0; // �û���������ĵ���λ
    unsigned int u_passwd_4 = 0; // �û���������ĵ���λ

    LCD_Init(); // ��ʼ��LCD��ʾ��

    while(1) // ��ѭ��
    {
        if(passwd == 0) // ���������δ����
        {
            LCD_ShowString(1, 1, "Set Password:"); // ��ʾ����������ʾ
            LCD_ShowString(2, 5, "_ _ _ _"); // ��ʾ����ռλ��
        }

        switch(step) // ���ݲ���������в�ͬ�Ĳ���
        {
            case 0: // �������벽��
                KeyNum = MatrixKey(); // ��ȡ�������
                if(KeyNum) // ����а�������
                {
                    if(KeyNum <= 11 && count < 4) // ������������0-11֮��������λ��С��4
                    {
                        switch(count) // ��������λ����������ֵ���洢�����ÿһλ
                        {
                            case 0: passwd_1 = KeyNum; passwd *= 10;
                                    passwd += KeyNum % 10; count++; 
                                    break;
                            case 1: passwd_2 = KeyNum; passwd *= 10;
                                    passwd += KeyNum % 10; count++; break;
                            case 2: passwd_3 = KeyNum; passwd *= 10;
                                    passwd += KeyNum % 10; count++; break;
                            case 3: passwd_4 = KeyNum; passwd *= 10;
                                    passwd += KeyNum % 10; count++; break;
                        }
                    }
                    LCD_ShowNum(2, 5,  passwd_1, 1); // ��ʾ�����ÿһλ
                    LCD_ShowNum(2, 7,  passwd_2, 1);
                    LCD_ShowNum(2, 9,  passwd_3, 1);
                    LCD_ShowNum(2, 11, passwd_4, 1);
                }
                if(KeyNum == 11 && count == 4) // ������µ���'*'��������λ��Ϊ4
                {
                    LCD_Init(); // ���³�ʼ��LCD
                    Delay(20); // ��ʱ
                    LCD_ShowString(1, 1, " Successful Set "); // ��ʾ���óɹ���Ϣ
                    LCD_ShowNum(2, 1, passwd, 4); // ��ʾ���õ�����
                    step=1; // ������һ��
                }
                break;

            case 1: // �û��������벽��
                if(u_passwd == 0 && u_count == 0) // ����û�����ͼ�������Ϊ0
                {
                    LCD_ShowString(1, 1, "Entry Password:"); // ��ʾ����������ʾ
                    LCD_ShowString(2, 5, "_ _ _ _"); // ��ʾ����ռλ��
                    u_count++; // �û������������1
                }
                KeyNum = MatrixKey(); // ��ȡ�������
                if(KeyNum) // ����а�������
                {
                    if(KeyNum <= 11 && u_count < 5) // ������������0-11֮��������λ��С��5
                    {
                        switch(u_count) // ��������λ����������ֵ���洢�û����������ÿһλ
                        {
                            case 1: u_passwd_1 = KeyNum; u_passwd *= 10;
                                    u_passwd += KeyNum % 10; u_count++; 
                                    break;
                            case 2: u_passwd_2 = KeyNum; u_passwd *= 10;
                                    u_passwd += KeyNum % 10; u_count++; break;
                            case 3: u_passwd_3 = KeyNum; u_passwd *= 10;
                                    u_passwd += KeyNum % 10; u_count++; break;
                            case 4: u_passwd_4 = KeyNum; u_passwd *= 10;
                                    u_passwd += KeyNum % 10; u_count++; break;
                        }
                    }
                    LCD_ShowNum(2, 5,  u_passwd_1, 1); // ��ʾ�û����������ÿһλ
                    LCD_ShowNum(2, 7,  u_passwd_2, 1);
                    LCD_ShowNum(2, 9,  u_passwd_3, 1);
                    LCD_ShowNum(2, 11, u_passwd_4, 1);
                }
                if(KeyNum == 11 && u_count == 5) // ������µ���'*'��������λ��Ϊ5
                {
                    step=2; // ������һ��
                }
                break;

            case 2: // ������֤����
                if(passwd == u_passwd && show_flag == 0) // ���������ȷ����ʾ��־λΪ0
                {
                    LCD_ShowString(1, 1, "  Right Passwd  "); // ��ʾ������ȷ����Ϣ
                    LCD_ShowString(2, 1, "  Door  Open   "); // ��ʾ���ѿ�����Ϣ
                    show_flag++; // ��ʾ��־λ��1
                }
                KeyNum = MatrixKey(); // ��ȡ�������
                if(KeyNum) // ����а�������
                {
                    if(KeyNum == 12) // ������µ���'#'��
                    {
                        u_passwd = 0; // ����û�����
                        u_passwd_1 = 0;
                        u_passwd_2 = 0;
                        u_passwd_3 = 0;
                        u_passwd_4 = 0;

                        KeyNum = 0; // ��հ������
                        u_KeyNum = 0;

                        count = 0; // �������λ��������
                        u_count = 0; // ����û�����λ��������
                        show_flag = 0; // �����ʾ��־λ

                        Delay(100); // ��ʱ
                        LCD_Init(); // ���³�ʼ��LCD
                        step = 1; // ���ص��������벽��
                    }
                }
                else if(passwd != u_passwd && show_flag == 0) // ������벻��ȷ����ʾ��־λΪ0
                {
                    LCD_Init(); // ���³�ʼ��LCD
                    Delay(20); // ��ʱ
                    LCD_ShowString(1, 1, "  Wrong Passwd  "); // ��ʾ����������Ϣ
                    LCD_ShowString(2, 1, "     Result     "); // ��ʾ�����Ϣ

                    show_flag++; // ��ʾ��־λ��1
                    step = 1; // ���ص��������벽��

                    u_passwd = 0; // ����û�����
                    u_passwd_1 = 0;
                    u_passwd_2 = 0;
                    u_passwd_3 = 0;
                    u_passwd_4 = 0;

                    KeyNum = 0; // ��հ������
                    u_KeyNum = 0;

                    count = 0; // �������λ��������
                    u_count = 0; // ����û�����λ��������
                    show_flag = 0; // �����ʾ��־λ

                    Delay(1000); // ��ʱ
                    LCD_Init(); // ���³�ʼ��LCD
                }
                break;
        }
    }
}