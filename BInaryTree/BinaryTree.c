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

int parseTree() { // Ʈ�� �Ľ� �Լ�
    skipSpaces(); //���� �ǳʶٱ�

    if (*ptr != '(') return ERROR;
    ptr++; // '(' �� ���� ���ϸ� ERROR -> ���� ����

    skipSpaces();

    // �� ��ȣ ó��
    if (*ptr == ')') {
		ptr++; // ')' �̸� TRUE ��ȯ (�� Ʈ��)
        return TRUE;
    }

    int children = 0; //�ڽ� ��� ���� 0���� �ʱ�ȭ
    int res; //res ��� ���� ����

	while (*ptr != ')' && *ptr != '\0') { //')' �Ǵ� ���ڿ� ������ �ݺ�
        if (isalpha(*ptr)) { //�������̸�
            ptr++; //���� ���ڷ� �̵�
            children++; //�ڽ� ��� ���� ����
            if (children > 2) res = FALSE; // �ڽ� 3�� �̻� �� FALSE
			else res = TRUE; // �ڽ� 2�� ���� �� TRUE
        }
        else if (*ptr == '(') { // '(' �̸� �ٽ� ��� ȣ��
            res = parseTree(); //res ������ ��� ȣ���� ����� ����
            if (res == ERROR) return ERROR; //��� ȣ���Ҷ� ERROR �� ( ���� �ҋ� '(' �� �ƴҶ� ERROR
			children++; //res�� ERROR�� �ƴϸ� �ڽ� ��� ���� ����
			if (children > 2) res = FALSE; // �ڽ� 3�� �̻� �� FALSE
        }
		else if (isspace(*ptr)) { //�����̸� �ǳʶٱ�
            ptr++;
            continue;
        }
        else {
            return ERROR; // �� �� ���� ����
        }
        skipSpaces();
    }

    if (*ptr != ')') return ERROR;
	ptr++; // ')' �� ������ ������ ERROR -> ���� ����

	return (children > 2) ? FALSE : TRUE; // �ڽ� 3�� �̻� �� FALSE, �ƴϸ� TRUE
}

