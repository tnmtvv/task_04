

#include <iostream>
#include <ctime>
#include <locale.h>

struct element_t {
    int value;
    struct element_t* next;
};

typedef struct element_t element;

void push(element *newone, element* head)
{
    newone->next = head->next;
    head->next = newone;
}

void before(element* given,element* prev, element* newone)
{
    
    newone->next = given;
    prev->next = newone;
}

void after(element *given, element *next, element *newone) {

    newone->next = next;
    given->next = newone;
}

void end(element* newone, element* head)
{
    element* tmp =head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newone;
    newone->next = NULL;
}

element* pop(element* head, element* first)
{
    head->next = first->next;
    return first;
}

void deleteel(element *prev, element* next)
{
    prev->next = next;
}

void deletelastel(element* notlast)
{
    notlast->next = NULL;
}

element *create_new_element(int val) {
    element* result = (struct element_t*)malloc(sizeof(element));
    result->value = val;
    result->next = NULL;

    return result;
}

void create_list(element* head) 
{
    element* tmp;
    element* tmp_1 = head;

    for (int i = 0; i < 10; i++) {
        tmp = create_new_element(rand() % 10 + 1);
        tmp_1->next = tmp;
        tmp_1 = tmp;
    }
}

void printlist(element* begin) {
    
    element* tmp = begin;

    while (tmp->next!=NULL)
    {

        printf_s("%d->", tmp->value);

        tmp = tmp->next;
    }
    printf_s("%d", tmp->value);
}

element* search_for_el(int val, element* head, int before)
{
    element* tmp = head;

    while (tmp->next != NULL)
    {
        if (before == 0) {
            if (tmp->value == val) {
                return tmp;
            }
        }
        else if (tmp->next->value == val) {
            return tmp;
        }
        tmp = tmp->next;
    }
    if (tmp->value == val)
        return tmp;
    return NULL;
}

int individual_task(element* head) {

    element* tmp = head;

    int sum = 0;
    while (tmp->next != NULL) {
        if (tmp->next->value > tmp->value)
            sum += tmp->value;
        tmp = tmp->next;
    }

    return sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    int choice = 5;
    int choice2;
    int val;
    int val2;

    srand(static_cast<unsigned int>(time(0)));

    element* head = (struct element_t*)malloc(sizeof(element));
    element* el = (struct element_t*)malloc(sizeof(element));

    head->value = 0;
    head->next = NULL;
    element* newone = (struct element_t*)malloc(sizeof(element));
    newone->next = NULL;

    create_list(head);
    printlist(head);

    while(choice !=0){

    printf("\nКакую функцию следует реализовать? 1-добавить, 2-удалить, 3-индивидуальное задание\n");
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        printf_s("введите значение нового элемента\n");
        scanf_s("%d", &val);

        newone = create_new_element(val);

        printf("1-в начало, 2-до заданного элемента, 3-после заданного элемента, 4-в конец \n");
        scanf_s("%d", &choice2);

        switch (choice2)
        {

        case 1:
            push(newone, head);
            printlist(head);
            break;

        case 2:
            if (head->next == NULL) {
                printf_s("Список еще пуст, добавьте элемент в начало\n");
                
            }
            else {
                printf_s("введите значение искомого элемента\n");
                scanf_s("%d", &val);

                el = search_for_el(val, head, 1);

                before(el->next, el, newone);
                printlist(head);
            }
            break;

        case 3:
            if (head->next == NULL)
            {
                printf_s("Список еще пуст, добавьте элемент в начало\n");

            }
            else {
                printf_s("введите значение искомого элемента\n");
                scanf_s("%d", &val);

                el = search_for_el(val, head, 0);

                after(el, el->next, newone);
                printlist(head);
            }
            break;
        case 4:
            end(newone, head);
            printlist(head);

            break;
        }
        break;
    case 2:
        if (head->next == NULL)
        {
            printf_s("Список еще пуст, добавьте элемент в начало\n");

        }
        else 
        {
            printf("1-из начала, 2-заданный элемент, 3-из конца\n ");
            scanf_s("%d", &choice2);

            switch (choice2)
            {
            case 1:

                pop(head, head->next);
                printlist(head);
                break;

            case 2:
                printf_s("введите значение искомого элемента\n");
                scanf_s("%d", &val);
                el = search_for_el(val, head, 1);
                deleteel(el, el->next->next);
                printlist(head);
                break;

            case 3:
                el = head;

                while (el->next->next != NULL) {
                    el = el->next;
                }
                deletelastel(el);
                printlist(head);
                break;
            }
        }
        break;
    case 3:
        printf_s("сумма элементов, стого меньших следующих за ними:");
        printf_s("\n%d",individual_task(head));
        break;
    }

    }


}

