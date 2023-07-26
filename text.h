#ifndef TEXT_H
#define TEXT_H
#define NULL ((void *)0)

/*text_manipulation_1*/
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/*text_manipulation_2*/
int digits(int n);
char *to_string(int number);
int _isdigit(int c);
int _atoi(char *s);
int contains_letter(char *s);

#endif