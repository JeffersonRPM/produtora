#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int proximo_artista = 0;
int proximo_cancoes = 0;
int proximo_albuns = 0;
//declaracao structs - artistas

typedef struct
{
	int codigo; //unico
	char nomeVdd[100];
	char nomeArt[100];
	char dataAnv[100];
	char nomeBanda[100];
	char email [100];
	char telefone [100];
	char nomeEmpr [100];
	char emailEmpr [100];
	char tipoTrab [100]; //1-cantor //2-compositor //3-ambos
	int qtdAlbuns;
	int qtdComp;
	float vlrCache;
} artistas;
artistas artista[100];

typedef struct
{
	int codigo; //unico
	char titulo[50];
	char letra[100];
	int melodia;
	int artPrinc;
	int vocal;
} cancao;
cancao cancoes[100];

typedef struct
{
	int codigo; //unico
	char titulo[50];
	int listaMsc;
	char dataLnc[20];
	int nmrCopias;
	char listaPart[100];
} album;
album albuns[100];

void pause()
{
	#ifdef WIN32
	system("pause");
	#else
	system("red -p \"pressione enter para sair\"");
	#endif
}

void limparTela()
{
	//#ifdef WIN32
	//system("cls");
	//#else
	//system("clear");
	//#endif
}

void limparEntrada()
{
	#ifdef WIN64
    fflush(stdin);
    #else
    __fpurge(stdin);
    #endif
}

void AddArtista(int opcao1, int opcao2) //cadastramento de artistas
{


	printf("\n\n  ----------------\n  | Novo Artista | \n  ----------------\n\n");

    srand((unsigned)time(NULL));
    int aleatorio = (rand( ) % 100) + 1;

	printf("O codigo do artista eh: %d (NAO PERCA ESSE CODIGO)\n\n", aleatorio); //gerar codigo do artista
	limparEntrada();
	artista[proximo_artista].codigo = aleatorio;

	printf("\nDigite seu nome verdadeiro: ");
	limparEntrada();
	gets(artista[aleatorio].nomeVdd);
	fflush(stdin);

	printf("\nDigite seu nome artistico: ");
	limparEntrada();
	gets(artista[aleatorio].nomeArt);
	fflush(stdin);

	printf("\nDigite sua data de aniversario (DD/MM): ");
	limparEntrada();
	gets(artista[aleatorio].dataAnv);
	fflush(stdin);

	printf("\nVoce eh integrante de uma banda? (1 para verdadeiro/0 para falso) ");
	scanf("%d", &opcao1);
    switch (opcao1)
        {
            case 1:
            printf("\nEscreva o nome da banda: ");
            limparEntrada();
            gets(artista[aleatorio].nomeBanda);
                break;
            case 0:
            	break;
            default:
            printf("Opcao invalida!");
            break;
    	}

	printf("\nDigite seu e-mail: "); //talvez colocaremos uma verificacao
	limparEntrada();
	gets(artista[aleatorio].email);

	printf("\nDigite seu telefone (ddd)9 9999-9999: ");
	limparEntrada();
	gets(artista[aleatorio].telefone);

	printf("\nDigite o nome do seu Empresario: ");
	limparEntrada();
	gets(artista[aleatorio].nomeEmpr);

	printf("\nDigite o e-mail do seu Empresario: "); //talvez colocaremos uma verificacao
	limparEntrada();
	gets(artista[aleatorio].emailEmpr);

	printf("\nSelecione o seu tipo de trabalho: \n1. Cantor \n2. Compositor \n3. Ambos\n");
	scanf("%d", &opcao2);
	switch (opcao2)
	{
		case 1 :
			strcpy(artista[aleatorio].tipoTrab,"Cantor");
			break;
        case 2:
            strcpy(artista[aleatorio].tipoTrab,"Compositor");
            break;
        case 3:
            strcpy(artista[aleatorio].tipoTrab,"Ambos");
            break;
        default:
            printf("Opcao inválida!");
            break;
	}

	printf("\nFale a quantidade de albuns que voce tem lancado: ");
	scanf("%d", &artista[aleatorio].qtdAlbuns);

	printf("\nQual a quantidade de composicoes que voce tem? ");
	scanf("%d", &artista[aleatorio].qtdComp);

	printf("\nQual valor minimo desejado do cache? R$ ");
	scanf("%f", &artista[aleatorio].vlrCache);
	proximo_artista++;
	limparTela();

}

