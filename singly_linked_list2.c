#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;//노드 속 데이터가 들어갈 공간
    struct Node* link;//노드들을 이을 링크
}listNode;

//제일 앞에 있는 노드
typedef struct Head{
    struct Node* first;
}headNode;

headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("2019038042 이도경\n");
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

//헤드 노드 초기화
headNode* initialize(headNode* h){
    if(h!=NULL)//헤드노드가 초기화 안되어있으면
        freeList(h);//모든 노드 메모리해제
    headNode* temp=(headNode*)malloc(sizeof(headNode));
    temp->first=NULL;//헤드노드를 초기화
    return temp;//초기화된 템프헤드노드를 새로운 헤드로 만들어줌
}

//노드 메모리해제
int freeList(headNode* h){

listNode* p=h->first;//첫번째 노드

listNode* prev=NULL;//다음노드
while(p!=NULL){ //초기화가 되어있지 않으면
    prev=p;//다음노드
    p=p->link;//다음 노드로 옮김
    free(prev);//검사한 노드를 메모리해제해줌
}
free(h);//메모리해제 후 헤드 노드도 메모리해제해줌
return 0;
}

//노드를 삽입하자
int insertNode(headNode* h,int key){

    listNode* node=(listNode*)malloc(sizeof(listNode));
    node->key=key;//삽입할 값
    node->link=NULL;//아직 연결되기전이니 NULL을 넣어줌

    if(h->first==NULL)//노드값이 없으니 삽입할 노드가 첫번쨰로 감
    {
        h->first=node;
        return 0;
    }

    listNode* n=h->first;
    listNode* trail=h->first;

    while(n!=NULL){
        if(n->key<=key){
            if(n==h->first){//헤드노드가 삽입할 값과 같다면 헤드노드와 키값을 연결
                h->first=node;
                node->link=n;
            }
            else{//나머지 경우들에 경우
                node->link=n;
                trail->link=node;
            }
        return 0;
        }
        trail=n;
        n=n->link;
    }
	//위에서 노드를 연결하지 못했을경우 마지막에 연결
    trail->link=node;
    return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;
//헤드가 빈경우 그냥 삽입
	if (h->first == NULL)
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	while(n->link != NULL) {//마지막노드가 될때까지 확인 후 NULL이면 뒤에 노드연결
		n = n->link;
	}
	n->link = node;
	return 0;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = NULL;

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {
		if(n->key == key) {
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {
				h->first = n->link;
			} else { /* 중간인 경우거나 마지막인 경우 */
				trail->link = n->link;
			}
			free(n);
			return 0;
		}

		trail = n;
		n = n->link;
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = NULL;

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) {
		h->first = NULL;
		free(n);
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) {
		trail = n;
		n = n->link;
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL;
	free(n);

	return 0;
}
/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;

	h->first = n->link;
	free(n);

	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {


	if(h->first == NULL) {
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;//역순으로 만들 리시트
	listNode *trail = NULL;//역순으로 만들 노드
	listNode *middle = NULL;//역순으로 된 리스트

	while(n != NULL){
		trail = middle;//middle->trail,trail->n순으로 따라감
		middle = n;
		n = n->link;
		middle->link = trail;//trail의 링크방향을 바꿔줌
	}

	h->first = middle;

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {//순서대로 출력
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

