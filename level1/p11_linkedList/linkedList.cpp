#include <iostream>
using namespace std;
struct storeinteger
{
    int stored;
    struct storeinteger * next;
};
void rev(struct storeinteger * current);
int main()
{
    struct storeinteger * head, * current, * prev;
    head = NULL;
    cout << "Put the number you want to store in a row:\n";
    //读入(一行用空格隔开，提行即停止)
    int read;
    while (cin >> read)
    {
        current = (struct storeinteger *)malloc(sizeof(struct storeinteger));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        current->stored = read;
        prev = current;
        char c = cin.get();
        if(c == '\n')
            break;
    }
    //显示
    cout << "The numbers you put in are:";
    current = head;
    while (current != NULL)
    {
        cout << current->stored << ' ';
        current = current->next;
    }
    cout << endl;
    //节点反序
    cout << "The numbers you put in are(reversed):";
    current = head;
    rev(current);
    head->next = NULL;
    struct storeinteger * temp;
    temp = head;
    head = prev;
    prev = temp;//交换head和prev
    current = head;
    while (current != NULL)
    {
        cout << current->stored << ' ';
        current = current->next;
    }
    cout << endl;
    //查找节点
    cout << "The position of the first 5:";
    int position = 0;
    current = head;
    while (current->stored != 5)
    {
        current = current->next;
        position++;
    }
    cout << position+1 << endl;
    cout << "The position of the second 5:";
    current = current->next;
    position++;
    while (current->stored != 5)
    {
        current = current->next;
        position++;
    }
    cout << position+1 << endl;
    //释放空间
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    return 0;
}

void rev(struct storeinteger * current)
{
    if (current->next->next != NULL)
        rev(current->next);
    current->next->next = current;
}