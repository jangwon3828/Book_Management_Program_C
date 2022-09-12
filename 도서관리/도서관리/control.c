//control.c
#include "std.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define DATAMAX	100

book g_booklist[DATAMAX];

int count = 0;

void savelist() {
    FILE* fp = fopen("list.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[i].classfirst, g_booklist[i].classsecond,g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, g_booklist[i].flag1, g_booklist[i].flag);
        
    }
    fclose(fp);
}

void readlist() {
    FILE* in = fopen("list.txt", "r");
    int ccount = 0;
    fscanf(in, "\n");
    while (!feof(in)) {
        fscanf(in, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[ccount].classfirst, g_booklist[ccount].classsecond, &g_booklist[ccount].classnum1, &g_booklist[ccount].classnum2, &g_booklist[ccount].classnum3, g_booklist[ccount].classpub, g_booklist[ccount].classauth, g_booklist[ccount].classname, g_booklist[ccount].name, g_booklist[ccount].auth, g_booklist[ccount].pub, &g_booklist[ccount].flag1, &g_booklist[ccount].flag);
        ccount++;
    }
    
    count = ccount;
    fclose(in);
    return;
}

int random() {
    srand(time(NULL));
    int i = rand() % 100000;

    return i;
}

void Swap(book* arr, int a, int b)
{
    book temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void Sort(book* arr, int m, int n)
{
        
        if (m < n) // ��������
        {
            int key = m;
            int i = m + 1;
            int j = n;
            while (i <= j)
            {
                while (i <= n && arr[i].classnum1 <= arr[key].classnum1)
                    i++;
                while (j > m && arr[j].classnum1 >= arr[key].classnum1)
                    j--;
                if (i > j)
                    Swap(arr, j, key);
                else
                    Swap(arr, i, j);
            }
            Sort(arr, m, j - 1);
            Sort(arr, j + 1, n);
        }
}

void con_printall()
{
    system("cls");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��                                  ���� ���                                  ��\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
   
    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //���Ⱑ�ɿ���
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "��  ��");
        }
        else {
            strcpy_s(gar, sizeof(gar), "�Ұ���");
        }
        if (g_booklist[i].flag == 1) {
            printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3,g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("��                                                                             ��\n");
    }
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("[1] ��з���ȣ �������� ���� \n");
    printf("[2] �޴� \n");
    char sel = _getch();
    if (sel == '1') {
        Sort(g_booklist, 0, count - 1);
        con_printall();
    }
    else {
        return;
    }
}

void con_printall1()
{
    system("cls");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //���Ⱑ�ɿ���
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "��  ��");
        }
        else {
            strcpy_s(gar, sizeof(gar), "�Ұ���");
        }
        if (g_booklist[i].flag == 1) {
            printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("��                                                                             ��\n");
    }
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}

void con_insert()
{

    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    char ch = menuprint2();
    switch (ch)
    {
    case '0':	con_insert0(ch); 		break;
    case '1':	con_insert1(ch); 		break;
    case '2':	con_insert2(ch);		break;
    case '3':	con_insert3(ch);		break;
    case '4':	con_insert4(ch);		break;
    case '5':	con_insert5(ch);		break;
    case '6':	con_insert6(ch);		break;
    case '7':	con_insert7(ch); 		break;
    case '8':	con_insert8(ch); 		break;
    case '9':	con_insert9(ch); 		break;
    case 'x':		break;
    }
}


