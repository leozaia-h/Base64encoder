#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void ascii(char x[], int len)
{
	int i;

	for(i = 0; i < len; i++)
		printf("%d%c", x[i], i < (len-1) ? ' ' : '\n');
}

unsigned int_to_bin(unsigned x)
{
	if(x == 0)	return 0;
	if(x == 1)	return 1;
	return (x % 2) + 10  * int_to_bin(x / 2);
}
int bin_to_int(char x[])
{
	int k, sum = 0, i, len = strlen(x);
	char a;

	for(i = 0; i < len; i++)
	{
		a = x[(len-1)-i];
		k = a - '0';
		sum += pow(2, i) * k;
	}
	return sum;
}

char B64_gen(char x)
{
	char b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	return b64chars[x];
}

int main(void)
{
	char str[1000];
	scanf("%[^\n]", str);
	int len = strlen(str);
	if(str[len-1] == '\n') str[len-1] = '\0';
	int i, j, e, cont=0, aux, igual = 0;

	printf("String: %s\n", str);

	printf("ASCII decimal:\n");
	ascii(str, len);

	printf("Binario:\n");
	for(i = 0; i < len; i++)
		printf("%08d%c", int_to_bin(str[i]), i < (len-1) ? ' ' : '\n');

	printf("Decimal Base64:\n");

	int charB64bin;
	char *strB64bin;
	char *strB64;
	int *test;
	char a[8];
	char b[8];
	char c[6];
	char d[6];
	char tmp[6];

	memset(tmp, 0, sizeof(tmp));
	strB64bin = malloc(len * sizeof(strB64bin));
	strB64 = malloc(len * sizeof(strB64));
	test = malloc(1 * sizeof(tmp));
	for(i = 0; i < len; i++)
	{
		sprintf(a, "%08d", int_to_bin(str[i]));
		strcat(strB64bin, a);
	}

	for(i = 0; i < strlen(strB64bin); i++)
	{
		if(i % 6 == 0 && i != 0)
		{
			test = realloc(test, (cont+1)*sizeof(test));
			test[cont] = bin_to_int(tmp);
			cont++;
			printf("%d ", bin_to_int(tmp));
			memset(tmp, 0, sizeof(tmp));
		}
		sprintf(d, "%c", strB64bin[i]);
		strcat(tmp, d);
		if(i == strlen(strB64bin)-1)
		{
			if(strlen(tmp) % 6 == 0)
			{
				test = realloc(test, (cont+1)*sizeof(test));
				test[cont] = bin_to_int(tmp);
				cont++;
				printf("%d ", bin_to_int(tmp));
				memset(tmp, 0, sizeof(tmp));
			}
			else
			{
				e = 6 - strlen(tmp);
				igual = e/2;
				while(e > 0)
				{
					strcat(tmp, "0");
					e--;
				}
				test = realloc(test, (cont+1)*sizeof(test));
				test[cont] = bin_to_int(tmp);
				cont++;
				printf("%d ", bin_to_int(tmp));
				memset(tmp, 0, sizeof(tmp));
			}
		}
	}

	printf("\nTexto Codificado:\n");
	for(i = 0; i < cont; i++)
		printf("%c", B64_gen(test[i]));
	while(igual > 0)
	{
		printf("=");
		igual--;
	}
	printf("\n");

	return 0;
}
