#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAYER_NAME_LENGTH 11

// Enum for Factions
typedef enum {
    RED,   // 0
    BLUE,  // 1
    GREEN  // 2
} Faction;

// Player struct
typedef struct Player {
    char playerName[PLAYER_NAME_LENGTH];
    int level;
    Faction faction;
} Player;

// Queue Node struct
typedef struct QueueNode {
    Player player;
    struct QueueNode* next;
} QueueNode;

// Queue struct
typedef struct Queue {
    QueueNode* head;
    QueueNode* tail;
} Queue;

// Function Prototypes
void initializeQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Player player);
Player dequeue(Queue* q);  // Fixed function signature
Player createPlayer();
void fillQueue(Queue* q, int numPlayers);
const char* getFactionName(Faction faction);

#endif // QUEUE_H