char menuprint2() {
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��            �ѷ�(000~099): 0��           ��\n");
    printf("\t\t\t\t��            ö��(100~199): 1��           ��\n");
    printf("\t\t\t\t��            ����(200~299): 2��           ��\n");
    printf("\t\t\t\t��            ��ȸ����(300~399): 3��       ��\n");
    printf("\t\t\t\t��            �ڿ�����(400~499): 4��       ��\n");
    printf("\t\t\t\t��            �������(500~599): 5��       ��\n");
    printf("\t\t\t\t��            ����(600~699): 6��           ��\n");
    printf("\t\t\t\t��            ���(700~799): 7��           ��\n");
    printf("\t\t\t\t��            ����(800~899): 8��           ��\n");
    printf("\t\t\t\t��            ����(900~999): 9��           ��\n");
    printf("\t\t\t\t��            ���ư���: xŰ                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    char ch = _getch();
    return ch;
}

void con_insert0(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t������, ������(000) \t\t  ��\n");
    printf("\t\t\t\t��\t����������(010) \t\t  ��\n");
    printf("\t\t\t\t��\t�������(020) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������,������,��������(030)       ��\n");
    printf("\t\t\t\t��\t�Ϲݿ��Ӱ��๰(040) \t\t  ��\n");
    printf("\t\t\t\t��\t��ȸ,��ü,��ȸ,���,�������(050) �� \n");
    printf("\t\t\t\t��\t�Ź�,���θ���(060)\t \t  ��\n");
    printf("\t\t\t\t��\t�Ϲ� ����, �Ѽ�(070)\t\t  ��\n");
    printf("\t\t\t\t��\t�����ڷ�(080)  \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(090)\t\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 0;
    getchar();
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "�ѷ�");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�������");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�Ϲݿ���");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�д�����");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�Ź�����");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�����Ѽ�");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�����ڷ�");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert1(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\tö��(100)\t\t\t  ��\n");
    printf("\t\t\t\t��\t���̻���(110)\t\t\t  ��\n");
    printf("\t\t\t\t��\t�νķ�(120)\t\t\t  ��\n");
    printf("\t\t\t\t��\t�ʽɸ���,�ź�����(130)\t\t  ��\n");
    printf("\t\t\t\t��\tö����(140)\t\t\t  ��\n");
    printf("\t\t\t\t��\t�ɸ���(150)\t\t\t  �� \n");
    printf("\t\t\t\t��\t����(160\t\t\t  ��\n");
    printf("\t\t\t\t��\t������(170)\t\t\t  ��\n");
    printf("\t\t\t\t��\t��� ö��,�߼� ö��, ����ö��(180)��\n");
    printf("\t\t\t\t��\t���� ����ö��(190) \t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 1;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "ö��");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ö��");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���̻���");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�νķ�");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�ɸ��ź�");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ö����");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�ɸ���");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���ߵ�ö");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����ö��");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert2(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t����(200) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������ ö�� �� �̷�(210)\t  ��\n");
    printf("\t\t\t\t��\t����(220) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����������(230)\t\t\t  ��\n");
    printf("\t\t\t\t��\t�׸������� ����(240) \t\t  ��\n");
    printf("\t\t\t\t��\t������ȸ(250)\t\t\t  �� \n");
    printf("\t\t\t\t��\t�׸������� ��ȸ����(260)\t  ��\n");
    printf("\t\t\t\t��\t�׸������� ��ȸ��(270)\t\t  ��\n");
    printf("\t\t\t\t��\t�׸������� ����(280)  \t\t  ��\n");
    printf("\t\t\t\t��\t��Ÿ ����(290) \t\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 2;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "����");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ö����");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׸�����");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������ȸ");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׸����");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׸���ȸ");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׸�����");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��Ÿ����");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert3(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t��ȸ����(300)\t\t\t  ��\n");
    printf("\t\t\t\t��\t���(310) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��ġ��(320) \t\t\t  ��\n");
    printf("\t\t\t\t��\t�����(330) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(340) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������,������(350) \t\t  �� \n");
    printf("\t\t\t\t��\t��ȸ����,��ȸ����(360)\t\t  ��\n");
    printf("\t\t\t\t��\t������(370) \t\t\t  ��\n");
    printf("\t\t\t\t��\t���,���,����(380) \t\t  ��\n");
    printf("\t\t\t\t��\tǳ��,�μ���(390)\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 3;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "���");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ȸ����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ġ��");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�����");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ȸ����");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���뱳��");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ǳ�ӹμ�");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert4(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t�ڿ�����(400) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(410) \t\t\t  ��\n");
    printf("\t\t\t\t��\tõ����(420) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(430) \t\t\t  ��\n");
    printf("\t\t\t\t��\tȭ��(440)  \t\t\t  �� \n");
    printf("\t\t\t\t��\t��������(450)\t\t\t  �� \n");
    printf("\t\t\t\t��\t�������(460) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(470) \t\t\t  ��\n");
    printf("\t\t\t\t��\t�Ĺ���(480) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(490) \t\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 4;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "�ڰ�");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�ڿ�����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "õ����");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ȭ��");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�������");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�Ĺ���");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert5(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t�������(500) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(510) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(520) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(530) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(540)  \t\t\t  �� \n");
    printf("\t\t\t\t��\t�濵��(550)\t\t\t  �� \n");
    printf("\t\t\t\t��\tȭ�а���(560) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(570) \t\t\t  ��\n");
    printf("\t\t\t\t��\tƯ��������(580) \t\t  ��\n");
    printf("\t\t\t\t��\t�������(590) \t\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 5;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "���");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�ڿ�����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "õ����");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ȭ��");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�������");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�Ĺ���");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert6(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t����(600) \t\t\t  ��\n");
    printf("\t\t\t\t��\t���ÿ���,���濹��(610) \t\t  ��\n");
    printf("\t\t\t\t��\t�����(620) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������(630) \t\t\t  ��\n");
    printf("\t\t\t\t��\t�׷��Ⱦ�Ʈ,��Ŀ���(640)  \t  �� \n");
    printf("\t\t\t\t��\tȸȭ(650)\t\t\t  �� \n");
    printf("\t\t\t\t��\t��ȭ(660) \t\t\t  ��\n");
    printf("\t\t\t\t��\t������,��ȭ����(670)\t\t  ��\n");
    printf("\t\t\t\t��\t����(680) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��������,����,������(690)\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 6;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "����");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�������");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�濵��");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ȭ�а���");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "Ư������");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�������");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert7(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t���(700) \t\t\t  ��\n");
    printf("\t\t\t\t��\t�����(710) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����(720) \t\t\t  ��\n");
    printf("\t\t\t\t��\t���Ͼ�(730) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��������(740)  \t\t\t  �� \n");
    printf("\t\t\t\t��\t��Ż���ƾ�(750)\t\t\t  �� \n");
    printf("\t\t\t\t��\t�����ξ�(760) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��ƾ��,���¸���(770)\t\t  ��\n");
    printf("\t\t\t\t��\t�׸�����(780) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��Ÿ���(790) \t\t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 7;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "����");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�����");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׷����");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ȸȭ");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ȭ");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "������ȭ");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}

