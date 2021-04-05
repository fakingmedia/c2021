#include <iostream>
#include <string>
using namespace std;
struct goods
{
    int type;
    int quantity;
    struct goods * next;
};
int main()
{
    struct goods * head=NULL, * current, * prev=NULL;
    char choice;
    printf("Here is the centrol controller of a warehouse.\n");
    printf("Input 's' to show all the goods, 'i' to store goods, 'o' to offstore goods and 'q' to exit.\n");;
    cin >> choice;
    while (choice != 'q')
    {
        switch (choice)
        {
            case 's':
            {
                current = head;
                int num=0;
                while (current != NULL)
                {
                    num++;
                    cout << num << ":\t" << current->type << "\t" << current->quantity << endl;
                    current = current->next;
                }
            }
                break;
            case 'i':
            {
                int TempType1;
                int TempQuantity1;
                cout << "Input the goods you want to store(its name(using number) and quantity)\n";
                cin >> TempType1 >> TempQuantity1;
                current = head;
                prev = NULL;
                while (1)
                {
                    if (current == NULL)
                    {
                        current = (struct goods *)malloc(sizeof(struct goods));
                        if (head == NULL)
                            head = current;
                        else
                            prev->next = current;
                        current->quantity = TempQuantity1;
                        current->type = TempType1;
                        prev = current;
                        current->next = NULL;
                        break;
                    }
                    else if (current->type == TempType1)
                    {
                        current->quantity += TempQuantity1;
                        break;
                    }
                    else
                    {
                        prev = current;
                        current = current->next;
                    }
                }
            }
                break;
            case 'o':
            {
                current = head;
                prev = NULL;
                int TempType2;
                int TempQuantity2;
                cout << "Input the goods you want to offstore(its name and quantity)\n";
                cin >> TempType2 >> TempQuantity2;
                while (1)
                {
                    if (current == NULL)
                        break;
                    else if (current->type == TempType2)
                    {
                        if (TempQuantity2 < current->quantity)
                            current->quantity -= TempQuantity2;
                        else
                        {
                            if (current == head)
                            {
                                head = current->next;
                                free(current);
                            }
                            else
                            {
                                prev->next = current->next;
                                free(current);
                            }
                        }
                        break;
                    }
                    else
                    {
                        prev = current;
                        current = current->next;
                    }
                }
            }
                break;
            default:
                break;
        }
        printf("Input 's' to show all the goods, 'i' to store goods, 'o' to offstore goods and 'q' to exit.\n");;
        cin >> choice;
    }
    cout << "Good bye!\n";
    //释放数据
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }

    return 0;
}