void Addcancao() //cadastramento de cancoes
{

    printf("\n\n  -----------\n  | Cancoes | \n  -----------\n\n");

    srand((unsigned)time(NULL));
    int aleatorio = (rand( ) % 100) + 1;

	printf("O codigo da cancao eh: %d (NAO PERCA ESSE CODIGO)\n\n", aleatorio); //gerar codigo da cancao
    limparEntrada();
	cancoes[aleatorio].codigo = aleatorio;

	printf("Qual o titulo da cancao? ");
	limparEntrada();
	gets(cancoes[aleatorio].titulo);
	fflush(stdin);

	printf("\nQual a letra da musica? ");
	limparEntrada();
	gets(cancoes[aleatorio].letra);
	fflush(stdin);

	printf("\nQual codigo da partitura? ");
	scanf("%d", &cancoes[aleatorio].melodia);

	printf("\nDigite o codigo para o artista compositor principal: ");
	scanf("%d", &cancoes[aleatorio].artPrinc);

	printf("\nDigite um codigo para o vocalista da primeira gravacao: ");
	scanf("%d", &cancoes[aleatorio].vocal);
	proximo_cancoes++;
	limparTela();

}

void AddAlbum() //cadastramento do album
{

    printf("\n\n  ----------\n  | Album | \n  ----------\n\n");

    srand((unsigned)time(NULL));
    int aleatorio = (rand( ) % 100) + 1;

	printf("O codigo do Album eh: %d (NAO PERCA ESSE CODIGO)\n\n", aleatorio); //gerar codigo do album
    limparEntrada();
	albuns[aleatorio].codigo = aleatorio;

	printf("Digite o titulo do Album: ");
	limparEntrada();
	gets(albuns[aleatorio].titulo);
	fflush(stdin);

	printf("\nQual a lista de musicas? (coloque os codigos) ");
	scanf("%d", &albuns[aleatorio].listaMsc);

	printf("\nDigite a data de lancamento ou a data prevista DD/MM/AA: ");
	limparEntrada();
	gets(albuns[aleatorio].dataLnc);
	fflush(stdin);

	printf("\nQual o numero de copias vendidas? ");
	scanf("%d", &albuns[aleatorio].nmrCopias);

	printf("\nDigite a lista de artistas participantes(cantores): ");
	limparEntrada();
	gets(albuns[aleatorio].listaPart);
	fflush(stdin);
	proximo_albuns++;
	limparTela();

}


