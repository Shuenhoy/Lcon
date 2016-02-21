#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std ;


void ConPrint(char *CharBuffer, int len);
void ConPrintAt(int x, int y, char *CharBuffer, int len);
void gotoXY(int x, int y);
void ClearConsole(void);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground(int ForgC, int BackC);
void SetColor(int ForgC);
void HideTheCursor(void);
void ShowTheCursor(void);
void CurrentCursorPosition() ;
int CursorX();
int CursorY();
void TopMost(int a);
void WriteStr(char *str,int x,int y){
	COORD size;
    
    DWORD dw;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD home ={0,0};
    home.X=x;
    home.Y=y;
    DWORD temp;
    WriteConsoleOutputCharacter(hOut,str,strlen(str),home,&temp);
    //_getch();
}
void InitMouse(){
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD oldmode;
	GetConsoleMode(hin,&oldmode);
	SetConsoleMode(hin, oldmode|ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); 
}
INPUT_RECORD    mouseRec;
DWORD           res;
COORD           crPos;
int mouse_x,mouse_y;
void UpdateMouseMsg(){
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hin, &mouseRec, 1, &res);
	if (mouseRec.EventType == MOUSE_EVENT)  {  
		crPos = mouseRec.Event.MouseEvent.dwMousePosition;
	}
}
int GetMouseX(){
	return crPos.X;
}
int GetMouseY(){
	return crPos.Y;
}
int MouseButtonState(){
	return mouseRec.Event.MouseEvent.dwButtonState;
}
int MouseEventFlags(){
	return mouseRec.Event.MouseEvent.dwEventFlags;
}
void CloseButton();

#define _WINDLL
#ifndef _WINDLL



int main(int argc, char* argv[])
{
	HANDLE hOut;											// ´¢´æÊä³ö¾ä±úµÄ±äÁ¿
	HANDLE hIn;												// ´¢´æÊäÈë¾ä±úµÄ±äÁ¿
	INPUT_RECORD mouseRec;									// ´¢´æÊó±êÐÅÏ¢µÄ½á¹¹Ìå
	DWORD res;												// ´¢´æÊÂ¼þ¸öÊýµÄ±äÁ¿
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);					// »ñÈ¡Êä³ö¾ä±ú
	hIn=GetStdHandle(STD_INPUT_HANDLE);						// »ñÈ¡ÊäÈë¾ä±ú
	DWORD oldmode;
	GetConsoleMode(hIn,&oldmode);
	SetConsoleMode(hIn,oldmode|ENABLE_MOUSE_INPUT);
	TopMost(0);
	CloseButton();
	for(;;)													// Ñ­»·
	{
		ReadConsoleInput(hIn, &mouseRec, 2, &res);			// ¶ÁÈ¡Êó±êÐÅÏ¢
		SetConsoleCursorPosition(hOut,mouseRec.Event.MouseEvent.dwMousePosition);
		// ÉèÖÃ¹â±ê×ø±êÎªÊó±ê×ø±ê
		if(mouseRec.Event.MouseEvent.dwEventFlags==0)		// Èç¹ûÊÂ¼þÐÅÏ¢Îª0
		{
			if(mouseRec.Event.MouseEvent.dwButtonState==2)	// Èç¹ûÊó±ê¼ü1£¨×ó¼ü£©±»°´ÏÂ
			{
				break;										// ÍË³ö
			}
		}
	}
	
	//system("pause");
	return 0;
}
#endif

void CloseButton(){
	HWND hWnd;												// ´¢´æ´°¿Ú¾ä±úµÄ±äÁ¿
	HMENU hMenu;											// ´¢´æ´°¿Ú²Ëµ¥µÄ±äÁ¿	
	LONG style = ::GetWindowLong(hWnd,GWL_STYLE);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rc = {0,0, 80-1, 25-1}; // ÖØÖÃ´°¿ÚÎ»ÖÃºÍ´óÐ¡
	SetConsoleWindowInfo(hStdOut,true ,&rc);
	hWnd=GetConsoleWindow();
	hMenu=GetSystemMenu(hWnd,false);						// »ñÈ¡´°¿Ú²Ëµ¥
	EnableMenuItem(hMenu,SC_CLOSE,MF_GRAYED|MF_BYCOMMAND);	// ÎÞÐ§»¯¹Ø±Õ°´Å¥
	 
}

