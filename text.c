/* FULL NAME: Rabia Qureshi
 * STUDENT ID: 1046427
 * E-MAIL: rqureshi@uoguelph.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "text.h"

void ftext(FILE *fPtr, struct node_struct *list) {
  struct node_struct *temp = NULL;

  /* open file in read mode */
  fPtr = fopen("output.txt", "w");
  if(!fPtr) {
    printf("output.txt not found!\n");
    return;
  }

  temp = list;
  while(temp != NULL) {
    fprintf(fPtr,"%s\n", (char *)temp->data);
    temp = temp->next;
  }

  fclose(fPtr);
}

/* frees the nodes in the list given by “list” */
void free_list(struct node_struct *list, int free_data) {
  struct node_struct *temp = NULL, *temp2 = NULL;

  temp = list;
  while(temp != NULL) {
    temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
}

/* returns the number of nodes in the list given by “list” */
int length(struct node_struct *list) {
  struct node_struct *temp2 = NULL;
  int i = 0;

  temp2 = list;
  while(temp2 != NULL) {
    i++;
    temp2 = temp2->next;
  }

  return i;
}

/* compare user search input to data in each node, one node at a time
 * and return 0 if a node's data with the same input is found
 */
int compar(const void *data, const void *userSearch) {
  int i;
  int strLen;
  char *nodeData;
  char *userInput;

  nodeData = (char *)data;
  userInput = (char *)userSearch;


  if(strlen(nodeData) != strlen(userInput)) {
    return 1; /* definitely not the same strings */
  }

  /* making function case insensitive */
  strLen = strlen(nodeData);
  for(i = 0; i < strLen; i++) {
    if (tolower(nodeData[i]) != tolower(userInput[i])) { /* get lowercase char */
      return 1;
    }
  }

  return 0;
}

/* traverse linked list given by “list”,
 * inspecting each node in turn.
 */
struct node_struct *search(struct node_struct *list, char *target, int (*compar)(const void *data, const void *userSearch)) {
  struct node_struct *nodeSearch = list;
  struct node_struct *tail = NULL;
  struct node_struct *foundNodes = NULL; /* return pointer */

  while (nodeSearch != NULL) {
    if (compar((char *)nodeSearch->data, target) == 0) {
      if (foundNodes == NULL) { /* start of linked list */
        /* linking the list */
        foundNodes = (struct node_struct *) malloc(sizeof(struct node_struct));
        tail = foundNodes; /* tail will also point to foundNodes */
      } else { /* linked list not empty */
        /* creating new node */
        tail->next = (struct node_struct *) malloc(sizeof(struct node_struct));
        tail = tail->next; /* tail will be updated last node */
      }
      tail->data = nodeSearch; /* tail->data points to node only */
      tail->next = NULL; /* end of list */
    }
    nodeSearch = nodeSearch->next;
  }

  return foundNodes;
}

/* get a word from the line of text read from file */
char *get_word(char *linePtr, struct node_struct **head, struct node_struct **tail) {
  int lineLen;
  char *word;
  char *buffer;
  struct node_struct *newNode;
  int i = 0, k = 0; /* counters */

  /* put lineOfText into buffer */
  lineLen = strlen(linePtr) + 1; /* strlen doesn't include \0 */
  buffer = (char *)malloc(lineLen * sizeof(char));
  strcpy(buffer, linePtr);

  /* parsing? to find length of word */
  if (buffer[0] == '\n') { /* if first char is a newline */
    while(buffer[i] == '\n') {
      i++;
    }
  } else if (isalpha(buffer[0]) != 0) { /* if first char is a letter */
    while(isalpha(buffer[i]) != 0) {
      i++;
      if (buffer[i] == '\'') { /* if next char is apostrophe, treat as part of word */
        i++;
      }
    }
  } else if (isdigit(buffer[0]) != 0) { /* if first char is a number */
    while(isdigit(buffer[i]) != 0) {
      i++;
    }
  } else if (buffer[0] == '[') { /* if first char is a square bracket */
    while(buffer[i] == '[') {
        i++;
    }
  } else if (buffer[0] == ']') { /* if first char is a square bracket */
    while(buffer[i] == ']') {
        i++;
    }
  } else if (buffer[0] == '(') { /* if first char is a bracket */
    while(buffer[i] == '(') {
        i++;
    }
  } else if (buffer[0] == ')') { /* if first char is a bracket */
    while(buffer[i] == ')') {
        i++;
    }
  } else if (buffer[0] == '-') { /* if first char is a hyphen */
    while(buffer[i] == '-') {
        i++;
    }
  } else if (buffer[0] == '/') { /* if first char is a slash */
    while(buffer[i] == '/') {
      i++;
    }
  } else if (buffer[0] == '.') { /* if first char is a period */
    while(buffer[i] == '.') {
      i++;
    }
  } else if (buffer[0] == ',') { /* if first char is a comma */
    while(buffer[i] == ',') {
      i++;
    }
  } else if (buffer[0] == ':') { /* if first char is a colon */
    while(buffer[i] == ':') {
      i++;
    }
  } else if (buffer[0] == '\'') { /* if first char is an apostrophe */
    while(buffer[i] == '\'') {
      i++;
    }
  } else if (buffer[0] == ';') { /* if first char is a semi colon mark */
    while(buffer[i] == ';') {
      i++;
    }
  } else if (buffer[0] == '*') { /* if first char is an asterisk */
    while(buffer[i] == '*') {
      i++;
    }
  } else if (buffer[0] == '?') { /* if first char is a question mark */
    while(buffer[i] == '?') {
      i++;
    }
  } else if (buffer[0] == '!') { /* if first char is an exclamation mark */
    while(buffer[i] == '!') {
      i++;
    }
  } else if (buffer[0] == '_') { /* if first char is an underscore */
    while(buffer[i] == '_') {
      i++;
    }
  } else if (buffer[0] == '#') { /* if first char is the number sign */
    while(buffer[i] == '#') {
        i++;
    }
  } else if (buffer[0] == '%') { /* if first char is a % */
    while(buffer[i] == '%') {
      i++;
    }
  } else if (buffer[0] == '@') { /* if first char is a @ */
    while(buffer[i] == '@') {
      i++;
    }
  } else if (buffer[0] == '$') { /* if first char is a $ */
    while(buffer[i] == '$') {
      i++;
    }
  } else if ((int)buffer[0] < 0) { /* if first char is a UNICODE char */
    while((int)buffer[i] < 0) {
      i++;
    }
  }

  /* to find spaces after word */
  if (buffer[i] == ' ') { 
    while(buffer[i+k] == ' ') {
      k++;
    }
  }

  /* find word */
  word = (char *)malloc(sizeof(char) * (i + 1)); /* including NULL */
  strncpy(word, buffer, i); /* copying word */
  word[i] = '\0'; /* last index val is i-1 */

  /* linking the list */
  if((*head) == NULL) { /* linked list is empty */
    newNode = (struct node_struct *) malloc(sizeof(struct node_struct));
    (*head) = newNode; /* head will point to newNode */
    (*tail) = newNode; /* tail will also point to newNode */
    (*head)->data = word; /* data in head will store address of string */
    (*head)->next = NULL; /* end of list */
  } else { /* linked list not empty */
    newNode = (struct node_struct *) malloc(sizeof(struct node_struct));
    (*tail)->next = newNode; /* next ptr of tail struct ptr will point to newNode */
    (*tail) = newNode; /* tail will point to newNode */
    (*tail)->data = word; /* data in newNode will store address of string */
    (*tail)->next = NULL; /* end of list */
  }

  return (buffer + i + k); /* return new location in buffer that skips over previous word AND spaces */
}

/* read each line of text from the file pointer fp, and
 * split each line into words allocating a string for each word
 */
struct node_struct *txt2words(FILE *fp) {
  char lineOfText[256] = {'\0'}; /* max 256 chars/line */
  struct node_struct *head = NULL, *tail = NULL;
  char *buffer; /* malloc not needed since var will point to (not store) char */

  /* get one line of text from file at a time and print it out */
  while(fgets(lineOfText, 256, fp)) {
    /* split each line into words, allocating a string for each word
     * and store the address of the string in the “data” pointer.
     */
    buffer = lineOfText;
    do { /* while not end of line */
      buffer = get_word(buffer, &head, &tail);
    } while(*buffer != '\0');
  }

  return head; /* head points to first word in linked list */
}

/* will open chosen file in read mode and pass the file pointer to txt2words
 * function. will close the file.
 */
int main() {
  FILE *fPtr, *fPtr2;
  struct node_struct *textList = NULL;
  struct node_struct *list = NULL;
  struct node_struct *temp = NULL, *temp2 = NULL, *temp3 = NULL;
  struct node_struct *searchList = NULL;
  struct node_struct *copiedList = NULL;
  char string[100] = {'\0'};
  int x = 0, i = 0, j = 0, k = 0; /* counters for number of nodes in linked lists */

  printf("Document Analysis on 'Pride and Prejudice' by Jane Austen\n\n");

  /* open file in read mode */
  fPtr = fopen("1342-0.txt", "r");
  if(!fPtr) {
    printf("1342-0.txt not found!\n");
    return 1;
  }

  /* find the head of the linked list --> point to first word in text */
  textList = txt2words(fPtr);

  /* after reading file */
  printf("Please enter a string to search for in this text: ");
  scanf(" %s", string);

  /* search for data in linked list */
  list = textList;
  searchList = search(list, string, &compar); /* sending address to use later */

  /* output search results */
  if(searchList != NULL) { /* if word matches were found in the .txt file */
    printf("\nMatching search results:\n");

    /* print out list of words found */
    temp = searchList;
    while(temp != NULL) {
      temp2 = (struct node_struct *)temp->data;
      printf("%s\n", (char *)temp2->data);
      temp = temp->next;
    }

    /* setting startNode and endNode to addresses of first and nth nodes
     * of the copiedList linked list (includes all text in between the nodes)
     */
    temp = textList;
    while(temp != NULL && x != 2) {
      temp2 = (struct node_struct *)temp->data;
      if (compar((char *)temp2, string) == 0) { /* if same words (case-insensitive) */
        x++;
        if (x == 1) {
          copiedList = (struct node_struct *)malloc(sizeof(struct node_struct));
          copiedList = temp->data;
        }
      }
      temp = temp->next;
      copiedList = (struct node_struct *)temp;
    }
  }

  ftext(fPtr2, copiedList);

  /* finding the lengths of all lists */
  temp3 = copiedList;
  i = length(temp3);
  temp3 = searchList;
  j = length(temp3);
  temp3 = textList;
  k = length(temp3);

  printf("\nNumber of occurrences of '%s': %d\n", string, j);

  /* length of lists - using length() function */
  printf("There are %d words in the copied linked list.\n", i);
  printf("There are %d words in the text file.\n", k);

  /* close files */
  fclose(fPtr);

  /* freeing all ptrs */
  free_list(searchList, j);
  free_list(textList, k);

  return 0;
}
