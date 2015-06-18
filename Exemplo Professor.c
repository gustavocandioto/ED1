#include <stdio.h>
#include <stdlib.h>

typedef struct{
        char descricao[50];
        int codigo;
        double preco;
        int quantidade;
                
} Produto;


typedef struct categoria{
        int ID;
        char nome[50];
        int totalProd;
        Produto *listProd;
        struct categoria *proximo;        
        
}Categoria;

//Funções de Categoria
void inicia(Categoria *listCat);
void insereInicio(Categoria *listCat);
void insereFim(Categoria *listCat);
int  vazia(Categoria *LISTA);
void libera(Categoria *LISTA);
void cadListCategoria(Categoria *listCat,int *quant);
void cadCategoria(Categoria *cat);
void listarCategorias(Categoria *listCat,int quant);
void cadListProdutoCat(Categoria *list);
Categoria *buscaCatID(Categoria *list,int id);
void mostraCatID(Categoria *list);

//Funções de Poduto
Produto *totalProdutos(int *quant);
void cadListProduto(Produto *list, int quant);
void cadProduto(Produto *prod);
void exibirFaltaEstoque(Produto *list, int quant);
void exibirEstoque(Produto *list, int quant);


int main(void){
	
	Categoria *listCat=(Categoria*)malloc(sizeof(Categoria));
		
	if(!listCat)
    {
      printf("Sem memoria disponivel!\n");
      //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
      exit(1);
    } 
    inicia(listCat);
    
    
    int quant=0;
    int op;
    do{
        printf("\nMenu\n\n");
        printf("1) Cadastrar categoria.\n");        
        printf("2) Cadastro da lista de Produtos.\n");
        printf("3) Listar as categorias.\n");  
        printf("4) Buscar uma categoria por ID.\n");  
        printf("0) Sair do programa.\n");   
        printf(" >"); 
        scanf("%d", &op);
        switch(op){
                   case 1:
                        cadListCategoria(listCat,&quant);
                   		/*if(listProd!=NULL)
				     	  free(listProd);					 
                        listProd = totalProdutos(&quant);*/
                        system("cls");
                        break;
                   case 2:
                        cadListProdutoCat(listCat);
                        //system("cls");
                        break;
                   case 3:
                        listarCategorias(listCat,quant);
                        break;
                   case 4:
                        mostraCatID(listCat);
                        break;
                   case 0:
                         break;    
                   default:
                         break;     
                   
        }
        
    } while(op!=0);
    
    
    //DESALOCA TODOS AS CATEGORIAS E PRODUTOS
    libera(listCat);
    
    //LIBERA A PRÓPRIA LISTA
    printf("Liberando a lista\n\n");
   // free(listCat);
    system("pause");
    return EXIT_SUCCESS;    
}


//Funções de Categoria
void inicia(Categoria *listCat)
{
     listCat->proximo = NULL;
     listCat->listProd = NULL;
	 listCat->totalProd = 0;
}

void insereInicio(Categoria *listCat)
{
	Categoria *novo=(Categoria *) malloc(sizeof(Categoria));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	//preenche categoria
	cadCategoria(novo);
	
	Categoria *oldHead = listCat->proximo;
	
	listCat->proximo = novo;
	novo->proximo = oldHead;
}

void insereFim(Categoria *listCat)
{
	Categoria *novo=(Categoria *) malloc(sizeof(Categoria));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	//preenche categoria
	cadCategoria(novo);
	
	novo->proximo = NULL;
	
	if(vazia(listCat))
		listCat->proximo=novo;
	else{
		Categoria *tmp = listCat->proximo;
		
		while(tmp->proximo != NULL)
			tmp = tmp->proximo;
		
		tmp->proximo = novo;
	}
}

int vazia(Categoria *LISTA)
{
	if(LISTA->proximo == NULL)
		return 1;
	else
		return 0;
}

void libera(Categoria *LISTA)
{
	printf("\n========= LIBERANDO MEMORIA =========\n\n");  
	if(!vazia(LISTA)){
		Categoria *proxNode,
			  *atual;
		atual = LISTA->proximo;
		while(atual != NULL){
			proxNode = atual->proximo;
			printf("\nLiberando Categoria ID: %d\n",atual->ID);
			if(atual->totalProd>0){
			   printf("\nLiberando os %d Produtos da Categoria ID: %d\n",atual->totalProd,atual->ID);
			   free(atual->listProd);
			}
				
			free(atual);
			atual = proxNode;
		}
		//LIBERA A PRÓPRIA LISTA
        printf("Liberando a lista\n\n");
		free(LISTA);
	}
	else
	{	printf("Nenhuma Categoria Cadastrada!\n\n");
	    //LIBERA A PRÓPRIA LISTA
        printf("Liberando a lista\n\n");
        free(LISTA);
    }
}

