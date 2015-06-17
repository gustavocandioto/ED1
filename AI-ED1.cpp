#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int codigo;
        char descricao[50];
        double preco;
        int quantidade;
        int IDCategoria;
                
} Produto;

typedef struct categoria{
        int ID;
        char nome[50];
        int totalProd;       
        
} Categoria;

typedef struct{
        char rua[50];        
        int numero;
        char bairro[50];
        char cidade[30];
        char siglaEstado[3];
        long int CEP;
		                
} Endereco;

typedef struct{
        long int cpf;
        char nome[50];
        int telefone;
        Endereco endereco;
		                
} Funcionario;

typedef struct{
        int ID;
        long int cpf;
        double valor;
        int IDProduto;
		                
} Compra;

//CADASTRO
void cadFuncionario(Funcionario *func);

int main(void){
	
	
	
    system("pause");
    return EXIT_SUCCESS;    
}

//CADASTRO
void cadFuncionario(Funcionario *func, Endereco *end){
//	     if(!func){
//	        printf("Voce deve informar primeiramente a quantidade de Produtos cadastrados!\n");
//	        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
//	        return;
//	     }
		do{
             printf("Digite o CPF: ");
             scanf("%d", &func->CPF);

             if(strlen(func->CPF) < 11){
                    printf("CPF precisa conter 11 digitos.\n");               
             }
        } while(strlen(func->CPF) < 11);
		
		do{
             printf("\nDigite o nome: ");
             fflush(stdin);
             gets(func->nome);
             
             if(func->nome == NULL || strcmp(func->nome,"")==0 || strcmp(func->nome," ")==0){
                printf("Nome nao pode ser vazio.\n");                  
             }
         } while(func->nome == NULL || strcmp(func->nome,"")==0 || strcmp(func->nome," ")==0);
           
         do{  
             printf("\nDigite o telefone: ");
             scanf("%d", &func->telefone);
             
             if(strlen(func->telefone) < 8){
                    printf("O telefone precisa conter no minimo 8 digitos.\n");               
             }
        } while(strlen(func->telefone) < 8);
        
        do{  
             printf("\nENDEREÇO ");
             
             do{
	             printf("\nDigite a rua: ");
	             fflush(stdin);
	             gets(end->rua);
	             
	             if(end->rua == NULL || strcmp(end->rua,"")==0 || strcmp(end->rua," ")==0){
	                printf("Nome da rua nao pode ser vazio.\n");                  
	             }
	         } while(end->rua == NULL || strcmp(end->rua,"")==0 || strcmp(end->rua," ")==0);
	         
	         do{
	             printf("Digite o numero: ");
	             scanf("%d", &end->numero);
	
	             if(end->numero < 1){
	                    printf("O número precisa ser maior que 0.\n");               
	             }
	        } while(end->numero < 1);
	        
	        do{
	             printf("\nDigite o bairro: ");
	             fflush(stdin);
	             gets(end->bairro);
	             
	             if(end->bairro == NULL || strcmp(end->bairro,"")==0 || strcmp(end->bairro," ")==0){
	                printf("Nome do bairro nao pode ser vazio.\n");                  
	             }
	         } while(end->bairro == NULL || strcmp(end->bairro,"")==0 || strcmp(end->bairro," ")==0);
	         
	         do{
	             printf("\nDigite a cidade: ");
	             fflush(stdin);
	             gets(end->cidade);
	             
	             if(end->cidade == NULL || strcmp(end->cidade,"")==0 || strcmp(end->cidade," ")==0){
	                printf("Nome da cidade nao pode ser vazio.\n");                  
	             }
	             if(strlen(end->cidade) > 30){
				 	printf("Máximo de 30 caracteres.\n");
				 }
	         } while(end->cidade == NULL || strcmp(end->cidade,"")==0 || strcmp(end->cidade," ")==0 || strlen(end->cidade) > 30);
	         	
	         do{
	             printf("\nDigite a sigla do estado: ");
	             fflush(stdin);
	             gets(end->siglaEstado);
	             
	             if(end->siglaEstado == NULL || strcmp(end->siglaEstado,"")==0 || strcmp(end->siglaEstado," ")==0){
	                printf("Sigla nao pode ser vazia.\n");                  
	             }
	             if(strlen(end->siglaEstado) > 3){
				 	printf("Máximo de 3 caracteres.\n");
				 }
	         } while(end->siglaEstado == NULL || strcmp(end->siglaEstado,"")==0 || strcmp(end->siglaEstado," ")==0 || strlen(end->siglaEstado) > 3);
             
        } while(); 
         
         
}

