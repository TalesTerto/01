#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <string.h>
void excluir(){
	char cpf[40];
	printf("CFP à deletar");
	scanf("%s", cpf);
	if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Usuário não encontrado.\n");
    }
}
void registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    int reinicio=0;
    
	while(reinicio==0){
	    printf("Cadastrar CPF: ");
	    scanf("%s", cpf);
	    strcpy(arquivo, cpf);
	
	    FILE *file;
	    file = fopen(arquivo, "w");
	    fprintf(file, "%s", cpf);
	    fclose(file);
	
	    file = fopen(arquivo, "a");
	    fprintf(file, ",");
	    fclose(file);
	
	    printf("Novo nome: ");
	    scanf("%s", nome);
	
	    file = fopen(arquivo, "a");
	    fprintf(file, "%s,", nome);
	    fclose(file);
	
	    printf("Sobrenome: ");
	    scanf("%s", sobrenome);
	
	    file = fopen(arquivo, "a");
	    fprintf(file, "%s,", sobrenome);
	    fclose(file);
	
	    printf("Cargo: ");
	    scanf("%s", cargo);
	
	    file = fopen(arquivo, "a");
	    fprintf(file, "%s", cargo);
	    fclose(file);
	    
	    printf("deseja reiniciar?\n 0-sim \n 1-nao\n");
	    scanf("%d",&reinicio);
	}
    system("pause");
}
void consulta(){
	char cpf[40];
	char conteudo[200];
	
	printf("consulta cpf:");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("nao localizado. \n");
	}
	while(fgets(conteudo,200,file)!=NULL){
		printf("\n Usuarios informação");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int main() {
    int op = 0;
    int laco = 1;
    setlocale(LC_ALL, "Portuguese");
    char pw[10]="a";
    
    printf("#### Cartório Afonso ###\n\n");
    printf("login ADM!(senha ADM)\n digite sua senha:");
    scanf("%s", &pw);
    
    int compar1=strcmp(pw,"ADM");
    if(compar1==0){
	    while (laco == 1) {
	        system("cls");
	
	        printf("#### Cartório Afonso ###\n");
	        printf("\nEscolha a opção desejada\n\n");
	        printf("\t1 Registrar nome\n");
	        printf("\t2 Verificar nome\n");
	        printf("\t3 Excluir nome\n\n");
	        printf("\t4 SAIR\n\n");
	        printf("Este software é para uso de estudantes\n");
	
	        scanf("%d", &op);
	        system("cls");
	
	        if (op == 1) {
	            std::cout << "Registrar nome\n" << std::endl;
	            registro();
	            system("pause");
	        } else if (op == 2) {
	            printf("Verificar nome\n");
	            consulta();
	            system("pause");
	        } else if (op == 3) {
	            printf("Excluir nome\n");
	            excluir();
	            system("pause");
	        }else if(op==4){
				printf("Obrigado por utiliza o sistema\n");
				return 0;
				break;
			} else {
	            printf("Opção não definida\n");
	            system("pause");
	        }
	    }
	}else{
		printf("senha incorreta");
	}
}