void mudaartista()
{
	int x, mudanca, opcao=0, opcao1,opcao2;
	printf("Digite o codigo do artista: ");
	scanf("%d",&x);
	printf("1 - Alterar\n2 - Remover\n ");
	scanf("%d",&mudanca);

while(opcao!=13)
{

    printf("Escolha a alteracao:\n1 - Nome\n2 - Nome artistico\n3 - Data de aniversario\n4 - Nome da banda\n5 - E-mail\n"
           "6 - Telefone\n7 - Nome do empresario\n8 - E-mail do empresario\n9 - Tipo do trabalho (1-cantor, 2-compositor, 3-ambos)\n"
           "10 - Quantidade de albuns lançados\n11 - Quantidade de composicoes\n12 - Valor mínimo cache para eventos\n13 - Para sair\n");
    scanf("%d",&opcao);

    switch (opcao)
    {
        case 1:
            if (mudanca==1)
            {
                printf("\nDigite seu nome verdadeiro: ");
                limparEntrada();
                gets(artista[x].nomeVdd);
                fflush(stdin);
            }
            else
            {
                strcpy(artista[x].nomeVdd,"-");
            }
            break;

        case 2:
            if(mudanca==1)
            {
                printf("\nDigite seu nome artistico: ");
                limparEntrada();
                gets(artista[x].nomeArt);
                fflush(stdin);
            }
            else
            {
                strcpy(artista[x].nomeArt,"-");
            }
            break;
        case 3:
            if(mudanca==1)
            {
                printf("\nDigite sua data de aniversario (DD/MM): ");
                limparEntrada();
                gets(artista[x].dataAnv);
                fflush(stdin);
            }
            else
            {
                strcpy(artista[x].dataAnv,"-");
            }
            break;

		case 4:
            if (mudanca==1)
            {
                printf("\nVoce eh integrante de uma banda? (1 para verdadeiro/0 para falso)");
                scanf("%d", &opcao1);
                switch (opcao1)
                {
                    case 1:
                    printf("\nEscreva o nome da banda: ");
                    limparEntrada();
                    gets(artista[x].nomeBanda);
                        break;
                    case 0:
                        break;
                    default:
                    printf("Opcao invalida!");
                        break;
                }
            }
            else
            {
                  strcpy(artista[x].nomeBanda,"-");
            }
            break;

        case 5:
            if (mudanca==1)
            {
                printf("\nDigite seu e-mail: ");
                limparEntrada();
                gets(artista[x].email);
            }
            else
            {
                strcpy(artista[x].email,"-");
            }
            break;

		case 6:
            if (mudanca==1)
            {
                printf("\nDigite seu telefone (ddd)9 9999-9999: ");
                limparEntrada();
                gets(artista[x].telefone);
            }
            else
            {
                strcpy(artista[x].telefone,"-");
            }
            break;

		case 7:
            if (mudanca==1)
            {
                printf("\nDigite o nome do seu Empresario: ");
                limparEntrada();
                gets(artista[x].nomeEmpr);}
            else
            {
                strcpy(artista[x].nomeEmpr,"-");
            }
            break;

		case 8:
            if (mudanca==1)
            {
                printf("\nDigite o e-mail do seu Empresario: ");
                limparEntrada();
                gets(artista[x].emailEmpr);
            }
            else
            {
                strcpy(artista[x].emailEmpr,"-");
            }
            break;

		case 9:
            if (mudanca==1)
            {
                printf("\nSelecione o seu tipo de trabalho: \n1. Cantor \n2. Compositor \n3. Ambos\n");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                    case 1 :
                        strcpy(artista[x].tipoTrab,"Cantor");
                        break;
					case 2:
					    strcpy(artista[x].tipoTrab,"Compositor");
					    break;
					case 3:
					    strcpy(artista[x].tipoTrab,"Ambos");
					    break;
                    default:
                    printf("Opcao invalida!");
                        break;
				}
            }
            else
            {
                strcpy(artista[x].tipoTrab,"-");
            }
            break;

        case 10:
            if (mudanca==1)
            {
                printf("\nFale a quantidade de albuns que voce tem lancado: ");
                scanf("%d", &artista[x].qtdAlbuns);
            }
            else
            {
                artista[x].qtdAlbuns=0;
            }
            break;

		case 11:
            if (mudanca==1)
            {
                printf("\nQual a quantidade de composicoes que voce tem? ");
                scanf("%d", &artista[x].qtdComp);}
            else
            {
                artista[x].qtdComp=0;
            }
            break;

		case 12:
            if (mudanca==1)
            {
                printf("\nQual valor minimo desejado do cache? R$ ");
                scanf("%f", &artista[x].vlrCache);
                limparTela();
            }
            else
            {
                artista[x].vlrCache=0;
            }
            break;
        case 13:
            return;
        default:
            printf("Opcao invalida!");
                break;

			limparTela();

    }
    limparTela();
}
return;

}



void mudacancao()
{

int x, mudanca, opcao=0;
	printf("Qual e o codigo da musica: ");
	scanf("%d",&x);
	printf("1 - Alterar\n2 - Remover\n");
	scanf("%d",&mudanca);

while(opcao!=6)
{
    printf("Escolha a alteracao:\n1 - Titulo da musica\n2 - Letra\n3 - Codigo partitura\n4 - Codigo do compositor principal\n5 - Codigo do vocalista da musica\n6 - Para sair\n");
    scanf("%d",&opcao);
    switch (opcao)
    {
        case 1:
            if(mudanca==1)
            {
                printf("Digite o titulo da cancao: ");
                limparEntrada();
                gets(cancoes[x].titulo);
                fflush(stdin);
            }
			else
            {
                strcpy(cancoes[x].titulo,"-");
            }
            break;

		case 2:
            if(mudanca==1)
            {
                printf("\nDigite a letra da musica: ");
                limparEntrada();
                gets(cancoes[x].letra);
                fflush(stdin);}
            else
            {
                strcpy(cancoes[x].letra,"-");
            }
            break;

		case 3:
            if(mudanca==1)
            {
                printf("\nDigite o codigo da partitura: ");
                scanf("%d", &cancoes[proximo_cancoes].melodia);
            }
            else
            {
                cancoes[x].melodia=0;
            }
            break;

		case 4:
            if(mudanca==1)
            {
                printf("\nDigite um codigo para o artista compositor principal: ");
                scanf("%d", &cancoes[x].artPrinc);
            }
            else
            {
                cancoes[x].artPrinc=0;
            }
            break;

		case 5:
            if(mudanca==1)
            {
                printf("\nDigite um codigo para o vocalista da primeira gravacao: ");
                scanf("%d", &cancoes[x].vocal);
                limparTela();
            }
            else
            {
                cancoes[x].vocal=0;
            }
            break;
        case 6:
            return;
        default:
            printf("Opcao invalida!");
                break;
        limparTela();
    }
    limparTela();

}
return;
}


