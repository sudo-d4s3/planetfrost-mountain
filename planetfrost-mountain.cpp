#include <ncurses.h>


int main(int argc, char const *argv[]) {
        int x = 0;
        int y = 0;


        initscr();
        noecho();
        cbreak();
        curs_set(FALSE);
        keypad(stdscr, TRUE);

        for (size_t i = 0; i < 24; i++) {
                mvhline(i, 0, '.', 80);
        }
        do {
                refresh();
        }
        while (1);

        return 0;
}
