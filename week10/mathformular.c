#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // isdigit()

// 연산자 확인 함수
int checkOp(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// 숫자 확인 함수
int numCheck(char ch) {
    return ch >= '0' && ch <= '9';
}

// 문자열을 정수로 변환하는 함수
int arrayToInt(char str[]) {
    int i = 0, num = 0;
    while (str[i] != '\0') {
        if (numCheck(str[i])) {
            num = num * 10 + (str[i] - '0');
        }
        else {
            break;
        }
        i++;
    }
    return num;
}

int main() {
    char input[100], numStr1[50], numStr2[50], operator = '\0';
    int i = 0, j = 0, result = 0;

    printf("Enter a simple math formula (e.g., 12+34):\n");
    fgets(input, sizeof(input), stdin);

    // 첫 번째 숫자 추출
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr1[j++] = input[i++];
    }
    numStr1[j] = '\0';  // 숫자 끝에 null terminator 추가

    // 연산자 확인
    if (checkOp(input[i])) {
        operator = input[i++];
    }
    else {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    // 두 번째 숫자 추출
    j = 0;  // numStr2 인덱스 초기화
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr2[j++] = input[i++];
    }
    numStr2[j] = '\0';  // 숫자 끝에 null terminator 추가

    // 숫자 문자열을 정수로 변환
    int num1 = arrayToInt(numStr1);
    int num2 = arrayToInt(numStr2);

    // 연산 수행
    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            printf("Error: Division by zero!\n");
            return 1;
        }
        break;
    default:
        printf("Error: Invalid operator!\n");
        return 1;
    }

    // 결과 출력
    printf("Result: %d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}
