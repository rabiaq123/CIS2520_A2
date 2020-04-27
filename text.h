/* FULL NAME: Rabia Qureshi
 * STUDENT ID: 1046427
 * E-MAIL: rqureshi@uoguelph.ca*/

#ifndef TEXT_H
#define TEXT_H

/* STRUCTS */

/* 1. represent the text;
 * 2. used to store lists of node structures to be created by
 * searching the words in the main list;
 * 3. used to represent the elements in a linked list that
 * represent the result of a search of a linked list.
 * Each result pointer will point to an item that was found and
 * still exists in the word_struct list.
 */
struct node_struct {
  void *data; /*will point to malloced memory holding string of text + '\0'*/
  struct node_struct *next;
};

/* FUNCTION PROTOTYPES */

/* returns a malloced string containing the first word in the input string */
char *get_word(char *linePtr, struct node_struct **head, struct node_struct **tail);

/* read text from the file pointer fp, one line at a time */
struct node_struct *txt2words(FILE *fp);

/* traverse linked list given by “list”, inspecting each node in turn. */
struct node_struct *search(struct node_struct *list, char *target, int (*compar)(const void *, const void *));

/* print out the strings “data” pointers point to in the linked list in order */
void ftext(FILE *fp, struct node_struct *list);

/* returns the number of nodes in the list given by “list” */
int length(struct node_struct *list);

/* frees the nodes in the list given by “list” */
void free_list(struct node_struct *list, int free_data);


#endif
