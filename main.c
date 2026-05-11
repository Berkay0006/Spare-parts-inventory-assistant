#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define LINE_SIZE 50
#define PARTS_COUNT 3

char line[LINE_SIZE];

const char MESSAGE_WELCOME[] = "Hej. Welcome to the spare parts inventory!\n";
const char KNOWN_PARTS[][LINE_SIZE] = {"hydraulic pump", "PLC module", "servo motor"};
const char MESSAGE_QUESTION[] = "Which part do you need?\n";
const char MESSAGE_POSITIVE[] = "I've got %s here for you.😊\n";
const char MESSAGE_NEGATIVE[] = "I am afraid we don't have any %s in the inventory.😔\n";

int main(void) { 
 printf(MESSAGE_WELCOME);

while (1){
    printf(MESSAGE_QUESTION);
    fgets(line, _Countof line, stdin);
    line[strcspn(line, "\r\n")] = '\0';

  if (strcmp(line, "Do you actually have any parts?") == 0){
    printf("We have %d part(s)!\n", PARTS_COUNT);
    for (int i = 0; i < PARTS_COUNT; i++) {
      printf("%s\n", KNOWN_PARTS[i]);
    continue;
}}
  for (int i = 0; i < _Countof KNOWN_PARTS; i++){
    if (strcmp(line, KNOWN_PARTS[i]) == 0) {
      printf(MESSAGE_POSITIVE, line);
      return EXIT_SUCCESS;
    }}
  printf(MESSAGE_NEGATIVE, line);
}}