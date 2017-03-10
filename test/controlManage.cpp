#include "menu.h"

int list_len(struct media *pcurrent){
	struct media *p3 = pcurrent;
	int num = 0;
	while (p3 != NULL){
		num++;
		p3 = p3->next;
	}
	free(p3);
	p3 = NULL;
	return num;
}

void display_allinfo(struct media* pcurrent){
	Song* p = pcurrent;
	int i = 0;
	for (i = 0; p != NULL; i ++){
		setcolor(EGERGB(255, 255, 255));
		setfont(20, 0, "华文琥珀");
		outtextxy(0,100 + i*50, p->path);
		outtextxy(400,100 + i*50, p->author);
		p  = p->next;
	}
}

void display_info(struct media* pcurrent){
	if (pcurrent == NULL){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(0, 0, "当前没有播放媒体文件");
		return;
	}
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "华文琥珀");
	outtextxy(50,100, pcurrent->path);
	outtextxy(50,130, pcurrent->author);
}

struct media* check_music(struct media* pcurrent){
	int i = 0;
	struct media *p3 = pcurrent;
	char name[M];
	inputbox_getline("Enter music name:", "Enter music name:（press Enter to comfirm）", name, 50);
	count = list_len(pcurrent);
	for (i = 0; i < count; i++){
		if (strcmp(name, p3->name) == 0){
			pcurrent = p3;
			break;
		}
		else{
			p3 = p3->next;
		}
	}
	//free(p3);
	p3 = NULL;
	if (i == count){
		pcurrent = NULL;
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "华文琥珀");
		outtextxy(0, 0, "此歌曲不存在，请添加");
		return pcurrent;
	}
	else{
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "华文琥珀");
		outtextxy(0,0, "此歌曲在列表中");
		return pcurrent;
	}
	return pcurrent;
}

struct media* search_music(struct media* pcurrent){
	int i = 0;
	struct media *p3 = pcurrent;
	char name[M];
	inputbox_getline("Enter music name:", "Enter music name:（press Enter to comfirm）", name, 50);
	count = list_len(pcurrent);
	for (i = 0; i < count; i++){
		if (strcmp(name, p3->name) == 0){
			pcurrent = p3;
			break;
		}
		else{
			p3 = p3->next;
		}
	}
	//free(p3);
	p3 = NULL;
	if (i == count){
		pcurrent = NULL;
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(0, 0, "当前没有播放媒体文件");
		return pcurrent;
	}
	else{
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "华文琥珀");
		outtextxy(0, 0, pcurrent->path);
		return pcurrent;
	}
}

int play(struct media* pcurrent){
	char* playOpen = play_open(pcurrent);
	char* playPlay = play_play(pcurrent);
	MCIERROR mciError;
	char error[50];
	stop(pcurrent);
	if (pcurrent == NULL){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(58, 70, "无音乐");
		return 0;
	}
	mciError = mciSendString(playOpen, NULL, 0, NULL);
	if (mciError){
		mciGetErrorString(mciError, error, strlen(error));
		//mention(error);	
		return 0;
	}	
	mciSendString(playPlay, NULL, 0, NULL);
	if (mciError){
		mciGetErrorString(mciError, error, strlen(error));
		//mention(error);
		return 0;
	}
	//input_msg(pcurrent);
}

char* play_open(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	struct media* pcurrent1 = pcurrent;
	strcpy(mp3, "");
	strcat(mp3, "open ");
	strcat(mp3, pcurrent1->path);
	return mp3;
}

char* play_play(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "play ");
	strcat(mp3, pcurrent->path);
	return mp3;
}

struct media* play_single(struct media* pcurrent){
	pcurrent = search_music(pcurrent);
	play(pcurrent);
	return pcurrent;
}

void play_list(struct media* pcurrent){
	pcurrent = create();
	if(pcurrent == NULL)
		pcurrent = play_single(pcurrent);
	while (pcurrent != NULL){
		play_next(pcurrent);
	}
	stop(pcurrent);
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "宋体");
	outtextxy(58, 70, "无下一首");
}

