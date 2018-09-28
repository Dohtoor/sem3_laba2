// sem3_laba2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"

#pragma warning(disable:4996)

int main()
{
	int i = 0;
	int len = 0;
	int k = 0;

	FILE *inFile;
	inFile = fopen("file_in.txt", "r");
	FILE *outFile;
	outFile = fopen("file_out.bin", "w");

	char buffer[256];

	while (fgets(buffer, 256, inFile) != NULL)
	{
		k = 0;
		while ((buffer[k] < 127) && (buffer[k] > 31))
			k++;

		if (k > len)
			len = k;
		i++;
	}

	rewind(inFile);

	fwrite(&i, sizeof(i), 1, outFile);

	len = len;

	while (fgets(buffer, 256, inFile) != NULL)
	{
		if (strchr(buffer, '\n') != nullptr)
			memset(strchr(buffer, '\n'), ' ', 256 - len);
		else memset(strchr(buffer, '\0'), ' ', 255 - len);
		fwrite(buffer, sizeof(char), len, outFile);
	}

	fclose(inFile);
	fclose(outFile);
	return 0;
}

