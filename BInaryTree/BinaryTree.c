/*
입력 문자열 공백 제거 -> 줄바꿈이 있으면 ERROR
재귀 파싱 함수 parsNode() -> 현재 포인터가 (이면 
그 안에서 노드를 읽음 -> 자식 노드가 2개 초과하면 FALSE 반환
) 만나면 종료. 현재 포인터가 영문자이면 -> 한글자 소비하고 return
현재포인터가 ()이면 null 자식 -> 허용
*/
#include "BinaryTree.h"

char* ptr; //입력 문자열을 탐색할 전역 포인터
void skipSpaces()
{
    //문자형 포인터 ptr이 마지막은 0값 이기에 
    //isspace는 공백이면 0 아니면 0 이외의 수
    // 비어있는 값을 가리키지 않고 공백이 아니면 ptr ++ 실행 반복
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
}

int parseTree() { // 트리 파싱 함수
    skipSpaces(); //공백 건너뛰기

    if (*ptr != '(') return ERROR;
    ptr++; // '(' 로 시작 안하면 ERROR -> 문법 오류

    skipSpaces();

    // 빈 괄호 처리
    if (*ptr == ')') {
		ptr++; // ')' 이면 TRUE 반환 (빈 트리)
        return TRUE;
    }

    int children = 0; //자식 노드 개수 0으로 초기화
    int res; //res 결과 변수 생성

	while (*ptr != ')' && *ptr != '\0') { //')' 또는 문자열 끝까지 반복
        if (isalpha(*ptr)) { //영문자이면
            ptr++; //다음 문자로 이동
            children++; //자식 노드 개수 증가
            if (children > 2) res = FALSE; // 자식 3개 이상 → FALSE
			else res = TRUE; // 자식 2개 이하 → TRUE
        }
        else if (*ptr == '(') { // '(' 이면 다시 재귀 호출
            res = parseTree(); //res 변수에 재귀 호출한 결과를 저장
            if (res == ERROR) return ERROR; //재귀 호출할때 ERROR 시 ( 시작 할떄 '(' 가 아닐때 ERROR
			children++; //res가 ERROR가 아니면 자식 노드 개수 증가
			if (children > 2) res = FALSE; // 자식 3개 이상 → FALSE
        }
		else if (isspace(*ptr)) { //공백이면 건너뛰기
            ptr++;
            continue;
        }
        else {
            return ERROR; // 알 수 없는 문자
        }
        skipSpaces();
    }

    if (*ptr != ')') return ERROR;
	ptr++; // ')' 로 끝나지 않으면 ERROR -> 문법 오류

	return (children > 2) ? FALSE : TRUE; // 자식 3개 이상 → FALSE, 아니면 TRUE
}

