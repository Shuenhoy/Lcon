# Lcon
A Lua library for colorful console

```
module lcon
{
void gotoXY(int x, int y);
void cls(void);
void cls_c(int ForgC, int BackC);
void set_colorx(int ForgC, int BackC);
void set_color(int ForgC);
void hide_cursor(void);
void show_cursor(void);
void pcurpos() ;
int cur_x();
int cur_y();
int getch();
int kbhit();
}
```
