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
	printf("myshell-->");
}
	
extern void cd_command(char* cur, char* path){
	int check = chdir(path);
	if (strcmp(path,"") != 0){
		if (check == 0){
			chdir(path);
			list_contents(cur);
		}
		else {
			printf("%s> No Path Exists\n"	, cur);
		}
	}
	printf("myshell-->");
}

extern void clear(void){
	printf("\e[1;1H\e[2J");
	printf("myshell-->");
}

extern void environ(char shell[][BUFFER]){
	printf("%s\n%s\n", env[0], env[1]);
}

extern void display_help(void){
	printf("\nList of available commands:\n\n");
    	printf("help\t\t\t Lists the help menu.\n");
    	printf("dir <directory>\t\t Lists the contents of the directory\n");
    	printf("environ\t\t\t Lists all the environment strings..\n");
    	printf("echo <comment>\t\t Displays comment on the command line followed by a newline.\n");
	printf("cd <path>\t\t Changes the working directory to the specified path.\n");
    	printf("clr\t\t\t Clears the screen.\n");
    	printf("pause\t\t\t Pauses operation of the shell until the ENTER key is hit.\n");
    	printf("quit\t\t\t Quits the shell.\n\n\n");
}
