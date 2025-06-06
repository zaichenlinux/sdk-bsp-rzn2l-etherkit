/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/

/*******************************************************************************
 * File Name    : r_usb_rtos_apl.h
 * Description  : Realtime OS header file for the application
 *******************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 30.09.2017 1.00 First release.
 ******************************************************************************/

/******************************************************************************
Macro definitions
******************************************************************************/
#define USB_APL_MBX                 (0)

#define USB_APL_OK                  (0)
#define USB_APL_ERROR               (1)

#define USB_APL_SND_MSG(ID, MESS)   (usb_apl_snd_msg((uint8_t)(ID), (usb_msg_t *)(MESS)))
#define USB_APL_RCV_MSG(ID, MESS)   (usb_apl_rec_msg((uint8_t)(ID), (usb_msg_t **)(MESS), (usb_tm_t)(0U)))

/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Exported global variables
******************************************************************************/
extern QueueHandle_t *g_apl_mbx_table[];

/******************************************************************************
Exported global functions (to be accessed by other files)
******************************************************************************/
void main_task (void);
usb_er_t usb_apl_rec_msg(uint8_t id, usb_msg_t **mess, usb_tm_t tm);
usb_er_t usb_apl_snd_msg(uint8_t id, usb_msg_t *mess);
void usb_apl_callback (usb_event_info_t *p_api_event, usb_hdl_t cur_task, usb_onoff_t usb_state);

/******************************************************************************
 End  Of File
 ******************************************************************************/
