#include <lis2dh12.h>
#include <esp_log.h>


static const char TAG[] = "LIS2DH12_driver";


static esp_err_t LIS2DH12_write_ctrl_reg0(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG0_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg0.sdo_pu_disc << 7;
    buf_to_send[1] |= 1 << 4;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG0");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG0: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg1(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG1_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg1.odr << 4;
    buf_to_send[1] |= accel.config.reg1.lpen << 3;
    buf_to_send[1] |= accel.config.reg1.zen << 2;
    buf_to_send[1] |= accel.config.reg1.yen << 1;
    buf_to_send[1] |= accel.config.reg1.xen << 0;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG1");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG1: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg2(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG2_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg2.hpm << 6;
    buf_to_send[1] |= accel.config.reg2.hpcf << 4;
    buf_to_send[1] |= accel.config.reg2.fds << 3;
    buf_to_send[1] |= accel.config.reg2.hpclick << 2;
    buf_to_send[1] |= accel.config.reg2.hp_ia2 << 1;
    buf_to_send[1] |= accel.config.reg2.hp_ia1 << 0;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG2");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG2: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg3(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG3_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg3.i1_click << 7;
    buf_to_send[1] |= accel.config.reg3.i1_ia1 << 6;
    buf_to_send[1] |= accel.config.reg3.i1_ia2 << 5;
    buf_to_send[1] |= accel.config.reg3.i1_zyxda << 4;
    buf_to_send[1] |= accel.config.reg3.i1_wtm << 2;
    buf_to_send[1] |= accel.config.reg3.i1_overrun << 1;


    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG3");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG3: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg4(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG4_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg4.bdu << 7;
    buf_to_send[1] |= accel.config.reg4.ble << 6;
    buf_to_send[1] |= accel.config.reg4.fs << 4;
    buf_to_send[1] |= accel.config.reg4.hr << 3;
    buf_to_send[1] |= accel.config.reg4.st << 1;
    buf_to_send[1] |= accel.config.reg4.sim << 0;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG4");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG4: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg5(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG5_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg5.boot << 7;
    buf_to_send[1] |= accel.config.reg5.fifo_en << 6;
    buf_to_send[1] |= accel.config.reg5.lir_int1 << 3;
    buf_to_send[1] |= accel.config.reg5.d4d_int1 << 2;
    buf_to_send[1] |= accel.config.reg5.lir_int2 << 1;
    buf_to_send[1] |= accel.config.reg5.d4d_int2 << 0;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG5");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG5: %d", err);
    }
    return err;
}


static esp_err_t LIS2DH12_write_ctrl_reg6(lis2dh12_dev_s accel) {
    uint8_t buf_to_send[2] = {LIS2DH12_CTRL_REG6_ADDR, 0x00};
    buf_to_send[1] |= accel.config.reg6.i2_click << 7;
    buf_to_send[1] |= accel.config.reg6.i2_ia1 << 6;
    buf_to_send[1] |= accel.config.reg6.i2_ia2 << 5;
    buf_to_send[1] |= accel.config.reg6.i2_boot << 4;
    buf_to_send[1] |= accel.config.reg6.i2_act << 3;
    buf_to_send[1] |= accel.config.reg6.int_polarity << 1;

    esp_err_t err = i2c_master_transmit(accel.device_handle, buf_to_send, sizeof(buf_to_send), LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err == ESP_OK) {
        ESP_LOGD(TAG, "Wrote CTRL_REG6");
    }
    else {
        ESP_LOGD(TAG, "Failed to write CTRL_REG6: %d", err);
    }
    return err;
}


esp_err_t LIS2DH12_write_ctrl_regs(lis2dh12_dev_s accel) {
    if (accel.config.reg1.lpen == 1 && accel.config.reg4.hr == 1) {
        ESP_LOGD(TAG, "Can't set both LPEN and HR!");
        return ESP_ERR_INVALID_ARG;
    }

    esp_err_t return_err = ESP_OK;
    esp_err_t err;

    err = LIS2DH12_write_ctrl_reg0(accel);
    if (err != ESP_OK) { return_err = err; }
    err = LIS2DH12_write_ctrl_reg2(accel);
    if (err != ESP_OK) { return_err = err; }
    err = LIS2DH12_write_ctrl_reg3(accel);
    if (err != ESP_OK) { return_err = err; }
    err = LIS2DH12_write_ctrl_reg4(accel);
    if (err != ESP_OK) { return_err = err; }
    err = LIS2DH12_write_ctrl_reg5(accel);
    if (err != ESP_OK) { return_err = err; }
    err = LIS2DH12_write_ctrl_reg6(accel);
    if (err != ESP_OK) { return_err = err; }
    // Write CTRL REG1 last since nonzero ODR could start sampling
    err = LIS2DH12_write_ctrl_reg1(accel);
    if (err != ESP_OK) { return_err = err; }

    return return_err;
}


