#include "queue.h"

void initializeQueue(Queue* q) { //initialize queue
	q->head = NULL;
	q->tail = NULL;
}
int isEmpty(Queue* q) { // check if queue is empty
	if (q->head == NULL) {
		return 1;
	}
	return 0;
}
void enqueue(Queue* q, Player player) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (!newNode) {
		printf("Malloc Failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->player = player;
	newNode->next = NULL;
}
Player dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty, dequeue failed\n");
		exit(EXIT_FAILURE);
	}

	QueueNode* temp = q->head;
	Player player = temp->player;
	q->head = q->head->next;

	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(temp);
	return player; 
}
Player createPlayer() {

}
void fillQueue(Queue* q, int numPlayers) {

}
const char* getFactionName(Faction faction) {

}