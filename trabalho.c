#include <stdio.h>
#include <string.h>

struct Pessoa{
	char nome[200];
	char tel[20];
	char curso[200];
    float nota1;
	float nota2;
};

int main() {
    FILE *entrar = fopen("DadosEntrada.csv", "r");
    FILE *sair = fopen("SituacaoFinal.csv", "w");

    if (entrar == NULL || sair == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }
	
	struct Pessoa aluno;

    while (fscanf(entrar, "%[^,],%[^,],%[^,],%f,%f\n", aluno.nome, aluno.tel, aluno.curso, &aluno.nota1, &aluno.nota2) == 5) {
        float media = (aluno.nota1 + aluno.nota2) / 2.0;
        char situacaofinal[20];

        if (media >= 7.0) {
            strcpy(situacaofinal, "Aprovado");
        } else {
            strcpy(situacaofinal, "Reprovado");
        }

        fprintf(sair, "%s,%.2f,%s\n", aluno.nome, media, situacaofinal);
    }

    fclose(entrar);
    fclose(sair);

    return 0;
}
