#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*this has been entirely coded by me apart from given function formats for getline,sscanf , No large language model has been used by me*/

/*QUESTION*/

/*Write a program to store and search vehicle numbers using a Binary Search Tree (BST).

At an intersection, several vehicles pass by every day. We want to record the four-digit numbers appearing on their number plates and later search for specific vehicle numbers.

The vehicle numbers must be stored in a Binary Search Tree. Insert the vehicle numbers into an initially empty BST in the same order in which they are given in the input.

For every search operation, determine whether the given vehicle number exists in the BST. If it exists, also print the path from the root of the BST to that node.

The path is represented using:

L - Move to the left child.

R - Move to the right child.

If the searched number is present at the root, the path is empty.

Input Format:

The first line contains n distinct four-digit integers separated by a single space. These numbers must be inserted into an initially empty Binary Search Tree in the same order in which they appear.

Each number is between 1000 and 9999.

Each subsequent line contains a search query in the following format:

S m

where S represents the search operation and m is the four-digit vehicle number to be searched.

The vehicle number m may or may not exist in the BST, and the same number may be searched multiple times.

There is no special terminating input. The input ends at End Of File (EOF).

Output Format:

There will be no output after reading and inserting the vehicle numbers from the first line.

For every search query S m:

If m exists in the BST, print:

1 path

where path is a sequence of L and R characters representing the path from the root to the node containing m.

If m is the root of the BST, print 1 followed by a single space because the path is empty.

If m does not exist in the BST, print:

0

Each result must be printed on a new line.

Constraints:

1 <= n <= 9000

1000 <= ai, m <= 9999

All vehicle numbers in the first line are distinct.

There can be at most 105 search queries.

The input numbers are not guaranteed to be in random order. They may be already sorted.

The BST must be constructed by inserting the numbers in exactly the order in which they are provided.

Searching must be performed using the constructed BST. Do not search the original input list linearly or use an auxiliary sorted array or hash table.

Each BST node should contain pointers to its left child, right child, and parent. The parent of the root should be NULL.

Example:
INPUT:

5000 3000 7000 2000 4000 6000 8000
S 4000
S 8000
S 5000
S 1234

OUTPUT:

1 LR
1 RR
1
0

Explanation:

The BST is constructed with 5000 as the root.

3000 and 7000 are the left and right children of 5000.

2000, 4000, 6000, and 8000 are the leaf nodes.

For S 4000, the path from 5000 is Left followed by Right, so the output is 1 LR.

For S 8000, the path is Right followed by Right, so the output is 1 RR.

For S 5000, the searched number is the root, so the path is empty and the output is 1 followed by a space.

For S 1234, the number is not present in the BST, so the output is 0.
*/



struct TreeNode{
    struct TreeNode* LeftPtr;
    struct TreeNode* RightPtr;
    long int value;
    struct TreeNode* ParentPtr;
};

typedef struct TreeNode treeNode;


struct letterNode{//a doubly linked list.
        char character;
        struct letterNode* nextPtr;
        struct letterNode* previousNodePtr;
    };

typedef struct letterNode letterNode;


void insertInTree(char* numPtr,treeNode** rPtr);
int searchInTree(char* numPtr,treeNode*rootPtr);


int main(void){
  char* firstLine=NULL;
  char* inputLine=NULL;
  size_t length=0, counter=0, plateLength = 5;
  char choice;
  char numberPlate[6];
  treeNode* rootPtr = NULL;
  int p = 0 ;
    // printf("%s\n",numberPlate);

  length = getline(&firstLine,&length,stdin);   // Fetching only the first line of input.
    // printf("%s\n",firstLine);
    // printf("%d\n",length);
//   Parsing the string word by word. 
  while(counter < length){
    strncpy(numberPlate,&((firstLine)[counter]),plateLength);
    numberPlate[plateLength]='\0';
    // printf("%sO\n",numberPlate);
    insertInTree(numberPlate,&rootPtr); 
    counter += plateLength; 
    // printf("Hello%d\n",counter);
    continue;
    // Call your BST Insert function here with argument: numberPlate
  }

//   printf("Hello*\n");

  // Main input handler to serve requests.
  while(getline(&inputLine, &length, stdin) != -1){
    // printf("%s\n",inputLine);
    sscanf(inputLine,"%c %s",&choice, numberPlate);
    numberPlate[5] = '\0';
    // printf("%c %sSTARK\n",choice,numberPlate);
    if(choice == 'S'){
        // printf("EINSTEIN\n");
      p = searchInTree(numberPlate,rootPtr);
    //   puts("HEYTHERE");
      if(p != 2){
        // puts("GOING IN!");
        printf("%s",(p != 0) ? "1\n" : "0\n");
      }
      // Call your BST Search function here with argument: numberPlate
      continue;
    }else{
        puts("You didnt type a valid option.");
        continue;
    }
    free(inputLine); inputLine=NULL;
    length=0;
  }
  return 0;
  
}


