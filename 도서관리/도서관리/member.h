#pragma once

typedef struct tagbook book;
struct tagbook
{
    int flag; //���� ���� ���� 0 (X), 1(0)
    int flag1; //���� �� ���� 0 (X), 1(0)
    char name[20]; //����
    char auth[20]; //����
    char pub[20]; //���ǻ�
    char classfirst[10]; //�з�ù��°
    char classsecond[10]; //�з��ι�°
    int classnum1; //�з�ù��°
    int classnum2; //�з��ι�°
    int classnum3; //���¼�

    char classpub[4]; //�з� ���ǻ�
    char classauth[4]; //�з�����
    char classname[10]; //�з� ����
};