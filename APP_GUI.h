/***************************************************************************************
**�ļ���:     APP_GUI.h
**�汾:       V1.00
**˵��:       ���ļ����Ը���ʵ������޸ġ�
**�޸ļ�¼:
*�汾:V1.00
*�޸���:hhx
*ʱ��:
*�޸�˵����
����������ļ�
**��ע:
****************************************************************************************/
#ifndef __APP_GUI_H__
#define __APP_GUI_H__
//#include "MyConfig.h"
//#include "stdint.h"
#define APP_GUI_MODULE_EN (1) //ģ��ʹ��
#if APP_GUI_MODULE_EN
/*************************ר�ú궨��*************************/

/*************************�����ṹ����*************************/
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
#define NULL 0 

typedef enum
{
    eMenuMainDesk, //ϵͳ����˵�
    eNull,         //������˵��°�
} GuiMenuIndex_e;

typedef struct
{
    GuiMenuIndex_e index;
    uint8_t submenuCnt;           //�Ӳ˵�
    void (*currentOperate)(void); //��ǰִ�еĲ˵�
} GuiMenuTab_t;

typedef struct
{
    GuiMenuIndex_e currentIndex;  //��ǰ�˵��°�
    uint8_t submenu;              //�Ӳ˵�
    volatile uint32_t keepTime;   //�˵�����ʱ��
    void (*PreOperate)(void);     //�ϴ�ִ�еĲ˵�
    void (*currentOperate)(void); //��ǰִ�еĲ˵�
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

    /*************************��������*************************/

    /*************************��������*************************/
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
       