void con_insert8(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t����(800) \t\t\t  ��\n");
    printf("\t\t\t\t��\t�̱�����(810) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��������(820) \t\t\t  ��\n");
    printf("\t\t\t\t��\t���Ϲ���(830) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����������(840)  \t\t  �� \n");
    printf("\t\t\t\t��\t��Ż���ƹ���(850)\t\t  �� \n");
    printf("\t\t\t\t��\t�����ι���(860) \t\t  ��\n");
    printf("\t\t\t\t��\t��ƾ �� ���¸�����(870)\t\t  ��\n");
    printf("\t\t\t\t��\t�׸�������(880) \t\t  ��\n");
    printf("\t\t\t\t��\t��Ÿ��� ����(890) \t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 8;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "����");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�̱�����");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���Ϲ���");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��Ż����");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�����ι�");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��ƾ����");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�׸�����");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��Ÿ���");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }
}

void con_insert9(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �߰�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��\t����(900) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����,����(910) \t\t\t  ��\n");
    printf("\t\t\t\t��\t����,�躸��(920) \t\t  ��\n");
    printf("\t\t\t\t��\t��뼼�� ����(930) \t\t  ��\n");
    printf("\t\t\t\t��\t��������(940)  \t\t\t  �� \n");
    printf("\t\t\t\t��\t�ƽþƿ���(950)\t\t\t  �� \n");
    printf("\t\t\t\t��\t������ī����(960) \t\t  ��\n");
    printf("\t\t\t\t��\t�Ϲ̿���(970) \t\t\t  ��\n");
    printf("\t\t\t\t��\t���̿���(980) \t\t\t  ��\n");
    printf("\t\t\t\t��\t��Ÿ���� ����(990) \t\t  ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 9;
    printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t����(���� �� ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t���� : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t���ǻ� : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "����");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "����躸");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��뿪��");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�ƽÿ���");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��������");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�Ϲ̿���");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "���̿���");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "��Ÿ����");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t����Ǿ����ϴ�.\n");

    }
    else
    {
        printf("\t\t\t\t������ ������ϴ�..\n");

    }

}


int searchsn(int serialnum) //�Ϸù�ȣ �˻�
{
    for (int i = 0; i <= count; i++) {
        if (g_booklist[i].classnum3 == serialnum) {
            return i;
        }
    }
    return -1;
}

