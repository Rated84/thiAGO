#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"


int main() {
    struct Usuario usuarios[100];
    int num_usuarios = 0;

    struct Jogo jogos[100];
    int num_jogos = 0;

    struct Jogo promocao[100];
    int num_promocao = 0;

    char nome[50], senha[50];
    
    mensagem_boas_vindas();

    // Cadastro de nome de usuário e senha
    printf("Cadastro de usuário e senha:\n");
    printf("Digite seu nome de usuário: ");
    scanf("%s", nome);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    strcpy(usuarios[num_usuarios].nome, nome);
    strcpy(usuarios[num_usuarios].senha, senha);
    num_usuarios++;

    // Realiza o login
    login(usuarios[0]);

    while (1) {
        
        printf("\n");
    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*     Bem-vindo o nossa loja de jogos!   *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
    printf("\n");
    
        printf("\nSelecione uma opção:\n");
        printf("1. Cadastrar novo email\n");
        printf("2. Verificação de email\n");
        printf("3. Adicionar novo jogo\n");
        printf("4. Pesquisar jogo\n");
        printf("5. Remover jogo\n");
        printf("6. Listar jogos em promoção\n");
        printf("7. Alterar nome de usuário\n");
        printf("8. Alterar senha\n");
        printf("9. Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_email(usuarios, &num_usuarios);
                break;
            case 2: {
                char email[80];
                printf("Digite o email a ser verificado: ");
                scanf("%s", email);
                if (verificar_email(email, usuarios, num_usuarios)) {
                    printf("Email válido!\n\n");
                } else {
                    printf("Email inválido ou já cadastrado.\n\n");
                }
                break;
            }
            case 3:
                adicionar_jogo(jogos, &num_jogos);
                break;
            case 4:
                pesquisar_jogo(jogos, num_jogos);
                break;
            case 5:
                remover_jogo(jogos, &num_jogos);
                break;
            case 6:
                criar_lista_promocao(jogos, num_jogos, promocao, &num_promocao);
                printf("Jogos em promoção (preço abaixo de 30):\n");
                for (int i = 0; i < num_promocao; i++) {
                    printf("%s - Preço: %.2f\n", promocao[i].nome, promocao[i].preco);
                }
                break;
   case 7:
                ordenar_jogos(promocao, num_promocao);
                printf("Jogos em promoção ordenados por preço:\n");
                for (int i = 0; i < num_promocao; i++) {
                    printf("%s - Preço: %.2f\n", promocao[i].nome, promocao[i].preco);
                }
                break;
            case 8:
                alterar_usuario(&usuarios[0]);
                break;
            case 9:
                alterar_senha(&usuarios[0]);
                break;
            case 10:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n\n");
        }
    }

    return 0;
}

 


