#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "utility.h"
#include "myshell.h"

//Initialize Global Variables
//BUFFER holds the buffer 
#define BUFFER 1024
//Tokens holds the parsed input from the user
#define TOKENS 10

int main(int argc, char *argv[]){
	
	//Variables are intialized
	char shell[2][BUFFER] = {0};
	char cur[BUFFER] = {0};
	char myshell[BUFFER] = {0};
	char buffer[BUFFER] = {0};
	char command[BUFFER] = {0};
	char tokens[TOKENS][BUFFER] = {0};
	int t_count = 0;
	int track = 0;
	
	//File is created and set to null
	FILE* file = NULL;
	
	//Checks if file opens correctly
	if (file == NULL && argc > 1){
	printf("Error opening file");
	return 0;
	}
	
	//Opens file, uses user input for parsing
	if (argc > 1){
	file = fopen(argv[1], "r");
	}else{
	file = stdin;
	}
	
	printf("Welcome!\n");
	
	strcpy(shell[0], "CUR: ");
	strcpy(shell[0], cur);
	strcpy(shell[1], "myshell: ");
	strcpy(shell[1], myshell);
	
	printf("%s-myshell-> ", cur);
	
	//Loop runs as long as file, BUFFER, and buffer and not null
	while (fgets(buffer, BUFFER, file) != NULL){
		
		//Input is parsed using tokens
		int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		t_count = parse(buffer, tokens);
		strcpy(command, tokens[0]);
		
		//if/else tree that compares the user input with available commands
		//track variable is set to the appropriate number that corresponds with the command
		if (strcmp(command, "cd") == 0){
			track = 1;
			}
			
		else if (strcmp(command, "clr") == 0){
			track = 2;
			}
		
		else if (strcmp(command, "dir") == 0){
			track = 3;
			
			}
		
		else if (strcmp(command, "echo") == 0){
			track = 4;
			
			}
		
		else if (strcmp(command, "environ") == 0){
			track = 5;
			}
		
		else if (strcmp(command, "help") == 0){
			track = 6;
			}
		
		else if(strcmp(command, "quit") == 0){
			track = 7;
			}
		
		else if(strcmp(command, "pause") == 0){
			track = 8;
			}
			
		//track variable is used to called functions to perform on the shell
		switch(track)
		{
		case 1:
			//cd_command() is called with the present directory and the directory requested by the user	
			cd_command(cur, tokens[1]);
			strcpy(shell[0], "CUR: ");
			strcat(shell[0], cur);
			break;
		case 2:
			//clear() is called to clear the shell	
			clear();
			break;
		case 3:
			//list_contents is called to display all the contents of the shell	
			list_contents(tokens[1]);
			printf("\n");
			break;	
		case 4:
			printf("%s> ", cur);
			for (int i = 1; i < token_count; i++){
				printf("%s ", tokens[i]);
			}
			printf("\n");	
			break;	
		case 5:
			environ(environ);
			break;	
		case 6:
			display_help();
			break;
		case 7:
			//quick_exit() is used to exit the shell	
			quick_exit(0);
	
		case 8:
			break;
		}
	}
}				
			
	
