
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

/* Funtion Prototypes */
void addEntry();
void display(int index);
void search(char *key, search_t type);
void readFromFile();
void saveToFile();

#endif  // PHONEBOOK_H
