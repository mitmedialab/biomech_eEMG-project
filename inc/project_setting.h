
/*
 * user_setting.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Seong Ho Yeon_ML
 */

#ifndef PROJECT_SETTING_H_
#define PROJECT_SETTING_H_


// #include "arm_math.h"

// #include "periph_adc.h"
#include "sw_sysconfig.h"
#include "eeprom.h"
#include "sw_comm.h"
#include "sw_envf.h"
#include "project_app.h"

//****************************************************************************
// Definition(s):
//****************************************************************************

#define PROJ_EEPROM_EN      (EE_OFF) //EE_OFF
//#define PROJ_EEPROM_EN      (EE_OFF)

//Set Device ID
#define PROJ_CONFIG_ID      100
#define PROJ_CONFIG_I2CDATA (COMM_DATA_BPF)
#define PROJ_CONFIG_SPIDATA (COMM_DATA_ENVF)
#define PROJ_CONFIG_RTGPIOLINE (SYS_CONFIG_RTGPIO_OFF)
#define PROJ_CONFIG_DSPWINDOW 100 //100ms
#define PROJ_CONFIG_ENVFMODE (ENVF_MODE_AVG) // ENVF_MODE_RMS
// #define PROJ_CONFIG_PATRECMODE 0
#define PROJ_CONFIG_PROJECTAPP (PROJ_MODE_APP1)


#define PROJ_MACT_MIN_SET 10
#define PROJ_MACT_MAX_SET 1000

//****************************************************************************
// Shared variable(s)
//****************************************************************************
// extern float32_t user_mact_minthresh[EMG_NUM_CH];
// extern float32_t user_mact_maxthresh[EMG_NUM_CH];
// extern volatile uint16_t user_configs[SYS_CONFIG_ADDR_SIZE];
// extern int8_t project_eeprom_use;
// extern int8_t user_error_reset;
//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************


#endif
