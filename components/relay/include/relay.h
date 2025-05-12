#ifndef RELAY_H   // Verifica se RELAY_H já foi definido anteriormente
#define RELAY_H   // Define RELAY_H (usado para proteção contra múltiplas inclusões)

//----------------------------------------------------------------------------------------------------------------

// Estrutura para armazenar as características do relé
typedef struct {
    int pin;        // Armazena o número do pino GPIO conectado ao relé
    int state;      // Armazena o estado atual do relé: 0 = desligado, 1 = ligado
} Relay;            // Define o nome da estrutura como 'Relay'

//----------------------------------------------------------------------------------------------------------------

// Função de inicialização do componente relé
void relay_init(Relay *relay, int pin);         
// Inicializa o relé:
// - Armazena o número do pino na struct
// - Define o pino como saída
// - Inicializa o relé desligado (nível baixo)

//----------------------------------------------------------------------------------------------------------------

// Função para ligar o relé
void relay_turn_on(Relay *relay);    
// Liga o relé:
// - Atualiza o estado para 1
// - Seta o pino como nível lógico alto

//----------------------------------------------------------------------------------------------------------------

// Função para desligar o relé
void relay_turn_off(Relay *relay);  
// Desliga o relé:
// - Atualiza o estado para 0
// - Seta o pino como nível lógico baixo

//----------------------------------------------------------------------------------------------------------------

// Função para obter o status do relé
int relay_get_status(Relay *relay);       
// Retorna o estado atual do relé:
// - 0 se estiver desligado
// - 1 se estiver ligado

#endif           // Fim do bloco de proteção contra múltiplas inclusões