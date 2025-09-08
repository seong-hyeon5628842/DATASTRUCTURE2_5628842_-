#include"BinaryTree.h"


int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // ¡ŸπŸ≤ﬁ ∞ÀªÁ
    for (int i = 0; input[i]; i++) {
        if (input[i] == '\n' && input[i + 1] != '\0') {
            printf("ERROR\n");
            return 0;
        }
    }

    ptr = input;
    int result = parseTree();

    skipSpaces();
    if (*ptr != '\0' && *ptr != '\n') result = ERROR;

    if (result == TRUE) printf("TRUE\n");
    else if (result == FALSE) printf("FALSE\n");
    else printf("ERROR\n");

    return 0;
}