void TopMost(int a){
	HWND hWnd=GetConsoleWindow();											// ´¢´æ´°¿Ú¾ä±úµÄ±äÁ¿
	
	if(a==0){
		SetWindowPos(hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOACTIVATE|SWP_SHOWWINDOW|SWP_NOMOVE|SWP_NOSIZE);
		
	}
	else{
		SetWindowPos(hWnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOACTIVATE|SWP_SHOWWINDOW|SWP_NOMOVE|SWP_NOSIZE);
	}
}


//This will clear the console while setting the forground and
//background colors.
void ClearConsoleToColors(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//This is used to reset the carat/cursor to the top left.
	COORD coord = {0, 0};
	//A return value... indicating how many chars were written
	//not used but we need to capture this since it will be
	//written anyway (passing NULL causes an access violation).
	DWORD count;

	//This is a structure containing all of the console info
	// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//Here we will set the current color
	SetConsoleTextAttribute(hStdOut, wColor);
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		//This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
}

//This will clear the console.
void ClearConsole()
{
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//This is used to reset the carat/cursor to the top left.
	COORD coord = {0, 0};
	//A return value... indicating how many chars were written
	//   not used but we need to capture this since it will be
	//   written anyway (passing NULL causes an access violation).
	DWORD count;
	//This is a structure containing all of the console info
	// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//Here we will set the current color
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		//This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
}

//This will set the position of the cursor
void gotoXY(int x, int y)
{
	//Initialize the coordinates
	COORD coord = {x, y};
	//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
	WORD wColor; 
	//We will need this handle to get the current background attribute
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);     
	}
}

//This will set the forground and background color for printing in a console window.
void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);     
}

//Direct console output
void ConPrint(char *CharBuffer, int len)
{
	DWORD count;
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), CharBuffer, len, &count, NULL);
}

//Direct Console output at a particular coordinate.
void ConPrintAt(int x, int y, char *CharBuffer, int len)
{
	DWORD count;
	COORD coord = {x, y}; 
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord); 
	WriteConsole(hStdOut, CharBuffer, len, &count, NULL);
}

//Hides the console cursor
void HideTheCursor()
{
	CONSOLE_CURSOR_INFO cci;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(handle, &cci);
}

//Shows the console cursor
void ShowTheCursor()
{
	CONSOLE_CURSOR_INFO cci;
	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.bVisible = TRUE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(handle, &cci);
}

int CursorX(){
	HANDLE   hStdout; 

	CONSOLE_SCREEN_BUFFER_INFO   pBuffer; 

	hStdout   =   GetStdHandle(STD_OUTPUT_HANDLE); 

	GetConsoleScreenBufferInfo(hStdout,   &pBuffer); 
	return pBuffer.dwCursorPosition.X;
}
int CursorY(){
	HANDLE   hStdout; 

	CONSOLE_SCREEN_BUFFER_INFO   pBuffer; 

	hStdout   =   GetStdHandle(STD_OUTPUT_HANDLE); 

	GetConsoleScreenBufferInfo(hStdout,   &pBuffer); 
	return pBuffer.dwCursorPosition.Y;
}
void   CurrentCursorPosition() 
{ 
	HANDLE   hStdout; 

	CONSOLE_SCREEN_BUFFER_INFO   pBuffer; 

	hStdout   =   GetStdHandle(STD_OUTPUT_HANDLE); 

	GetConsoleScreenBufferInfo(hStdout,   &pBuffer); 

	printf(   "(%d,   %d)\n ",   pBuffer.dwCursorPosition.X,   pBuffer.dwCursorPosition.Y   ); 
}