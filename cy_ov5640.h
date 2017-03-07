/*
 * cy_ov5640.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Lou
 */

#ifndef CY_OV5640_H_
#define CY_OV5640_H_

#include <cyu3types.h>

/* Enumeration defining Stream Format used for CyCx3_ImageSensor_Set_Format */
typedef enum CyU3PSensorStreamFormat_t
{
    SENSOR_YUV2 = 0,    /* UVC YUV2 Format*/
    SENSOR_RGB565       /* RGB565 Format  */
}CyU3PSensorStreamFormat_t;


/* Initialize Image Sensor*/
CyU3PReturnStatus_t CyCx3_ImageSensor_Init(void);

/* Set Sensor to output 720p Stream */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_720p(void);

/* Set Sensor to output 1080p Stream */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_1080p(void);

/* Set Sensor to output QVGA Stream */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_Qvga(void);

/* Set Sensor to output VGA Stream */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_Vga(void);

/* Set Sensor to output 5Megapixel Stream */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_5M(void);


/* Put Image Sensor to Sleep/Low Power Mode */
CyU3PReturnStatus_t CyCx3_ImageSensor_Sleep(void);

/* Wake Image Sensor from Sleep/Low Power Mode to Active Mode */
CyU3PReturnStatus_t CyCx3_ImageSensor_Wakeup(void);

/* Set Image Sensor Data Format */
CyU3PReturnStatus_t CyCx3_ImageSensor_Set_Format(CyU3PSensorStreamFormat_t format);

/* Trigger Autofocus for the Sensor*/
CyU3PReturnStatus_t CyCx3_ImageSensor_Trigger_Autofocus(void);

#endif /* CY_OV5640_H_ */
