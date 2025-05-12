#include <stdio.h>
#include "relay.h"
#include "driver/gpio.h"

// Função de inicialização do componente relé
void relay_init(Relay *relay, int pin) {
    relay->pin = pin;
    relay->state = 0;
    gpio_set_direction(relay->pin, GPIO_MODE_OUTPUT);
    gpio_set_level(relay->pin, relay->state);
}

// Função para ligar o relé
void relay_turn_on(Relay *relay) {
    relay->state = 1;
    gpio_set_level(relay->pin, relay->state);
}

// Função para desligar o relé
void relay_turn_off(Relay *relay) {
    relay->state = 0;
    gpio_set_level(relay->pin, relay->state);

}

//
int relay_get_status(Relay *relay) {
    return relay->state;
}
