#ifndef SERVO_LED_H
#define SERVO_LED_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição dos pinos
#define SERVO_PIN 22
#define LED_PIN_BLUE 12

// Configuração do PWM
#define PWM_WRAP 20000

// Declaração das funções
void definir_posicao_servo(uint slice, uint canal, uint duty_us);
void movimentacao_suave_servo(uint slice, uint canal);
void definir_brilho_led(uint slice, uint canal, uint duty);
void efeito_pisca_led(uint slice, uint canal);

#endif // SERVO_LED_H