long musiclen(struct media* pcurrent){
	char mp3[N];
	char st[256] = "";
	long len = 0;
	char lenString[5];
	strcpy(mp3, "");
	strcat(mp3, "open ");
	strcat(mp3, pcurrent->path);
	strcat(mp3, " alias music");
	mciSendString(mp3, NULL, 0, NULL);
	strcpy(mp3, "status music length");
	mciSendString(mp3, st, 255, 0);
	len = strtol(st, NULL, 10);
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "宋体");
	sprintf(lenString,"%ld",len);
	outtextxy(58,90,"文件长度");
	outtextxy(58, 70, lenString);
	return len;
}

void play_list_cyc(struct media* pcurrent){
	play_single(pcurrent);
	while (1){
		if (pcurrent->next == NULL){
			pcurrent->next = head;
		}
		pcurrent = pcurrent->next;
		play(pcurrent);
	}
}

struct media* play_random(struct media* pcurrent){
	stop(pcurrent);
	int num = 0;
	struct media* pst = pcurrent;
	count = list_len(pcurrent);
	int i = 0;
	if (pcurrent->next == NULL){
		pcurrent->next = pcurrent;
	}
	srand(time(NULL));
	num = rand() % count;
	for (i = 0; i < num - 1; i++){
		pcurrent = pcurrent->next;
		if (pcurrent->next == NULL){
		pcurrent->next = pcurrent;
		}
	}
	play(pcurrent);
	return pcurrent;
}

void pause(struct media* pcurrent){
	char error[50];
	char* pauseStr = pause_str(pcurrent);
	MCIERROR mciError = mciSendString(pauseStr, NULL, 0, NULL);
	mciGetErrorString(mciError, error, strlen(error));
	if (mciError){
	//mention(error);
	}
}

char* pause_str(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "pause ");
	strcat(mp3, pcurrent->path);
	return mp3;
}

void stop(struct media* pcurrent){
	char error[50];
	char* playStop = play_stop(pcurrent);
	char* playClose = play_close(pcurrent);
	MCIERROR mciError = mciSendString(playStop, NULL, 0, NULL);
	if (mciError){
	//mention(error);
	}
	mciSendString(playClose, NULL, 0, NULL);
}

char* play_stop(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "stop ");
	strcat(mp3, pcurrent->path);
	return mp3;
}

char* play_close(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "close ");
	strcat(mp3, pcurrent->path);
	return mp3;
}

void play_next(struct media* pcurrent){
	stop(pcurrent);
	/*if (head == NULL){
		//mention(No music);
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(58, 70, "列表为空");
		return;
	}*/	
	if (pcurrent->next == NULL){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(0, 0, "没有更多了");
		//stop(pcurrent);
		//play(pcurrent);
		return;
	}
	pcurrent = pcurrent->next;
	play(pcurrent);
	mark(pcurrent);
	head = pcurrent;
}

struct media* play_previous(struct media* pcurrent, struct media* head){
	stop(pcurrent);
	struct media *p3 = head;
	/*if (pcurrent == NULL){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(58, 70, "列表为空");
		return 0;
	}*/
	if (pcurrent == NULL){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(58, 70, "请选择一首歌");
		search_music(pcurrent);
		p3 = head;
		play(pcurrent);
		if (pcurrent == NULL){
			return 0;
		}
	}
	if (pcurrent == head){
		setcolor(EGERGB(255, 255, 255));
		setfont(30, 0, "宋体");
		outtextxy(58, 70, "没有更多了");
		//play(pcurrent);
		return head;
	}
	while (p3->next != pcurrent){
		p3 = p3->next;
	}
	pcurrent = p3;
	play(pcurrent);
	mark(pcurrent);
	head = pcurrent;
	return p3;
}

void volume_up(struct media* pcurrent){
	int vol = 0;
	char v[64];
	char *volStatus = vol_status(pcurrent);
	char *volSet = vol_set(pcurrent);
	mciSendString(volStatus,v,64,0);
	vol = atoi(v);
	vol += 50;
	char st[10];
	sprintf(st, "%d", vol);
	strcat(volSet, st);
	mciSendString(volSet, 0, 0, 0);
}

