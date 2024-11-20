#include <stdio.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
typedef struct Node {
	struct Node *children[ALPHABET_SIZE];
	struct Node *fail;
	int is_end;
} Node;

Node *createNode() {
	Node *current = malloc(sizeof(Node));
	current->fail = NULL;
	current->is_end = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		current->children[i] = NULL;

	}
	return current;
}
void insertNode(Node *root, char *word) {
	while (*word) {
		int index = *word - 'a';
		if (root->children[index] == NULL) {
			root->children[index] = createNode();
		}
		root = root->children[index];
		word++;
	}
	root->is_end = 1;
}

void buildFailureFunc(Node *root) {
	Node *queue[1000];
	int front, rear = 0;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (root->children[i]) {
			queue[rear++] = root->children[i];
			root->children[i]->fail = root;
		}
	}
	while (front < rear) {
		Node *current = queue[front++];
		Node *fail = current->fail;

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (!current->children[i]) continue;

			while (fail && !fail->children[i]) {
				fail = fail->fail;
			}
			current->children[i]->fail = fail ? fail->children[i] : root;
			queue[rear++] = current->children[i];
		}
	}
}

int search(Node *root, char *word) {
	Node *current = root;
	for (char *cur = word; *cur != '\0'; cur++) {
		int index = *cur - 'a';
		while (current && !current->children[index]) {
			current = current->fail;
		}
		current = current ? current->children[index] : root;
		Node *temp = current;
		while (temp) {
			if (temp->is_end) {
				printf("find");
			}
			temp = temp->fail;
		}
	}
}

int main(void) {
	Node *root1 = createNode();
	insertNode(root1, "aaa");
	insertNode(root1, "abaaa");
	insertNode(root1, "ababaaa");
	buildFailureFunc(root1);
	search(root1, "aaadfabab");
}

