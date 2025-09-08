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

    // �Է� �� ó���ߴ��� Ȯ��
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
    if (*ptr == ')') { // �� ��ȣ
        ptr++;
        return TRUE;
    }

    // ��Ʈ ��� ���̺�
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    int childCount = 0;
    while (1) {
        skipSpaces();
        if (*ptr == '(') {
            childCount++;
            if (childCount > 2) return FALSE; // �ڽ� 3�� �̻� �� FALSE
            int r = parseTree();
            if (r != TRUE) return r;
        }
        else if (isalpha(*ptr)) {
            // �ܵ� ���ĺ� �ڽ�
            childCount++;
            if (childCount > 2) return FALSE;
            ptr++;
        }
        else if (*ptr == ')') {
            ptr++;
            return TRUE; // ��� ��
        }
        else if (*ptr == '\0' || *ptr == '\n') {
            return ERROR;
        }
        else {
            return ERROR;
        }
    }
}


