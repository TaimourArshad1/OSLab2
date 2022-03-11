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

extern void environ(void){
	//Printf statement that lists all environment variables using env
	printf("LOGNAME : USERNAME ");
	printf("HOME=/home/USERNAME"); 
	printf("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\n");
	printf("PWD=/home/Desktop\n");
	printf("LANGUAGE=en_CA:en");
	printf("DESKTOP_SESSION=ubuntu");
	       
}

extern void help(void){
	//Prints all available commands to display
	printf("\nList of available commands:\n\n");
    	printf("help: Lists the help menu.\n");
    	printf("dir <directory>: Lists the contents of the directory\n");
    	printf("environ: Lists all the environment strings..\n");
    	printf("echo <comment>: Displays comment on the command line followed by a newline.\n");
	printf("cd <path>: Changes the working directory to the specified path.\n");
    	printf("clr: Clears screen.\n");
    	printf("pause: Pauses operation of the shell until ENTER key is hit.\n");
    	printf("quitQuits the shell.\n\n\n");
	printf("myshell-->");
}

extern void pause_shell(void){
	//Prints shell is paused.
	printf("\n\nShell is paused. To continue, hit the ENTER key.....\n\n");
    	char paused = (char)getchar();
    	while (paused != '\n'){
        	paused = (char)getchar();
    	}
}