void con_select()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �˻�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                                         ��\n");
    printf("\t\t\t\t��             [1] ���� �˻�               ��\n");
    printf("\t\t\t\t��             [2] ���� �˻�               ��\n");
    printf("\t\t\t\t��             [3] ���ǻ� �˻�             ��\n");
    printf("\t\t\t\t��             [4] �з��� �˻�             ��\n");
    printf("\t\t\t\t��             [5] �Ϸù�ȣ �˻�           ��\n");
    printf("\t\t\t\t��                                         ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� �˻�                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t���� �Է�) ");
        gets_s(name, sizeof(name));

        int i = nametoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��                                  �˻� ���                                  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            char gar[10]; //���Ⱑ�ɿ���
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "��  ��");
            }
            else {
                strcpy_s(gar, sizeof(gar), "�Ұ���");
            }
            if (g_booklist[i].flag == 1) {
                printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� �˻�                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t���� �Է�) ");
        gets_s(name, sizeof(name));

        int i = authtoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��                                  �˻� ���                                  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            char gar[10]; //���Ⱑ�ɿ���
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "��  ��");
            }
            else {
                strcpy_s(gar, sizeof(gar), "�Ұ���");
            }
            if (g_booklist[i].flag == 1) {
                printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if (temp == '3') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� �˻�                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t���ǻ� �Է�) ");
        gets_s(name, sizeof(name));

        int i = pubtoidx(name);
        
        if (i != -1) {
            system("cls");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��                                  �˻� ���                                  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            char gar[10]; //���Ⱑ�ɿ���
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "��  ��");
            }
            else {
                strcpy_s(gar, sizeof(gar), "�Ұ���");
            }
            if (g_booklist[i].flag == 1) {
                printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if (temp == '4') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� �˻�                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��            �ѷ�(000~099): 0��           ��\n");
        printf("\t\t\t\t��            ö��(100~199): 1��           ��\n");
        printf("\t\t\t\t��            ����(200~299): 2��           ��\n");
        printf("\t\t\t\t��            ��ȸ����(300~399): 3��       ��\n");
        printf("\t\t\t\t��            �ڿ�����(400~499): 4��       ��\n");
        printf("\t\t\t\t��            �������(500~599): 5��       ��\n");
        printf("\t\t\t\t��            ����(600~699): 6��           ��\n");
        printf("\t\t\t\t��            ���(700~799): 7��           ��\n");
        printf("\t\t\t\t��            ����(800~899): 8��           ��\n");
        printf("\t\t\t\t��            ����(900~999): 9��           ��\n");
        printf("\t\t\t\t��            ���ư���: xŰ                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        char ch = _getch();

        if (ch == 'x') {
            printf("\t\t\t\t�߸��� ���Դϴ�.\n");
        }
        else {
            system("cls");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��                                  �˻� ���                                  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            int classnum = (int)ch - 48;
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            for (int i = 0; i <= count; i++)
            {
                char gar[10]; //���Ⱑ�ɿ���
                if (g_booklist[i].flag1 == 1) {
                    strcpy_s(gar, sizeof(gar), "��  ��");
                }
                else {
                    strcpy_s(gar, sizeof(gar), "�Ұ���");
                }
                if (g_booklist[i].flag == 1 && g_booklist[i].classnum1 == classnum) {
                    printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                    printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                    printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
                }
                printf("��                                                                             ��\n");
            }
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("\n");
        }
    }
    else if (temp == '5') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� �˻�                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t�Ϸù�ȣ �Է�) ");
        scanf_s("%d", &sn);
        int i = searchsn(sn);
        if (i == -1) {
            printf("\t\t\t\t�߸��� ���Դϴ�.\n");
        }
        else {
            system("cls");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��                                  �˻� ���                                  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("��   �з���ȣ\t����\t\t  ����  \t  ���ǻ�  \t�뿩���ɿ���  ��\n");
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            char gar[10]; //���Ⱑ�ɿ���
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "��  ��");
            }
            else {
                strcpy_s(gar, sizeof(gar), "�Ұ���");
            }
            if (g_booklist[i].flag == 1) {
                printf("�� %-2s.%-8s                                                               ��\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("��  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s ��\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("�� %-2s.%-2s.%-8s                                                              ��\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("\n");
        }
    }
}
void con_update()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �뿩                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��         [1] ���� �˻� �� �뿩           ��\n");
    printf("\t\t\t\t��         [2] �Ϸù�ȣ �˻� �� �뿩       ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t���� �Է� : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 1) {
                g_booklist[idx].flag1 = 0;

                printf("\t\t\t\t�뿩�Ǿ����ϴ�.\n");
            }
            else
                printf("\t\t\t\t�̹� �뿩�Ǿ��ֽ��ϴ�.\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if (temp == '2') {
        int sn;
        printf("\t\t\t\t�Ϸù�ȣ �Է�) ");
        scanf_s("%d", &sn);
        int temp = searchsn(sn);
        if (temp == -1) {
            printf("\t\t\t\t�����ϴ�\n");
        }
        else {
            if (g_booklist[temp].flag1 == 1) {
                g_booklist[temp].flag1 = 0;

                printf("\t\t\t\t�뿩�Ǿ����ϴ�.\n");
            }
            else {
                printf("\t\t\t\t�̹� �뿩�Ǿ��ֽ��ϴ�.\n");
            }
        }
    }
    else {
        return;
    }
}
void con_update1()
{
    system("cls"); 
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� �ݳ�                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��         [1] ���� �˻� �� �ݳ�           ��\n");
    printf("\t\t\t\t��         [2] �Ϸù�ȣ �˻� �� �ݳ�       ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t���� �Է� : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t�ݳ��Ǿ����ϴ�.\n");
            }
            else
                printf("\t\t\t\t�̹� �ݳ��Ǿ��ֽ��ϴ�.\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if(temp == '2') {
        int sn;
        printf("\t\t\t\t�Ϸù�ȣ �Է�) ");
        scanf_s("%d", &sn);

        int idx = searchsn(sn);
        if (idx != -1) {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t�ݳ��Ǿ����ϴ�.\n");
            }
            else
                printf("\t\t\t\t�̹� �ݳ��Ǿ��ֽ��ϴ�.\n");
        }
        else {
            printf("\t\t\t\t�����ϴ�.\n");
        }
    }
}
void con_update2()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� ����                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��         [1] ���� �˻� �� ����           ��\n");
    printf("\t\t\t\t��         [2] �Ϸù�ȣ �˻� �� ����       ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� ����                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t���� �Է� : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            char auth[20];
            char pub[20];
            char name[20];
            int cn1;
            int cn2;

            printf("\t\t\t\t������ ��з� ��ȣ �Է�(0~9) : ");
            scanf_s("%d", &cn1);
            if (cn1 < 0 && cn1 > 9) {
                printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
                return;
            }
            if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "�ѷ�");
            else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "ö��");
            else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
            else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
            else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "�ڰ�");
            else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
            else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
            else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
            else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
            else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");


            printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
            scanf_s("%d", &cn2);
            if (cn2 < 0 && cn2 > 99) {
                printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
                return;
            }
            if (cn1 == 0)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ϲݿ���");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�д�����");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ź�����");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����Ѽ�");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ڷ�");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
            }
            if (cn1 == 1)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ö��");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���̻���");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�νķ�");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ɸ��ź�");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ö����");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ɸ���");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���ߵ�ö");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����ö��");
            }
            if (cn1 == 2)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ö����");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������ȸ");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸����");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸���ȸ");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ����");
            }
            if (cn1 == 3)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȸ����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ġ��");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȸ����");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���뱳��");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ǳ�ӹμ�");
            }
            if (cn1 == 4)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ڿ�����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "õ����");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȭ��");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ĺ���");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
            }
            if (cn1 == 5)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�濵��");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȭ�а���");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Ư������");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
            }
            if (cn1 == 6)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׷����");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȸȭ");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȭ");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������ȭ");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
            }
            if (cn1 == 7)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���Ͼ�");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���¸���");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ξ�");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ƾ����");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ���");
            }
            if (cn1 == 8)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�̱�����");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���Ϲ���");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ż����");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ι�");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ƾ����");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ���");
            }
            if (cn1 == 9)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����躸");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��뿪��");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ƽÿ���");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ϲ̿���");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���̿���");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ����");
            }

            getchar();
            printf("\t\t\t\t������ ���� �Է� : ");
            gets_s(name, sizeof(name));
            printf("\t\t\t\t������ �۰� �Է� : ");
            gets_s(auth, sizeof(auth));
            printf("\t\t\t\t������ ���ǻ� �Է� : ");
            gets_s(pub, sizeof(pub));
            g_booklist[idx].classnum1 = cn1;
            g_booklist[idx].classnum2 = cn2;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

            strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
            g_booklist[idx].classpub[3] = '\0';
            strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
            g_booklist[idx].classauth[3] = '\0';
            strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
            g_booklist[idx].classname[8] = '\0';


            printf("\t\t\t\t�����Ǿ����ϴ�.\n");
        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� ����                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t�Ϸù�ȣ �Է�) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx == -1) {
            printf("\t\t\t\t�߸��� ���Դϴ�.\n");
        }
        else {
            if (sn != -1)
            {
                char auth[20];
                char pub[20];
                char name[20];
                int cn1;
                int cn2;

                printf("\t\t\t\t������ ��з� ��ȣ �Է�(0~9) : ");
                scanf_s("%d", &cn1);
                if (cn1 < 0 && cn1 > 9) {
                    printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
                    return;
                }
                if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "�ѷ�");
                else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "ö��");
                else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
                else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
                else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "�ڰ�");
                else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
                else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
                else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "���");
                else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");
                else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "����");


                printf("\t\t\t\t������ �Һз� ��ȣ �Է�(00~99) : ");
                scanf_s("%d", &cn2);
                if (cn2 < 0 && cn2 > 99) {
                    printf("\t\t\t\t�߸� �ԷµǾ����ϴ�.\n");
                    return;
                }
                if (cn1 == 0)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ϲݿ���");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�д�����");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ź�����");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����Ѽ�");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ڷ�");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                }
                if (cn1 == 1)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ö��");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���̻���");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�νķ�");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ɸ��ź�");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ö����");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ɸ���");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���ߵ�ö");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����ö��");
                }
                if (cn1 == 2)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ö����");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������ȸ");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸����");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸���ȸ");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ����");
                }
                if (cn1 == 3)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȸ����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ġ��");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȸ����");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���뱳��");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ǳ�ӹμ�");
                }
                if (cn1 == 4)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ڿ�����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "õ����");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȭ��");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ĺ���");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                }
                if (cn1 == 5)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�濵��");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȭ�а���");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Ư������");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�������");
                }
                if (cn1 == 6)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׷����");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ȸȭ");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ȭ");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "������ȭ");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                }
                if (cn1 == 7)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���Ͼ�");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���¸���");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ξ�");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ƾ����");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ���");
                }
                if (cn1 == 8)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�̱�����");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���Ϲ���");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ż����");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�����ι�");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��ƾ����");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�׸�����");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ���");
                }
                if (cn1 == 9)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "����躸");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��뿪��");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�ƽÿ���");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��������");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�Ϲ̿���");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "���̿���");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "��Ÿ����");
                }

                getchar();
                printf("\t\t\t\t������ ���� �Է� : ");
                gets_s(name, sizeof(name));
                printf("\t\t\t\t������ �۰� �Է� : ");
                gets_s(auth, sizeof(auth));
                printf("\t\t\t\t������ ���ǻ� �Է� : ");
                gets_s(pub, sizeof(pub));
                g_booklist[idx].classnum1 = cn1;
                g_booklist[idx].classnum2 = cn2;
                strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
                strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
                strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

                strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
                g_booklist[idx].classpub[3] = '\0';
                strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
                g_booklist[idx].classauth[3] = '\0';
                strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
                g_booklist[idx].classname[8] = '\0';


                printf("\t\t\t\t�����Ǿ����ϴ�.\n");
            }
            else
            {
                printf("\t\t\t\t�����ϴ�\n");
            }
        }
    }
}

void con_delete()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                ���� ����                ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��         [1] ���� �˻� �� ����           ��\n");
    printf("\t\t\t\t��         [2] �Ϸù�ȣ �˻� �� ����       ��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� ����                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        char name[20];
        printf("\t\t\t\t���� �Է� : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].classnum3 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");
            strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "");


            printf("\t\t\t\t�����Ǿ����ϴ�.\n\n");

        }
        else
        {
            printf("\t\t\t\t�����ϴ�\n\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��                ���� ����                ��\n");
        printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
        int sn;
        printf("\t\t\t\t�Ϸù�ȣ �Է�) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");


            printf("\t\t\t\t�����Ǿ����ϴ�.\n\n");

        }
        else
        {
            printf("\t\t\t\t�߸��� ���Դϴ�.\n\n");
        }
    }
}

int nametoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].name, name) == 0)
            return i;
    }
    return -1;
}

int authtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].auth, name) == 0)
            return i;
    }
    return -1;
}
int pubtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].pub, name) == 0)
            return i;
    }
    return -1;
}