void insertInTree(char* nPtr, treeNode** rPtr){
    long data = strtol(nPtr,NULL,10);
    if(*(rPtr) == NULL){//adding the first(root) node.
        treeNode* newPtr = (treeNode*)malloc(sizeof(treeNode));
        newPtr->LeftPtr = NULL;
        newPtr->RightPtr = NULL;
        newPtr->ParentPtr = NULL;
        newPtr->value = data;
        *(rPtr) = newPtr;
    }else{//adding the other nodes.
        treeNode* tempPtr = *(rPtr);
       while(1){
            if(data < tempPtr->value && tempPtr->LeftPtr != NULL){
              tempPtr = tempPtr->LeftPtr;
              continue;
            }else if(data > tempPtr->value && tempPtr->RightPtr != NULL){
                tempPtr = tempPtr->RightPtr;
                continue;
            }else if(data < tempPtr->value && tempPtr->LeftPtr == NULL){
                treeNode* newPtr = (treeNode*)malloc(sizeof(treeNode));
                newPtr->LeftPtr = NULL;
                newPtr->RightPtr = NULL;
                newPtr->ParentPtr = tempPtr;
                newPtr->value = data;
                tempPtr->LeftPtr = newPtr;
                break;
            }
            else if(data > tempPtr->value && tempPtr->RightPtr == NULL){
                treeNode* newPtr = (treeNode*)malloc(sizeof(treeNode));
                newPtr->LeftPtr = NULL;
                newPtr->RightPtr = NULL;
                newPtr->ParentPtr = tempPtr;
                newPtr->value = data;
                tempPtr->RightPtr = newPtr;
                break;
            }
        }
    }
}


void insert(char data , letterNode**rPtr){
    // puts("Executing \"insert\" function.");
    if(*(rPtr) == NULL){//adding the first node.
        letterNode* newPtr = (letterNode*)malloc(sizeof(letterNode));
        newPtr->nextPtr = NULL;
        newPtr->previousNodePtr = NULL;
        newPtr->character = data;
        *(rPtr) = newPtr;
    }else{//adding the other nodes.
        letterNode* tempPtr = *(rPtr);
           for(int i = 0;tempPtr->nextPtr != NULL;i++){
            tempPtr = tempPtr->nextPtr;
         }
       letterNode* newPtr = (letterNode*)malloc(sizeof(letterNode));
        newPtr->nextPtr = NULL;
        newPtr->previousNodePtr = tempPtr;
        newPtr->character = data;
        tempPtr->nextPtr = newPtr;
    }
}


void printReverseList(letterNode*startPtr){
    // puts("Executing \"printReverseList\" function.");
     for(int i = 0;startPtr->nextPtr != NULL;i++){
            startPtr = startPtr->nextPtr;
         }

    for(int i = 0;startPtr != NULL;i++){
        printf("%c ",startPtr->character);
        startPtr = startPtr->previousNodePtr;
    }
    printf("\n");
}

void printPath(treeNode*NodePtr){
    // puts("Executing \"printPath\" function.");
    letterNode* startPtr=NULL;
    for(int i = 0;NodePtr->ParentPtr != NULL; i++){
        // printf("ERLANG%d\n",i);
        if(NodePtr == ((NodePtr->ParentPtr)->LeftPtr)){
            // printf("DENNIS%d\n",i);
            insert('L',&startPtr);
        }else if(NodePtr == ((NodePtr->ParentPtr)->RightPtr)){
            // printf("RITCHIE%d\n",i);
            insert('R',&startPtr);
        }
        NodePtr = NodePtr->ParentPtr;
    }
    insert('1',&startPtr);
    printReverseList(startPtr);
   
    letterNode* otherPtr = startPtr;    // code the free part here.
    letterNode* tempPtr; 
    for(int i = 0; otherPtr != NULL;i++){
        tempPtr = otherPtr;
        otherPtr= otherPtr->nextPtr;
        free(tempPtr);
    }
}


int searchInTree(char* numPtr,treeNode*rootPtr){
    // puts("Executing \"searchInTree\" function.");
    long data = strtol(numPtr,NULL,10);
    // printf("%ld\n",data);
    treeNode* tempPtr = rootPtr;
    while(tempPtr != NULL){
        if(data < tempPtr->value && tempPtr != NULL){
            tempPtr = tempPtr->LeftPtr;
            // printf("HI\n");
            continue;
        }else if(data > tempPtr->value && tempPtr != NULL){
            tempPtr = tempPtr->RightPtr;
            // printf("HI\n");
            continue;
        }else if(data == rootPtr->value && tempPtr != NULL){
            return 1;
        }else if(data == tempPtr->value && tempPtr != NULL){
            printPath(tempPtr);
            return 2;
        }
    }
    return 0;
}


