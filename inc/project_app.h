
/*
 * project_app.h
 *
 *  Created on: Feb 18, 2019
 *      Author: Seong Ho Yeon_ML
 */

#ifndef PROJECT_APP_H_
#define PROJECT_APP_H_

#include "arm_math.h"

//****************************************************************************
// Definition(s):
//****************************************************************************
#define PROJ_DATA_TYPE0 0
// #define PROJ_DATA_TYPE1 1
// #define PROJ_DATA_TYPE2 2
#define PROJ_DATA_TYPESIZE 1

#define PROJ_BUFFER_SIZE 10

#define PROJ_MODE_OFF 0
#define PROJ_MODE_APP1 31



//****************************************************************************
// Shared variable(s)
//****************************************************************************

//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************

void proj_init(void);
void proj_core(void);
void proj_load_buf(int16_t* buf);
float32_t *proj_get_buf(int8_t dtype, int8_t ch, int16_t size);
float32_t proj_get_val(int8_t dtype, int8_t ch);
#endif
