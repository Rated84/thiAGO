#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"
// login
void login(struct Usuario usuario) {
    char nome_digitado[50];
    char senha_digitada[50];

    while (1) {
        printf(" Usuário: ");
        scanf("%s", nome_digitado);

        printf(" Senha: ");
        scanf("%s", senha_digitada);

        
        if (strcmp(nome_digitado, usuario.nome) == 0 && strcmp(senha_digitada, usuario.senha) == 0) {
            printf("Logando!\n");
            break;
        } else {
            printf("Nome de usuário ou senha incorretos. Tente novamente.\n\n");
        }
    }
}

// verificar email
int verificar_email(char email[], struct Usuario usuarios[], int num_usuarios) {
    int i;

    
    if (strchr(email, '@') != NULL && strlen(email) < 80) {
    
        for (i = 0; i < num_usuarios; i++) {
            if (strcmp(email, usuarios[i].email) == 0) {
                return 0; 
            }
        }
        return 1; 
    }
    return 0;  
}

// cadastro
void cadastrar_email(struct Usuario usuarios[], int *num_usuarios) {
    char email[80];

    printf("Digite seu email: ");
    scanf("%s", email);

    if (verificar_email(email, usuarios, *num_usuarios)) {
        strcpy(usuarios[*num_usuarios].email, email);
        printf("Email cadastrado com sucesso!\n\n");
        (*num_usuarios)++;
    } else {
        printf("Email inválido ou já cadastrado.\n\n");
    }
}

// adição
void adicionar_jogo(struct Jogo jogos[], int *num_jogos) {
    if (*num_jogos < 100) {
        printf("Digite o nome do jogo: ");
        scanf("%s", jogos[*num_jogos].nome);

        printf("Digite o preço do jogo: ");
        scanf("%f", &jogos[*num_jogos].preco);

        (*num_jogos)++;
        printf("Jogo adicionado com sucesso!\n\n");
    } else {
        printf("Limite de jogos alcançado. Impossível adicionar mais jogos.\n\n");
    }
}

// pesquisa
void pesquisar_jogo(struct Jogo jogos[], int num_jogos) {
    char nome_pesquisa[50];
    int i;

    printf("Digite o nome do jogo: ");
    scanf("%s", nome_pesquisa);

    for (i = 0; i < num_jogos; i++) {
        if (strcmp(nome_pesquisa, jogos[i].nome) == 0) {
            printf("Jogo encontrado:\n");
            printf("Nome: %s\n", jogos[i].nome);
            printf("Preço: %.2f\n\n", jogos[i].preco);
            return;
        }
    }

    printf("Jogo não encontrado.\n\n");
}

// remover jogos
void remover_jogo(struct Jogo jogos[], int *num_jogos) {
    char nome_remover[50];
    int i, j;

    printf("Digite o nome do jogo: ");
    scanf("%s", nome_remover);

    for (i = 0; i < *num_jogos; i++) {
        if (strcmp(nome_remover, jogos[i].nome) == 0) {
            // Move os jogos subsequentes uma posição para trás
            for (j = i; j < *num_jogos - 1; j++) {
                strcpy(jogos[j].nome, jogos[j + 1].nome);
                jogos[j].preco = jogos[j + 1].preco;
            }
            (*num_jogos)--;
            printf("Jogo removido!\n\n");
            return;
        }
    }

    printf("Não encontrado.\n\n");
}

// jogos em promoção
void criar_lista_promocao(struct Jogo jogos[], int num_jogos, struct Jogo promocao[], int *num_promocao) {
    int i;
    *num_promocao = 0;

    for (i = 0; i < num_jogos; i++) {
        if (jogos[i].preco < 30) {
            strcpy(promocao[*num_promocao].nome, jogos[i].nome);
            promocao[*num_promocao].preco = jogos[i].preco;
            (*num_promocao)++;
        }
    }
}
void ordenar_jogos(struct Jogo promocao[], int num_promocao) {
    int i, j;
    struct Jogo temp;

    // Algoritmo de ordenação Bubble Sort
    for (i = 0; i < num_promocao - 1; i++) {
        for (j = 0; j < num_promocao - i - 1; j++) {
            if (promocao[j].preco > promocao[j + 1].preco) {
                // Troca de posição dos jogos
                temp = promocao[j];
                promocao[j] = promocao[j + 1];
                promocao[j + 1] = temp;
            }
        }
    }
}
// usuario
void alterar_usuario(struct Usuario *usuario) {
    printf("Novo nome de usuário: ");
    scanf("%s", usuario->nome);
    printf("Nome de usuário alterado!\n\n");
}

//  senha
void alterar_senha(struct Usuario *usuario) {
    printf("Nova senha: ");
    scanf("%s", usuario->senha);
    printf("Senha alterada com sucesso!\n\n");
}

void mensagem_boas_vindas() {
    printf("Bem-vindo ao Sistema de Gerenciamento de Usuários e Jogos!\n\n");
}
