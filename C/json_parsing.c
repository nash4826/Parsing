#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_parsing.h"


//파일을 읽어서 내용을 반환하는 함수
char* readFile(char* filename, int* readSize)
{
	FILE* fp = fopen(filename, "rb"); //읽기/바이너리
	if (fp == NULL)
		return NULL;

	int size;
	char* buffer;

	fseek(fp, 0, SEEK_END); //파일 포인터를 파일의 끝으로 이동.
	size = ftell(fp); //파일 포인터의 위치가 파일 끝이므로 파일 size를 알수있음.
	
	fseek(fp, 0, SEEK_SET);//파일 포인터를 다시 처음 위치로 복귀(이유는 fread시 size만큼 읽어줘야하기 때문이다.)


	buffer = malloc(size + 1);
	memset(buffer, 0, size+1);

	//파일 내용 읽기
	if (fread(buffer, size, 1, fp) < 1)
	{
		*readSize = 0;
		free(buffer);
		fclose(fp);
		return NULL;
	}

	//파일 크기를 넘겨줌
	*readSize = size;

	fclose(fp);

	return buffer;
}




/*
	//JSON 파일 내용

{
	"Title": "Inception",
		"Genre" : "Sci-Fi",
		"Director" : "Christopher Nolan"
}

*/

//JSON 파싱 함수
void parseJSON(char* doc, int size, JSON* json)
{
	int tokenIndex = 0; //토큰 인덱스
	int pos = 0; //문자 검색 위치를 저장하는 변수

	if (doc[pos] != '{') //문서의 시작이 { 인지 검사 
		return;
	
	pos++; //다음 문자로
	
	while (pos < size) //문자 크기만큼 반복 
	{
		switch (doc[pos]) //문자의 종류에 따라 분기
		{
		case '"': //문자가 " 이면 문자열
		{
			//문자열의 시작 위치를 구함. 맨 앞의 " 을 제외하기 위해 + 1 함
			char* begin = doc + pos + 1;

			//문자열의 끝 위치를 구함. 다음 "의 위치
			char* end = strchr(begin, '"');
			if (end == NULL)
				break;

			int stringLength = end - begin; //문자열의 실제 길이는 (끝 위치 - 시작위치)

			//토큰 배열에 문자열 저장
			json->tokens[tokenIndex].type = TOKEN_STRING; //토큰 종류는 문자열

			//문자열 길이 + NULL 공간만큼 메모리 할당
			json->tokens[tokenIndex].string = malloc(stringLength + 1);
			
			//메모리 0으로 초기화
			memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

			
			//문서에서 문자열을 토큰에 저장
			memcpy(json->tokens[tokenIndex].string, begin, stringLength); //문자열 시작 위치에서 문자열 길이만큼만 복사

			tokenIndex++;

			pos = pos + stringLength + 1;
		}
		break;
		}
		pos++;//다음 문자로
	}
}

//JSON 해제 함수
void freeJSON(JSON* json)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		if (json->tokens[i].type == TOKEN_STRING)
			free(json->tokens[i].string);
	}
}

