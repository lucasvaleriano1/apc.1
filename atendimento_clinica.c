#include <stdio.h>
#include <string.h>

struct Atendimento {
    char nome[50];
    int idade;
    char data[11];
    char hora[6];
};

int main() {
    struct Atendimento atendimentos[100]; // Array to store up to 100 records
    int total = 0;
    int opcao;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Cadastrar atendimento\n");
        printf("2. Listar atendimentos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        while (getchar() != '\n'); // Clear input buffer

        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida! Escolha entre 1 e 3.\n");
            continue;
        }

        if (opcao == 1) {
            if (total >= 100) {
                printf("Limite de atendimentos atingido!\n");
                continue;
            }
            printf("Nome do paciente: ");
            fgets(atendimentos[total].nome, 50, stdin);
            atendimentos[total].nome[strcspn(atendimentos[total].nome, "\n")] = 0;
            while (strlen(atendimentos[total].nome) == 0) {
                printf("Nome nao pode ser vazio! Digite novamente: ");
                fgets(atendimentos[total].nome, 50, stdin);
                atendimentos[total].nome[strcspn(atendimentos[total].nome, "\n")] = 0;
            }
            do {
                printf("Idade (0-120): ");
                scanf("%d", &atendimentos[total].idade);
                while (getchar() != '\n');
                if (atendimentos[total].idade < 0 || atendimentos[total].idade > 120) {
                    printf("Idade invalida! Digite entre 0 e 120.\n");
                }
            } while (atendimentos[total].idade < 0 || atendimentos[total].idade > 120);
            printf("Data (dd/mm/aaaa): ");
            fgets(atendimentos[total].data, 11, stdin);
            atendimentos[total].data[strcspn(atendimentos[total].data, "\n")] = 0;
            while (strlen(atendimentos[total].data) == 0 || strlen(atendimentos[total].data) != 10 ||
                   atendimentos[total].data[2] != '/' || atendimentos[total].data[5] != '/') {
                printf("Data invalida! Use o formato dd/mm/aaaa: ");
                fgets(atendimentos[total].data, 11, stdin);
                atendimentos[total].data[strcspn(atendimentos[total].data, "\n")] = 0;
            }
            printf("Hora (hh:mm): ");
            fgets(atendimentos[total].hora, 6, stdin);
            atendimentos[total].hora[strcspn(atendimentos[total].hora, "\n")] = 0;
            while (strlen(atendimentos[total].hora) == 0 || strlen(atendimentos[total].hora) != 5 ||
                   atendimentos[total].hora[2] != ':') {
                printf("Hora invalida! Use o formato hh:mm: ");
                fgets(atendimentos[total].hora, 6, stdin);
                atendimentos[total].hora[strcspn(atendimentos[total].hora, "\n")] = 0;
            }
            total++;
            printf("Atendimento cadastrado com sucesso!\n");
        } else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum atendimento cadastrado.\n");
            } else {
                printf("\n=== Lista de Atendimentos ===\n");
                for (int i = 0; i < total; i++) {
                    printf("Atendimento %d:\n", i + 1);
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("Idade: %d\n", atendimentos[i].idade);
                    printf("Data: %s\n", atendimentos[i].data);
                    printf("Hora: %s\n", atendimentos[i].hora);
                    printf("------------------------\n");
                }
            }
        }
    } while (opcao != 3);

    printf("Programa finalizado.\n");
    return 0;
}