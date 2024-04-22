#include <iostream>
#include <string.h>
using namespace std;

const int MAXSIZE = 100;
struct Stack
{
    char data[MAXSIZE];
    int size;
};

void Push(Stack& S, char x)
{
    if (S.size == MAXSIZE) {
        cout << "���� ����������";
        return;
    }
    S.data[S.size] = x;
    S.size++;
}

char Pop(Stack& S)
{
    if (S.size == 0) {
        cout << "���� ����";
        return char(255);
    }
    S.size--;
    return S.data[S.size];
}

int main()
{
    setlocale(0, "");
    char leftBracket[3] = { '(', '[', '{' }; // ����������� ������
    char rightBrackets[3] = { ')', ']', '}' }; // ����������� ������
    char s[80], upper;

    int i, k, OK;
    Stack S; //���� ��������
    cout << "������� ��������� �� ��������: \n";
    cin >> s;
    S.size = 0; //������� ���� ����
    OK = 1;
    for (i = 0; OK && (s[i] != '\0'); i++)
        for (k = 0; k < 3; k++) { //��������� 3 ���� ������
            if (s[i] == leftBracket[k]) { // ����������� ������
                Push(S, s[i]);
                break;
            }
            if (s[i] == rightBrackets[k]) { // ����������� ������
                upper = Pop(S);
                if (upper != leftBracket[k])
                    OK = 0;
                break;
            }
        }
    if (OK && (S.size == 0))
        cout << "\n��p������ �p��������\n";
    else
        cout << "\n��p������ ���p�������� \n";

    return 0;
}