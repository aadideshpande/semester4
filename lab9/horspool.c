// horspool's algorithm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[26];
int* shiftTable(char* pattern,int len)
{
	for(int i = 0; i < 26; i++){table[i] = len;}
	// loop till the second last element of the pattern	
	for(int j = 0; j <= len - 2; j++)
	{
		int x = (pattern[j] - 'a');
		table[x] = len - 1 - j;
	}
	return table;
}

int horspoolMatch(char* pattern, int p_len, char* text, int t_len)
{
	int* mytable = shiftTable(pattern, p_len);
	int i = p_len - 1, k;
	while(i <= t_len - 1)
	{
		k = 0;
		//this loop checks if the pattern is matching
		while(k <= p_len - 1 && pattern[p_len - 1 - k] == text[i - k])
		{
			k += 1;
		}
		//if pattern matches, return the position of the substring 
		if(k == p_len){return (i - p_len + 1);}
		else
		{
			int x = text[i] - 'a';
			i = i + mytable[x];
		}
	}
	return -1;
}

int main()
{
	char text[100], pattern[50];
	printf("enter the text: \n");
	scanf(" %s", text);
	printf("enter the pattern to be found: \n");
	scanf(" %s", pattern);

	int p_len = strlen(pattern);
	int t_len = strlen(text);

	int* mytable = shiftTable(pattern, p_len);
	int index = horspoolMatch(pattern, p_len, text, t_len);
	printf("found at: %d \n", index);
	
	/* print the SHIFT TABLE */
	for(int i = 0; i < 26; i++)
	{
		printf("%d ", mytable[i]);
	}
	printf("\n");
	
}