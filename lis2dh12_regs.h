#pragma once

#include <stdint.h>
#include <stdbool.h>


#define LIS2DH12_CTRL_REG0_ADDR 0x1E
#define LIS2DH12_CTRL_REG1_ADDR 0x20
#define LIS2DH12_CTRL_REG2_ADDR 0x21
#define LIS2DH12_CTRL_REG3_ADDR 0x22
#define LIS2DH12_CTRL_REG4_ADDR 0x23
#define LIS2DH12_CTRL_REG5_ADDR 0x24
#define LIS2DH12_CTRL_REG6_ADDR 0x25
#define LIS2DH12_TEMP_CFG_REG_ADDR 0x1F

#define LIS2DH12_WHO_AM_I_ADDR 0x0F
#define LIS2DH12_STATUS_REG_ADDR 0x27
#define LIS2DH12_OUT_TEMP_L_ADDR 0x0C
#define LIS2DH12_OUT_TEMP_H_ADDR 0x0D

#define LIS2DH12_OUT_X_L_ADDR 0x28
#define LIS2DH12_OUT_X_H_ADDR 0x29
#define LIS2DH12_OUT_Y_L_ADDR 0x2A
#define LIS2DH12_OUT_Y_H_ADDR 0x2B
#define LIS2DH12_OUT_Z_L_ADDR 0x2C
#define LIS2DH12_OUT_Z_H_ADDR 0x2D


typedef struct lis2dh12_ctrl_reg0_struct {
    bool sdo_pu_disc;   // Bit 7. 0 = internal pullup enabled, 1 = disabled
    // Bits [6:5] should be set to 0
    // Bit 4 should be set to 1
    // Bits [3:0] should be set to 0
} lis2dh12_ctrl_reg0_s;


typedef enum {
    // [ODR3, ODR2, ODR1, ODR0]
    LIS2DH12_ODR_POWER_DOWN_MODE = 0b000,
    LIS2DH12_ODR_FREQ_1HZ_MODE = 0b0001,
    LIS2DH12_ODR_FREQ_10HZ_MODE = 0b0010,
    LIS2DH12_ODR_FREQ_25HZ_MODE = 0b0011,
    LIS2DH12_ODR_FREQ_50HZ_MODE = 0b0100,
    LIS2DH12_ODR_FREQ_100HZ_MODE = 0b0101,
    LIS2DH12_ODR_FREQ_200HZ_MODE = 0b0110,
    LIS2DH12_ODR_FREQ_400HZ_MODE = 0b0111,
    LIS2DH12_ODR_LP_FREQ_1_62KHZ_MODE = 0b1000,
    LIS2DH12_ODR_HR_NORMAL_FREQ_1_344KHZ_LP_FREQ_5_376KHZ_MODE = 0b1001,
} LIS2DH12_ODR_e;   // Data rate

typedef struct lis2dh12_ctrl_reg1_struct {
    LIS2DH12_ODR_e odr; // Bits [7:4]. Data rate selection, see enum values
    bool lpen;          // Bit 3. 0 = high-resolution (HR) / normal mode, 1 = low-power (LP) mode
    bool zen;           // Bit 2. 0 = z-axis disabled, 1 = enabled
    bool yen;           // Bit 1. 0 = y-axis disabled, 1 = enabled
    bool xen;           // Bit 0. 0 = x-axis disabled, 1 = enabled
} lis2dh12_ctrl_reg1_s;


typedef enum {
    // [HPM1, HPM0]
    LIS2DH12_HPM_NORMAL_RESET_MODE = 0b00,   // Default
    LIS2DH12_HPM_REFERENCE_MODE = 0b01,
    LIS2DH12_HPM_NORMAL_MODE = 0b10,
    LIS2DH12_HPM_AUTORESET_MODE = 0b11,
} LIS2DH12_HPM_e;   // High-pass filter mode

typedef struct lis2dh12_ctrl_reg2_struct {
    LIS2DH12_HPM_e hpm; // Bits [7:6]. High-pass filter mode selection, see enum values
    uint8_t hpcf;       // Bits [5:4]. High-pass filter cutoff frequency selection. Not documented?
    bool fds;           // Bit 3. 0 = internal filter bypassed, 1 = use filter
    bool hpclick;       // Bit 2. 0 = filter (CLICK function) bypassed, 1 = filter enabled
    bool hp_ia2;        // Bit 1. 0 = filter disabled for AOI fn on Interrupt 2, 1 = filter enabled
    bool hp_ia1;        // Bit 0. 0 = filter disabled for AOI fn on Interrupt 1, 1 = filter enabled
} lis2dh12_ctrl_reg2_s;


