#include "queue.h"

void initializeQueue(Queue* q) { //initialize queue
	q->head = NULL;
	q->tail = NULL;
}
int isEmpty(Queue* q) { // check if queue is empty
	return q->head == NULL;
}
void enqueue(Queue* q, Player player) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (!newNode) {
		printf("Malloc Failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->player = player;
	newNode->next = NULL;
	if (isEmpty(q)) {
		q->head = newNode;
		q->tail = newNode;
	}
	else {
		q->tail->next = newNode;
		q->tail = newNode; 
	}
}
Player dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty, dequeue failed\n");
		Player emptyPlayer;
		memset(&emptyPlayer, 0, sizeof(Player));
		emptyPlayer.faction = RED;
		return emptyPlayer;
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
void getRandomPlayerName(char* playername) {
	for (int i = 0; i < PLAYER_NAME_LENGTH - 1; i++) {
		
		int randomType = rand() % 3;
		if (randomType == 0) {
			playername[i] = 'a' + (rand() % 26); //lowercase letters
		}
		else if(randomType == 1) {
			playername[i] = 'A' + (rand() % 26); //uppercase letters
		}
		else {
			playername[i] = '0' + (rand() % 10);
		}

	}
	playername[PLAYER_NAME_LENGTH - 1] = '\0'; //null terminator
}
const char* getFactionName(Faction faction) {
	static const char* factionNames[] = { "Red", "Blue", "Green" };
	return factionNames[faction];
}
Player createPlayer() {
	Player newPlayer;
	getRandomPlayerName(newPlayer.playerName);
	newPlayer.level = (rand() % 60) + 1;
	newPlayer.faction = rand() % 3;
	return newPlayer;
}
void fillQueue(Queue* q, int numPlayers) {
	for (int i = 0; i < numPlayers; i++) {
		Player newPlayer = createPlayer();
		enqueue(q, newPlayer);
	}
}