void volume_down(struct media* pcurrent){
	int vol = 0;
	char v[64];
	char *volStatus = vol_status(pcurrent);
	char *volSet = vol_set(pcurrent);
	mciSendString(volStatus, v, 64, 0);
	vol = atoi(v);
	vol -= 50;
	char st[10];
	sprintf(st, "%d", vol);
	strcat(volSet, st);
	mciSendString(volSet, 0, 0, 0);
}

char* vol_set(struct media* pcurrent){
	char* mp3;
	mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "setaudio ");
	strcat(mp3, pcurrent->path);
	strcat(mp3, " volume to ");
	return mp3;
}

void fast_rewind(struct media* pcurrent){
	int position = 0;
	int min = 0;
	int sec = 0;
	char st[64];
	char pos[40];
	char* reStatus = rewind_status(pcurrent);
	char* reSeek = rewind_seek(pcurrent);
	char* playPlay = play_play(pcurrent);	
	mciSendString(reStatus, st, 64, 0);
	position = atoi(st);
	position -= 4000;
	min = (int)((position / 1000)) / 60;
	sec = (position / 1000) - 60 * min;
	itoa(position, st, 10);	
	sprintf(pos, "%s", st);
	strcat(reSeek, pos);
	mciSendString(reSeek, NULL, 0, NULL);
	mciSendString(playPlay, NULL, 0, NULL);	
}

char* rewind_status(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "status ");
	strcat(mp3, pcurrent->path);
	strcat(mp3," position");
	return mp3;
}

char* rewind_seek(struct media* pcurrent){
	char* mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "seek ");
	strcat(mp3, pcurrent->path);
	strcat(mp3, " to ");
	return mp3;
}

void fast_forward(struct media* pcurrent){
	int position = 0;
	int min = 0;
	int sec = 0;
	char st[64];
	char pos[40];
	char* reStatus = rewind_status(pcurrent);
	char* reSeek = rewind_seek(pcurrent);
	char* playPlay = play_play(pcurrent);
	mciSendString(reStatus, st, 64, 0);
	position = atoi(st);
	position += 4000;
	min = (int)((position / 1000)) / 60;
	sec = (position / 1000) - 60 * min;
	itoa(position, st, 10);
	sprintf(pos, "%s", st);
	strcat(reSeek, pos);
	mciSendString(reSeek, NULL, 0, NULL);
	mciSendString(playPlay, NULL, 0, NULL);
}

char* vol_status(struct media* pcurrent){
	char* mp3;
	mp3 = (char*)malloc(sizeof(char)*N);
	strcpy(mp3, "");
	strcat(mp3, "status ");
	strcat(mp3, pcurrent->path);
	strcat(mp3, " volume");
	return mp3;
}

struct media* add_music(struct media* pcurrent){
	char* path = (char*)malloc(sizeof(char)*N);
	inputbox_getline("请输入要添加的歌曲的路径", "回车确认", path, N);
	mark(pcurrent);
	int i = add(path);	
	if(i==2){
		char* error = "找不到音乐文件！\n";
		//mention(error);
	}else if(i==0){
		char* error = "文件打开失败！\n";
		//mention(error);
	}
	head = create();
	return head;
}


int add(char *path){							
	FILE *fpUser_Music;												//user_Music文件指针
	FILE *fpAll_Music;												//all_Music文件指针
	char *seps = "_";
	char *token = (char*)malloc(sizeof(char)*N);
	if((fpAll_Music = fopen("all_Music.txt", "r")) == NULL){		//如果mark为空，以user_Music自然顺序建立链表
		return 0;													//错误处理:all_Music文件打开失败
	}else{
		Song *p1;
		p1 = (Song*)malloc (sizeof(Song));
		if (p1 != NULL){
			char str[100];
			while(!feof(fpAll_Music)){
				p1 = (Song*)malloc (sizeof(Song));
				fscanf(fpAll_Music, "%s", str);
				token = strtok(str, seps);
				strcpy(p1->path, token);
				token = strtok(NULL, seps);
				strcpy(p1->name, token);
				token = strtok(NULL, seps);
				strcpy(p1->author, token);
				if (strcmp(p1->path, path) == 0){
					fclose(fpAll_Music);
					if((fpUser_Music = fopen("user_Music.txt", "a")) != NULL){
						fputc('\n', fpUser_Music);
						fputs(p1->path, fpUser_Music);
						fputc('_', fpUser_Music);
						fputs(p1->name, fpUser_Music);
						fputc('_', fpUser_Music);
						fputs(p1->author, fpUser_Music);
						fclose(fpUser_Music);
						return 1;
					}else{
						fclose(fpAll_Music);
						return 0;
					}
				}
			}
			return 2;
		}
	}
}