typedef struct lis2dh12_ctrl_reg3_struct {
    bool i1_click;      // Bit 7. CLICK interrupt on INT1 pin. 0 = disable, 1 = enable
    bool i1_ia1;        // Bit 6. IA1 interrupt on INT1 pin. 0 = disable, 1 = enable
    bool i1_ia2;        // Bit 5. IA2 interrupt on INT1 pin. 0 = disable, 1 = enable
    bool i1_zyxda;      // Bit 4. ZYXDA interrupt on INT1 pin. 0 = disable, 1 = enable
    // Bit 3 should always be set to 0
    bool i1_wtm;        // Bit 2. FIFO watermark interrupt on INT1 pin. 0 = disable, 1 = enable
    bool i1_overrun;    // Bit 1. FIFO overrun interrupt on INT1 pin. 0 = disable, 1 = enable
    // Bit 0 don't care
} lis2dh12_ctrl_reg3_s;


typedef enum {
    // [FS1, FS0]
    LIS2DH12_FS_2G = 0b00,
    LIS2DH12_FS_4G = 0b01,
    LIS2DH12_FS_8G = 0b10,
    LIS2DH12_FS_16G = 0b11,
} LIS2DH12_FS_e;    // Full-scale selection

typedef enum {
    // [ST1, ST0]
    LIS2DH12_ST_NORMAL_MODE = 0b00,
    LIS2DH12_ST_SELF_TEST0 = 0b01,
    LIS2DH12_ST_SELF_TEST1 = 0b10,
} LIS2DH12_ST_e;    // Self-test mode

typedef struct lis2dh12_ctrl_reg4_struct {
    bool bdu;           // Bit 7. Block data update. 0 = continuous update, 1 = output regs not updated until MSB and LSB read
    bool ble;           // Bit 6. Big/little Endian select (only in high-res mode). 0 = data LSB at lower address, 1 = data MSB at lower address
    LIS2DH12_FS_e fs;   // Bits [5:4]. Full-scale selection, see enum values
    bool hr;            // Bit 3. Operating mode selection. 0 for low-power or normal mode, 1 for high-res mode (can't be used with LPen=1). See Table 10 in datasheet
    LIS2DH12_ST_e st;   // Bits [2:1]. Self-test selection, see enum values
    bool sim;           // Bit 0. SPI mode selection. 0 = 4-wire (default), 1 = 3-wire
} lis2dh12_ctrl_reg4_s;


typedef struct lis2dh12_ctrl_reg5_struct {
    bool boot;      // Bit 7. Reboot memory content. 0 = normal mode (default), 1 = reboot memory content
    bool fifo_en;   // Bit 6. 0 = FIFO disabled (default), 1 = FIFO enabled
    // Bits [5:4] don't care
    bool lir_int1;  // Bit 3. Latch interrupt request on INT1. 0 = interrupt request not latched, 1 = latched
    bool d4d_int1;  // Bit 2. 4D enable on INT1 pin, not clear what value to use? Just leave as 0 for now
    bool lir_int2;  // Bit 1. Latch interrupt request on INT2. 0 = interrupt request not latched, 1 = latched
    bool d4d_int2;  // Bit 0. 4D enable on INT2 pin, not clear what value to use? Just leave as 0 for now
} lis2dh12_ctrl_reg5_s;


typedef struct lis2dh12_ctrl_reg6_struct {
    bool i2_click;      // Bit 7. Click interrupt on INT2 pin. 0 = disabled (default), 1 = enabled
    bool i2_ia1;        // Bit 6. Enable interrupt 1 fn on INT2 pin. 0 = disabled (default), 1 = enabled
    bool i2_ia2;        // Bit 5. Enable interrupt 2 fn on INT2 pin. 0 = disabled (default), 1 = enabled
    bool i2_boot;       // Bit 4. Enable boot on INT2 pin. 0 = disabled (default), 1 = enabled
    bool i2_act;        // Bit 3. Enable activity interrupt on INT2 pin. 0 = disabled (default), 1 = enabled
    // Bit 2 don't care
    bool int_polarity;  // Bit 1. INT1 and INT2 pin polarity. 0 = active-high (default), 1 = active-low
    // Bit 0 don't care
} lis2dh12_ctrl_reg6_s;


typedef struct lis2h12_temp_cfg_struct {
    bool temp_en;   // Bits [7:6]. 00 = temp sensor disabled, 11 = enabled
    // Bits [5:0] should be set to 0
} lis2h12_temp_cfg_s;
