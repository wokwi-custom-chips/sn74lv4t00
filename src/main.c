// SPDX-License-Identifier: MIT
// Copyright 2024 Algovoid

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    pin_t pin_1A;
    pin_t pin_1B;
    pin_t pin_1Y;
    pin_t pin_2A;
    pin_t pin_2B;
    pin_t pin_2Y;
    pin_t pin_3Y;
    pin_t pin_3A;
    pin_t pin_3B;
    pin_t pin_4Y;
    pin_t pin_4A;
    pin_t pin_4B;
} chip_state_t;


static void set_nand(chip_state_t *chip) {
  pin_write(chip->pin_1Y, !( pin_read(chip->pin_1A) & pin_read(chip->pin_1B) )  );
  pin_write(chip->pin_2Y, !( pin_read(chip->pin_2A) & pin_read(chip->pin_2B) )  );
  pin_write(chip->pin_3Y, !( pin_read(chip->pin_3A) & pin_read(chip->pin_3B) )  );
  pin_write(chip->pin_4Y, !( pin_read(chip->pin_4A) & pin_read(chip->pin_4B) )  );
}


static void chip_pin_change(void *user_data, pin_t pin, uint32_t value) {
  chip_state_t *chip = (chip_state_t*)user_data;
  set_nand(chip);
}


void chip_init() {
  printf("Initialize sn74lv4t00 chip!\n");
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  chip->pin_1A = pin_init("1A", INPUT);
  chip->pin_1B = pin_init("1B", INPUT);
  chip->pin_1Y = pin_init("1Y", OUTPUT);

  chip->pin_2A = pin_init("2A", INPUT);
  chip->pin_2B = pin_init("2B", INPUT);
  chip->pin_2Y = pin_init("2Y", OUTPUT);

  chip->pin_3A = pin_init("3A", INPUT);
  chip->pin_3B = pin_init("3B", INPUT);
  chip->pin_3Y = pin_init("3Y", OUTPUT);

  chip->pin_4A = pin_init("4A", INPUT);
  chip->pin_4B = pin_init("4B", INPUT);
  chip->pin_4Y = pin_init("4Y", OUTPUT);

  pin_write(chip->pin_1A, LOW);
  pin_write(chip->pin_1B, LOW);

  pin_write(chip->pin_2A, LOW);
  pin_write(chip->pin_2B, LOW);

  pin_write(chip->pin_3A, LOW);
  pin_write(chip->pin_3B, LOW);

  pin_write(chip->pin_4A, LOW);
  pin_write(chip->pin_4B, LOW);

  const pin_watch_config_t config = {
    .edge = BOTH,
    .pin_change = chip_pin_change,
    .user_data = chip,
  };

  pin_watch(chip->pin_1A, &config);
  pin_watch(chip->pin_1B, &config);

  pin_watch(chip->pin_2A, &config);
  pin_watch(chip->pin_2B, &config);

  pin_watch(chip->pin_3A, &config);
  pin_watch(chip->pin_3B, &config);

  pin_watch(chip->pin_4A, &config);
  pin_watch(chip->pin_4B, &config);  

  set_nand(chip);
}
