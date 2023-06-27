#ifndef GLADOS_H
#define GLADOS_H

#define streq(s, s1) (strncasecmp((s), (s1), strlen((s1))) == 0)

#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

#define STRING_BUFFER_SIZE 100

#endif