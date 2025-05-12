#include <stdio.h>                // Biblioteca padrão de entrada e saída (usada para printf)
#include "freertos/FreeRTOS.h"    // Inclui definições do sistema operacional FreeRTOS
#include "freertos/task.h"        // Inclui funções para manipulação de tarefas (como vTaskDelay)


#include "relay.h"               // Inclui o cabeçalho do componente Relay (definição da struct e funções)

// Define os pinos dos relés
#define RELAY1_PIN 3           // Define o número do pino para o relé 1 (exemplo: GPIO3)
    #define RELAY2_PIN 33      // Define o número do pino para o relé 2 (exemplo: GPIO33)


void app_main(void)           // Função principal executada ao iniciar o programa (no ESP-IDF) 
{
    
    Relay relay1, relay2;         // Declara duas variáveis do tipo Relay para controlar dois relés

    // Inicializa os relés
    relay_init(&relay1, RELAY1_PIN);    // Inicializa o relé 1 no pino definido (configura como saída e desliga)
    relay_init(&relay2, RELAY2_PIN);    // Inicializa o relé 2 da mesma forma

    while(1){                                                           // Loop infinito que alterna os estados dos relés a cada 5 segundos
        relay_turn_on(&relay1);                                         // Liga o relé 1
        printf("Status do relé 1: %d\n", relay_get_status(&relay1));    // Imprime o status do relé 1
        relay_turn_off(&relay2);                                        // Desliga o relé 2
        printf("Status do relé 2: %d\n", relay_get_status(&relay2));    // Imprime o status do relé 2
        vTaskDelay(5000 / portTICK_PERIOD_MS);                          // Aguarda 5 segundos
        relay_turn_off(&relay1);                                        // Desliga o relé 1
        printf("Status do relé 1: %d\n", relay_get_status(&relay1));    // Imprime o status do relé 1
        relay_turn_on(&relay2);                                         // Liga o relé 2
        printf("Status do relé 2: %d\n", relay_get_status(&relay2));    // Imprime o status do relé 2
        vTaskDelay(5000 / portTICK_PERIOD_MS);                          // Aguarda 5 segundos
    }   
}
