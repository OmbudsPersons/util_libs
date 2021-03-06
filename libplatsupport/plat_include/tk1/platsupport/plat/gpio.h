/*
 * Copyright 2016, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <utils/util.h>

#define GPIO_PADDR_BASE    0x6000D000

enum gpio_pad_mode {
        GPIO_MODE = 0,
        SFIO_MODE
};

enum gpio_mode {
        GPIO_MODE_OUTPUT = 0,
        GPIO_MODE_INPUT
};

enum gpio_int_type {
        GPIO_INT_RISING_EDGE = 0,
        GPIO_INT_FALLING_EDGE,
        GPIO_INT_BOTH_EDGE,
        GPIO_INT_HIGH_LVL,
        GPIO_INT_LOW_LVL
};

enum gpio_int_enb {
        GPIO_INT_ENABLE = 0,
        GPIO_INT_DISABLE
};

enum gpio_bank {
        GPIO_BANK_1 = 0,
        GPIO_BANK_2,
        GPIO_BANK_3,
        GPIO_BANK_4,
        GPIO_BANK_5,
        GPIO_BANK_6,
        GPIO_BANK_7,
        GPIO_BANK_8,
};

enum gpio_pin {
        GPIO_PA0 = 0,    /* pin 0 */
        GPIO_PA1,
        GPIO_PA2,
        GPIO_PA3,
        GPIO_PA4,
        GPIO_PA5,
        GPIO_PA6,
        GPIO_PA7,
        GPIO_PB0 = 8,    /* pin 8 */
        GPIO_PB1,
        GPIO_PB2,
        GPIO_PB3,
        GPIO_PB4,
        GPIO_PB5,
        GPIO_PB6,
        GPIO_PB7,
        GPIO_PC0,    /* pin 16 */
        GPIO_PC1,
        GPIO_PC2,
        GPIO_PC3,
        GPIO_PC4,
        GPIO_PC5,
        GPIO_PC6,
        GPIO_PC7,
        GPIO_PD0,    /* pin 24 */
        GPIO_PD1,
        GPIO_PD2,
        GPIO_PD3,
        GPIO_PD4,
        GPIO_PD5,
        GPIO_PD6,
        GPIO_PD7,
        GPIO_PE0,    /* pin 32 */
        GPIO_PE1,
        GPIO_PE2,
        GPIO_PE3,
        GPIO_PE4,
        GPIO_PE5,
        GPIO_PE6,
        GPIO_PE7,
        GPIO_PF0,    /* pin 40 */
        GPIO_PF1,
        GPIO_PF2,
        GPIO_PF3,
        GPIO_PF4,
        GPIO_PF5,
        GPIO_PF6,
        GPIO_PF7,
        GPIO_PG0,    /* pin 48 */
        GPIO_PG1,
        GPIO_PG2,
        GPIO_PG3,
        GPIO_PG4,
        GPIO_PG5,
        GPIO_PG6,
        GPIO_PG7,
        GPIO_PH0,    /* pin 56 */
        GPIO_PH1,
        GPIO_PH2,
        GPIO_PH3,
        GPIO_PH4,
        GPIO_PH5,
        GPIO_PH6,
        GPIO_PH7,
        GPIO_PI0,    /* pin 64 */
        GPIO_PI1,
        GPIO_PI2,
        GPIO_PI3,
        GPIO_PI4,
        GPIO_PI5,
        GPIO_PI6,
        GPIO_PI7,
        GPIO_PJ0,    /* pin 72 */
        GPIO_PJ1,
        GPIO_PJ2,
        GPIO_PJ3,
        GPIO_PJ4,
        GPIO_PJ5,
        GPIO_PJ6,
        GPIO_PJ7,
        GPIO_PK0,    /* pin 80 */
        GPIO_PK1,
        GPIO_PK2,
        GPIO_PK3,
        GPIO_PK4,
        GPIO_PK5,
        GPIO_PK6,
        GPIO_PK7,
        GPIO_PL0,    /* pin 88 */
        GPIO_PL1,
        GPIO_PL2,
        GPIO_PL3,
        GPIO_PL4,
        GPIO_PL5,
        GPIO_PL6,
        GPIO_PL7,
        GPIO_PM0,    /* pin 96 */
        GPIO_PM1,
        GPIO_PM2,
        GPIO_PM3,
        GPIO_PM4,
        GPIO_PM5,
        GPIO_PM6,
        GPIO_PM7,
        GPIO_PN0,    /* pin 104 */
        GPIO_PN1,
        GPIO_PN2,
        GPIO_PN3,
        GPIO_PN4,
        GPIO_PN5,
        GPIO_PN6,
        GPIO_PN7,
        GPIO_PO0,    /* pin 112 */
        GPIO_PO1,
        GPIO_PO2,
        GPIO_PO3,
        GPIO_PO4,
        GPIO_PO5,
        GPIO_PO6,
        GPIO_PO7,
        GPIO_PP0,    /* pin 120 */
        GPIO_PP1,
        GPIO_PP2,
        GPIO_PP3,
        GPIO_PP4,
        GPIO_PP5,
        GPIO_PP6,
        GPIO_PP7,
        GPIO_PQ0,    /* pin 128 */
        GPIO_PQ1,
        GPIO_PQ2,
        GPIO_PQ3,
        GPIO_PQ4,
        GPIO_PQ5,
        GPIO_PQ6,
        GPIO_PQ7,
        GPIO_PR0,    /* pin 136 */
        GPIO_PR1,
        GPIO_PR2,
        GPIO_PR3,
        GPIO_PR4,
        GPIO_PR5,
        GPIO_PR6,
        GPIO_PR7,
        GPIO_PS0,    /* pin 144 */
        GPIO_PS1,
        GPIO_PS2,
        GPIO_PS3,
        GPIO_PS4,
        GPIO_PS5,
        GPIO_PS6,
        GPIO_PS7,
        GPIO_PT0,    /* pin 152 */
        GPIO_PT1,
        GPIO_PT2,
        GPIO_PT3,
        GPIO_PT4,
        GPIO_PT5,
        GPIO_PT6,
        GPIO_PT7,
        GPIO_PU0,    /* pin 160 */
        GPIO_PU1,
        GPIO_PU2,
        GPIO_PU3,
        GPIO_PU4,
        GPIO_PU5,
        GPIO_PU6,
        GPIO_PU7,
        GPIO_PV0,    /* pin 168 */
        GPIO_PV1,
        GPIO_PV2,
        GPIO_PV3,
        GPIO_PV4,
        GPIO_PV5,
        GPIO_PV6,
        GPIO_PV7,
        GPIO_PW0,    /* pin 176 */
        GPIO_PW1,
        GPIO_PW2,
        GPIO_PW3,
        GPIO_PW4,
        GPIO_PW5,
        GPIO_PW6,
        GPIO_PW7,
        GPIO_PX0,    /* pin 184 */
        GPIO_PX1,
        GPIO_PX2,
        GPIO_PX3,
        GPIO_PX4,
        GPIO_PX5,
        GPIO_PX6,
        GPIO_PX7,
        GPIO_PY0,    /* pin 192 */
        GPIO_PY1,
        GPIO_PY2,
        GPIO_PY3,
        GPIO_PY4,
        GPIO_PY5,
        GPIO_PY6,
        GPIO_PY7,
        GPIO_PZ0,    /* pin 200 */
        GPIO_PZ1,
        GPIO_PZ2,
        GPIO_PZ3,
        GPIO_PZ4,
        GPIO_PZ5,
        GPIO_PZ6,
        GPIO_PZ7,
        GPIO_PAA0,    /* pin 208 */
        GPIO_PAA1,
        GPIO_PAA2,
        GPIO_PAA3,
        GPIO_PAA4,
        GPIO_PAA5,
        GPIO_PAA6,
        GPIO_PAA7,
        GPIO_PBB0,    /* pin 216 */
        GPIO_PBB1,
        GPIO_PBB2,
        GPIO_PBB3,
        GPIO_PBB4,
        GPIO_PBB5,
        GPIO_PBB6,
        GPIO_PBB7,
        GPIO_PCC0,    /* pin 224 */
        GPIO_PCC1,
        GPIO_PCC2,
        GPIO_PCC3,
        GPIO_PCC4,
        GPIO_PCC5,
        GPIO_PCC6,
        GPIO_PCC7,
        GPIO_PDD0,    /* pin 232 */
        GPIO_PDD1,
        GPIO_PDD2,
        GPIO_PDD3,
        GPIO_PDD4,
        GPIO_PDD5,
        GPIO_PDD6,
        GPIO_PDD7,
        GPIO_PEE0,    /* pin 240 */
        GPIO_PEE1,
        GPIO_PEE2,
        GPIO_PEE3,
        GPIO_PEE4,
        GPIO_PEE5,
        GPIO_PEE6,
        GPIO_PEE7,
        GPIO_PFF0,    /* pin 248 */
        GPIO_PFF1,
        GPIO_PFF2,
        GPIO_PFF3,
        GPIO_PFF4,
        GPIO_PFF5,
        GPIO_PFF6,
        GPIO_PFF7,    /* pin 255 */
        GPIOPORT_NONE,
};

