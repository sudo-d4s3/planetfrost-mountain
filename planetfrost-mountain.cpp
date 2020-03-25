#include <ncursesw/curses.h>
#include <ctime>
#include "draw_map.cpp"

int main(int argc, char const *argv[]) {
        int x = 40;
        int y = 12;
        char map[24][80];
        char crops[24][80];
        int seeds = 10;

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
                if (ch == 261 and x != 79){ //left arrow
                        x += 1;
                        redraw_map(map);
                }
                if (ch == 260 and x != 0){ //right arrow
                        x -= 1;
                        redraw_map(map);
                }
                if (ch == 259 and y != 0){ //up arrow
                        y -= 1;
                        redraw_map(map);
                }
                if (ch == 258 and y != 23){ //down arrow
                        y += 1;
                        redraw_map(map);
                }
                if (ch == 32) {
                        if (seeds != 0 and map[y][x] != '*') {
                                crops[y][x] = '*';
                                seeds -= 1;
                                map[y][x] = crops[y][x];
                        } else if (map[y][x] == '*') {
                                crops[y][x] = ' ';
                                seeds += 1;
                                map[y][x] = '.';
                        }
                }
        }
        while (1);

        endwin();
        return 0;
}
