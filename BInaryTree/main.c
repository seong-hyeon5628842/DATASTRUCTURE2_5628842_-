#include"BinaryTree.h"

int main() {
    char input[1000];
    // �Է� ��ü�� �� �ٷ� �ޱ�
    printf("Input: \n");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("ERROR\n");
        return 0;
    }

    ptr = input;
	printf("Output: \n");
    int result = parseTree();

    skipSpaces();
    if (*ptr != '\0' && *ptr != '\n') {
        // �Է� ���� ���ʿ��� ���ڰ� ���������� ����
        printf("ERROR\n");
        return 0;
    }

    if (result == TRUE) printf("TRUE\n");
    else if (result == FALSE) printf("FALSE\n");
    else printf("ERROR\n");

    return 0;
}