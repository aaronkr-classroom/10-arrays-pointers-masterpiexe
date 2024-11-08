#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // isdigit()

// ������ Ȯ�� �Լ�
int checkOp(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// ���� Ȯ�� �Լ�
int numCheck(char ch) {
    return ch >= '0' && ch <= '9';
}

// ���ڿ��� ������ ��ȯ�ϴ� �Լ�
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

    // ù ��° ���� ����
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr1[j++] = input[i++];
    }
    numStr1[j] = '\0';  // ���� ���� null terminator �߰�

    // ������ Ȯ��
    if (checkOp(input[i])) {
        operator = input[i++];
    }
    else {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    // �� ��° ���� ����
    j = 0;  // numStr2 �ε��� �ʱ�ȭ
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr2[j++] = input[i++];
    }
    numStr2[j] = '\0';  // ���� ���� null terminator �߰�

    // ���� ���ڿ��� ������ ��ȯ
    int num1 = arrayToInt(numStr1);
    int num2 = arrayToInt(numStr2);

    // ���� ����
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

    // ��� ���
    printf("Result: %d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}
