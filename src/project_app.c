/*
 * sw_envf.c
 *
 *  Created on: Jan 8, 2019
 *      Author: Seong Ho Yeon_ML
 */

#include "stm32f4xx_hal.h"
#include "arm_math.h"
#include "math.h"

#include "sw_adcbuf.h"
#include "sw_bpf.h"
#include "sw_envf.h"
#include "sw_mact.h"

#include "sw_os.h"
#include "sw_sysconfig.h"
#include "project_app.h"

//****************************************************************************
// Variable(s)
//****************************************************************************
volatile uint16_t proj_index;
int8_t dtype;

float32_t proj_buffer[PROJ_DATA_TYPESIZE][EMG_NUM_CH][PROJ_BUFFER_SIZE*2];

//****************************************************************************
// Private Function Prototype(s):
//****************************************************************************

int8_t proj_app_f1(float32_t* input, float32_t* output, int16_t size);
//****************************************************************************
// Public Function(s)
//****************************************************************************

void proj_init(void)
{
    memset(proj_buffer, 0, PROJ_DATA_TYPESIZE*EMG_NUM_CH*PROJ_BUFFER_SIZE*2*4);
    proj_index = 0;
    dtype = PROJ_DATA_TYPE0;
    return;

}

void proj_core(void)
{
    uint8_t mode = sysconfig_get_reg(SYS_CONFIG_ADDR_PROJECTAPP);
    int16_t size = sysconfig_get_reg(SYS_CONFIG_ADDR_DSPWINDOW) * BPF_BATCH_SIZE;

    if(mode != PROJ_MODE_OFF)
    {
        //Example processing usage
        switch(mode)
        {
            case PROJ_MODE_APP1:
                for(uint8_t ch=0;ch<EMG_NUM_CH;ch++)
                {
                    //Example Usage
                    proj_app_f1( (float32_t*) bpf_get_buf(ch,size), &proj_buffer[dtype][ch][proj_index], size);
                    proj_buffer[dtype][ch][proj_index+PROJ_BUFFER_SIZE] = proj_buffer[dtype][ch][proj_index];
                }

                break;
            default:
                break;
        }

        proj_index++;
        if(proj_index>= PROJ_BUFFER_SIZE)
            proj_index = 0;
    }

    return;
}

//This function will load the data on communication buffer
//Example loading
void proj_load_buf(int16_t* buf)
{
    for(uint8_t ch=0;ch<EMG_NUM_CH;ch++)
    {
        buf[ch] = (int16_t)proj_get_val(dtype,ch);
    }
    return;
}

float32_t *proj_get_buf(int8_t dtype, int8_t ch, int16_t size)
{
    return &proj_buffer[dtype][ch][proj_index+PROJ_BUFFER_SIZE-size];
}

float32_t proj_get_val(int8_t dtype, int8_t ch)
{
    return proj_buffer[dtype][ch][proj_index+PROJ_BUFFER_SIZE-1];
}

int8_t proj_app_f1(float32_t* input, float32_t* output, int16_t size)
{
    //Example loading function
    *output = input[size-1];

    return 0;
}
