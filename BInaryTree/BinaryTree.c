/*
�Է� ���ڿ� ���� ���� -> �ٹٲ��� ������ ERROR
��� �Ľ� �Լ� parsNode() -> ���� �����Ͱ� (�̸� 
�� �ȿ��� ��带 ���� -> �ڽ� ��尡 2�� �ʰ��ϸ� FALSE ��ȯ
) ������ ����. ���� �����Ͱ� �������̸� -> �ѱ��� �Һ��ϰ� return
���������Ͱ� ()�̸� null �ڽ� -> ���
*/
#include "BinaryTree.h"


void skipSpaces()
{
    //������ ������ ptr�� �������� 0�� �̱⿡ 
    //isspace�� �����̸� 0 �ƴϸ� 0 �̿��� ��
    // ����ִ� ���� ����Ű�� �ʰ� ������ �ƴϸ� ptr ++ ���� �ݺ�
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
}

int parseTree() {
    skipSpaces();

    if (*ptr != '(') return ERROR;
    ptr++; // '(' ��������

    skipSpaces();

    // �� ��ȣ ó��
    if (*ptr == ')') {
        ptr++;
        return TRUE;
    }

    int children = 0;
    int res;

    while (*ptr != ')' && *ptr != '\0') {
        if (isalpha(*ptr)) {
            ptr++;
            children++;
            if (children > 2) res = FALSE; // �ڽ� 3�� �̻� �� FALSE
            else res = TRUE;
        }
        else if (*ptr == '(') {
            res = parseTree();
            if (res == ERROR) return ERROR;
            children++;
            if (children > 2) res = FALSE;
        }
        else if (isspace(*ptr)) {
            ptr++;
            continue;
        }
        else {
            return ERROR; // �� �� ���� ����
        }
        skipSpaces();
    }

    if (*ptr != ')') return ERROR;
    ptr++;

    return (children > 2) ? FALSE : TRUE;
}

