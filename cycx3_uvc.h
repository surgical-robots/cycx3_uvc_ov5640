/*
 ## Cypress CX3 Firmware Example Header (cycx3_uvc.h)
 ## ===========================
 ##
 ##  Copyright Cypress Semiconductor Corporation, 2013-2014,
 ##  All Rights Reserved
 ##  UNPUBLISHED, LICENSED SOFTWARE.
 ##
 ##  CONFIDENTIAL AND PROPRIETARY INFORMATION
 ##  WHICH IS THE PROPERTY OF CYPRESS.
 ##
 ##  Use of this file is governed
 ##  by the license agreement included in the file
 ##
 ##     <install>/license/license.txt
 ##
 ##  where <install> is the Cypress software
 ##  installation root directory path.
 ##
 ## ===========================
 */

#ifndef _INCLUDED_CYCX3_APP_H_
#define _INCLUDED_CYCX3_APP_H_

#include "cyu3types.h"
#include "cyu3usbconst.h"
#include "cyu3os.h"
#include "cyu3utils.h"
#include "cyu3mipicsi.h"

#include "cyu3externcstart.h"

/* This header file comprises of the UVC application constants and the video frame configurations */

/* Uncomment following line to enable still image support */
#define STILL_CAPTURE_ENABLE                    (1)

/* Uncomment the following line to provide verbose debug logging. */
/* #define CX3_DEBUG_ENABLED                    (1) */
        
/* Uncomment the following line to run the mipi error thread */
/* #define CX3_ERROR_THREAD_ENABLE              (1) */

/* Uncomment the following line to run as UVC 1.0 device. Default is UVC 1.1 device. */
/* #define CX3_UVC_1_0_SUPPORT                  (1) */

/* Uncomment the following line to enable a timer that aborts an ongoing frame and restarts streaming
 * when the transfer is stalled. Default setting is timer enabled. */
#define RESET_TIMER_ENABLE                      (1)

#ifdef RESET_TIMER_ENABLE
#define TIMER_PERIOD    (500)                          /* Maximum frame transfer time in milli-seconds. */
#endif

#define CX3_APP_THREAD_STACK                    (0x1000)        /* Thread stack size */
#define CX3_APP_THREAD_PRIORITY                 (8)             /* Thread priority */

#ifdef CX3_ERROR_THREAD_ENABLE
#define CX3_MIPI_ERROR_THREAD_STACK             (0x1000)        /* Thread stack size */
#define CX3_MIPI_ERROR_THREAD_PRIORITY          (15)            /* Thread priority */
#endif

/* Endpoint definition for CX3 application */
#define CX3_EP_BULK_VIDEO                       (0x83)          /* EP 1 IN */
#define CX3_EP_CONTROL_STATUS                   (0x82)          /* EP 2 IN */

#define CX3_APP_SOCKET_COUNT                    (2)             /* Socket Count for Manual Many to One DMA Channel */
#define CX3_EP_VIDEO_CONS_SOCKET                (CY_U3P_UIB_SOCKET_CONS_3)  /* Consumer socket 1 */
#define CX3_PRODUCER_PPORT_SOCKET_0             (CY_U3P_PIB_SOCKET_0)       /* P-port Socket 0 is producer */
#define CX3_PRODUCER_PPORT_SOCKET_1             (CY_U3P_PIB_SOCKET_1)       /* P-port Socket 0 is producer */

/* Endpoint Packet Sizes */
#define CX3_EP_BULK_FULL_SPEED_PKT_SIZE         (0x40)  /* Full Speed endpoint packet Size */
#define CX3_EP_BULK_HIGH_SPEED_PKT_SIZE         (0x200) /* High Speed endpoint packet Size */
#define CX3_EP_INTR_PACKET_SIZE                 (0x40)  /* Interrupt endpoint packet Size */

/* Endpoint Burst Lengths */
#define CX3_EP_INTR_BURST_LEN                   (1)     /* Interrupt Endpoint Burst Length */
#define CX3_EP_BULK_SUPER_SPEED_BURST_LEN       (16)    /* Super Speed endpoint burst length */
#define CX3_EP_BULK_HIGH_SPEED_BURST_LEN        (1)     /* High Speed endpoint burst length */
#define CX3_EP_BULK_FULL_SPEED_BURST_LEN        (1)     /* High Speed endpoint burst length */

/* CX3 Application descriptor types */
#define CX3_INTRFC_ASSN_DESCR                   (11)    /* Interface association descriptor type. */
#define CX3_CS_INTRFC_DESCR                     (0x24)  /* Class Specific Interface Descriptor type: CS_INTERFACE */
#define CX3_EP_BULK_VIDEO_PKT_SIZE              (0x400) /* CX3 App video streaming endpoint packet Size */

