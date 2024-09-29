#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "config.h"

void mode() {
    while (true) {
        std::string mode;
        std::cout << "Bot mode or PvP? (bot/pvp) > "; std::cin >> mode;
        if (mode == "bot") {
            bot = true;
            std::cout << "Player vs. Bot\n" << std::endl;
            break;
        }
        else if (mode == "pvp") {
            bot = false;
            std::cout << "PvP\n" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice!" << std::endl;
            continue;
        }
    }
}

void number_input(char player, char opponent) {
    while (true) {
        std::cout << player << "'s turn >> ";
        std::cin >> spot;
        if (board[spot - 1] == player || board[spot - 1] == opponent || spot < 1 || spot > 9) {
            std::cout << "Invalid spot!" << std::endl;
            continue;
        }
        else {
            board[spot - 1] = player;
            break;
        }
    }
}

void bot_input(char bot, char opponent) {
    while (true) {
        srand((int)time(NULL));
        spot = 1 + rand() % 9;
        if (board[spot - 1] == opponent || board[spot - 1] == bot) {
            continue;
        }
        else {
            std::cout << bot << "'s turn > " << spot << std::endl;
            board[spot - 1] = bot;
            break;
        }
    }
}

void print_board() {
    // std::cout << "   *   *   " << std::endl;
    std::cout << " " << board[0] << " * " << board[1] << " * " << board[2] << " " << std::endl;
    std::cout << "***********" << std::endl;
    std::cout << " " << board[3] << " * " << board[4] << " * " << board[5] << " " << std::endl;
    std::cout << "***********" << std::endl;
    std::cout << " " << board[6] << " * " << board[7] << " * " << board[8] << " " << std::endl;
    // std::cout << "   *   *   " << std::endl;
}

bool check_win(char player) {
    turn++;
    bool win_combos[8] = {};
    // Define the row combos
    for (int i = 0; i <= 2; i++) {
        win_combos[i] = (
            board[0 + (3 * i)] == board[1 + (3 * i)] &&
            board[1 + (3 * i)] == board[2 + (3 * i)]
            );
    }
    // Define column combos
    for (int i = 0; i <= 2; i++) {
        win_combos[i + 3] = (
            board[0 + (1 * i)] == board[3 + (1 * i)] &&
            board[3 + (1 * i)] == board[6 + (1 * i)]
            );
    }
    // Define diagonal combos
    win_combos[6] = (board[0] == board[4] && board[4] == board[8]);
    win_combos[7] = (board[2] == board[4] && board[4] == board[6]);

    // If any combo matches, the respective player wins
    // If no combo matches when the board is full, the players draw
    for (int i = 0; i < 8; i++) {
        if (win_combos[i]) {
            std::cout << player << " won!" << std::endl;
            return true;
        }
    }
    if (turn == 9) {
        std::cout << "Draw!" << std::endl;
        return true;
    }
    return false;
}

bool check_replay() {
    std::string replay;
    while (true) {
        std::cout << "Play again? (yes/no) > "; std::cin >> replay;
        if (replay == "yes") {
            for (int i = 0; i < 9; i++)
                board[i] = '0' + i + 1;
            turn = 0;
            return true;
        }
        else if (replay == "no")
            return false;
        else {
            std::cout << "Invalid choice!" << std::endl;
            continue;
        }
    }
}
