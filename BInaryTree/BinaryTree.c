#include "BinaryTree.h"


void skipSpaces()
{
    //������ ������ ptr�� �������� 0�� �̱⿡ 
    //isspace�� �����̸� 0 �ƴϸ� 0 �̿��� ��
    // ����ִ� ���� ����Ű�� �ʰ� ������ �ƴϸ� ptr ++ ���� �ݺ�
    while (*ptr && isspace(*ptr)) ptr++;
}

// Ʈ�� ��ü �Ľ� ����
int parseTree()
{
    skipSpaces();//���� �˻�
    if (*ptr != '(') return ERROR; // Ʈ���� �ݵ�� '('�� ���� �׷��� ������ ERROR
    int result = parseNode(); //result �� ��� �Ľ� �Լ� ����
    skipSpaces();
    if (*ptr != '\0') return ERROR; // ���ڿ� ������ �о����� Ȯ��
    return result;
}

// ��� �Ľ�
int parseNode()
{
    skipSpaces();
    if (*ptr != '(') return ERROR;
    ptr++; // '(' ��� �� ���� �������� �̵�

    skipSpaces();

    // �� ��ȣ
    if (*ptr == ')') {
        ptr++; // ')' �Һ�
        return TRUE;
    }

    // ��� ���̺� üũ
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    // �ڽ� ��� �Ľ�
    int childResult = parseChildren();
    if (childResult == ERROR) return ERROR; // ���� ���� �߻�
    // �ڽ� ��尡 ����Ʈ�� ��Ģ �����̸� FALSE ��ȯ
    int isBinary = (childResult == TRUE) ? TRUE : FALSE; //childResult �� TRUE�̸� TRUE �ƴϸ� FALSE �� ������ ���� isBinary�� ����

    skipSpaces();
    if (*ptr != ')') return ERROR; // ��� �ݴ� ')' Ȯ�� 
    ptr++; // ')' �Һ�

    return isBinary;
}

// �ڽ� ��� �Ľ�
int parseChildren()
{
    int childCount = 0;
    int isBinary = TRUE;

    while (1) {
        skipSpaces();
        if (*ptr == '(') { // �ڽ� ����
            childCount++;
            int res = parseNode();
            if (res == ERROR) return ERROR; // ���� ����
            if (res == FALSE) isBinary = FALSE; // ���� ��Ģ ����

            if (childCount > 2) isBinary = FALSE; // ����Ʈ�� ��Ģ ����
        }
        else break; // �� �̻� �ڽ� ����
    }

    return isBinary ? TRUE : FALSE;
}
