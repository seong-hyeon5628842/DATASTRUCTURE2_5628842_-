#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

char* ptr;

int parseTree();
void skipSpaces();

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    ptr = input;
    int result = parseTree();

    // 입력 다 처리했는지 확인
    skipSpaces();
    if (*ptr != '\0' && *ptr != '\n') result = ERROR;

    if (result == TRUE) printf("TRUE\n");
    else if (result == FALSE) printf("FALSE\n");
    else printf("ERROR\n");

    return 0;
}

void skipSpaces() {
    while (*ptr && isspace(*ptr)) ptr++;
}

int parseTree() {
    skipSpaces();
    if (*ptr != '(') return ERROR; // '('로 시작하지 않으면 오류
    ptr++; // '(' 소비

    skipSpaces();
    if (*ptr == ')') { // 빈 괄호
        ptr++;
        return TRUE;
    }

    // 루트 노드 레이블
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    int childCount = 0;
    int result = TRUE; // 기본은 TRUE
    while (1) {
        skipSpaces();
        if (*ptr == '(') { // 서브트리 존재
            childCount++;
            int r = parseTree();
            if (r == ERROR) return ERROR;
            if (childCount > 2) result = FALSE; // 자식 3개 이상 → FALSE
        }
        else if (*ptr == ')') { // 현재 노드 종료
            ptr++;
            if (childCount > 2) return FALSE;
            return result; // 0~2 자식이면 TRUE, 3개 이상이면 FALSE
        }
        else if (*ptr == '\0' || *ptr == '\n') { // 입력 끝
            return ERROR;
        }
        else { // 괄호 없이 알파벳 나오면 ERROR
            return ERROR;
        }
    }
}