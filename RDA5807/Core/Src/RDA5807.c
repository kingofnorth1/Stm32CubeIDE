/*
**==============================================================================
** RDA5807.C:             -- by Dr. ZhuoQing, 2020-01-30
**
**==============================================================================
*/

//------------------------------------------------------------------------------
#include "stm32f1xx_hal.h"

#define RDA5807_GLOBALS        1              // Define the global variables
#include "RDA5807.H"

//------------------------------------------------------------------------------
#define RDA5807_BOOT_LENGTH     12
uint8_t RDA5807_boot_config[] = {
    0xc1, 0x03,                             // Register 0x2
    0x00, 0x00,                             // Register 0x3
    0x0a, 0x00,                             // Register 0x4
    0x88, 0x0f,                             // Register 0x5
    0x00, 0x00,                             // Register 0x6
    0x42, 0x02,                             // Register 0x7
};



//------------------------------------------------------------------------------
#define RDA5807_TUNE_CONFIG_LENGTH  4

uint8_t RDA5807_tune_config[] = {
    0xc0, 0x01,                             // Register 2
    0x00, 0x00,                             // Reigster 3
};

void RDA5807SetTuneConfig(uint16_t channel) {
    RDA5807_tune_config[2] = (uint8_t)(channel >> 2);
    RDA5807_tune_config[3] = (uint8_t)(((channel & 0x3) << 6) | 0x10);
}

//------------------------------------------------------------------------------

void RDA5807Init(void) {

/* Assumin band starts at 87.0MHz(per setting below)
 * and channel spaceing of 100kHz(0.1Mhz)(per settings below)
 * then channel can be derive as floowins:
 * channel = (<desired freq in MHz> - 87.0) / 0.1
 *
 * which is ave as:
 * <10x desired ferq in MHz> - 870
*/

    g_nRDA5807Channel = 6;

    RDA5807Setup();
}

//------------------------------------------------------------------------------
extern I2C_HandleTypeDef hi2c1;
void RDA5807I2CWrite(uint8_t * pucData, int nLength) {
    HAL_I2C_Master_Transmit(&hi2c1, 0x20, pucData, nLength, 10);
}

//------------------------------------------------------------------------------
void RDA5807Setup(void) {
    RDA5807I2CWrite(RDA5807_boot_config, RDA5807_BOOT_LENGTH);
    RDA5807SetTuneConfig(g_nRDA5807Channel);
    RDA5807I2CWrite(RDA5807_tune_config, RDA5807_TUNE_CONFIG_LENGTH);
}


void RDA5807SetChannel(float freq) {
    g_nRDA5807Channel = (int)((freq - 87.0) * 10.0 + 0.5);
    RDA5807SetTuneConfig(g_nRDA5807Channel);
    RDA5807I2CWrite(RDA5807_tune_config, RDA5807_TUNE_CONFIG_LENGTH);
}

//==============================================================================
//                END OF THE FILE : RDA5807.C
//------------------------------------------------------------------------------

