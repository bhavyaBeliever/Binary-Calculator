//link for leetcode question ==> https://leetcode.com/problems/simplify-path/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *simplifyPath(char *path);
int main()
{
    char path[] = "/home/";

    char *simplePath = simplifyPath(path);
    printf("%s\n%s\n", path, simplePath);
    return 0;
}

char *simplifyPath(char *path)
{
    char *top = path;
    int i = 0, j = 0;
    while (path[i] != '\0')
    {
        if (path[i] == '/' && path[i + 1] == '.' && path[i + 2] == '/')
        {
            path[i] = path[i + 1] = '\0';
            i += 1;
        }
        else if (path[i] == '/' && path[i + 1] == '.' && path[i + 2] == '.' && path[i + 3] == '/')
        {
            //removing the directory
            int k = i;
            while (top != (path + k) && k)
            {
                path[k] = '\0';
                k--;
            };
            j=k;
            //changing the top position;
            *top='\0';
            while(*top!='/' && top!=path) {
                top=top-1;
            }
            printf("%s ",path);

            i += 2;
        }
        else if (path[i] == '/' && path[i + 1] != '/' && path[i + 1] != '\0')
        {
            top = path + i;
            path[j] = path[i];
            j++;
        }
        else if (path[i] == '/' && (path[i + 1] == '/' || path[i + 1] == '\0'))
        {
            i++;
            continue;
        }
        else
        {
            path[j] = path[i];
            j++;
        }
        i++;
    }
    path[0]='/';
    return path;
}
