#include <stdio.h>

int verificaSubstring(char *str1, char *str2) 
{
    while (*str1 != '\0') 
	{ 
        char *p1 = str1;
        char *p2 = str2;

        while (*p1 == *p2 && *p2 != '\0') 
		{  
            p1++;
            p2++;
        }

        if (*p2 == '\0') 
		{  
            return 1;
        }

        str1++;  
    }

    return 0; 
}

int main(void) 
{
    char str1[100];
    char str2[100];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    if (verificaSubstring(str1, str2)==1) 
	{
        printf("A segunda string ocorre dentro da primeira.\n");
    } 
	else 
	{
        printf("A segunda string nao ocorre dentro da primeira.\n");
    }

    return 0;
}