int deletes(char* path){
	FILE *fpUser_Music;
	char *seps = "_";
	char *token = (char*)malloc(sizeof(char)*N);
	if((fpUser_Music = fopen("user_Music.txt", "r")) != NULL){
		Song *p1;
		long adderss3 = 0;
		fseek(fpUser_Music, 0, 2);
		adderss3 = ftell(fpUser_Music);
		rewind(fpUser_Music);
			char str[100];
			while(!feof(fpUser_Music)){
				long adderss1 = 0;
				long adderss2 = 0;
				int i = 0;
				char *str1;
				char *str2;
				p1 = (Song*)malloc (sizeof(Song));
				if (p1 != NULL){
					fscanf(fpUser_Music, "%s", str);
					token = strtok(str, seps);
					strcpy(p1->path, token);
					token = strtok(NULL, seps);
					strcpy(p1->name, token);
					token = strtok(NULL, seps);
					strcpy(p1->author, token);
					if (strcmp(p1->path, path) == 0){
						adderss2 = ftell(fpUser_Music);
						fseek(fpUser_Music, -(sizeof(char)*(strlen(p1->author) + strlen(p1->name) + strlen(p1->path)) + 5), 1);
						adderss1 = ftell(fpUser_Music);
						str1 = (char*)malloc(sizeof(char) * (adderss1 + 1));
 						str2 = (char*)malloc(sizeof(char) * (adderss3 - adderss2 + 2));
						rewind(fpUser_Music);
						for (i = 0; i < adderss1; i ++){
							*(str1+i) = fgetc(fpUser_Music);
						}
						*(str1+i) = '\0';
						fseek(fpUser_Music, adderss2, 0);
						for(i = 0; i < (adderss3-adderss2); i ++){
							*(str2 + i) = fgetc(fpUser_Music);
						}
						*(str2 + i ) = '\0';
						fclose(fpUser_Music); 
						if ((fpUser_Music = fopen("user_Music.txt", "w"))!=NULL){
							for (i = 0; *(str1+i)!='\0'; i ++){
								fputc(*(str1 + i), fpUser_Music);
							}
							for (i = 0; *(str2+i)!='\0'; i ++){
								fputc(*(str2 + i), fpUser_Music);
							}
							fclose(fpUser_Music);
							return 1;
						}else
							return 0;
					}
				}
			}
			free(p1);
			return 2;
	}else{
		return 0;
	}
}

int mark(Song *p){
	FILE *fpMark;
	char *str = NULL;
	int i = 0;
	if ((fpMark = fopen("mark.txt", "w")) != NULL){
		str = (char*)malloc(sizeof(char)*(strlen(p->path) + 1));
		strcpy(str, p->path);
		for (i = 0; *(str+i)!='\0';i++){
			fputc(*(str + i), fpMark);
		}
		fclose(fpMark);
	}else{
		return 0;
	}
}

