/*
** Lua binding: lcon
*/

#include "tolua.h"
#include "windows.h"
#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API extern "C" int tolua_lcon_open (lua_State* tolua_S);
extern "C" LUALIB_API int luaopen_lcon (lua_State* tolua_S);

#include "lcon.h"
#include "conio.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: gotoXY */
static int tolua_lcon_lcon_gotoXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  gotoXY(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gotoXY'.",&tolua_err);
 return 0;
#endif
}
/* function: writestr */
static int tolua_lcon_lcon_writestr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
  !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* ch=((char*)  tolua_tostring(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  WriteStr(ch,x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writestr'.",&tolua_err);
 return 0;
#endif
}
/* function: ClearConsole */
static int tolua_lcon_lcon_cls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ClearConsole();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cls'.",&tolua_err);
 return 0;
#endif
}

/* function: ClearConsoleToColors */
static int tolua_lcon_lcon_cls_c00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int ForgC = ((int)  tolua_tonumber(tolua_S,1,0));
  int BackC = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  ClearConsoleToColors(ForgC,BackC);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cls_c'.",&tolua_err);
 return 0;
#endif
}

/* function: SetColorAndBackground */
static int tolua_lcon_lcon_set_colorx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int ForgC = ((int)  tolua_tonumber(tolua_S,1,0));
  int BackC = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SetColorAndBackground(ForgC,BackC);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_colorx'.",&tolua_err);
 return 0;
#endif
}

/* function: SetColor */
static int tolua_lcon_lcon_set_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int ForgC = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  SetColor(ForgC);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_color'.",&tolua_err);
 return 0;
#endif
}

/* function: HideTheCursor */
static int tolua_lcon_lcon_hide_cursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  HideTheCursor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide_cursor'.",&tolua_err);
 return 0;
#endif
}

/* function: ShowTheCursor */
static int tolua_lcon_lcon_show_cursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ShowTheCursor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show_cursor'.",&tolua_err);
 return 0;
#endif
}

/* function: CurrentCursorPosition */
static int tolua_lcon_lcon_pcurpos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CurrentCursorPosition();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pcurpos'.",&tolua_err);
 return 0;
#endif
}

/* function: CursorX */
static int tolua_lcon_lcon_cur_x00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  CursorX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_x'.",&tolua_err);
 return 0;
#endif
}

/* function: CursorY */
static int tolua_lcon_lcon_cur_y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  CursorY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_y'.",&tolua_err);
 return 0;
#endif
}

/////////////////////////////////////////////////////////////
//===========================================================
/* function: CursorX */
static int tolua_lcon_lcon_mouse_x00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  GetMouseX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouse_x'.",&tolua_err);
 return 0;
#endif
}

/* function: CursorY */
static int tolua_lcon_lcon_mouse_y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  GetMouseY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouse_y'.",&tolua_err);
 return 0;
#endif
}
/* function: CursorX */
static int tolua_lcon_lcon_mousestate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  MouseButtonState();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mousestate'.",&tolua_err);
 return 0;
#endif
}

/* function: CursorY */
static int tolua_lcon_lcon_mouseflag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  MouseEventFlags();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouseflag'.",&tolua_err);
 return 0;
#endif
}
/* function: CursorX */
static int tolua_lcon_lcon_initmouse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  InitMouse();
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouseinit'.",&tolua_err);
 return 0;
#endif
}

/* function: CursorY */
static int tolua_lcon_lcon_updatemouse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
 UpdateMouseMsg();
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouseupdate'.",&tolua_err);
 return 0;
#endif
}
//===========================================================
/////////////////////////////////////////////////////////////


/* function: getch */
static int tolua_lcon_lcon_getch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  getch();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getch'.",&tolua_err);
 return 0;
#endif
}

/* function: kbhit */
static int tolua_lcon_lcon_kbhit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  kbhit();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'kbhit'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_lcon (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"lcon",0);
 tolua_beginmodule(tolua_S,"lcon");
 tolua_function(tolua_S,"gotoXY",tolua_lcon_lcon_gotoXY00);
 tolua_function(tolua_S,"writestr",tolua_lcon_lcon_writestr00);
 tolua_function(tolua_S,"cls",tolua_lcon_lcon_cls00);
 tolua_function(tolua_S,"cls_c",tolua_lcon_lcon_cls_c00);
 tolua_function(tolua_S,"set_colorx",tolua_lcon_lcon_set_colorx00);
 tolua_function(tolua_S,"set_color",tolua_lcon_lcon_set_color00);
 tolua_function(tolua_S,"hide_cursor",tolua_lcon_lcon_hide_cursor00);
 tolua_function(tolua_S,"show_cursor",tolua_lcon_lcon_show_cursor00);
 tolua_function(tolua_S,"pcurpos",tolua_lcon_lcon_pcurpos00);
 tolua_function(tolua_S,"cur_x",tolua_lcon_lcon_cur_x00);
 tolua_function(tolua_S,"cur_y",tolua_lcon_lcon_cur_y00);
 tolua_function(tolua_S,"mouse_x",tolua_lcon_lcon_mouse_x00);
 tolua_function(tolua_S,"mouse_y",tolua_lcon_lcon_mouse_y00);
 tolua_function(tolua_S,"initmouse",tolua_lcon_lcon_initmouse00);
 tolua_function(tolua_S,"updatemouse",tolua_lcon_lcon_updatemouse00);
 tolua_function(tolua_S,"mousestate",tolua_lcon_lcon_mousestate00);
 tolua_function(tolua_S,"mouseflag",tolua_lcon_lcon_mouseflag00);
 tolua_function(tolua_S,"getch",tolua_lcon_lcon_getch00);
 tolua_function(tolua_S,"kbhit",tolua_lcon_lcon_kbhit00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_lcon_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_lcon);
 lua_pushstring(tolua_S, "lcon");
 lua_call(tolua_S, 1, 0);
 return 1;
}
