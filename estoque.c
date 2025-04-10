#include <stdio.h>

#define ESTOQUEMAX 10

int main(){
	short KeepG = 1;
	char produtos[12][ESTOQUEMAX];
	float preços[ESTOQUEMAX];
	short opção;
	int posproduto = 0;
	char identificador, identificadorProduto[ESTOQUEMAX];
	int qtd_em_estoque[ESTOQUEMAX];
	while(KeepG){
		printf("Digite sua opção(1 a 5): \n");
		scanf("%hd", &opção);
		switch(opção){
			case 1:
				if(posproduto < ESTOQUEMAX){
					printf("Insira nome do produto: \n");
					scanf("%12s", produtos[posproduto]);
					printf("Insira preço do produto: \n");
					scanf("%f",&preços[posproduto]);
					printf("Quantidade em estoque: \n");
					scanf("%d", &qtd_em_estoque[posproduto]);
					printf("Identificador do produto: \n");
					scanf(" %c", &identificadorProduto[posproduto]);
					posproduto++;
				}else{printf("O limite de produtos foi atingido\n");}
			break;
			case 2:
				for(int i=0;i< posproduto;i++){
					printf("Produto %d : %12s\n",i ,produtos[i]);
				}
				break;
			case 3:
				printf("Digite o identificador do produto: \n");
				scanf(" %c", &identificador);
				for(int i=0;i<posproduto;i++){
					if(identificador == identificadorProduto[i]){
						printf("Produto %d : %12s\n", i, produtos[i]);
						printf("Preço: %f\n", preços[i]);
						printf("Quantidade em estoque: %d\n", qtd_em_estoque[i]);
						printf("Deseja modificar algo deste produto?(1/0)\n");
						scanf("%hd",&opção);
						if(opção){
							printf("Deseja modificar qual parte?(1(nome)/2(preço)/3(quantidade em estoque))\n");
							scanf("%hd", &opção);
							switch(opção){
								case 1:
									printf("Qual será o novo nome do produto: \n");
									scanf(" %12s", produtos[i]);
									break;
								case 2:
									printf("Qual será o novo preço: \n");
									scanf("%f", &preços[i]);
									break;
								case 3:
									printf("Qual será a nova quantidade em estoque: \n");
									scanf("%d", &qtd_em_estoque[i]);
							}
						}else{break;}
				  }
				}
				break;
			case 4:
        float iniciointervalo;
        float finalintervalo;
        printf("Digite uma faixa de preço. (Ex: 10(entrada) <= x(produto) <= 20(entrada) \n");
        printf("Inicio do intervalo: \n");
        scanf("%f", &iniciointervalo);
        printf("Final do Intervalo: \n");
        scanf("%f", &finalintervalo);
        for(short i=0;i < posproduto; i++){
            if(iniciointervalo <= preços[i] && preços[i] <= finalintervalo){
                printf("Produto %d : %s \nIdentificador: %c \n", i,produtos[i], identificadorProduto[i]); 
            }
        }
				break;
				case 5:	
					KeepG = 0;

			}
  }
	return 0;
}
