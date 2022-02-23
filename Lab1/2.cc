#include <cstdio>


int main(){
	FILE *f = fopen("in.txt", "r");

	if(f == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}

	int numar = 0, suma = 0;

	while(fscanf(f, "%d", &numar) != EOF)
	{
		suma += numar;
	}
	
	printf("%d\n", suma);
	fclose(f);
}
