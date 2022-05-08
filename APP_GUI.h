/***************************************************************************************
**文件名:     APP_GUI.h
**版本:       V1.00
**说明:       此文件可以根据实际情况修改。
**修改记录:
*版本:V1.00
*修改者:hhx
*时间:
*修改说明：
创建了这个文件
**备注:
****************************************************************************************/
#ifndef __APP_GUI_H__
#define __APP_GUI_H__
//#include "MyConfig.h"
//#include "stdint.h"
#define APP_GUI_MODULE_EN (1) //模块使能
#if APP_GUI_MODULE_EN
/*************************专用宏定义*************************/

/*************************变量结构声明*************************/
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
#define NULL 0 

typedef enum
{
    eMenuMainDesk, //系统桌面菜单
    eNull,         //标记最大菜单下包
} GuiMenuIndex_e;

typedef struct
{
    GuiMenuIndex_e index;
    uint8_t submenuCnt;           //子菜单
    void (*currentOperate)(void); //当前执行的菜单
} GuiMenuTab_t;

typedef struct
{
    GuiMenuIndex_e currentIndex;  //当前菜单下班
    uint8_t submenu;              //子菜单
    volatile uint32_t keepTime;   //菜单保持时间
    void (*PreOperate)(void);     //上次执行的菜单
    void (*currentOperate)(void); //当前执行的菜单
} GuiMenuItem_t;

#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus*/

#ifdef APP_GUI_GLOBALS
#define APP_GUI_EXT
#else
#define APP_GUI_EXT extern
#endif /*APP_GUI_GLOBALS*/

    /*************************公共变量*************************/

    /*************************公共函数*************************/
    APP_GUI_EXT void APP_GUI_Init(void);
    APP_GUI_EXT void APP_GUI_Deal(void);
    APP_GUI_EXT void APP_GUI_JumpMenu(GuiMenuIndex_e index);
    APP_GUI_EXT void APP_GUI_TimeDeal(void);
#ifdef __cplusplus
}
#endif /*__cplusplus*/
#else  /*APP_GUI_MODULE_EN*/
#endif /*APP_GUI_MODULE_EN*/
#endif /*__APP_GUI_H__*/
       /************************************Code End******************************************/
       