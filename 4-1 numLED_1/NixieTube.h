#ifndef NIXIETUBE_H
#define NIXIETUBE_H

#include <REGX52.H>


// 定义一个结构体来存储输出值
typedef struct {
    unsigned char P2_4;
    unsigned char P2_3;
    unsigned char P2_2;
    unsigned char P0;
} NixieOutputs;

// 函数原型声明
NixieOutputs nixieTube(unsigned char location, number);

#endif 
// NIXIETUBE_H