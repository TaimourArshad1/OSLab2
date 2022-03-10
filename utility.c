#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "utility.h"

extern int parse(char* str, char tokens[][BUFFER]){
	//del holds the blank space
	const char del[2] = " ";
	int t_count = 0;
	//ignore the blanks and token holds all the other words using strtok()
	char* token = strtok(str, del);
	//Runs while token is not empty
	while (token != NULL){
		//Puts the token at the appropriate index of tokens[]
		strcpy(tokens[t_count], token);
		token = strtok(NULL, del);
		}
		return t_count;
}

extern void list_contents(char* path){
	
	struct dirent *dir;
	DIR *d = NULL;
	//Opens the appropriate directory and returns true or false 
	d = opendir(".");
	//d is true
	if (d) {
		//runs while the dir is not empty
		while ((dir = readdir(d)) != NULL) {
			//prints teh contents od teh directory using the struct variable
			printf("%s\n", dir->d_name);
		}
		//closes directory
		closedir(d);
	}
	printf("myshell-->");
}
	
extern void cd_command(char* cur, char* path){
	//chdir result is stored in check variable
	int check = chdir(path);
	//checks if the path provided is not blank
	if (strcmp(path,"") != 0){
		//chdir result is succesfull
		if (check == 0){
			//directory is changed with the path provided by the user
			chdir(path);
			//list_contents() is called to display the contents of the chaned directory
			list_contents(cur);
		}
		else {
			//Prints if the path provided by the user does not exist
			printf("%s> No Path Exists\n"	, cur);
		}
	}
	printf("myshell-->");
}

extern void clear(void){
	//Printf statement that clears the entire screen
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
