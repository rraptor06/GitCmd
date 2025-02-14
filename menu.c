#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

static int selection = 0;

void displayMenu() {
    system("cls");
    printf("Program started.\n");
    printf("%c Display info menu.\n", selection == 0 ? '>' : ' ');
    printf("%c Display command.\n", selection == 1 ? '>' : ' ');
}

int main() {
    displayMenu();

    while (true) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 0 || ch == 224) {
                switch (_getch()) {
                    case 72:
                        selection = (selection - 1 + 2) % 2;
                        break;
                    case 80:
                        selection = (selection + 1) % 2;
                        break;
                }
                displayMenu();
            } else if (ch == 13) {
                break;
            }
        }
    }

    if (selection >= 0) {
        switch (selection) {
            default:
            case 0:
                printf("This is the info menu.\n");
                break;
            case 1:
                printf("This is the command menu.\n");
                break;
        }
    }

    printf("Press ENTER to close the program.\n");
    getchar();

    printf("Program ended.\n");
    return 0;
}