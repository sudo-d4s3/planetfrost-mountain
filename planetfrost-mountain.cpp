#include <ncurses.h>
#include "draw_map.cpp"

int main(int argc, char const *argv[]) {
        int x = 0;
        int y = 0;
        char map[24][80];

        initscr();
        noecho();
        cbreak();
        curs_set(FALSE);
        keypad(stdscr, TRUE);

        draw_map(map);
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
                        redraw_map(map);
                }
                if (ch == 260 and x != 0) { //right arrow
                        mvaddch(y, x, '.');
                        x -= 1;
                        redraw_map(map);
                }
                if (ch == 259 and y != 0) { //left arrow
                        mvaddch(y, x, '.');
                        y -= 1;
                        redraw_map(map);
                }
                if (ch == 258 and y != 23) { //left arrow
                        mvaddch(y, x, '.');
                        y += 1;
                        redraw_map(map);
                }
                if (ch == 32){
                        //mvaddch(y + 1, x, '^');
                        map[y][x] = '^';
                }
        }
        while (1);

        endwin();
        return 0;
}
