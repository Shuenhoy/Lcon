#pragma comment(lib,"lua5.lib")
#pragma comment(lib,"tolua-vc.lib")
extern void gotoXY(int x, int y);
extern void ClearConsole(void);
extern void ClearConsoleToColors(int ForgC, int BackC);
extern void SetColorAndBackground(int ForgC, int BackC);
extern void SetColor(int ForgC);
extern void HideTheCursor(void);
extern void ShowTheCursor(void);
extern void CurrentCursorPosition() ;
extern void InitMouse();
extern void UpdateMouseMsg();
extern int GetMouseX();
extern int GetMouseY();
extern int MouseButtonState();
extern int MouseEventFlags();
extern int CursorX();
extern int CursorY();
extern void WriteStr(char *str,int x,int y);