
    // while (!stateBNMO) {
    //     do {
    //         printf("> ENTER COMMAND: ");
    //         GetCommand();
    //         clear();

    //         if (!IsWordEq(toKata("START"), currentWord) && !IsWordEq(toKata("LOAD"), AccessCommand(currentWord, 0))) {
    //             printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         ||  /          \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");
    //             printf("Command tidak valid. Mesin BNMO belum dijalankan!\nGunakan command START / LOAD <file.txt> untuk memulai\n\n");
    //         }
    //     } while (!IsWordEq(toKata("START"), currentWord) && !IsWordEq(toKata("LOAD"), AccessCommand(currentWord, 0)));

    //     if (IsWordEq(toKata("START"), currentWord)) start(&listGame, &historyGame, SB);
    //     else load(&listGame, &historyGame, AccessCommand(currentWord, 1), SB);
    // }
    // sleep(1);

    // if (stateBNMO) {
    //     while (stateBNMO) {
    //         menuList(&listGame, &queueGame, &historyGame, SB);
    //     }
    // } else {
    //     printf("BNMO gagal dijalankan.\n");
    // }
    // clear();