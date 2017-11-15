#include <stdio.h>

int main()
{
	FILE *arq = fopen("y.txt","w");
	int i;
	for(i=1;i<=1000;++i)
	{
		fprintf(arq,"%d\n",i);
	}
	return 0;

}
