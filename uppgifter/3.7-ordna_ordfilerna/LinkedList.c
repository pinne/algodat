#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int Length(struct node* head) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current=current->next;
    }
    return(count);
}

int Count(struct node* head, int searchFor) {
    struct node* current=head;
    int count=0;
    while (current!=NULL) {
        if (current->data==searchFor) count++;
        current=current->next;
    }
    return count;
}

int Count2(struct node* head, int searchFor) {
    struct node* current;
    int count = 0;
    for (current=head; current!=NULL; current=current->next) {
        if (current->data==searchFor) count++;
    }
    return count;
}

void Push(struct node** headRef, int newData) {
    struct node* newNode;
    newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count=0;
    while (current!=NULL) {
        if (count==index) return(current->data);
        count++;
        current=current->next;
    }
    assert(0);
}

void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

void InsertNth(struct node** headRef, int index, int data) {
    if (index == 0) Push(headRef, data);
    else {
        struct node* current = *headRef;
        int i;
        for (i=0; i<index-1; i++) {
            assert(current != NULL);
            current = current->next;
        }
        assert(current != NULL);
        Push(&(current->next), data);
    }
}

void SortedInsert(struct node** headRef, struct node* newNode) {
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct node* current = *headRef;
        while (current->next!=NULL && current->next->data<newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void SortedInsert2(struct node** headRef, struct node* newNode) {
    struct node dummy;
    struct node* current = &dummy;
    dummy.next = *headRef;
    while (current->next!=NULL && current->next->data<newNode->data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    *headRef = dummy.next;
}

void SortedInsert3(struct node** headRef, struct node* newNode) {
    struct node** currentRef = headRef;
    while (*currentRef!=NULL && (*currentRef)->data<newNode->data) {
        currentRef = &((*currentRef)->next);
    }
    newNode->next = *currentRef;
    *currentRef = newNode;
}

int Pop(struct node** headRef) {
    struct node* head;
    int result;
    head=*headRef;
    assert(head!=NULL);
    result=head->data;
    *headRef = head->next;
    free(head);
    return result;
}

void InsertSort(struct node** headRef) {
    struct node* result = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current!=NULL) {
        next = current->next;
        SortedInsert(&result, current);
        current = next;
    }
    *headRef = result;
}

void Append(struct node** aRef, struct node** bRef) {
    struct node* current;
    if (*aRef == NULL) {
        *aRef = *bRef;
    } else {
        current = *aRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *bRef;
    }
    *bRef=NULL;
}


void FrontBackSplit(struct node* source,
                    struct node** frontRef, struct node** backRef) {
    int len = Length(source);
    int i;
    struct node* current = source;
    if (len < 2) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        int hopCount = (len-1)/2;
        for (i = 0; i<hopCount; i++) {
            current = current->next;
        }
        *frontRef = source;
        *backRef = current->next;
        current->next = NULL;
    }
}

void FrontBackSplit2(struct node* source,
                     struct node** frontRef, struct node** backRef) {
    struct node* fast;
    struct node* slow;
    if (source==NULL || source->next==NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

void RemoveDuplicates(struct node* head) {
    struct node* current = head;
    if (current == NULL) return;
    while (current->next!=NULL) {
        if (current->data == current->next->data) {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}


void MoveNode(struct node** destRef, struct node** sourceRef) {
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}


void AlternatingSplit(struct node* source,
                      struct node** aRef, struct node** bRef) {
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* current = source;
    while (current != NULL) {
        MoveNode(&a, &current);
        if (current != NULL) {
            MoveNode(&b, &current);
        }
    }
    *aRef = a;
    *bRef = b;
}

void AlternatingSplit2(struct node* source,
                       struct node** aRef, struct node** bRef) {
    struct node aDummy;
    struct node* aTail = &aDummy;
    struct node bDummy;
    struct node* bTail = &bDummy;
    struct node* current = source;
    aDummy.next = NULL;
    bDummy.next = NULL;
    while (current != NULL) {
        MoveNode(&(aTail->next), &current);
        aTail = aTail->next;
        if (current != NULL) {
            MoveNode(&(bTail->next), &current);
            bTail = bTail->next;
        }
    }
    *aRef = aDummy.next;
    *bRef = bDummy.next;
}

struct node* ShuffleMerge1(struct node* a, struct node* b) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    while (1) {
        if (a==NULL) {
            tail->next = b;
            break;
        } else if (b==NULL) {
            tail->next = a;
            break;
        } else {
            tail->next = a;
            tail = a;
            a = a->next;
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    return(dummy.next);
}

struct node* ShuffleMerge2(struct node* a, struct node* b) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    while (1) {
        if (a==NULL) {
            tail->next = b;
            break;
        } else if (b==NULL) {
            tail->next = a;
            break;
        } else {
            MoveNode(&(tail->next), &a);
            tail = tail->next;
            MoveNode(&(tail->next), &b);
            tail = tail->next;
        }
    }
    return(dummy.next);
}

struct node* ShuffleMerge3(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** lastPtrRef = &result;
    while (1) {
        if (a==NULL) {
            *lastPtrRef = b;
            break;
        } else if (b==NULL) {
            *lastPtrRef = a;
            break;
        } else {
            MoveNode(lastPtrRef, &a);
            lastPtrRef = &((*lastPtrRef)->next);
            MoveNode(lastPtrRef, &b);
            lastPtrRef = &((*lastPtrRef)->next);
        }
    }
    return(result);
}

struct node* ShuffleMerge4(struct node* a, struct node* b) {
    struct node* result;
    struct node* recur;
    if (a==NULL) return(b);
    else if (b==NULL) return(a);
    else {
        recur = ShuffleMerge4(a->next, b->next);
        result = a;
        a->next = b;
        b->next = recur;
        return(result);
    }
}

struct node* SortedMerge(struct node* a, struct node* b) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    while (1) {
        if (a == NULL) {
            tail->next = b;
            break;
        } else if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data) {
            MoveNode(&(tail->next), &a);
        } else {
            MoveNode(&(tail->next), &b);
        }
        tail = tail->next;
    }
    return(dummy.next);
}

struct node* SortedMerge2(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** lastPtrRef = &result;
    while (1) {
        if (a==NULL) {
            *lastPtrRef = b;
            break;
        } else if (b==NULL) {
            *lastPtrRef = a;
            break;
        }
        if (a->data <= b->data) {
            MoveNode(lastPtrRef, &a);
        } else {
            MoveNode(lastPtrRef, &b);
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return(result);
}

struct node* SortedMerge3(struct node* a, struct node* b) {
    struct node* result = NULL;
    if (a==NULL) return(b);
    else if (b==NULL) return(a);
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge3(a->next, b);
    } else {
        result = b;
        result->next = SortedMerge3(a, b->next);
    }
    return(result);
}

void MergeSort(struct node** headRef) {
    struct node* head = *headRef;
    struct node* a;
    struct node* b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}

struct node* SortedIntersect(struct node* a, struct node* b) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    while (a!=NULL && b!=NULL) {
        if (a->data == b->data) {
            Push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return(dummy.next);
}

struct node* SortedIntersect2(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** lastPtrRef = &result;
    while (a!=NULL && b!=NULL) {
        if (a->data == b->data) {
            Push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a=a->next;
            b=b->next;
        } else if (a->data < b->data) {
            a=a->next;
        } else {
            b=b->next;
        }
    }
    return(result);
}

static void Reverse(struct node** headRef) {
    struct node* result = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        current->next = result;
        result = current;
        current = next;
    }
    *headRef = result;
}

static void Reverse2(struct node** headRef) {
    struct node* result = NULL;
    struct node* current = *headRef;
    while (current != NULL) {
        MoveNode(&result, &current);
    }
    *headRef = result;
}

void Reverse3(struct node** headRef) {
    if (*headRef != NULL) {
        struct node* middle = *headRef;
        struct node* front = middle->next;
        struct node* back = NULL;
        while (1) {
            middle->next = back;
            if (front == NULL) break;
            back = middle;
            middle = front;
            front = front->next;
        }
        *headRef = middle;
    }
}

void RecursiveReverse(struct node** headRef) {
    struct node* first;
    struct node* rest;
    if (*headRef == NULL) return;
    first = *headRef;
    rest = first->next;
    if (rest == NULL) return;
    RecursiveReverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *headRef = rest;
}

void Print(struct node* headRef){
    while(headRef!=NULL){
        printf("%d ",headRef->data);
        headRef=headRef->next;
    }
    printf("\n");
}

int main(void) {
    struct node *head=NULL, *head2=NULL, *h1=NULL, *h2=NULL;
    int i;
    for(i=1;i<=100000;i++)
        Push(&h1,rand());
    printf("%d\n",Length(h1));
    InsertSort(&h1);
    //MergeSort(&h1);
}
