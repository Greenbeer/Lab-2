#include <stdio.h>
#include <string.h>

struct package 
{
	int num;
	char words[255];
	float f_num;
};

void main(int argc, char *argv[])
{
	FILE *cur_file;
	struct package line;
	char text[255];
	int i=0, size;
	
	cur_file = fopen(argv[1], "rb");
	while (cur_file == NULL) 
	{
		printf("Please, enter the correct file name\n");
		scanf("%s", text);
		cur_file = fopen(text, "rb");
	}
	printf("Your table:\n");
	while (fread(&line, sizeof(struct package), 1, cur_file)) 
	{
		printf("%2d  %s  %f\n", line.num, line.words, line.f_num);
		i++;
	}
	size = i * sizeof(struct package);
	printf("File size: %d bytes\n", size);
}
