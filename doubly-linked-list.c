#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* llink;//오른쪽 링크
    struct Node* rlink;//왼쪽 링크
} listNode;

typedef struct Head{//헤드노드
    struct Node* first;
} headNode;

int initialize(headNode** h);

int freeList(headNode* h);

int insertNode(headNode* h,int key);
int insertLast(headNode* h,int key);
int insertFirst(headNode* h,int key);
int deleteNode(headNode* h,int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode *h);

int main(){
    char command;
    int key;
    headNode* headnode=NULL;

    do{
        printf("2019038042 이도경\n");
        printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

        printf("Command=");
        scanf("%c",&command);
        
        switch(command){
        case 'z':case'Z':
            initialize(&headnode);
            break;
        case 'p':case'P':
            printList(headnode);
            break;
        case 'i':case 'I':
            printf("Your Key=");
            scanf("%d",&key);
            insertNode(headnode,key);
            break;
        case 'd':case 'D':
            printf("Your Key=");
            scanf("%d",&key);
            deleteNode(headnode,key);
            break;
        case 'n':case 'N':
            printf("Your Key=");
            scanf("%d",&key);
            insertLast(headnode,key);
            break;
        case 'e':case'E':
            deleteLast(headnode);
            break;
        case 'f':case 'F':
            printf("Your key=");
            scanf("%d",&key);
            insertFirst(headnode,key);
            break;
        case 't':case 'T':
            deleteFirst(headnode);
            break;
        case 'r':case 'R':
            invertList(headnode);
            break;
        case 'q':case 'Q':
            freeList(headnode);
            break;
        default:
            printf("\n\t\t>>>>>\tConcentration!\t<<<<<\t\t\n");
            break;
        }
    }while(command!='q' && command !='Q');

    return 1;
}

/* note: initialize는 이중포인터를 매개변수로 받음
         lab3의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h){

    if(*h!=NULL)//헤드가 NULL이 아니면 freeNode를 호출 할당된 메모리 모두 해제
        freeList(*h);
    //headNode 메모리 할당
    *h=(headNode*)malloc(sizeof(headNode));
    (*h)->first=NULL;
    return 1;
}

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
         - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h){
    listNode* p=h->first;

    listNode* prev=NULL;
    while(p!=NULL){ //p가 다 초기화될때까지 반복
        prev=p; //헤드부터 초기화시작
        p=p->rlink;
        free(prev);
    }
    free(h);//헤드노드도 메모리 할당해제
    return 0;
}

void printList(headNode* h){
    int i=0;
    listNode* p;

    printf("\n---PRINT\n");

    if(h==NULL){
        printf("nothing to print\n");
        return;
    }

    p=h->first;
//NULL이 나올때까지(마지막값까지) 노드값 출력
    while(p!=NULL){
        printf("[ [%d]=%d ]",i,p->key);
        p-p->rlink;
        i++;
    }

    printf("\titems=%d\n",i);
}

int insertLast(headNode* h,int key){

    listNode* node=(listNode*)malloc(sizeof(listNode));
    node->key=key;
    node->rlink=NULL;
    node->llink=NULL;

//헤드노드값이 없으면 헤드노드에 삽입
    if(h->first==NULL)
    {
        h->first=node;
        return 0;
    }


    listNode* n=h->first;
    while(n->rlink!=NULL){//마지막값 검색
        n=n->rlink;
    }
    n->rlink=node;//노드연결
    node->llink=n;
    return 0;
}

int deleteLast(headNode* h){

    if(h->first==NULL)
    {
        printf("nothing to delete.\n");
        return 0;
    }

    listNode* n=h->first;
    listNode* trail=NULL;

    if(n->rlink!=NULL){//rlink가 NULL이면 마지막노드
        trail=n;
        n=n->rlink;
    }

    trail->rlink=NULL;//trail은 전노드이므로 rlink를 NULL로 만들어 link를 없애줌
    free(n);

    return 0;
}

int insertFirst(headNode* h,int key){
    
    listNode* node=(listNode*)malloc(sizeof(listNode));
    node->key=key;
    node->rlink=node->llink=NULL;

    if(h->first==NULL)
    {
        h->first=node;
        return 1;
    }

//node를 새로운 head로 연결
    node->rlink=h->first;
    node->llink=NULL;

    listNode *p=h->first;
    p->llink=node;
    h->first=node;

    return 0;
}

int deleteFirst(headNode* h){

    if(h->first==NULL)
    {
        printf("nothing to delete.\n");
        return 0;
    }

    listNode* n=h->first;
    h->first=n->rlink;

    free(n);

    return 0;
}

int invertList(headNode* h){

    if(h->first==NULL){
        printf("nothing to invert\n");
        return 0;
    }
    listNode *n=h->first;
    listNode *trail=NULL;
    listNode *middle=NULL;

    while(n!=NULL){//n이 NULL이 나올때까지 노드를 역순으로 바꿔줌
        trail=middle;
        middle=n;
        n=n->rlink;
        middle->rlink=trail;
        middle->llink=n;
    }

    h->first=middle;
}

int insertNode(headNode* h,int key){

    listNode* node=(listNode*)malloc(sizeof(listNode));
    node->key=key;
    node->llink=node->rlink=NULL;

    if(h->first==NULL)
    {
        h->first=node;
        return 0;
    }

    listNode* n=h->first;

    while(n!=NULL){
        if(n->key>=key){
            if(n==h->first){//첫노드인지 확인
                insertFirst(h,key);
            }else {//중간이거나 마지막인경우
                node->rlink=n;
                node->llink=n->llink;
                n->llink->rlink=node;
            }
            return 0;
        }

        n=n->rlink;
    }

    insertLast(h,key);
    return 0;
}

int deleteNode(headNode* h,int key){

    if(h->first==NULL)
    {
        printf("nothing to delete.\n");
        return 1;
    }

    listNode* n=h->first;

    while(n!=NULL){
        if(n->key==key){
            if(n==h->first){
            deleteFirst(h);
        }else if(n->rlink==NULL){
            deleteLast(h);
            //중간인경우
        }else{
            n->llink->rlink=n->rlink;
            n->rlink->llink=n->llink;
            free(n);
        }
        return 1;
    }

    n=n->rlink;
    }

    printf("cannot find the node for key=%d\n",key);
    return 1;
}






