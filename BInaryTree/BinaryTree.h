#pragma once
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

extern char* ptr; //입력 문자열을 탐색할 전역 포인터

extern int parseTree();
//트리를 파싱하는 함수 (파싱: 문자열을 의미단위로 해석)
//int parseNode();
//int parseChildren();

extern void skipSpaces();
//공백문자를 건너뛰는 함수