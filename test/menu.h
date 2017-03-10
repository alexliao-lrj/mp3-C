/*Ԥ����*/
#ifndef __MENU_H_
#define __MENU_H_

/*��Ŀ���õ���ͷ�ļ�*/
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "windows.h"
#pragma comment(lib,"WinMM.Lib")
#include "mmsystem.h"
#include "time.h"

/*��غ궨��*/
#define N 100
#define M 50
#define O 20
static char filepath[N];
static int count = 0;
static struct media{
	char path[N];
	char name[M];
	char author[O];
	struct media *next;
};
static struct media *head = NULL;
static struct media *p1, *p2, *pcurrent = head;
typedef struct media Song; 

/*
Author:���
Date:2015.7.18
Description:���湹����غ���
*/
void main_Menu();
void play_Menu(struct media* pcurrent, struct media* head);
void list_Menu(struct media* pcurrent);
void mode_Menu(struct media* pcurrent);
char main_Click();
char play_Click();
char list_Click();
char mode_Click();

/*
Author:����
Date:2015.7.18
Description:LOGģ����غ���
*/
void input_msg(struct media *pcurrent);										//��¼�û�������Ϣ
void output_msg(struct media *pcurrent);									//����û�������Ϣ
void input_error(char *error);												//��¼������Ϣ
/*void hotkey();*/

/*
Author:�Ʒ�Բ
Date:2015.7.18
Description:��������غ���
*/
void mention(char *error);													//������ʾ
void output_error(char *error);												//���������Ϣ

/*
Author:������
Date:2015.7.18
Description:�ļ��������ݴ�����غ���
*/
int deletes(char* path);													//���û�������ɾ������
int add(char *path);														//���û���������Ӹ���
Song* create();																//��������(�����б�)
int mark(Song *p);															//��¼��ǰ���Ÿ�����ַ
void display_allinfo(struct media* pcurrent);								//�����б�����ʾ���и�������Ϣ


/*
Author:������
Date:2015.7.18
Description:����������غ���
*/
long musiclen(struct media* pcurrent);										//return file length�����ļ�����
int list_len(struct media *head);											//���������ȣ������б��ȣ�
void display_info(struct media* pcurrent);									//����������ʾ���׸���Ϣ
struct media* search_music(struct media* pcurrent);							//��ѯ����
int play(struct media* pcurrent);											//�������� �ɹ���1������0
void stop(struct media* pcurrent);											//ֹͣ����
void pause(struct media* pcurrent);											//��ͣ����
char* play_open(struct media* pcurrent);
char* play_play(struct media* pcurrent);
char* play_stop(struct media* pcurrent);
char* play_close(struct media* pcurrent);
char* pause_str(struct media* pcurrent);
void play_next(struct media* pcurrent);										//������һ��
struct media* play_previous(struct media* pcurrent, struct media* head);	//������һ��
void fast_forward(struct media* pcurrent);									//���ֿ��
void fast_rewind(struct media* pcurrent);									//���ֿ���
void volume_up(struct media* pcurrent);										//��������
void volume_down(struct media* pcurrent);									//��������
char* rewind_status(struct media* pcurrent);
char* rewind_seek(struct media* pcurrent);
char* vol_set(struct media* pcurrent);
char* vol_status(struct media* pcurrent);
void show_list();															//��ʾ�б���Ϣ
struct media* check_music(struct media* pcurrent);
struct media* play_single(struct media* pcurrent);							//��������
void play_list(struct media* pcurrent);										//�б�˳��
void play_single_cyc(struct media* pcurrent);								//single music cycle����ѭ��
void play_list_cyc(struct media* pcurrent);									//list cycle play�б�ѭ��
struct media* play_random(struct media* pcurrent);							//random play���

#endif