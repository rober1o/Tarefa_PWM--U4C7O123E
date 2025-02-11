#include "Tarefa__PWM.h"

// ======================== [ CONTROLE DO SERVO MOTOR ] ========================

// Define a posição do servo (em µs)
void definir_posicao_servo(uint slice, uint canal, uint duty_us) {
    pwm_set_chan_level(slice, canal, duty_us);
}

// Movimentação suave do servo de 0° a 180° e vice-versa
void movimentacao_suave_servo(uint slice, uint canal) {
    // Subindo (0° → 180°)
    for (uint duty = 500; duty <= 2400; duty += 5) {
        definir_posicao_servo(slice, canal, duty);
        sleep_ms(10);
    }

    // Descendo (180° → 0°)
    for (uint duty = 2400; duty >= 500; duty -= 5) {
        definir_posicao_servo(slice, canal, duty);
        sleep_ms(10);
    }
}

// ========================== [ CONTROLE DO LED ] =============================

// Define o brilho do LED
void definir_brilho_led(uint slice, uint canal, uint duty) {
    pwm_set_chan_level(slice, canal, duty);
}

// Aumenta e diminui o brilho do LED
void efeito_pisca_led(uint slice, uint canal) {
    // Aumentando brilho
    for (uint duty = 0; duty <= PWM_WRAP; duty += 500) {
        definir_brilho_led(slice, canal, duty);
        sleep_ms(10);
    }

    // Diminuindo brilho
    for (uint duty = PWM_WRAP; duty >= 0; duty -= 500) {
        definir_brilho_led(slice, canal, duty);
        sleep_ms(10);
    }
}

// ============================= [ FUNÇÃO PRINCIPAL ] =========================

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN_BLUE, GPIO_FUNC_PWM);

    // Configuração do Servo
    uint slice_servo = pwm_gpio_to_slice_num(SERVO_PIN);
    uint canal_servo = pwm_gpio_to_channel(SERVO_PIN);
    pwm_set_wrap(slice_servo, PWM_WRAP);
    pwm_set_clkdiv(slice_servo, 125.0f);
    pwm_set_enabled(slice_servo, true);

    // Configuração do LED
    uint slice_led = pwm_gpio_to_slice_num(LED_PIN_BLUE);
    uint canal_led = pwm_gpio_to_channel(LED_PIN_BLUE);
    pwm_set_wrap(slice_led, PWM_WRAP);
    pwm_set_clkdiv(slice_led, 125.0f);
    pwm_set_enabled(slice_led, true);

    // Teste inicial: posições fixas do servo
    definir_posicao_servo(slice_servo, canal_servo, 2400); // 180°
    sleep_ms(5000);

    definir_posicao_servo(slice_servo, canal_servo, 1470); // 90°
    sleep_ms(5000);

    definir_posicao_servo(slice_servo, canal_servo, 500); // 0°
    sleep_ms(5000);

    // Loop principal: controla servo e LED ao mesmo tempo
    while (1) {
        movimentacao_suave_servo(slice_servo, canal_servo); // Move o servo
        // efeito_pisca_led(slice_led, canal_led); // Controla o LED
    }
}
