#pragma once
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

char* ptr; //�Է� ���ڿ��� Ž���� ���� ������

int parseTree();
//Ʈ���� �Ľ��ϴ� �Լ� (�Ľ�: ���ڿ��� �ǹ̴����� �ؼ�)
int parseNode();
int parseChildren();

void skipSpaces();
//���鹮�ڸ� �ǳʶٴ� �Լ