#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int codigo;
        char nome[50];
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
        long int CPF;
        char nome[50];
        int telefone;
        Endereco endereco;
		                
} Funcionario;

typedef struct{
        int ID;
        long int CPF;
        double valor;
        int IDProduto;
				                
} Venda;

//CADASTRO
void cadFuncionario(Funcionario *func, Endereco *end);
void cadCategoria(Categoria *cat);
void cadProduto(Produto *prod);

int main(void){
    
    int opcao;
    do{
        printf("\nMenu\n\n");
        printf("1) Cadastrar funcionario.\n");        
        printf("2) Cadastrar categoria.\n");
        printf("3) Cadastrar produto.\n");
        printf("4) Cadastrar venda.\n");
        printf("5) Alterar funcionario.\n");
        printf("6) Alterar categoria.\n");
        printf("7) Alterar produto.\n");
        printf("8) Excluir funcionario.\n");
        printf("9) Excluir categoria.\n");
        printf("10) Excluir produto.\n");
        printf("11) Listar funcionarios.\n");
        printf("12) Listar categorias e total de produtos.\n");  
        printf("13) Buscar produtos por categoria.\n");
        printf("14) Buscar produtos e total venda por funcionario.\n");
        printf("15) Funcionario com maior valor de venda.\n"); 
        printf("16) Categoria com mais venda.\n"); 
        printf("17) M�dia das vendas.\n"); 
        printf("0) Sair do programa.\n");   
        printf(" >"); 
        scanf("%d", &opcao);
        switch(opcao){
                   case 1:
                        break;
                   case 2:
                        break;
                   case 3:
                        break;
                   case 4:
                        break;
                   case 5:
                        break;
                   case 6:
                        break;
                   case 7:
                        break;
                   case 8:
                        break;
                   case 9:
                        break;
                   case 10:
                        break;
                   case 11:
                        break;
                   case 12:
                        break;
                   case 13:
                        break;
                   case 14:
                        break;
                   case 15:
                        break;
                   case 16:
                        break;
                   case 17:
                        break;     
                   case 0:
                         break;    
                   default:
                         break;     
                   
        }
        
    } while(opcao!=0);
	
    system("pause");
    return EXIT_SUCCESS;    
}

//CADASTROS
//FUNCIONARIOS
void cadFuncionario(Funcionario *func, Endereco *end){
	if(!func){
		printf("Voce deve informar primeiramente a quantidade de Funcionarios cadastrados!\n");
		//Provocando uma sa�da do sistema caso a mem�ria que precisemos n�o seja alocada.
		return;
	}

	printf("\n-- FUNCIONARIO --");
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
		printf("\nDigite a rua: ");
		fflush(stdin);
		gets(end->rua);
		
		if(end->rua == NULL || strcmp(end->rua,"")==0 || strcmp(end->rua," ")==0){
			printf("Nome da rua nao pode ser vazio.\n");                  
		}
		if(strlen(end->rua) > 50){
			printf("M�ximo de 20 caracteres.\n");
		}
	} while(end->rua == NULL || strcmp(end->rua,"")==0 || strcmp(end->rua," ")==0 || strlen(end->rua) > 50);
	
	do{
		printf("Digite o numero: ");
		scanf("%d", &end->numero);
		
		if(end->numero < 1){
			printf("O n�mero precisa ser maior que 0.\n");               
		}
	} while(end->numero < 1);
	
	do{
		printf("\nDigite o bairro: ");
		fflush(stdin);
		gets(end->bairro);
		
		if(end->bairro == NULL || strcmp(end->bairro,"")==0 || strcmp(end->bairro," ")==0){
			printf("Nome do bairro nao pode ser vazio.\n");                  
		}
		if(strlen(end->bairro) > 20){
			printf("M�ximo de 20 caracteres.\n");
		}
	} while(end->bairro == NULL || strcmp(end->bairro,"")==0 || strcmp(end->bairro," ")==0 || strlen(end->bairro) > 20);
	
	do{
		printf("\nDigite a cidade: ");
		fflush(stdin);
		gets(end->cidade);
		
		if(end->cidade == NULL || strcmp(end->cidade,"")==0 || strcmp(end->cidade," ")==0){
			printf("Nome da cidade nao pode ser vazio.\n");                  
		}
		if(strlen(end->cidade) > 30){
			printf("M�ximo de 30 caracteres.\n");
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
			printf("M�ximo de 3 caracteres.\n");
		}
	} while(end->siglaEstado == NULL || strcmp(end->siglaEstado,"")==0 || strcmp(end->siglaEstado," ")==0 || strlen(end->siglaEstado) > 3);
         
}
//CATEGORIAS
void cadCategoria(Categoria *cat){
	if(!cat){
		printf("Voce deve informar primeiramente a quantidade de Categorias cadastradas!\n");
		//Provocando uma sa�da do sistema caso a mem�ria que precisemos n�o seja alocada.
		return;
	}

	printf("\n-- CATEGORIA --");
	
	do{
         printf("\nDigite o nome: ");
         fflush(stdin);
         gets(cat->nome);
         
         if(cat->nome == NULL || strcmp(cat->nome,"")==0 || strcmp(cat->nome," ")==0){
            printf("Nome nao pode ser vazio.\n");                  
         }
     } while(func->cat == NULL || strcmp(func->cat,"")==0 || strcmp(cat->nome," ")==0);
     
}
//PRODUTOS
void cadProduto(Produto *prod){
	if(!prod){
		printf("Voce deve informar primeiramente a quantidade de Produtos cadastrados!\n");
		//Provocando uma sa�da do sistema caso a mem�ria que precisemos n�o seja alocada.
		return;
	}

	printf("\n-- PRODUTO --");
	
	do{
         printf("Digite o codigo do Produto: ");
         scanf("%d", &prod->codigo);

         if(prod->codigo < 0 || prod->codigo > 50){
                printf("Codigo deve ser de 0 a 50\n");               
         }
    } while(prod->codigo < 0 || prod->codigo > 50);
	do{
         printf("\nDigite o nome: ");
         fflush(stdin);
         gets(prod->nome);
         
         if(prod->nome == NULL || strcmp(prod->nome,"")==0 || strcmp(prod->nome," ")==0){
            printf("Nome nao pode ser vazio.\n");                  
         }
     } while(func->prod == NULL || strcmp(prod->nome,"")==0 || strcmp(prod->nome," ")==0);
       
     do{  
         printf("\nDigite o preco: ");
         scanf("%lf", &prod->preco);
         
         if(strlen(prod->preco) < 1){
                printf("O preco precisa ser maior que 0.\n");               
         }
    } while(strlen(prod->preco) < 1);
    
     do{    
         printf("\nDigite a quantidade do Produto em estoque: ");
         scanf("%d", &prod->quantidade);  
         
         if(prod->quantidade < 0){
                        printf("Digite uma quantidade positiva ou zero.\n");               
         }
     } while(prod->quantidade < 0);
     
     do{    
         printf("\nDigite o ID da categoria: ");
         scanf("%d", &prod->IDCategoria);  
        
     } while(prod->IDCategoria < 0);
     
     printf("\n");
}

