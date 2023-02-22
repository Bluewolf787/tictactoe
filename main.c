#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void drawField(char fields[3][3]) {
    printf("    A   B   C\n");
    printf("  ⎯⎯⎯⎯⎯⎯⎯⎯\n");
    printf("1 │ %c │ %c │ %c │\n", fields[0][0], fields[0][1], fields[0][2]);
    printf("2 │ %c │ %c │ %c │\n", fields[1][0], fields[1][1], fields[1][2]);
    printf("3 │ %c │ %c │ %c │\n", fields[2][0], fields[2][1], fields[2][2]);
    printf("  ⎯⎯⎯⎯⎯⎯⎯⎯\n");
}

bool checkWin(char fields[3][3]) {
    char a1 = fields[0][0];
    char a2 = fields[0][1];
    char a3 = fields[0][2];
    char b1 = fields[1][0];
    char b2 = fields[1][1];
    char b3 = fields[1][2];
    char c1 = fields[2][0];
    char c2 = fields[2][1];
    char c3 = fields[2][2];

    bool row1 = a1 != ' ' && a1 == b1 && a1 == c1;
    bool row2 = a2 != ' ' && a2 == b2 && a2 == c2;
    bool row3 = a3 != ' ' && a3 == b3 && a3 == c3;
    bool columnA = a1 != ' ' && a1 == a2 && a1 == a3;
    bool columnB = b1 != ' ' && b1 == b2 && b1 == b3;
    bool columnC = c1 != ' ' && c1 == c2 && c1 == c3;
    bool diagonal1 = a1 != ' ' && a1 == b2 && a1 == c3;
    bool diagonal2 = c1 != ' ' && c1 == b2 && c1 == a3;

    if (row1 || row2 || row3 || columnA || columnB || columnC || diagonal1 || diagonal2)
        return true;
    else
        return false;
}

int main() {
    char fields[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    drawField(fields);

    char player;
    int turn = 0;
    char field[2];
    while (1) {
        if (turn % 2 == 0) player = 'X';
        else player = 'O';

        printf("%c enter line and row: ", player);
        scanf("%s", field);

        if (strcmp(field, "A1") == 0) {
            fields[0][0] = player;
        }
        else if (strcmp(field, "B1") == 0) {
            fields[0][1] = player;
        }
        else if (strcmp(field, "C1") == 0) {
            fields[0][2] = player;
        }
        else if (strcmp(field, "A2") == 0) {
            fields[1][0] = player;
        }
        else if (strcmp(field, "B2") == 0) {
            fields[1][1] = player;
        }
        else if (strcmp(field, "C2") == 0) {
            fields[1][2] = player;
        }
        else if (strcmp(field, "A3") == 0) {
            fields[2][0] = player;
        }
        else if (strcmp(field, "B3") == 0) {
            fields[2][1] = player;
        }
        else if (strcmp(field, "C3") == 0) {
            fields[2][2] = player;
        }

        drawField(fields);

        if (checkWin(fields)) {
            printf("%c wins the game!\n", player);
            break;
        }

        turn++;
    }

    return 0;
}
