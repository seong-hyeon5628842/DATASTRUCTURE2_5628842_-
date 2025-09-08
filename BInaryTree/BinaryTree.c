/*
입력 문자열 공백 제거 -> 줄바꿈이 있으면 ERROR
재귀 파싱 함수 parsNode() -> 현재 포인터가 (이면 
그 안에서 노드를 읽음 -> 자식 노드가 2개 초과하면 FALSE 반환
) 만나면 종료. 현재 포인터가 영문자이면 -> 한글자 소비하고 return
현재포인터가 ()이면 null 자식 -> 허용
*/
#include "BinaryTree.h"


void skipSpaces()
{
    //문자형 포인터 ptr이 마지막은 0값 이기에 
    //isspace는 공백이면 0 아니면 0 이외의 수
    // 비어있는 값을 가리키지 않고 공백이 아니면 ptr ++ 실행 반복
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
}

int parseTree() {
    skipSpaces();

    if (*ptr != '(') return ERROR;
    ptr++; // '(' 지나가기

    skipSpaces();

    // 빈 괄호 처리
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
            if (children > 2) res = FALSE; // 자식 3개 이상 → FALSE
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
            return ERROR; // 알 수 없는 문자
        }
        skipSpaces();
    }

    if (*ptr != ')') return ERROR;
    ptr++;

    return (children > 2) ? FALSE : TRUE;
}