static int16_t LIS2DH12_convert_full_scale_multiplier(lis2dh12_dev_s accel) {
    int16_t fs_multiplier = 1;
    switch (accel.config.reg4.fs) {
        case LIS2DH12_FS_2G:
            fs_multiplier = 1;
            break;
        case LIS2DH12_FS_4G:
            fs_multiplier = 2;
            break;
        case LIS2DH12_FS_8G:
            fs_multiplier = 4;
            break;
        case LIS2DH12_FS_16G:
            fs_multiplier = 12;
            break;
    }

    int16_t power_mode_multiplier = 1;
    // Low power
    if (accel.config.reg1.lpen == 1) {
        power_mode_multiplier = 16;
    }
    // Normal
    else if (accel.config.reg4.hr == 0) {
        power_mode_multiplier = 4;
    }
    // High resolution
    else {
        power_mode_multiplier = 1;
    }

    return fs_multiplier * power_mode_multiplier;
}


static int16_t LIS2DH12_convert_full_scale_divisor(lis2dh12_dev_s accel) {
    int16_t divisor = 1;
    // Low power
    if (accel.config.reg1.lpen == 1) {
        // 8 bit
        divisor = 256;
    }
    // Normal
    else if (accel.config.reg4.hr == 0) {
        // 10 bit
        divisor = 64;
    }
    // High resolution
    else {
        // 12 bit
        divisor = 16;
    }

    return divisor;
}


esp_err_t LIS2DH12_read_accel(lis2dh12_dev_s accel, lis2dh12_output_s *output) {
    // Make sure output isn't null pointer
    if (!output) {
        return ESP_ERR_INVALID_ARG;
    }

    // Make sure endianness is correct
    if (accel.config.reg4.ble != 0) {
        ESP_LOGD(TAG, "BLE must be set to 0!");
        return ESP_ERR_INVALID_ARG;
    }

    // Make sure BDU enabled
    if (!accel.config.reg4.bdu) {
        ESP_LOGD(TAG, "BDU must be enabled for coherent XYZ reads");
        return ESP_ERR_INVALID_ARG;
    }

    // Read status and accel data registers
    uint8_t write_buf = LIS2DH12_STATUS_REG_ADDR | 0x80;    // Setting MSB to 1 allows sequential reads. Accel data is right after status
    uint8_t read_buf[7];
    esp_err_t err = i2c_master_transmit_receive(accel.device_handle, &write_buf, 1, read_buf, 7, LIS2DH12_I2C_TRANSFER_TIMEOUT_MS);
    if (err != ESP_OK) {
        ESP_LOGD(TAG, "Failed to read status register: %d", err);
        return err;
    }
    output->overrun = read_buf[0] & 0x80;
    output->fresh = read_buf[0] & 0x08;

    // Left justified data
    int16_t raw_x = (int16_t)(((uint16_t)read_buf[2] << 8) | read_buf[1]);
    int16_t raw_y = (int16_t)(((uint16_t)read_buf[4] << 8) | read_buf[3]);
    int16_t raw_z = (int16_t)(((uint16_t)read_buf[6] << 8) | read_buf[5]);

    int16_t scale = LIS2DH12_convert_full_scale_multiplier(accel);
    int16_t divisor = LIS2DH12_convert_full_scale_divisor(accel);

    output->x = ((int32_t)raw_x / divisor) * scale;
    output->y = ((int32_t)raw_y / divisor) * scale;
    output->z = ((int32_t)raw_z / divisor) * scale;

    return ESP_OK;
}


lis2dh12_dev_s LIS2DH12_default_config(i2c_master_dev_handle_t dev_handle) {
    lis2dh12_dev_s accel = {
        .config = {
            .reg0 = {
                .sdo_pu_disc = 0,
            },
            .reg1 = {
                .odr = LIS2DH12_ODR_FREQ_1HZ_MODE,
                .lpen = 0,
                .xen = 1,
                .yen = 1,
                .zen = 1,
            },
            .reg2 = {
                .hpm = LIS2DH12_HPM_NORMAL_RESET_MODE,
                .hpcf = 0,
                .fds = 0,
                .hpclick = 0,
                .hp_ia1 = 0,
                .hp_ia2 = 0,
            },
            .reg3 = {
                .i1_click = 0,
                .i1_ia1 = 0,
                .i1_ia2 = 0,
                .i1_zyxda = 0,
                .i1_wtm = 0,
                .i1_overrun = 0,
            },
            .reg4 = {
                .bdu = 1,
                .ble = 0,
                .fs = LIS2DH12_FS_2G,
                .hr = 0,
                .st = LIS2DH12_ST_NORMAL_MODE,
                .sim = 0,
            },
            .reg5 = {
                .boot = 0,
                .fifo_en = 0,
                .lir_int1 = 0,
                .lir_int2 = 0,
                .d4d_int1 = 0,
                .d4d_int2 = 0,
            },
            .reg6 = {
                .i2_click = 0,
                .i2_ia1 = 0,
                .i2_ia2 = 0,
                .i2_boot = 0,
                .i2_act = 0,
                .int_polarity = 0,
            }
        },

        .device_handle = dev_handle,
    };

    return accel;
}
