#include <stdio.h>
#include <string.h>

int main()
{
	char my_str[128]; 
	char v[32][128];
	int i = 0;
	
	printf("Introdu sirul: ");
	fgets(my_str, 128, stdin);
	my_str[strlen(my_str)-1] = '\0';

	char *p = strtok(my_str, " ");
	while(p != NULL)
	{
		strcpy(v[i++], p);
		p = strtok(NULL, " ");
	}
	
	for(int k = 0; k < i-1; k++)
	{
		for(int l = k+1; l < i; l++)
		{
			if(strlen(v[k]) < strlen(v[l]))
			{
				char tmp[128];
				strcpy(tmp, v[k]);
				strcpy(v[k], v[l]);
				strcpy(v[l], tmp);
			}
		}
	}

	for(int j = 0 ; j < i; j++)
		printf("%s\n", v[j]);
	return 0;
}