void cadListCategoria(Categoria *listCat,int *quant)
{        
        if(!listCat)
        {
          printf("Sem memoria!\n");
          //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
          exit(1);
        }               
        

        //printf("\n\ncadListCategoria[%p]\n\n",listCat);   
        insereFim(listCat);
        (*quant)++;
        
        printf("\nTotal de categorias: %d\n\n",*quant);
        system("pause");
}

void cadCategoria(Categoria *cat)
{
     if(!cat)
     {
        printf("Categoria nao cadastrada!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
        return;
     }
     int aux;
     
	 do{
         printf("Digite o codigo da Categoria: ");
         scanf("%d", &cat->ID);

         if(cat->ID < 0 || cat->ID > 50){
                printf("Codigo deve ser de 0 a 50\n");               
         }
    } while(cat->ID < 0 || cat->ID > 50);
    
    do{
         printf("\nDigite o nome da Categoria: ");
         fflush(stdin);
         gets(cat->nome);
         
         if(cat->nome == NULL || strcmp(cat->nome,"")==0 || strcmp(cat->nome," ")==0){
            printf("Nome nao pode ser vazio.\n");                  
         }
     } while(cat->nome == NULL || strcmp(cat->nome,"")==0 || strcmp(cat->nome," ")==0);

     printf("Deseja cadastrar os produtos? (1 para sim/0 para nao)");
     scanf("%d", &aux);
     
     if(aux)
     {//CADASTRAR PRODUTOS
      				 
       cat->listProd = totalProdutos(&cat->totalProd);
       cadListProduto(cat->listProd,cat->totalProd);
     }   
	 else
	 {
	 	cat->listProd = NULL;
	 	cat->totalProd = 0;
	 	
	 }  
}

void listarCategorias(Categoria *listCat,int quant)
{
     if(listCat==NULL)
     {
        printf("Nenhuma Categoria cadastrada!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
        return;
     }
      Categoria *tmp;
	  tmp = listCat->proximo; 
	  system("cls");   
	  printf("\n========= CATEGORIAS =========\n\n");      
      while( tmp != NULL){
           printf("Endereco    : %p\n"\
                  "Codigo      : %d\n"\
  		  	      "Nome        : %s\n"\
				  "Total Prod  : %d\n", tmp,tmp->ID, tmp->nome,tmp->totalProd);                                
           printf("\n=====================================\n");
           tmp = tmp->proximo;
      } 

}

void cadListProdutoCat(Categoria *list){
     
    if(list->proximo==NULL)
     {
        printf("Nenhuma categoria cadastrada!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
		return;
	}
	
	Categoria *tmp = list->proximo;
		
	while(tmp->proximo != NULL)
	{
		printf("\n\n========= Categoria %d =========", tmp->ID);
		if(tmp->listProd==NULL)
		{
			tmp->listProd = totalProdutos(&tmp->totalProd);
       		cadListProduto(tmp->listProd,tmp->totalProd);
		}
		else printf("\nProdutos ja cadastrados!");
		tmp = tmp->proximo;
	}
	  
}

Categoria *buscaCatID(Categoria *list,int id)
{
	
	 if(list->proximo==NULL)
     {
        printf("Nenhuma categoria cadastrada!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
		return;
	}
	
	Categoria *tmp = list->proximo;
	
	while(tmp != NULL)
	{
		if(tmp->ID==id)
		{
			
			return tmp;
		}
		tmp = tmp->proximo;
	}
	
	return NULL;
}

void mostraCatID(Categoria *list)
{
	 if(list->proximo==NULL)
     {
        printf("Nenhuma categoria cadastrada!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
		return;
	}
	int id;
	printf("\nQual categoria (id) gostaria de buscar? ");
	scanf("%d",&id);
	system("cls");
	Categoria *tmp = buscaCatID(list,id);
	
	if(tmp!=NULL)
	{
		printf("\n========= CATEGORIA =========\n\n");      
        printf("Endereco  : %p\n"\
               "Codigo  : %d\n"\
  	   	       "Nome    : %s\n", tmp,tmp->ID, tmp->nome);
		printf("\n-------------------------------------\n"); 
		exibirEstoque(tmp->listProd,tmp->totalProd);  
		exibirFaltaEstoque(tmp->listProd,tmp->totalProd);                             
        printf("\n=====================================\n");
           
    }
	else
		printf("\n\nCategoria nao encontrada!");
	
}

//Funções de Poduto
Produto *totalProdutos(int *quant){
     
     Produto *aux;
     
     do{
         printf("Informe a quantidade total de Produtos: ");
         scanf("%d", quant);
         
         if(*quant < 0){
              printf("Numero total de Produtos tem que ser positivo.\n");     
         }
     } while(*quant < 0);
     
 
     aux = (Produto*)malloc(sizeof(Produto) * (*quant));
     
     if(!aux)
	        {
	          printf("Sem memoria!\n");
	          //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
	          exit(1);
	        }
	
     return aux;
}

void cadListProduto(Produto *list, int quant){
     
    if(list==NULL)
     {
        printf("Voce deve informar primeiramente a quantidade de Produtos cadastrados!\n");
        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
		return;
	}
     
	 int x;
     for(x=0; x<quant; x++){
     	system("cls");
     	 printf("========= Produto %d =========\n\n", x+1);
         cadProduto(list);
         printf("\n\n");
         list++;
     }  
}

void cadProduto(Produto *prod)
{
	     if(!prod)
	     {
	        printf("Voce deve informar primeiramente a quantidade de Produtos cadastrados!\n");
	        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
	        return;
	     }
		do{
             printf("Digite o codigo do Produto: ");
             scanf("%d", &prod->codigo);

             if(prod->codigo < 0 || prod->codigo > 50){
                    printf("Codigo deve ser de 0 a 50\n");               
             }
        } while(prod->codigo < 0 || prod->codigo > 50);
		
		do{
             printf("\nDigite o nome do Produto: ");
             fflush(stdin);
             gets(prod->descricao);
             
             if(prod->descricao == NULL || strcmp(prod->descricao,"")==0 || strcmp(prod->descricao," ")==0){
                printf("Nome nao pode ser vazio.\n");                  
             }
         } while(prod->descricao == NULL || strcmp(prod->descricao,"")==0 || strcmp(prod->descricao," ")==0);
           
         do{  
             printf("\nDigite o preco do Produto: R$");
             scanf("%lf", &(*prod).preco);
             
             if(prod->preco < 0){
                            printf("Digite um preco positivo ou zero.\n");               
             }
         } while(prod->preco < 0);     
         
         do{    
             printf("\nDigite a quantidade do Produto em estoque: ");
             scanf("%d", &prod->quantidade);  
             
             if(prod->quantidade < 0){
                            printf("Digite uma quantidade positiva ou zero.\n");               
             }
         } while(prod->quantidade < 0);
         printf("\n");
}

void exibirFaltaEstoque(Produto *list, int quant){ 

		 if(!list)
	     {
	        printf("Nenhum produto cadastrado SEM estoque!\n");
	        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
	        return;
	     }     
     	  int x;
     	  //system("cls");
     	  printf("\n========= Produto EM FALTA DE ESTOQUE=========\n\n");
          for(x=0; x<quant; x++){
                   if(list[x].quantidade == 0){
                        printf("Produto: %s", list[x].descricao);                 
                   }  
                   printf("\n");
          }
}

void exibirEstoque(Produto *list, int quant){ 

		 if(list==NULL)
	     {
	        printf("Nenhum produto cadastrado EM estoque!\n");
	        //Provocando uma saída do sistema caso a memória que precisemos não seja alocada.
	        return;
	     }
          int x; 
		  //system("cls");   
		  printf("\n========= Produto EM ESTOQUE=========\n\n");      
          for(x=0; x<quant; x++){
                   if(list[x].quantidade > 0){
                          printf("Produto              : %s\n"\
						  	     "Quantidade em estoque: %d\n"\
								 "Codigo               : %d\n"\
								 "Preco                : R$%.2lf", list[x].descricao, list[x].quantidade, list[x].codigo, list[x].preco);   
						printf("\n=====================================\n");              
                   }  
                   
          }
}

