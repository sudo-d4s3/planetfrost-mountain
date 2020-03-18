#include <ncursesw/curses.h>

char draw_map(char map[24][80]) {
        for (size_t i = 0; i < 24; i++) {
                for (size_t i2 = 0; i2 < 80; i2++) {
                        map[i][i2] = '.';
                        mvhline(i, i2, map[i][i2], 1);
                }
        }
        return 0;
}

char redraw_map(char map[24][80]) {
        for (size_t i = 0; i < 24; i++) {
                for (size_t i2 = 0; i2 < 80; i2++) {
                        mvhline(i, i2, map[i][i2], 1);
                }
        }
        return 0;
}
