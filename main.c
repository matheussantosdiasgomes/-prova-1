#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarGerador() {
    srand(time(NULL));
}

int sortearPortaPremiada() {
    return rand() % 3 + 1;
}

int escolherPorta() {
    int escolha;
    printf("Escolha uma porta (1, 2 ou 3): ");
    scanf("%d", &escolha);
    while (escolha < 1 || escolha > 3) {
        printf("Escolha inválida. Por favor, escolha uma porta válida (1, 2 ou 3): ");
        scanf("%d", &escolha);
    }
    return escolha;
}

int revelarPorta(int portaPremiada, int escolhaJogador) {
    int portaRevelada;
    do {
        portaRevelada = rand() % 3 + 1;
    } while (portaRevelada == portaPremiada || portaRevelada == escolhaJogador);
    printf("O apresentador abriu a porta %d que está vazia.\n", portaRevelada);
    return portaRevelada;
}

int trocarPorta(int escolhaJogador, int portaRevelada) {
    char opcao;
    printf("Você deseja trocar para a outra porta? (s/n): ");
    scanf(" %c", &opcao);
    while (opcao != 's' && opcao != 'n') {
        printf("Opção inválida. Por favor, escolha 's' para sim ou 'n' para não: ");
        scanf(" %c", &opcao);
    }
    if (opcao == 's') {
        int novaEscolha;
        do {
            novaEscolha = rand() % 3 + 1;
        } while (novaEscolha == escolhaJogador || novaEscolha == portaRevelada);
        printf("Você trocou para a porta %d.\n", novaEscolha);
        return novaEscolha;
    } else {
        printf("Você optou por manter a porta %d.\n", escolhaJogador);
        return escolhaJogador;
    }
}

int verificarGanhador(int portaPremiada, int escolhaFinal) {
    return portaPremiada == escolhaFinal;
}

int main() {
    int portaPremiada, escolhaJogador, portaRevelada, escolhaFinal;

    inicializarGerador();
    portaPremiada = sortearPortaPremiada();

    printf("Bem-vindo ao jogo Monty Hall!\n");
    escolhaJogador = escolherPorta();

    portaRevelada = revelarPorta(portaPremiada, escolhaJogador);

    escolhaFinal = trocarPorta(escolhaJogador, portaRevelada);

    if (verificarGanhador(portaPremiada, escolhaFinal)) {
        printf("Parabéns! Você ganhou o prêmio!\n");
    } else {
        printf("Que pena! Você não ganhou o prêmio.\n");
    }

    return 0;
}