/* CX3 Application Buffer Parameters*/
#define CX3_APP_DATA_BUF_SIZE                   (0x5FF0) /* DMA Buffer Data Size Used: 12272 Bytes*/
#define CX3_APP_PROD_HEADER                     (12)     /* CX3 App DMA Buffer Header Size */
#define CX3_APP_PROD_FOOTER                     (4)      /* CX3 App DMA Buffer Footer Size */

/* CX3 Application Buffer size - Will map to bulk Transaction size */
#define CX3_APP_STREAM_BUF_SIZE                 (CX3_APP_DATA_BUF_SIZE + CX3_APP_PROD_HEADER + CX3_APP_PROD_FOOTER)

/* CX3 Application Buffer count */
#define CX3_APP_STREAM_BUF_COUNT                (4)

/* Low byte - CX3 Application video streaming endpoint packet size */
#define CX3_EP_BULK_VIDEO_PKT_SIZE_L            CY_U3P_GET_LSB(CX3_EP_BULK_VIDEO_PKT_SIZE)

/* High byte - CX3 Application video streaming endpoint packet size */
#define CX3_EP_BULK_VIDEO_PKT_SIZE_H            CY_U3P_GET_MSB(CX3_EP_BULK_VIDEO_PKT_SIZE)

#define CX3_APP_HEADER_LENGTH                   (CX3_APP_PROD_HEADER)           /* Maximum number of header bytes in UVC */
#define CX3_APP_HEADER_DEFAULT_BFH              (0x8C)                          /* Default BFH(Bit Field Header) for the UVC Header */

#ifdef CX3_UVC_1_0_SUPPORT
#define CX3_APP_MAX_PROBE_SETTING               (26)            /* UVC 1.0 Maximum number of bytes in Probe Control */
#define CX3_APP_MAX_PROBE_SETTING_ALIGNED       (32)            /* Maximum number of bytes in Probe Control aligned to 32 byte */
#else
#define CX3_APP_MAX_PROBE_SETTING               (34)            /* UVC 1.1 Maximum number of bytes in Probe Control */
#define CX3_APP_MAX_PROBE_SETTING_ALIGNED       (64)            /* Maximum number of bytes in Probe Control aligned to 32 byte */
#endif

#define CX3_APP_HEADER_FRAME                    (0)                /* Normal frame indication */
#define CX3_APP_HEADER_EOF                      (uint8_t)(1 << 1)  /* End of frame indication */
#define CX3_APP_HEADER_FRAME_ID                 (uint8_t)(1 << 0)  /* Frame ID toggle bit */

#define CX3_USB_APP_SET_REQ_TYPE                (uint8_t)(0x21)    /* UVC interface SET request type */
#define CX3_USB_APP_GET_REQ_TYPE                (uint8_t)(0xA1)    /* UVC Interface GET request type */
#define CX3_USB_APP_GET_CUR_REQ                 (uint8_t)(0x81)    /* UVC GET_CUR request */
#define CX3_USB_APP_SET_CUR_REQ                 (uint8_t)(0x01)    /* UVC SET_CUR request */
#define CX3_USB_APP_GET_MIN_REQ                 (uint8_t)(0x82)    /* UVC GET_MIN Request */
#define CX3_USB_APP_GET_MAX_REQ                 (uint8_t)(0x83)    /* UVC GET_MAX Request */
#define CX3_USB_APP_GET_RES_REQ                 (uint8_t)(0x84)    /* UVC GET_RES Request */
#define CX3_USB_APP_GET_LEN_REQ                 (uint8_t)(0x85)    /* UVC GET_LEN Request */
#define CX3_USB_APP_GET_INFO_REQ                (uint8_t)(0x86)    /* UVC GET_INFO Request */
#define CX3_USB_APP_GET_DEF_REQ                 (uint8_t)(0x87)    /* UVC GET_DEF Request */

#define CX3_APP_VS_PROBE_CONTROL                (0x0100)           /* Video Stream Probe Control Request */
#define CX3_APP_VS_COMMIT_CONTROL               (0x0200)           /* Video Stream Commit Control Request */
#define CX3_APP_VC_REQUEST_ERROR_CODE_CONTROL   (0x0200)           /* Request Control Error Code*/
#define CX3_APP_ERROR_INVALID_CONTROL           (0x06)             /* Error indicating invalid control requested*/
#define CX3_APP_STREAM_INTERFACE                (0x01)             /* Streaming Interface : Alternate setting 1 */
#define CX3_APP_CONTROL_INTERFACE               (0x00)             /* Control Interface: Alternate Setting 0 */

