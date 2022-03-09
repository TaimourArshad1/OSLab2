#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "utility.h"

extern int parse(char* str, char tokens[][BUFFER]){
	const char delimiter[2] = " ";
	int t_count = 0;
	char* token = strtok(str, delimiter);
	while (token != NULL){
		strcpy(tokens[t_count], token);
		token = strtok(NULL, delimiter);
		}
		return t_count;
}

extern void list_contents(char* path){
	struct dirent *dir;
	DIR *d = NULL;
	
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
		}
		}
	
extern void cd_command(char* cur, char* path){
	int c = chdir(path);
	if (strcmp(path,"") != 0){
		if (c == 0){
			list_contents(cur);
		}
		else{
		printf("%s> No Path Exists\n"	, cur);
		}
	}
}

extern void clear(void){
	printf("\e[1;1H\e[2J");
	}