void mudaalbum()
{
	int x, mudanca, opcao=0, opcao1,opcao2;
	printf("Qual e o codigo do album: \n");
	scanf("%d",&x);
	printf("1 - Alterar\n2 - Remover\n");
	scanf("%d",&mudanca);

while(opcao!=6)
{
    printf("Escolha a alteracao:\n1 - Titulo do album\n2 -Codigos das listas de musicas\n3 - Data ou previsao de lancamento\n4 - Numero de copias vendidas\n5 - Musicos participantes\n6 - Para sair\n");
    scanf("%d",&opcao);

    switch(opcao)
    {
		case 1:
            if (mudanca==1)
            {
                printf("Digite o titulo do Album: ");
                limparEntrada();
                gets(albuns[x].titulo);
                fflush(stdin);
            }
            else
            {
                strcpy(albuns[x].titulo,"-");
            }
            break;

        case 2:
            if (mudanca==1)
            {
                printf("\nQual a lista de musicas? (coloque os codigos): ");
                scanf("%d", &albuns[x].listaMsc);
            }
            else
            {
                albuns[x].listaMsc=0;
			}
			break;

		case 3:
            if(mudanca==1)
            {
                printf("\nDigite a data de lancamento ou a data prevista DD/MM/AA: ");
                limparEntrada();
                gets(albuns[x].dataLnc);
                fflush(stdin);
            }
            else
            {
                strcpy(albuns[x].dataLnc,"-");
            }
            break;

		case 4:
            if (mudanca==1)
            {
                printf("\nQual o numero de copias vendidas? ");
                scanf("%d", &albuns[x].nmrCopias);
            }
            else
            {
                albuns[proximo_albuns].nmrCopias=0;
            }
            break;

		case 5:
            if (mudanca==1)
            {
                printf("\nDigite a lista de artistas participantes(cantores): ");
                limparEntrada();
                gets(albuns[x].listaPart);
                fflush(stdin);
                limparTela();
            }
            else
            {
                strcpy(albuns[x].listaPart,"-");
            }
            break;
        case 6:
            return;
            default:
                printf("Opcao invalida!");
                    break;

			limparTela();
    }
    limparTela();
}
	return;
}

void ordenacao_artistas(artistas vetor[100])
{
    int posicao, aux, i ,j;

    for(i = 0; i < proximo_artista; i++)
    {
        posicao = i;

        for(j = i + 1; j < proximo_artista; j++)
        {
            if(vetor[j].codigo < vetor[posicao].codigo)
            {
                posicao = j;
            }
        }

        if(posicao != i)
        {
            aux = vetor[i].codigo;
            vetor[i].codigo = vetor[posicao].codigo;
            vetor[posicao].codigo = aux;
        }


     }
    for(i = 0; i < 100; i++)
    {

        artista[i].codigo = vetor[i].codigo;
        artista[i].vlrCache = vetor[i].vlrCache;
        artista[i].qtdComp = vetor[i].qtdComp;
        artista[i].qtdAlbuns = vetor[i].qtdAlbuns;
        strcpy(artista[i].tipoTrab,vetor[i].tipoTrab);
        strcpy(artista[i].dataAnv,vetor[i].dataAnv);
        strcpy(artista[i].email,vetor[i].email);
        strcpy(artista[i].emailEmpr,vetor[i].emailEmpr);
        strcpy(artista[i].nomeArt,vetor[i].nomeArt);
        strcpy(artista[i].nomeBanda,vetor[i].nomeBanda);
        strcpy(artista[i].nomeEmpr,vetor[i].nomeEmpr);
        strcpy(artista[i].nomeVdd,vetor[i].nomeVdd);
        strcpy(artista[i].telefone,vetor[i].telefone);
        if(artista[i].codigo != 0)
        {
            printf("\ncodigo: %d", artista[i].codigo);
        }
    }

}

