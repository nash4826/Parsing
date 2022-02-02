#pragma once
#ifndef __JSON_PARSING_H__
#define __JSON_PARSING_H__
#include <stdbool.h>
//��ū ���� ������
typedef enum _TOKEN_TYPE {
	TOKEN_STRING, //���ڿ� ��ū
	TOKEN_NUMBER, //���� ��ū
}TOKEN_TYPE;

//��ū ����ü
typedef struct _TOKEN {
	TOKEN_TYPE type; //��ū ����
	union {			// �� ���� �� �� ������ ������ ���̹Ƿ� ����ü�� ����
		char* string; //���ڿ� ������
		double number; //�Ǽ��� ����
	};
	bool isArray;	//���� ��ū�� �迭���� ǥ��
}TOKEN;

#define TOKEN_COUNT		20 //��ū�� �ִ� ����

typedef struct _JSON {
	TOKEN tokens[TOKEN_COUNT];
}JSON;


char* readFile(char* filename, int* readSize); //������ �о ������ ��ȯ�ϴ� �Լ�

void parseJSON(char* doc, int size, JSON* json); //JSON �Ľ� �Լ�

void freeJSON(JSON* json); //JSON ���� �Լ�

#endif // !__JSON_PARSING_H__
