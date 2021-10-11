#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
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
    newNode->link = NULL;
    printf("created newNode %d\n", newNode->data);
    return newNode;
}

ListNode* insert_last(LinkedList* list, element data){
    ListNode *newNode = node_init(data);
    ListNode *headNode = list->head;
    ListNode *selectNode = list->head;
    if(list->head == NULL){
        // selectNode = newNode;를 하면 안됨에 주의!
        list->head = newNode;
        // 자기 자신을 가리킴
        newNode->link = newNode;
    }else{
        while(selectNode->link != headNode){
            selectNode = selectNode->link;
            if(selectNode->link == headNode){
                //처음으로 돌아온 경우 종료
                break;
            }
        }
        // 마지막 노드의 next를 newNode로 설정
        selectNode->link = newNode;
        // 새로운 노드의 next를 head로 설정
        newNode->link = list->head;
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
        while(selectNode->link != NULL){
            selectNode = selectNode->link;
            if(selectNode->link == headNode){
                //처음으로 돌아온 경우 종료
                break;
            }
        }
        // 마지막 노드의 next를 newNode로 설정
        selectNode->link = newNode;
        // newNode를 가장 앞에 추가
        newNode->link = list->head;
        // 가장 앞의 노드 갱신
        list->head = newNode;
    }
    list->size++;
    return newNode;
}

void print_list(LinkedList *list){
    ListNode *headNode = list->head;
    ListNode *selectNode = list->head;
    while(selectNode != NULL){
        printf("%d", selectNode->data);
        selectNode = selectNode->link;
        if(selectNode == headNode){
            //처음으로 돌아온 경우 종료
            break;
        }
        if(selectNode != NULL){
            printf("-> ");
        }
    }
    printf("\n");
}

void print_node(ListNode *node){
    printf("%d\n", node->data);
}

ListNode* search_node(LinkedList* list, element data){
    ListNode *headNode = list->head;
    ListNode *selectNode = list->head;
    while(selectNode != NULL){
        if(selectNode->data == data){
            return selectNode;
        }
        selectNode = selectNode->link;
        if(selectNode == headNode){
            //처음으로 돌아온 경우 종료
            break;
        }
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
    // 데이터가 없는 경우
    if(list->head == NULL){
        return list->head;
    }

    // 데이터가 하나만 있는 경우
    if(list->head->link == NULL){
        free_node(list->head);
        list->head = NULL;
    }else{
        // 데이터가 여러개 있는 경우
        ListNode *prevNode = NULL; // 가장 마지막에서 두 번째
        ListNode *headNode = list->head;
        ListNode *selectNode = list->head; // 가장 마지막 노드

        while(selectNode->link != NULL){
            prevNode = selectNode;
            selectNode = selectNode->link;
            if(selectNode->link == headNode){
                break;
            }
        }
        free_node(selectNode);
        // 마지막 노드의 next를 head로
        prevNode->link = list->head;
    }
    list->size--;
    return list->head;
}

ListNode* delete_first(LinkedList* list){
    // 데이터가 없는 경우
    if(list->head == NULL){
        return list->head;
    }

    // 데이터가 하나만 있는 경우
    if(list->head->link == NULL){
        free_node(list->head);
        list->head = NULL;
    }else{
        // 마지막 노드 찾기
        ListNode *headNode = list->head;
        ListNode *lastNode = list->head; // 가장 마지막 노드
        while(lastNode->link != NULL){
            lastNode = lastNode->link;
            if(lastNode->link == headNode){
                break;
            }
        }
        // head 갱신
        ListNode *selectNode = list->head;
        list->head = selectNode->link;
        // 마지막 노드의 link 갱신
        lastNode->link = list->head;
        free_node(selectNode);
    }
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
