#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *Listptr;
struct listnode {
    int data;
    Listptr next;
};

int getsize(Listptr p) {
    int l = 0;
    if(p == NULL) {
        return 0;
    }
    
    while(p->next != NULL) {
        l++;
        p =  p->next;
    }
    return l;
}

void insert(Listptr *p,int pos, int val) {
    int size = getsize(*p);
    if(pos < 0 || pos > size) {
        printf("* ");
        return;
    }

    Listptr newnode = malloc(sizeof(struct listnode));
    newnode->next = NULL;
    newnode->data = val;
    if(pos == 1) {
        newnode->next = *p;
        *p = newnode;
        return;
    }
    Listptr curr = *p;
    for(int i = 1; i < pos -1; i++) {
        curr = curr->next;
    }
    newnode -> next = curr -> next;
    curr->next = newnode;
    
    return;
}

void insert_start(Listptr *p, int val) {
    Listptr newnode = malloc(sizeof(struct listnode));
    newnode->data = val;
    newnode->next = *p;
    *p = newnode;
    return;

    
}

void insert_end(Listptr *p, int val) {
    Listptr newnode = malloc(sizeof(struct listnode));
    newnode->data = val;
    newnode->next = NULL;
    if(*p == NULL) {
        newnode->next = *p;
        *p = newnode;
    }
    Listptr curr = *p;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
    
}
void removedupl(Listptr p) {
    Listptr current =p, next_next;
    while(current->next != NULL) {
        if(current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }else {
            current = current->next;
        }
    }
}
void delete_el(Listptr *p, int val) {
    if(*p &&(*p)->data == val) {
        Listptr temp = *p;
        *p = temp->next;
        free(temp);
        return;
    }
    
}

void deletelist(Listptr p) {
    while(p != NULL) {
        Listptr temp = p->next;
        free(p);
        p = temp;
        
    }  
}

void printList(Listptr p) {
    printf("List: ");
    while(p!=NULL) {
        printf(" %d -> ", p->data);
        p = p ->next;
    }
    printf("NULL\n");
    return;
    
}
int exists(Listptr p, int val) {
    while(p != NULL) {
        if(p->data == val) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

Listptr reverse(Listptr p) {
    if(p == NULL) {
        return p;
    }
    Listptr curr = p;
    Listptr prev = NULL;
    Listptr next = NULL;

    while(curr != NULL) {
        next = curr->next; //Πρωτα μπορω να βρω το next.
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //*p = prev; /*! Αλλαζω τη λιστα ! */
    return prev;


}
int ispalindrome(Listptr p, Listptr revp) {
    if(getsize(p) != getsize(revp)) {
        return 0;
    }
    while(p != NULL) {
        if(p->data != revp->data){
            return 0;
        }
        p= p->next;
        revp = revp->next;
    }
    return 1;
}

Listptr recreverse (Listptr head) { // 1 -> 2 -> 3-> 4. 
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Listptr p = recreverse(head->next); //Until we get to the end of the list.
    head->next->next = head; //For example head=3, next is 4 so next (no.2) i want it to be 3 so 4 point to 3.
    head->next = NULL; //I delete the 3->4 connection
    return p;

}

int main() {
    Listptr head = NULL;

    insert_start(&head, 8);
    insert_start(&head, 18);
    insert_start(&head, 38);
    
    insert_end(&head, 67);
    printList(head);
    insert(&head,2, 1);
    insert(&head,3, 23);
    insert(&head,1, 65);
    insert(&head,4, 12);

   
    delete_el(&head, 8);
    printList(head);;
   
    head = reverse(head);
 
    printf("Enter number: ");
    int num;
    scanf("%d", &num);
    
    printf("Number %d is %s in the list\n",num, exists(head,num) ? "" : "not");
    printList(head);
    deletelist(head);
    
return 0;
}