Song* create(){								
	FILE *fpUser_Music;															//user_Music文件指针
	FILE *fpMark;																//mark文件指针
	char *seps = "_";
	char *token = (char*)malloc(sizeof(char)*N);
	if ((fpMark = fopen("mark.txt", "r")) != NULL){								//以只读方式打开mark文件
		if(fgetc(fpMark) == EOF){
			if((fpUser_Music = fopen("user_Music.txt", "r")) == NULL)			//如果mark为空，以user_Music自然顺序建立链表
				return NULL;												    //错误处理:user_Music文件打开失败
			else{
				Song *head = NULL;
				Song *p1, *p2;
				char str[100];
				int n = 0;
				p1 = p2 = (Song*)malloc(sizeof(Song));
				if (p1 != NULL){
					n++;
					if (feof(fpUser_Music)==0){
						fscanf(fpUser_Music, "%s", str);
						token = strtok(str, seps);
						strcpy(p1->path, token);
						token = strtok(NULL, seps);
						strcpy(p1->name, token);                         
						token = strtok(NULL, seps);
						strcpy(p1->author, token);
						fseek(fpUser_Music, 1, 1);
						head = p1;
					}else{
						free(p1);
						return head;
					}
				}else
					return head;
		
				while(1){
					p1 = (Song*)malloc (sizeof(Song));
					if (p1 != NULL){
						if (feof(fpUser_Music)==0){
							n++;
							fscanf(fpUser_Music, "%s", str);
							token = strtok(str, seps);
							strcpy(p1->path, token);
							token = strtok(NULL, seps);
							strcpy(p1->name, token);                         
							token = strtok(NULL, seps);
							strcpy(p1->author, token);
							p2->next = p1;
							p2 = p1;
						}else{
							free(p1);
							p2->next = NULL;
							return head;
						}
					}else
						return head;
				}
			}
		}else{
			char strMark[N];
			rewind(fpMark);
			fgets(strMark, N, fpMark);	
			if((fpUser_Music = fopen("user_Music.txt", "r")) == NULL){			//如果mark为空，以user_Music自然顺序建立链表
				return NULL;													//错误处理:user_Music文件打开失败
			}else{
				Song *head = NULL;
				Song *p1, *p2;
				int n = 0;
				p1 = p2 = (Song*)malloc(sizeof(Song));							//头结点的申请 
				if (p1 != NULL){
					n++;
					if (feof(fpUser_Music)==0){
						char str[100];
						fscanf(fpUser_Music, "%s", str);
						token = strtok(str, seps);
						strcpy(p1->path, token);
						token = strtok(NULL, seps);
						strcpy(p1->name, token);                         
						token = strtok(NULL, seps);
						strcpy(p1->author, token);
						head = p1;			
						while(strcmp(head->path, strMark) != 0){
							p1 = (Song*)malloc (sizeof(Song));
							if (p1 != NULL){
								if (feof(fpUser_Music)==0){
									char str[100];
									fscanf(fpUser_Music, "%s", str);
									token = strtok(str, seps);
									strcpy(p1->path, token);
									token = strtok(NULL, seps);
									strcpy(p1->name, token);                         
									token = strtok(NULL, seps);
									strcpy(p1->author, token);
									p2->next = p1;
									head = p1;
									p2 = p1;
								}else{
									free(p1);
									p2->next = NULL;
									break;
								}
							}else
								return head;
						}		
						while(1){
							p1 = (Song*)malloc (sizeof(Song));
							if (p1 != NULL){
								if (feof(fpUser_Music)==0){
									n++;
									fscanf(fpUser_Music, "%s", str);
									token = strtok(str, seps);
									strcpy(p1->path, token);
									token = strtok(NULL, seps);
									strcpy(p1->name, token);                         
									token = strtok(NULL, seps);
									strcpy(p1->author, token);
									p2->next = p1;
									p2 = p1;
								}else{
									char *ps;
									rewind(fpUser_Music);
									p1 = (Song*)malloc (sizeof(Song));
									fscanf(fpUser_Music, "%s", str);
									token = strtok(str, seps);
									strcpy(p1->path, token);
									token = strtok(NULL, seps);
									strcpy(p1->name, token);                         
									token = strtok(NULL, seps);
									strcpy(p1->author, token);
									fseek(fpUser_Music, 1, 1);
									if (strcmp(p1->path, head->path) != 0){
										do{
											p2->next = p1;
											p2 = p1;
											p1 = (Song*)malloc (sizeof(Song));
											fscanf(fpUser_Music, "%s", str);
											token = strtok(str, seps);
											strcpy(p1->path, token);
											token = strtok(NULL, seps);
											strcpy(p1->name, token);                         
											token = strtok(NULL, seps);
											strcpy(p1->author, token);
										}while(strcmp(head->path, p1->path) != 0);
									}
									free(p1);
									p2->next = NULL;
									return head;
								}
							}else
								return head;
						}
						
					}
				}else
					return head;
			}
		}
	}else
		return NULL;
}