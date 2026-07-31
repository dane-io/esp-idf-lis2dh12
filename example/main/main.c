#include <inttypes.h>

#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <esp_err.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "lis2dh12.h"

#define I2C_PORT         I2C_NUM_0
#define I2C_SDA          GPIO_NUM_10
#define I2C_SCL          GPIO_NUM_11
#define I2C_FREQUENCY_HZ 100000
#define LIS2DH12_ADDR    0x19

static const char TAG[] = "lis2dh12_example";

void app_main(void)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_PORT,
        .sda_io_num = I2C_SDA,
        .scl_io_num = I2C_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));

    i2c_device_config_t device_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = LIS2DH12_ADDR,
        .scl_speed_hz = I2C_FREQUENCY_HZ,
    };

    i2c_master_dev_handle_t device_handle;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle,&device_config,&device_handle));
    lis2dh12_dev_s accel = LIS2DH12_default_config(device_handle);
    ESP_ERROR_CHECK(LIS2DH12_write_ctrl_regs(accel));

    ESP_LOGI(TAG, "LIS2DH12 configured");

    while (true) {
        // Default sample rate is 1 Hz, wait slightly longer than 1 sec
        vTaskDelay(pdMS_TO_TICKS(1100));

        lis2dh12_output_s output = {0};

        esp_err_t err = LIS2DH12_read_accel(accel, &output);

        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Read failed: %s", esp_err_to_name(err));
            continue;
        }

        if (!output.fresh) {
            ESP_LOGD(TAG, "No new sample");
            continue;
        }

        if (output.overrun) {
            ESP_LOGW(TAG, "One or more samples were missed");
        }

        ESP_LOGI(TAG, "x=%ld mg, y=%ld mg, z=%ld mg", output.x, output.y, output.z);
    }
}
