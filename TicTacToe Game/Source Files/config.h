#pragma once

// Both players must be a non-integer character.
char playerone = 'X';
char playertwo = 'O';
bool bot = true;

// Do not make any of the spaces:
// - Share the same character with any other space, or
// - whitespace.

char board[9] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'
};

// DO NOT edit below
int spot;
int turn;