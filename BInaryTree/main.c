#include"BinaryTree.h"

int main() {
    char input[1000];
    // 입력 전체를 한 줄로 받기
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
        // 입력 끝에 불필요한 문자가 남아있으면 에러
        printf("ERROR\n");
        return 0;
    }

    if (result == TRUE) printf("TRUE\n");
    else if (result == FALSE) printf("FALSE\n");
    else printf("ERROR\n");

    return 0;
}