void ordenacao_cancoes(cancao vetor[100])
{
    int posicao, i, j;
    char aux[100];

    for(i = 0; i < proximo_cancoes; i++)
    {
        for(j = i + 1; j < proximo_cancoes; j++)
        {
            posicao = strcmp(vetor[i].titulo,vetor[j].titulo);

            if(posicao > 0)
            {
                strcpy(aux,vetor[i].titulo);
                strcpy(vetor[i].titulo,vetor[j].titulo);
                strcpy(vetor[j].titulo,aux);
            }
        }
    }
    for(j = 0; j < proximo_cancoes; j++)
    {
        cancoes[j].codigo = vetor[j].codigo;
        cancoes[j].melodia = vetor[j].melodia;
        cancoes[j].artPrinc = vetor[j].artPrinc;
        cancoes[j].vocal = vetor[j].vocal;
        strcpy(cancoes[j].letra,vetor[j].letra);
        strcpy(cancoes[j].titulo,vetor[j].titulo);
        printf("\n Titulo: %s", cancoes[j].titulo);
    }

}

void ordenacao_albuns(album vetor[100])
{
    int posicao, i, j, salto;
    char aux[100];

    for(salto = 0; salto < 100; salto = 3*salto+1);
    while(salto > 0)
    {
        salto = (salto-1)/3;
        for (i = salto; i < 100; i++)
        {
             strcpy(aux,vetor[i].titulo);
             j = i;
             while (vetor[j-salto].titulo > aux)
             {
                   strcpy(vetor[j].titulo,vetor[j-salto].titulo);
                   j -= salto;
                   if (j < salto) break;
             }
             strcpy(vetor[j].titulo,aux);
        }
        }

    for(j = 0; j < 100; j++)
    {
        albuns[j].codigo = vetor[j].codigo;
        albuns[j].listaMsc = vetor[j].listaMsc;
        albuns[j].nmrCopias = vetor[j].nmrCopias;
        strcpy(albuns[j].dataLnc,vetor[j].dataLnc);
        strcpy(albuns[j].listaPart,vetor[j].listaPart);
        strcpy(albuns[j].titulo,vetor[j].titulo);
        if(strlen(albuns[j].titulo)!=0)
        {
            printf("\nTitulo: %s", albuns[j].titulo);
        }
    }

}

void busca_artista(int codigo)
{
    int opcao, cont;

    printf("\n\nDigite o codigo: ");
    scanf("%d",&opcao);
    limparTela();

    for (cont = 0; cont <= 100; cont++)
    {
			if (opcao == artista[cont].codigo)
			{
                printf("\nNome verdadeiro: %s", artista[opcao].nomeVdd);
                printf("\nNome Artistico: %s", artista[opcao].nomeArt);
                printf("\nData de aniversario: %s", artista[opcao].dataAnv);
                printf("\nNome da banda: %s", artista[opcao].nomeBanda);
                printf("\nE-mail: %s", artista[opcao].email);
                printf("\nTelefone: %s", artista[opcao].telefone);
                printf("\nNome do empresario: %s", artista[opcao].nomeEmpr);
                printf("\nE-mail do empresario: %s", artista[opcao].emailEmpr);
                printf("\nTipo de trablho: %s", artista[opcao].tipoTrab);
                printf("\nQuantidade de Albuns: %d", artista[opcao].qtdAlbuns);
                printf("\nQuantidade de composicoes: %d", artista[opcao].qtdComp);
                printf("\nValor do cache: %.2f", artista[opcao].vlrCache);

			}

    }
    for(cont=0; cont <= proximo_cancoes; cont++)
        if (cancoes[cont].artPrinc == opcao)
                printf("\nComposicoes: %s", cancoes[cont].titulo);

}

void busca_cancoes(cancao vetor[100])
{
    int cont;
    char opcao[100];

    printf("Digite o titulo: ");
    scanf("%s", &opcao);
    limparTela();


    for (cont=0; cont <= proximo_cancoes - 1; cont++)
    {
			if (strcmp(opcao,cancoes[cont].titulo)==0)
			{
                printf("\nTitulo: %s", cancoes[cont].titulo);
                printf("\nLetra: %s", cancoes[cont].letra);
                printf("\nMelodia: %d", cancoes[cont].melodia);

                    if ((strcmp(artista[cont].tipoTrab, "Compositor")==0) || (strcmp(artista[cont].tipoTrab, "Ambos")==0))
                        {
                            if (cancoes[cont].artPrinc == artista[cont].codigo)
                            printf("\nArtista compositor principal: %s", artista[cont].nomeArt);
                        }

                    if ((strcmp(artista[cont].tipoTrab,"Cantor")==0)  || (strcmp(artista[cont].tipoTrab, "Ambos")==0))
                    {
                        if (cancoes[cont].vocal == artista[cont].codigo)
                            printf("\nVocalista da primeira gravacao: %s", artista[cont].nomeArt);
                    }
                }
			}
}

