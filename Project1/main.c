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
    if (*ptr != '(') return ERROR; // '('�� �������� ������ ����
    ptr++; // '(' �Һ�

    skipSpaces();
    if (*ptr == ')') { // �� ��ȣ
        ptr++;
        return TRUE;
    }

    // ��Ʈ ��� ���̺�
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    int childCount = 0;
    int result = TRUE; // �⺻�� TRUE
    while (1) {
        skipSpaces();
        if (*ptr == '(') { // ����Ʈ�� ����
            childCount++;
            int r = parseTree();
            if (r == ERROR) return ERROR;
            if (childCount > 2) result = FALSE; // �ڽ� 3�� �̻� �� FALSE
        }
        else if (*ptr == ')') { // ���� ��� ����
            ptr++;
            if (childCount > 2) return FALSE;
            return result; // 0~2 �ڽ��̸� TRUE, 3�� �̻��̸� FALSE
        }
        else if (*ptr == '\0' || *ptr == '\n') { // �Է� ��
            return ERROR;
        }
        else { // ��ȣ ���� ���ĺ� ������ ERROR
            return ERROR;
        }
    }
}