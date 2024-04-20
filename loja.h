



// Estrutura para armazenar os dados do usuário
struct Usuario {
    char nome[50];
    char senha[50];
    char email[80];
};

//  armazenar os dados de um jogo
struct Jogo {
    char nome[50];
    float preco;
};

void login(struct Usuario usuario);
int verificar_email(char email[], struct Usuario usuarios[], int num_usuarios);
void cadastrar_email(struct Usuario usuarios[], int *num_usuarios);
void adicionar_jogo(struct Jogo jogos[], int *num_jogos);
void pesquisar_jogo(struct Jogo jogos[], int num_jogos);
void remover_jogo(struct Jogo jogos[], int *num_jogos);
void criar_lista_promocao(struct Jogo jogos[], int num_jogos, struct Jogo promocao[], int *num_promocao);
void ordenar_jogos(struct Jogo promocao[], int num_promocao);
void alterar_usuario(struct Usuario *usuario);
void alterar_senha(struct Usuario *usuario);
void mensagem_boas_vindas();