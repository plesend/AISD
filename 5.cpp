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
        cout << "Стек переполнен";
        return;
    }
    S.data[S.size] = x;
    S.size++;
}

char Pop(Stack& S)
{
    if (S.size == 0) {
        cout << "Стек пуст";
        return char(255);
    }
    S.size--;
    return S.data[S.size];
}

int main()
{
    setlocale(0, "");
    char leftBracket[3] = { '(', '[', '{' }; // открывающие скобки
    char rightBrackets[3] = { ')', ']', '}' }; // закрывающие скобки
    char s[80], upper;

    int i, k, OK;
    Stack S; //стек символов
    cout << "Введите выражение со скобками: \n";
    cin >> s;
    S.size = 0; //сначала стек пуст
    OK = 1;
    for (i = 0; OK && (s[i] != '\0'); i++)
        for (k = 0; k < 3; k++) { //проверить 3 вида скобок
            if (s[i] == leftBracket[k]) { // открывающая скобка
                Push(S, s[i]);
                break;
            }
            if (s[i] == rightBrackets[k]) { // закрывающая скобка
                upper = Pop(S);
                if (upper != leftBracket[k])
                    OK = 0;
                break;
            }
        }
    if (OK && (S.size == 0))
        cout << "\nВыpажение пpавильное\n";
    else
        cout << "\nВыpажение непpавильное \n";

    return 0;
}