#ifndef NIXIETUBE_H
#define NIXIETUBE_H

#include <REGX52.H>


// ����һ���ṹ�����洢���ֵ
typedef struct {
    unsigned char P2_4;
    unsigned char P2_3;
    unsigned char P2_2;
    unsigned char P0;
} NixieOutputs;

// ����ԭ������
NixieOutputs nixieTube(unsigned char location, number);

#endif 
// NIXIETUBE_H