#include <REGX52.H>  // 包含51单片机的寄存器定义
#include "Delay.h"    // 包含延时函数的头文件
#include "LCD1602.h"  // 包含LCD1602显示屏的驱动函数的头文件
#include "MatrixKey.h"// 包含矩阵键盘的驱动函数的头文件

void main()
{
    unsigned char KeyNum = 0;  // 存储按键编号
    unsigned char u_KeyNum = 0; // 存储未用的按键编号

    unsigned char count = 0;  // 密码输入位数计数器
    unsigned char u_count = 0; // 用户输入密码位数计数器
    unsigned char show_flag = 0; // 显示标志位
    unsigned int flag = 0; // 标志位

    unsigned char step = 0; // 状态步骤变量

    unsigned int passwd = 0; // 存储设置的密码
    unsigned int passwd_1 = 0; // 密码的第一位
    unsigned int passwd_2 = 0; // 密码的第二位
    unsigned int passwd_3 = 0; // 密码的第三位
    unsigned int passwd_4 = 0; // 密码的第四位

    unsigned int u_passwd = 0; // 用户输入的密码
    unsigned int u_passwd_1 = 0; // 用户输入密码的第一位
    unsigned int u_passwd_2 = 0; // 用户输入密码的第二位
    unsigned int u_passwd_3 = 0; // 用户输入密码的第三位
    unsigned int u_passwd_4 = 0; // 用户输入密码的第四位

    LCD_Init(); // 初始化LCD显示屏

    while(1) // 主循环
    {
        if(passwd == 0) // 如果密码尚未设置
        {
            LCD_ShowString(1, 1, "Set Password:"); // 显示设置密码提示
            LCD_ShowString(2, 5, "_ _ _ _"); // 显示密码占位符
        }

        switch(step) // 根据步骤变量进行不同的操作
        {
            case 0: // 设置密码步骤
                KeyNum = MatrixKey(); // 获取按键编号
                if(KeyNum) // 如果有按键按下
                {
                    if(KeyNum <= 11 && count < 4) // 如果按键编号在0-11之间且密码位数小于4
                    {
                        switch(count) // 根据密码位数计数器的值，存储密码的每一位
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
                    LCD_ShowNum(2, 5,  passwd_1, 1); // 显示密码的每一位
                    LCD_ShowNum(2, 7,  passwd_2, 1);
                    LCD_ShowNum(2, 9,  passwd_3, 1);
                    LCD_ShowNum(2, 11, passwd_4, 1);
                }
                if(KeyNum == 11 && count == 4) // 如果按下的是'*'键且密码位数为4
                {
                    LCD_Init(); // 重新初始化LCD
                    Delay(20); // 延时
                    LCD_ShowString(1, 1, " Successful Set "); // 显示设置成功信息
                    LCD_ShowNum(2, 1, passwd, 4); // 显示设置的密码
                    step=1; // 进入下一步
                }
                break;

            case 1: // 用户输入密码步骤
                if(u_passwd == 0 && u_count == 0) // 如果用户密码和计数器都为0
                {
                    LCD_ShowString(1, 1, "Entry Password:"); // 显示输入密码提示
                    LCD_ShowString(2, 5, "_ _ _ _"); // 显示密码占位符
                    u_count++; // 用户密码计数器加1
                }
                KeyNum = MatrixKey(); // 获取按键编号
                if(KeyNum) // 如果有按键按下
                {
                    if(KeyNum <= 11 && u_count < 5) // 如果按键编号在0-11之间且密码位数小于5
                    {
                        switch(u_count) // 根据密码位数计数器的值，存储用户输入密码的每一位
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
                    LCD_ShowNum(2, 5,  u_passwd_1, 1); // 显示用户输入密码的每一位
                    LCD_ShowNum(2, 7,  u_passwd_2, 1);
                    LCD_ShowNum(2, 9,  u_passwd_3, 1);
                    LCD_ShowNum(2, 11, u_passwd_4, 1);
                }
                if(KeyNum == 11 && u_count == 5) // 如果按下的是'*'键且密码位数为5
                {
                    step=2; // 进入下一步
                }
                break;

            case 2: // 密码验证步骤
                if(passwd == u_passwd && show_flag == 0) // 如果密码正确且显示标志位为0
                {
                    LCD_ShowString(1, 1, "  Right Passwd  "); // 显示密码正确的信息
                    LCD_ShowString(2, 1, "  Door  Open   "); // 显示门已开的信息
                    show_flag++; // 显示标志位加1
                }
                KeyNum = MatrixKey(); // 获取按键编号
                if(KeyNum) // 如果有按键按下
                {
                    if(KeyNum == 12) // 如果按下的是'#'键
                    {
                        u_passwd = 0; // 清空用户密码
                        u_passwd_1 = 0;
                        u_passwd_2 = 0;
                        u_passwd_3 = 0;
                        u_passwd_4 = 0;

                        KeyNum = 0; // 清空按键编号
                        u_KeyNum = 0;

                        count = 0; // 清空密码位数计数器
                        u_count = 0; // 清空用户密码位数计数器
                        show_flag = 0; // 清空显示标志位

                        Delay(100); // 延时
                        LCD_Init(); // 重新初始化LCD
                        step = 1; // 返回到输入密码步骤
                    }
                }
                else if(passwd != u_passwd && show_flag == 0) // 如果密码不正确且显示标志位为0
                {
                    LCD_Init(); // 重新初始化LCD
                    Delay(20); // 延时
                    LCD_ShowString(1, 1, "  Wrong Passwd  "); // 显示密码错误的信息
                    LCD_ShowString(2, 1, "     Result     "); // 显示结果信息

                    show_flag++; // 显示标志位加1
                    step = 1; // 返回到输入密码步骤

                    u_passwd = 0; // 清空用户密码
                    u_passwd_1 = 0;
                    u_passwd_2 = 0;
                    u_passwd_3 = 0;
                    u_passwd_4 = 0;

                    KeyNum = 0; // 清空按键编号
                    u_KeyNum = 0;

                    count = 0; // 清空密码位数计数器
                    u_count = 0; // 清空用户密码位数计数器
                    show_flag = 0; // 清空显示标志位

                    Delay(1000); // 延时
                    LCD_Init(); // 重新初始化LCD
                }
                break;
        }
    }
}