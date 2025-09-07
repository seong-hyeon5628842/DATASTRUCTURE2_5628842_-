#include "BinaryTree.h"


void skipSpaces()
{
    //문자형 포인터 ptr이 마지막은 0값 이기에 
    //isspace는 공백이면 0 아니면 0 이외의 수
    // 비어있는 값을 가리키지 않고 공백이 아니면 ptr ++ 실행 반복
    while (*ptr && isspace(*ptr)) ptr++;
}

// 트리 전체 파싱 시작
int parseTree()
{
    skipSpaces();//공백 검사
    if (*ptr != '(') return ERROR; // 트리는 반드시 '('로 시작 그렇지 않으면 ERROR
    int result = parseNode(); //result 에 노드 파싱 함수 저장
    skipSpaces();
    if (*ptr != '\0') return ERROR; // 문자열 끝까지 읽었는지 확인
    return result;
}

// 노드 파싱
int parseNode()
{
    skipSpaces();
    if (*ptr != '(') return ERROR;
    ptr++; // '(' 사용 후 다음 문장으로 이동

    skipSpaces();

    // 빈 괄호
    if (*ptr == ')') {
        ptr++; // ')' 소비
        return TRUE;
    }

    // 노드 레이블 체크
    if (!isalpha(*ptr)) return ERROR;
    ptr++;

    // 자식 노드 파싱
    int childResult = parseChildren();
    if (childResult == ERROR) return ERROR; // 문법 오류 발생
    // 자식 노드가 이진트리 규칙 위반이면 FALSE 반환
    int isBinary = (childResult == TRUE) ? TRUE : FALSE; //childResult 가 TRUE이면 TRUE 아니면 FALSE 로 나오는 값을 isBinary에 저장

    skipSpaces();
    if (*ptr != ')') return ERROR; // 노드 닫는 ')' 확인 
    ptr++; // ')' 소비

    return isBinary;
}

// 자식 노드 파싱
int parseChildren()
{
    int childCount = 0;
    int isBinary = TRUE;

    while (1) {
        skipSpaces();
        if (*ptr == '(') { // 자식 존재
            childCount++;
            int res = parseNode();
            if (res == ERROR) return ERROR; // 문법 오류
            if (res == FALSE) isBinary = FALSE; // 하위 규칙 위반

            if (childCount > 2) isBinary = FALSE; // 이진트리 규칙 위반
        }
        else break; // 더 이상 자식 없음
    }

    return isBinary ? TRUE : FALSE;
}
