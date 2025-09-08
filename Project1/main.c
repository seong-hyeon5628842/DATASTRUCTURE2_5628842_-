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
    if (*ptr != '(') return ERROR;
    ptr++;

    skipSpaces();
    if (*ptr == ')') { // 빈 괄호
        ptr++;
        return TRUE;
    }

    // 루트 노드 레이블
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    int childCount = 0;
    while (1) {
        skipSpaces();
        if (*ptr == '(') {
            childCount++;
            if (childCount > 2) return FALSE; // 자식 3개 이상 → FALSE
            int r = parseTree();
            if (r != TRUE) return r;
        }
        else if (isalpha(*ptr)) {
            // 단독 알파벳 자식
            childCount++;
            if (childCount > 2) return FALSE;
            ptr++;
        }
        else if (*ptr == ')') {
            ptr++;
            return TRUE; // 노드 끝
        }
        else if (*ptr == '\0' || *ptr == '\n') {
            return ERROR;
        }
        else {
            return ERROR;
        }
    }
}


