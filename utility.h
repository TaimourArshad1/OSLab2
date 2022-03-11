#ifndef UTILITY_H_
#define UTILITY_H_

#define BUFFER 1024

extern int parse(char* str, char tokens[][BUFFER]);

extern void list_contents(char* cur);

extern void cd_command(char* cur, char* path);

extern void clear(void);

extern void environ(void);

extern void display_help(void);

extern void echo(char* x);

#endif