#define CX3_APP_VS_PROBE_CONTROL                (0x0100)           /* Control selector for VS_PROBE_CONTROL. */  
#define CX3_APP_VS_COMMIT_CONTROL               (0x0200)           /* Control selector for VS_COMMIT_CONTROL. */
#define CX3_APP_VS_STILL_PROBE_CONTROL          (0x0300)           /* Control selector for VS_STILL_PROBE_CONTROL. */  
#define CX3_APP_VS_STILL_COMMIT_CONTROL         (0x0400)           /* Control selector for VS_STILL_COMMIT_CONTROL. */
#define CX3_APP_VS_STILL_IMAGE_TRIGGER_CONTROL  (0x0500)           /* Control selector for VS_STILL_IMAGE_TRIGGER_CONTROL. */

#define CX3_GPIF_SWITCH_TIMEOUT                 (2)                /* Timeout setting for the switch operation in GPIF clock cycles */
#define CX3_INVALID_GPIF_STATE                  (257)              /* Invalid state for use in CyU3PGpifSMSwitch calls */

/* Setup data field : Request */
#define CY_U3P_USB_REQUEST_MASK                 (0x0000FF00)
#define CY_U3P_USB_REQUEST_POS                  (8)

#define CX3_MIPI_ERROR_EVENT                    (1 << 3)           /* MIPI Error event. Used to flag a MIPI-CSI2 bus error */
#define CX3_DMA_RESET_EVENT                     (1 << 4)           /* DMA Reset event */
#define CX3_USB_SUSP_EVENT_FLAG                 (1 << 5)           /* Event generated on a USB Suspend Request*/

#ifdef STILL_CAPTURE_ENABLE
#define CX3_APP_MAX_STILL_PROBE_SETTING 		(11)	           /* Maximum number of bytes in Still Probe Control */
#define CX3_APP_HEADER_STI			            (uint8_t)(1 << 5)  /* Still Image Indication in the UVC Header*/
#define CX3_STILL_IMAGE_EVENT 	   	            (1 << 7)			/*Event used to Still Image Capture*/
#endif

/* Extern definitions of the USB Enumeration constant arrays used for the Application */
extern const uint8_t CyCx3USB20DeviceDscr[];
extern const uint8_t CyCx3USB30DeviceDscr[];
extern const uint8_t CyCx3USBDeviceQualDscr[];
extern const uint8_t CyCx3USBFSConfigDscr[];
extern const uint8_t CyCx3USBHSConfigDscr[];
extern const uint8_t CyCx3USBBOSDscr[];
extern const uint8_t CyCx3USBSSConfigDscr[];
extern const uint8_t CyCx3USBStringLangIDDscr[];
extern const uint8_t CyCx3USBManufactureDscr[];
extern const uint8_t CyCx3USBProductDscr[];
extern const uint8_t CyCx3USBConfigSSDscr[];
extern const uint8_t CyCx3USBConfigHSDscr[];
extern const uint8_t CyCx3USBConfigFSDscr[];

/* Extern definitions of the Video frame data */

/* UVC Probe Control Setting */
extern uint8_t       glProbeCtrl[CX3_APP_MAX_PROBE_SETTING];            /* Scratch buffer. */

extern const uint8_t gl720pProbeCtrl[CX3_APP_MAX_PROBE_SETTING];        /* 720p x60 settings. */
extern const uint8_t gl1080pProbeCtrl[CX3_APP_MAX_PROBE_SETTING];       /* 1080p x30 settings. */
extern const uint8_t gl5MpProbeCtrl[CX3_APP_MAX_PROBE_SETTING];         /* 2592*1944 (5 MP) x15 settings. */
extern const uint8_t glVga30ProbeCtrl[CX3_APP_MAX_PROBE_SETTING];       /* 640*480 (VGA) x30 settings for SS */

extern const uint8_t glVga30ProbeCtrl_HS[CX3_APP_MAX_PROBE_SETTING];    /* 640*480 (VGA) x30 settings for HS */
extern const uint8_t glVga60ProbeCtrl[CX3_APP_MAX_PROBE_SETTING];       /* 640*480 (VGA) x60 settings. */

/************************************/
/* MIPI Configuration parameters */
/************************************/

extern CyU3PMipicsiCfg_t cfgUvc1080p30NoMclk, cfgUvc720p60NoMclk,  cfgUvcVgaNoMclk, cfgUvc5Mp15NoMclk;

#include "cyu3externcend.h"

#endif /* _INCLUDED_CYCX3_APP_H_ */





