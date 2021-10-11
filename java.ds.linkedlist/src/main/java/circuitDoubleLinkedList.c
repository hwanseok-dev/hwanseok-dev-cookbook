#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    element size;
} LinkedList;


LinkedList* list_init(void);
ListNode* node_init(element data);
ListNode* insert_last(LinkedList* list, element data);
ListNode* insert_first(LinkedList* list, element data);
void print_list(LinkedList *list);
void print_node(ListNode *node);

void free_node(ListNode* node);
ListNode* delete_last(LinkedList* list);
ListNode* delete_first(LinkedList* list);

ListNode* search_node(LinkedList* list, element data);
int get_size(LinkedList* list);



LinkedList* list_init(void){
    LinkedList * newList;
    newList = (LinkedList*) malloc (sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    printf("created newList with size %d\n", newList->size);
    return newList;
}

ListNode* node_init(element data){
    ListNode * newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("created newNode %d\n", newNode->data);
    return newNode;
}

ListNode* insert_last(LinkedList* list, element data){
    ListNode *newNode = node_init(data);
    if(list->head == NULL){
        // selectNode = newNode;를 하면 안됨에 주의!
        list->head = newNode;
        // 자기 자신을 가리킴
        newNode->prev = newNode;
        newNode->next = newNode;
    }else{
        // list->head : 첫 번째 노드
        // list->head->prev : 마지막 노드

        // 2 : 새로운 노드의 prev를 마지막 노드로 설정
        newNode->prev = list->head->prev;
        // 3 : 새로운 노드의 next를 첫번째 노드로 설정
        newNode->next = list->head;

        // 1 : 마지막 노드의 next를 새로운 노드로 설정
        list->head->prev->next = newNode;
        // 4 : 첫 번째 노드의 prev를 새로운 노드로 설정
        list->head->prev = newNode;
    }
    list->size++;
    return newNode;
}

ListNode* insert_first(LinkedList* list, element data){
    ListNode *newNode = node_init(data);
    ListNode *headNode = list->head;
    ListNode *selectNode = list->head;
    if(list->head == NULL){
        list->head = newNode;
    }else{
        // list->head : 첫 번째 노드
        // list->head->prev : 마지막 노드

        // 새로운 노드 연결
        newNode->prev = list->head->prev;
        newNode->next = list->head;

        list->head->prev->next = newNode;
        list->head->prev = newNode;
    }
    list->size++;
    return newNode;
}

void print_list(LinkedList *list){
    ListNode *selectNode = list->head;
    int i;
    for(i=0; i<list->size; i++) {
        printf("%d",selectNode->data);
        selectNode = selectNode->next;
        if(i != list->size-1) {
            printf("->");
        }
    }
    printf("\n");
}

void print_node(ListNode *node){
    printf("%d\n", node->data);
}

ListNode* search_node(LinkedList* list, element data){
    ListNode *selectNode = list->head;
    int i;
    for(i=0; i<list->size; i++) {
        if(selectNode->data == data){
            return selectNode;
        }
        selectNode = selectNode->next;
    }
    return NULL;
}

int get_size(LinkedList* list){
    printf("list size is %d\n", list->size);
    return list->size;
}

void free_node(ListNode* node){
//    element 타입에 free가 필요한 경우만
//    free(node->data);
    free(node);
}

ListNode* delete_last(LinkedList* list){
    ListNode* selectNode = list->head;

    // 데이터가 없는 경우
    if (list->head == NULL) return list->head;

    // 데이터가 하나만 있는 경우
    if (list->head->next == list->head) {
        list->head = NULL;
    }
    // 데이터가 2개 있는 경우
    else if(list->head->next == list->head->prev) {
        selectNode = list->head->next;
        list->head->next = list->head;
        list->head->prev = list->head;
    }
    // 데이터가 3개 이상 있는 경우
    else {
        selectNode = list->head->prev;
        list->head->prev = list->head->prev->prev;
        list->head->prev->next = list->head;
    }
    free_node(selectNode);
    list->size--;
    return list->head;
}

ListNode* delete_first(LinkedList* list){
    ListNode* selectNode = list->head;

    // 데이터가 없는 경우
    if (list->head == NULL) return list->head;

    // 데이터가 하나만 있는 경우
    if (list->head->next == list->head) {
        list->head = NULL;
    }
    // 데이터가 2개 있는 경우
    else if(list->head->next == list->head->prev) {
        // 삭제할 노드 지정
        selectNode = list->head;
        // 헤드 옮기기
        list->head = list->head->next;
        // 자기 자신 가리키도록 변경
        list->head->prev = list->head;
        list->head->next = list->head;
    }
    // 데이터가 3개 이상 있는 경우
    else {
        // head 한 칸 이동
        list->head = list->head->next;

        // delete_last와 같음
        selectNode = list->head->prev;
        list->head->prev = list->head->prev->prev;
        list->head->prev->next = list->head;
    }
    free_node(selectNode);
    list->size--;
    return list->head;
}

int main(void){
    LinkedList * list = list_init();
    ListNode *head = NULL;
    head= insert_last(list, 20); print_list(list);
    head= insert_last(list, 30); print_list(list);
    head= insert_last(list, 40); print_list(list);
    head= search_node(list, 40); print_node(head);
    get_size(list);
    head= insert_first(list, 10); print_list(list);

    head= delete_last(list); print_list(list);
    head= delete_first(list); print_list(list);

    head= search_node(list, 30); print_node(head);
    return 0;
}
