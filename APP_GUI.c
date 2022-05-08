/***************************************************************************************
**文件名:     APP_GUI.c
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
#include "APP_GUI.h"
#include "string.h" 
#include "stdio.h" 
#if APP_GUI_MODULE_EN
#warning APP_GUI模块使能!
/*******************************宏定义***************************/

/*************************.C变量结构声明***********************/

/*************************私有全局变量*************************/
static GuiMenuItem_t GuiMenuItem = {
    0,
};
/*************************公共全局变量*************************/
static void APP_GUI_MenuMainDesk(void);
GuiMenuTab_t const guiMenuTab[] = {
    {eMenuMainDesk, 1, (*APP_GUI_MenuMainDesk)},
};
/*************************局部函数*****************************/
/***************************************************************************************
**函数名:       APP_GUI_MenuMainDesk
**功能描述:     菜单程序
**输入参数:     --
**输出参数:     --
**备注:
****************************************************************************************/
static void APP_GUI_MenuMainDesk(void)
{
    if (GuiMenuItem.PreOperate != GuiMenuItem.currentOperate)
    {
        /*首次进入菜单处理*/
        printf("enter APP_GUI_MenuMainDesk\n");
        GuiMenuItem.PreOperate = GuiMenuItem.currentOperate;
        GuiMenuItem.keepTime = 1000; //填写超时时间
    }
    /*执行的代码*/
    if (0 == GuiMenuItem.keepTime)
    {
        //超时退出菜单
        printf("keep time out!\n");
    }
}
/*************************全局函数****************************/
/***************************************************************************************
**函数名:       APP_GUI_Init
**功能描述:     GUI初始化
**输入参数:     --
**输出参数:     --
**备注:
****************************************************************************************/
void APP_GUI_Init(void)
{
    memset((uint8_t *)(&GuiMenuItem), 0, sizeof(GuiMenuItem));
}
/***************************************************************************************
**函数名:       APP_GUI_Deal
**功能描述:     GUI处理
**输入参数:     --
**输出参数:     --
**备注:
****************************************************************************************/
void APP_GUI_Deal(void)
{
    if (GuiMenuItem.currentIndex >= eNull) //菜单错误
    {
        return;
    }
    GuiMenuItem.currentOperate = guiMenuTab[GuiMenuItem.currentIndex].currentOperate;
    if (NULL != GuiMenuItem.currentOperate) //检查操作指针是否为空
    {
        GuiMenuItem.currentOperate(); //执行GUI
    }
}
/***************************************************************************************
**函数名:       APP_GUI_JumpMenu
**功能描述:     GUI 跳转
**输入参数:     --
**输出参数:     --
**备注:
****************************************************************************************/
void APP_GUI_JumpMenu(GuiMenuIndex_e index)
{
    GuiMenuItem.currentOperate = guiMenuTab[(uint8_t)index].currentOperate;
}

/***************************************************************************************
**函数名:       APP_GUI_TimeDeal
**功能描述:     GUI 定时器处理
**输入参数:     --
**输出参数:     --
**备注:         这个需要放到定时器中处理
****************************************************************************************/
void APP_GUI_TimeDeal(void)
{
    if (0 != GuiMenuItem.keepTime)
    {
        GuiMenuItem.keepTime--;
    }
}

//测试主函数 
int main(void)
{
	APP_GUI_Deal();
	return 0; 
}
#endif /*APP_GUI_MODULE_EN*/

/************************************Code End******************************************/
