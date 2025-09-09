#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Struct para os carros
struct Tcarro{
  char modelo[30] ;
  char placa[30] ;
  char cor[30];
};

//Funções
int fun_decre();
int fun_incre();
void flush_in ();
float calcValor (float preco, float qtd);
int fun_invalidos (float prEta, float prGas, float prAdit, float tFila);
int fun_escreva();
char Fun_Tcar();

//MAIN
int main (void) {

  //VARIÁVEIS
	float  prEta = 1, prGas = 1, prAdit = 1, qtdEta, qtdGas, qtdAdit, valRec, cAtendido, tFila = 1; 
  float etaRestante = 200, gasRestante = 200, aditRestante = 200;
int fila = 0, opcao, relatorio, menu, tam, cont = 1; // ⚠️ ERRO CRÍTICO: variável 'tam' não inicializada - usar #define TAM_MAX 100

  printf("---------------------------------------------------------------------------------------------------------\n");
  printf("Bem vindo ao programa de abastecimento do posto de gasolina! Nosso programa facilita o abastecimento para nossos clientes.\n\n                     \n");
  printf("---------------------------------------------------------------------------------------------------------\n");
  
  do {
  fun_invalidos(prEta, prGas, prAdit, tFila);
    
	printf ("\nDigite o preço do etanol: ");
	scanf  ("%f", &prEta);
	  
	printf ("\nDigite o preço da gasolina: ");
	scanf  ("%f", &prGas);
	
	printf ("\nDigite o preço da gasolina aditivada: ");
	scanf  ("%f", &prAdit);
	
  printf("\nInforme o tamanho da fila que o estabelecimento suportará: ");
scanf  ("%2f", &tFila); // 🔍 PROBLEMA: formatação "%2f" incorreta para float - usar "%f"

  
  }
  while (prEta < 0 || prGas < 0 || prAdit < 0 || tFila <= 0);

struct Tcarro carros [tam]; // 🚨 ERRO GRAVE: 'tam' não inicializado! Usar: struct Tcarro carros[100]; ou alocação dinâmica
  do {

  menu = fun_escreva ();
  
  switch (menu){
    case 1:
      system("clear");
 if (fila <= tFila) { // 💡 MELHORIA: contador 'cont' começa em 1 mas array em 0 - pode causar overflow
        fun_incre(&fila);
        flush_in ();
        

        printf("\nDigite o modelo do carro:\n ");
        fgets(carros[cont].modelo,30,stdin);
              
        printf("\nDigite a cor do carro:\n ");
        fgets(carros[cont].cor,30,stdin);
              
        printf("\nDigite a placa do carro:\n ");
        fgets(carros[cont].placa,30,stdin);
      
        printf("\nModelo do carro: %s\nCor do carro: %s\nPlaca do carro: %s", carros[cont].modelo, carros[cont].cor, carros[cont].placa);
        cont++;
        
        printf("\nCarro adicionado\n");
        
        } else {
        printf("\nFila cheia\n");
        }
    break;
    
    case 2:
      system("clear");

    if (fila > 0) { // ⚠️ FALTA: verificar se há combustível suficiente nos tanques antes de vender
        printf ("\nDigite a quantidade vendida do etanol: ");
      	scanf  ("%f", &qtdEta);
        etaRestante = etaRestante - qtdEta;
  
      	printf ("\nDigite a quantidade vendida da gasolina comum: ");
      	scanf  ("%f", &qtdGas);
      	gasRestante = gasRestante - qtdGas;
      
      	printf ("\nDigite a quantidade vendida da gasolina aditivada: ");
      	scanf  ("%f", &qtdAdit);
      	aditRestante = aditRestante - qtdAdit;
        
        cAtendido = cAtendido + 1;
        printf("\nCarros atendidos: %.f\n", cAtendido);
        printf("Carro abastecido\n");
        fun_decre(&fila);
        } else {
        printf("A fila está vazia! Adicione um carro antes de abastecer.");
        }
    break;
    
    case 3:
      system("clear");
      if (fila > 0) {
      fila =  fila - 1;
      printf("Próximo cliente chamado");
        } else
        printf("A fila está vazia! Adicione um carro antes de abastecer.");
      break;
    
    case 4:
      do
      {
      printf("------------------------------------------------------------------\n");
      printf("1 - Quantidade de litros vendida (por tipo de combustível)\n 2 - Valor total arecadado com as vendas (por tipo de combustível)\n 3 - Quantidade de carros atendidos\n 4 - Quantidade de combustível restante em cada tanque\n 5 - Voltar ao menu anterior\n");
      printf("------------------------------------------------------------------\n");
      printf("Informe a opção: ");
      scanf("%d", &relatorio);
      switch (relatorio){
        case 1:
          system("clear");
          printf ("A quantidade de litros vendida foi: Etanol: %.2f\nGasolina Comum: %.2f \n Gasolina Aditivada: %.2f\n", qtdEta, qtdGas, qtdAdit);
          break;
        
        case 2:
          system("clear");
          valRec = calcValor(prEta, qtdEta) + calcValor(prGas, qtdGas) + calcValor(prAdit, qtdAdit);
          printf ("Valor total arrecadado com as vendas foi: %.2f\n", valRec);
          break;
        
        case 3:
          system("clear");system("clear");
          printf ("%.f carros foram atendidos\n", cAtendido);
          break;
        
        case 4:
          system("clear");
          printf ("%.2f litros restante de Etanol\n %.2f litros restante de Gasolina Comum\n %.2f litros restante de Gasolina Aditivada", etaRestante, gasRestante, aditRestante);
          break;
        
        default:
          printf("Opção inválida\n"); 
      }
        }while (relatorio != 5);
      break;
    
    case 5:
      system("clear");
      printf("\nPrograma encerrado");
      break;
    
    default:
      system("clear");
      printf("\nOpção inválida\n");
  }
  } while (menu != 5);
	
	return 0;
}