enum gpio_features_indexes {
   CAN1_INTn = 0,
   CAN1_CS,
   CAN2_CS,
   USB_VBUS_EN1,
};

struct gpio_feature_data {
    int pin_number;
    enum gpio_int_enb int_enb;
    enum gpio_int_type int_type;
    enum gpio_mode mode;
    bool default_value;
};

/* mux_sys will be stored by this init and must live for as long as the gpio
 * subsystem is used for */
void gpio_init(volatile void *vaddr, mux_sys_t *mux_sys, gpio_sys_t *gpio_sys);

void gpio_set_pad_mode(gpio_sys_t *gpio_sys, enum gpio_pin gpio, enum gpio_pad_mode mode);

void gpio_set_level(gpio_sys_t *gpio_sys, enum gpio_pin gpio, int level);

void gpio_set_mode(gpio_sys_t *gpio_sys, enum gpio_pin gpio, enum gpio_mode mode);

bool gpio_get_input(gpio_sys_t *gpio_sys, enum gpio_pin gpio);

void gpio_set_interrupt_type(gpio_sys_t *gpio_sys, enum gpio_pin gpio, enum gpio_int_type type);

void gpio_interrupt_enable(gpio_sys_t *gpio_sys, enum gpio_pin gpio, enum gpio_int_enb setting);

bool gpio_check_pending(gpio_sys_t *gpio_sys, enum gpio_pin gpio);

void gpio_int_clear(gpio_sys_t *gpio_sys, enum gpio_pin gpio);
