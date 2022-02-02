#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_parsing.h"


//������ �о ������ ��ȯ�ϴ� �Լ�
char* readFile(char* filename, int* readSize)
{
	FILE* fp = fopen(filename, "rb"); //�б�/���̳ʸ�
	if (fp == NULL)
		return NULL;

	int size;
	char* buffer;

	fseek(fp, 0, SEEK_END); //���� �����͸� ������ ������ �̵�.
	size = ftell(fp); //���� �������� ��ġ�� ���� ���̹Ƿ� ���� size�� �˼�����.
	
	fseek(fp, 0, SEEK_SET);//���� �����͸� �ٽ� ó�� ��ġ�� ����(������ fread�� size��ŭ �о�����ϱ� �����̴�.)


	buffer = malloc(size + 1);
	memset(buffer, 0, size+1);

	//���� ���� �б�
	if (fread(buffer, size, 1, fp) < 1)
	{
		*readSize = 0;
		free(buffer);
		fclose(fp);
		return NULL;
	}

	//���� ũ�⸦ �Ѱ���
	*readSize = size;

	fclose(fp);

	return buffer;
}




/*
	//JSON ���� ����

{
	"Title": "Inception",
		"Genre" : "Sci-Fi",
		"Director" : "Christopher Nolan"
}

*/

//JSON �Ľ� �Լ�
void parseJSON(char* doc, int size, JSON* json)
{
	int tokenIndex = 0; //��ū �ε���
	int pos = 0; //���� �˻� ��ġ�� �����ϴ� ����

	if (doc[pos] != '{') //������ ������ { ���� �˻� 
		return;
	
	pos++; //���� ���ڷ�
	
	while (pos < size) //���� ũ�⸸ŭ �ݺ� 
	{
		switch (doc[pos]) //������ ������ ���� �б�
		{
		case '"': //���ڰ� " �̸� ���ڿ�
		{
			//���ڿ��� ���� ��ġ�� ����. �� ���� " �� �����ϱ� ���� + 1 ��
			char* begin = doc + pos + 1;

			//���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
			char* end = strchr(begin, '"');
			if (end == NULL)
				break;

			int stringLength = end - begin; //���ڿ��� ���� ���̴� (�� ��ġ - ������ġ)

			//��ū �迭�� ���ڿ� ����
			json->tokens[tokenIndex].type = TOKEN_STRING; //��ū ������ ���ڿ�

			//���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
			json->tokens[tokenIndex].string = malloc(stringLength + 1);
			
			//�޸� 0���� �ʱ�ȭ
			memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

			
			//�������� ���ڿ��� ��ū�� ����
			memcpy(json->tokens[tokenIndex].string, begin, stringLength); //���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����

			tokenIndex++;

			pos = pos + stringLength + 1;
		}
		break;
		}
		pos++;//���� ���ڷ�
	}
}

//JSON ���� �Լ�
void freeJSON(JSON* json)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		if (json->tokens[i].type == TOKEN_STRING)
			free(json->tokens[i].string);
	}
}