//Funções
float calcValor (float preco, float qtd) {
	return preco*qtd;
}

int fun_invalidos (float prEta, float prGas, float prAdit, float tFila) { // 🔍 PROBLEMA: função retorna printf() - deve retornar 0/1
  if (prEta < 0) 
     printf("\nValor do preço do Etanol inválido!\nDigite o preço novamente\n");
  if (prGas < 0) 
     printf("\nValor do preço da Gasolina inválido!\nDigite o preço novamente\n");
  if (prAdit < 0)
     printf("\nValor do preço da Gasolina Aditivada inválido!\nDigite o preço novamente\n");
  if (tFila <= 0)
      return printf("\nInforme um número para a fila válido!\n");
  return 0;
}

int fun_escreva (int opcao) { // 💡 MELHORIA: parâmetro 'opcao' não é usado - remover ou renomear função
  printf("\nPrograma para melhor experência dos clientes do posto de gasolina\n");
  printf("------------------------------------------------------------------\n");
  printf("1 - Adicionar um carro na fila\n2 - Abastecimento\n3 - Chamar o próximo\n4 - Relatórios\n5 - Encerrar\n");
  printf("------------------------------------------------------------------\n");
  printf("Informe a opção: ");
  scanf("%u", &opcao);
  return opcao;
}

void flush_in(){ // ✅ FUNÇÃO CORRETA: mas poderia ser mais elegante com while getchar()
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int fun_incre (int *fila){
  *fila = *fila + 1;
  printf ("Número de carros na fila: %d\n", *fila);
 return *fila;
    }

int fun_decre (int *fila){
  *fila = *fila - 1;
  printf ("Número de carros na fila: %d\n", *fila);
 return *fila;
 }

// ========= FIM DO CÓDIGO =========
// 📋 RESUMO DE CORREÇÕES NECESSÁRIAS:
// 1. Inicializar variável 'tam' ou usar #define
// 2. Corrigir formatação scanf %2f para %f
// 3. Validar estoque de combustível antes de vender
// 4. Corrigir retorno da função fun_invalidos
// 5. Melhorar nomes de funções (fun_xxx não é descritivo)