#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "glados.h"

#ifdef _WIN32
#define reset() system("color 0f");
#define set_color() system("color 0a")
#define play_logout() system("powershell -c (New-Object Media.SoundPlayer \"logout.wav\").PlaySync();")
#define play_portal() system("start https://www.youtube.com/watch?v=KLfJQkIJy58")
#define run_exec(exec) system(exec)
#else
#define reset() printf("\x1b[0;0m")
#define set_color() printf("\x1b[0;32m")
#define play_logout() system("aplay logout.wav -q")
#define play_portal() system("xdg-open https://www.youtube.com/watch?v=KLfJQkIJy58")
#define run_exec(exec) system("./"exec)
#endif

bool logout_signal = false;

void logout() {
    logout_signal = true;
}

void process_glados_command(char *command, char *arg, bool is_cave) {
    command[strlen(command)-1] = 0;
    clear();
    if (is_cave) {
        printf("GLaDOS v1.07a (c) 1982 Aperture Science, Inc.\n\n\n");
    } else {
        printf("GLaDOS v1.07 (c) 1982 Aperture Science, Inc.\n\n\n");
    }
    if (streq(command, "HELP") || streq(command, "LIB")) {
        printf("LIB\n");
        printf("   APPEND\n   ATTRIB\n   COPY\n   DIR\n   ERASE\n   FORMAT\n   INTERROGATE\n   LIB\n   PLAY\n   RENAME\n   TAPEDISK\n\n\n");
    } else if (streq(command, "APPEND") || streq(command, "ATTRIB") || streq(command, "COPY") || streq(command, "ERASE") || streq(command, "FORMAT") || streq(command, "RENAME")) {
        printf("\nERROR 15 [Disk is write protected]\n\n\n");
    } else if (streq(command, "DIR")) {
        if (is_cave) {
            printf("DISK VOLUME 255 [WORKSTATION CJOHNSON]\n\n\n   I 019 APPLY.EXE\n   I 004 NOTES.EXE\n\n\n2 FILES(S) IN 23 BLOCKS\n\n\n\n\n");
        } else {
            printf("DISK VOLUME 255 [NEW EMPLOYEE WORKSTATION]\n\n\n   I 019 APPLY.EXE\n\n\n1 FILE(S) IN 19 BLOCKS\n\n\n\n\n");
        }
    } else if (streq(command, "INTERROGATE")) {
        if (arg == NULL || arg == 1) {
            printf("\nERROR 02 [Command requires at least one parameter]\n\n\n");
        } else if (is_cave) {
            printf("\nERROR 07 [Unknown Employee]\n\n\n");
        } else {
            printf("\nERROR 01 [Illegal attempt to initate disciplinary action]\n\n\n");
        }
    } else if (streq(command, "PLAY")) {
        if (arg == NULL || arg == 1) {
            printf("\nERROR 03 [What would you like to play?]\n\n\n");
        } else if (streq(arg, "PORTAL")) {
            logout();
            play_portal();
        }
    } else if (streq(command, "TAPEDISK")) {
        printf("\nERROR 18 [User not authorized to transfer system tapes]\n\n\n");
    } else if (streq(command, "LOGOUT")) {
        logout();
    } else if (streq(command, "APPLY")) {
        run_exec("apply");
    } else if (is_cave && streq(command, "NOTES")) {
        run_exec("notes");
    } else if (command[0] == 0) {
        return;
    } else {
        printf("\nERROR 24 [File '%s' not found]\n\n\n", command);
    }
}

void glados(bool is_cave) {
    clear();
    printf("GLaDOS v1.07 (c) 1982 Aperture Science, Inc.\n\n\n");
    char command[100];
    while (1) {
        if (logout_signal) {
            clear();
            play_logout();
            break;
        }
        if (is_cave) {
            printf("ADMIN>");
        } else {
            printf("B:\\>");
        }
        fgets(command, 100, stdin);
        process_glados_command(command, strchr(command, ' ')+1, is_cave);
    }
}

void process_command(char *command) {
    if (streq(command, "HELP")) {
        clear();
        printf("If this is an actual plea for help in response to a hazardous material spill, an explosion, a fire on your person,\n");
        printf("radiation poisoning, a choking gas of unknown origin, eye trauma resulting from the use of an emergency eye\n");
        printf("wash station on floors three, four, or eleven, in an animal malfunction, or any other injurious experimental equipment\n");
        printf("faliure, please remain at your workstation. A Crisis Response Team has already been mobilized to deliberate on a response to your crisis.\n\n\n");
        printf("If you need help accessing the system, please refer to your User Handbook.\n\n\n");
    } else if (streq(command, "LOGIN") || streq(command, "LOGIN") || streq(command, "USER")) { 
        char username[100];
        char password[100];
        clear();
        printf("Username>");
        fgets(username, 100, stdin);
        clear();
password_entry:
        printf("Password>");
        fgets(password, 100, stdin);
        bool is_cave = false;
        if (streq(username, "CJOHNSON")) is_cave = true;
        if ((!streq(password, "PORTAL") && !streq(password, "PORTALS") && !is_cave) || (is_cave && !streq(password, "TIER3"))) {
            clear();
            printf("ERROR 07 [Incorrect Password]\n\n\n");
            goto password_entry;
        }
        glados(is_cave);
    } else {
        printf("\033[1K");
    }
}

void command_prompt() {
    while (1) {
        printf(">");
        char command[100];
        fgets(command, 100, stdin);
        process_command(command);
    }
}

void reset_on_exit() {
    reset();
}

int main() {
    atexit(reset_on_exit);
    clear();
    set_color();
    command_prompt();
    return 0;
}