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
                mvaddch(y, x, '@');
                move(y, x);
                refresh();


                int ch = getch();
                if (ch == 27) {
                        break;
                }
                if (ch == 261 and x != 79) { //left arrow
                        mvaddch(y, x, '.');
                        x += 1;
                }
                if (ch == 260 and x != 0) { //right arrow
                        mvaddch(y, x, '.');
                        x -= 1;
                }
                if (ch == 259 and y != 0) { //left arrow
                        mvaddch(y, x, '.');
                        y -= 1;
                }
                if (ch == 258 and y != 23) { //left arrow
                        mvaddch(y, x, '.');
                        y += 1;
                }
        }
        while (1);

        endwin();
        return 0;
}
