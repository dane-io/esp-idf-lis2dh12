#pragma once

#include <stdint.h>
#include <esp_check.h>
#include <lis2dh12_regs.h>
#include <driver/i2c_master.h>


#define LIS2DH12_I2C_TRANSFER_TIMEOUT_MS 100


typedef struct lis2dh12_ctrl_struct {
    lis2dh12_ctrl_reg0_s reg0;
    lis2dh12_ctrl_reg1_s reg1;
    lis2dh12_ctrl_reg2_s reg2;
    lis2dh12_ctrl_reg3_s reg3;
    lis2dh12_ctrl_reg4_s reg4;
    lis2dh12_ctrl_reg5_s reg5;
    lis2dh12_ctrl_reg6_s reg6;
} lis2dh12_ctrl_s;


typedef struct lis2dh12_dev_struct {
    i2c_master_dev_handle_t device_handle;
    lis2dh12_ctrl_s config;
} lis2dh12_dev_s;


typedef struct lis2dh12_output_struct {
    int32_t x;  // In mg
    int32_t y;  // In mg
    int32_t z;  // In mg
    bool fresh;
    bool overrun;
} lis2dh12_output_s;


esp_err_t LIS2DH12_write_ctrl_regs(lis2dh12_dev_s accel);
esp_err_t LIS2DH12_read_accel(lis2dh12_dev_s accel, lis2dh12_output_s *output);
lis2dh12_dev_s LIS2DH12_default_config(i2c_master_dev_handle_t dev_handle);