void busca_albuns(album vetor[100])
{
    int cont;
    int artP;

    printf("Digite o codigo do artista: ");
    scanf("%d", &artP);

    limparTela();

    for (cont=0; cont <= proximo_artista; cont++)
    {
			if (artP = artista[cont].codigo)
			{
                printf("\nTitulo: %s", albuns[cont].titulo);
                printf("\nData de lancamento: %s", albuns[cont].dataLnc);
                printf("\nNumero de copias: %d", albuns[cont].nmrCopias);
                printf("\nLista de participantes: %s", albuns[cont].listaPart);
                 for(cont=0; cont <= proximo_cancoes; cont++)
                    {
                        if (albuns[cont].listaMsc == cancoes[cont].codigo)
                        printf("\nLista de musicas: %s", cancoes[cont].titulo);
                    }
			}
			else
            {
                printf("Artista não encontrado!");
            }
    }

}

int main()
{
	setlocale(LC_ALL, "");

    printf("Caio Marcelo da Silva de Jesus - PC3011259\n\nJefferson Roberto Piaia Martines - PC3015602\n\n"
           "Murilo Formaggio Feliciano - PC3006875\n\nThiago Souza Peixoto - PC3003353\n\n");
    pause();
    limparTela();

	//VARIAVEIS
	int opcao1, opcao2, opcao3, opcao4, menu0, opcao5;

	//MENU
    do
    {
        printf("\n\n\t\t     ------------\n\t\t     |   MENU   | \n\t\t     ------------ \n\n      1 - Cadastro, alteracao ou remocao de Artista\n"
               "      2 - Cadastro, alteracao ou remocao de Cancoes \n      3 - Cadastro, alteracao ou remocao de Albuns  \n"
               "      4 - Ordenacao\n      5 - Buscas \n      6 - E-mails dos Empresarios \n      0 - sair \n ");
        scanf("%d", &menu0);
        //limparTela();

	switch (menu0)
	{
        case 1:
            printf("1 - Inserir\n2 - Alterar ou remover\n");
            scanf("%d",&opcao3);
            //limparTela();

	    if(opcao3==1)
        {
            AddArtista(opcao1, opcao2);
        }

	    else
        {
            mudaartista();
        }

        break;

        case 2:
            printf("1 - Inserir\n2 - Alterar ou remover\n");
            scanf("%d",&opcao3);
            //limparTela();

        if(opcao3==1)
        {
            Addcancao();
        }

		else
        {
            mudacancao();
        }

        break;

        case 3:
            printf("1 - Inserir\n2 - Alterar ou remover\n");
	    	scanf("%d",&opcao3);
	    	//limparTela();

		if(opcao3==1)
        {
            AddAlbum();
        }

		else
        {
            mudaalbum();
        }
        break;

        case 4:
            printf("Selecione qual lista de ordenacao voce deseja: \n1 - Artista\n2 - Cancao\n3 - Albuns\n");
            scanf("%d", &opcao4);

        if(opcao4 == 1)
        {
            ordenacao_artistas(artista);
        }
        else if(opcao4 == 2)
        {
            ordenacao_cancoes(cancoes);
        }
        else if(opcao4 == 3)
        {
            ordenacao_albuns(albuns);
        }

        else
        {
            printf("Opcao invalida!");
        }
        break;

        case 5:
            printf("Selecione o que você deseja buscar: \n1 - Artista\n2 - Cancao\n3 - Albuns\n");
            scanf("%d",&opcao5);
            switch(opcao5)
            {
                case 1:
                    busca_artista(artista[100].codigo);
                    break;
                case 2:
                    busca_cancoes(cancoes);
                    break;
                case 3:
                    busca_albuns(albuns);
                    break;
                default:
                printf("Opcao invalida!");
                break;
            }

	}
	//limparTela();
    } while (menu0 != 0);

    return 0;
}
