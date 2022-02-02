#include <stdio.h>
#include <stdlib.h>
#include "json_parsing.h"

int main()
{
	int size;

	char* doc = readFile("movie.json", &size);
	if (doc == NULL)
		return -1;

	JSON json = { 0, };

	parseJSON(doc, size, &json);

	printf("Title: %s\n", json.tokens[1].string);

	printf("Genre: %s\n", json.tokens[3].string);

	printf("Director: %s\n", json.tokens[5].string);

	freeJSON(&json);

	free(doc);

	return 0;
}