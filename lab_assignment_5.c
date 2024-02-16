#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    char letter;
    struct node* next;
} node;


int length(node* head) {
    int num = 0;
    if(head==NULL){
      return num;
    }
    while (head != NULL) {
        
        head = head->next;
        num=num+1;
    }
    return num;
}


char* toCString(node* head) {
  
    int siz = length(head);
    
    char* strin = (char*)malloc((siz + 1) * sizeof(char));
    
    
    if (strin == NULL) {
       
        exit(0);
          
    }

    for (int i = 0; i < siz; i++) {
        strin[i] = head->letter;
        head = head->next;
    }
    strin[siz] = '\0'; 
    return strin;
}


void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        
        exit(0);
    }

    newNode->letter = c;
    newNode->next = NULL;
    if(*pHead!=NULL) {
        node* temp;
        temp=*pHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    else if (*pHead == NULL) {
        *pHead = newNode;
    } 
   
}


void deleteList(node** pHead) {
    
    node* next;
    node* newNode;
    newNode= *pHead;
    while (newNode != NULL) {
        next = newNode->next;
        free(newNode);
        newNode = next;
    }

    *pHead = NULL; 
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        fprintf(stderr, "Failed to open input.txt\n");
        return EXIT_FAILURE;
    }
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0) {
        if (fscanf(inFile, " %d\n", &strLen) != 1) {
            fprintf(stderr, "Failed to read string length\n");
            fclose(inFile);
            deleteList(&head);
            return EXIT_FAILURE;
        }
        for (i = 0; i < strLen; i++) {
            if (fscanf(inFile, " %c", &c) != 1) {
                fprintf(stderr, "Failed to read character\n");
                fclose(inFile);
                deleteList(&head);
                return EXIT_FAILURE;
            }
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
    return 0;
}