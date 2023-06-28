#ifndef main_h
#define main_h
extern char **environ;

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strncat(char *dest, char *src, int n);
void _putchar(char c);
int len_buf(char *buffer);
char **tokenize(char *buffer);
char **sep_path(char **envp);
int len_path(char *buffer);
char *_getenv(char **envp);
char **checker(char **path, char **args);
char *find_path(char **path, char *filename);
char **prep(char *buffer, char **path);
void _exec(char **args, char **envp);
char *command(char **path, char *filename);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
#endif
