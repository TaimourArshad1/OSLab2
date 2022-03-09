#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "utility.h"
#include "myshell.h"

#define BUFFER 1024
#define TOKENS 10

int main(int argc, char *argv[]){
	
	char environ[2][BUFFER] = {0};
	char cur[BUFFER] = {0};
	char myshell[BUFFER] = {0};
	char buffer[BUFFER] = {0};
	char command[BUFFER] = {0};
	char tokens[TOKENS][BUFFER] = {0};
	int t_count = 0;
	int command = 0;
	
	FILE* file = NULL;
	
	if (file == NULL && argc > 1){
	printf("Error opening file");
	return 0;
	}
	
	if (argc > 1){
	file = fopen(argv[1], "r");
	}else{
	file = stdin;
	}
	
	printf("Welcome!\n");
	
	strcpy(environ[0], "dir: ");
	strcpy(environ[0], cur);
	strcpy(environ[1], "myshell: ");
	strcpy(environ[1], myshell);
	
	printf("%s--> ", cur);
	
	while (fgets(buffer, BUFFER, file) != NULL){
		
		int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		t_count = parse(buffer, tokens);
		strcpy(command, tokens[0]);
		
		if (strcmp(command, "cd") == 0){
			command = 1;
		
			cd_command(cur, tokens[1]);
			strcpy(environ[0], "dir: ");
			strcat(environ[0], pwd);
			}
			
		else if (strcmp(command, "clr") == 0){
			command = 2;
			clear();
			}
		
		else if (strcmp(command, "dir") == 0){
			command = 3;
			list_contents(tokens[1]);
			printf("\n");
			}
			
		switch(command)
		{
		case
		}
	}				
			
	
	
	

