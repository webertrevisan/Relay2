#include <stdio.h>        // Biblioteca padrão de entrada/saída (usada para debug com printf, se necessário)
#include "relay.h"        // Inclui o cabeçalho com a definição da struct Relay e as declarações das funções
#include "driver/gpio.h"  // Inclui as funções da ESP-IDF para controle dos pinos GPIO

// Função de inicialização do componente relé
void relay_init(Relay *relay, int pin) {
    relay->pin = pin;                                  // Guarda o número do pino
    relay->state = 0;                                  // Começa desligado
    gpio_set_direction(relay->pin, GPIO_MODE_OUTPUT);  // Define como saída
    gpio_set_level(relay->pin, relay->state);          // Envia nível 0 (desligado)
}

//----------------------------------------------------------------------------------------------------------------

// Função para ligar o relé
void relay_turn_on(Relay *relay) {              // Define função para ligar o relé
    relay->state = 1;                           // Atualiza o estado interno para "ligado"
    gpio_set_level(relay->pin, relay->state);   // Envia nível alto para o GPIO (liga o relé fisicamente)
}

//----------------------------------------------------------------------------------------------------------------

// Função para desligar o relé
void relay_turn_off(Relay *relay) {             // Define função para desligar o relé
    relay->state = 0;                           // Atualiza o estado interno para "desligado"
    gpio_set_level(relay->pin, relay->state);   // Envia nível baixo para o GPIO (desliga o relé fisicamente)

}

//----------------------------------------------------------------------------------------------------------------

//
int relay_get_status(Relay *relay) {  // Define função que retorna o status do relé
    return relay->state;              // Retorna o valor armazenado no campo "state" (0 ou 1) 
}
