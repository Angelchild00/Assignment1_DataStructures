#include "queue.h"
#include <time.h>

int main(int argc, char* argv[]) {
	//check arguments
	if (argc != 2) {
		printf("%s <number of players>\n", argv[0]);
		return 1;
	}
	int numPlayers = atoi(argv[1]);
	if (numPlayers <= 0) {
		printf("invalid number of players\n");
		return 1;
	}
	srand(time(NULL));

	Queue q;
	initializeQueue(&q);
	
	printf("Enqueuing %d players\n", numPlayers);
	fillQueue(&q, numPlayers);

	printf("Dequeuing players: \n");
	while (!isEmpty(&q)) {
		Player player = dequeue(&q);
		printf("Player Name: %s , Level: %d , Faction: %s\n", player.playerName, player.level, getFactionName(player.faction)); 
	}

	printf("Queue is now empty, ending program\n");
	return 0; 
}