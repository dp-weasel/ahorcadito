#include
#include
#include
#include
#include

int num, fin;

void menu();
void generador(char palabra[]);
void caracter(char palabra[], char adivinando[]);
void nombre(char palabra[]);

int main ()
{
    char palabra[30], adivinando[30];
    int op, i;

    num = 5;
    fin = 1;


    menu();
    generador(palabra);

    printf("Primer intento!! (ojo que los espacios tambien cuentan)\n\t[ ");
    for ( i = 0; i < strlen(palabra); ++i)
    {
	printf("_ ");
	adivinando[i] = '_';
    }

    adivinando[i+1] = '\n';

    printf("]\nIngresa una letra para el primer intento: ");

    caracter(palabra, adivinando);

    do
    {
	printf("Como desea continuar?\tIntentos restantes\n\t\t\t[ ");
	for(i = 0; i <5; ++i)
	{
	    if (i<num)
	    {
		printf("%d ", i+1);
	    }else
	    {
		printf("* ");
	    }
	}
	printf(" ]\n1)Ingresar otra letra\n2)Arriezgar por la palabra\n");
	printf("Opcion: ");
	scanf("%d",&op);
	switch (op)
	{
	    case 1: 
		printf("Ingrese una letra: ");
		caracter(palabra, adivinando);
		break;
	    case 2:
		printf("Ingresa el nombre del equipo: ");
		nombre(palabra);
		break;
	}

    }while (num > 0 && fin);
    if (fin)
    {
	printf("\nLo siento pero terminaste las oportunidades :(\n");
    }else
    {
	printf("\nFelicidades Ganaste el juego!!! :)\n");
    }
    printf("Gracias por usar mi software\nEspero te alla gustado ;)\n");
    while(getchar() != '\n');
    getchar();
}

void menu()
{
    int op;

    printf("************************************\n");
    printf("************************************\n");
    printf("**              JUEGO             **\n");
    printf("**  ADIVINA EL EQUIPO DE FUTBOL   **\n");
    printf("**                                **\n");
    printf("**  1)  JUGAR                     **\n");
    printf("**  2)  Salir                     **\n");
    printf("**                                **\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&op);

    if (op == 2)
    {
	printf("Gracias por usar mi software\nEspero te alla gustado ;)\n");
	while(getchar() != '\n');
	getchar();
	exit(0);
    }
};

void generador(char palabra[])
{
    int op, seed = time(NULL);
    srand(seed);

    for (int i = 0; i < 3; ++i)
    {
	op = rand()%20;
    }

    switch(op)
    {
	case 0: strcpy(palabra, "BOCA JUNIORS");
		break;
	case 1: strcpy(palabra, "RIVER PLATE");
		break;
	case 2: strcpy(palabra, "SAN LORENZO");
		break;
	case 3: strcpy(palabra, "RACING");
		break;
	case 4: strcpy(palabra, "INDEPENDIENTE");
		break;
	case 5: strcpy(palabra, "HURACAN");
		break;
	case 6: strcpy(palabra, "NEWELLS OLD BOYS");
		break;
	case 7: strcpy(palabra, "CENTRAL");
		break;
	case 8: strcpy(palabra, "ESTUDIANTES DE LA PLATA");
		break;
	case 9: strcpy(palabra, "TIGRE");
		break;
	case 10: strcpy(palabra, "GODOY CRUZ DE MENDOZA");
		break;
	case 11: strcpy(palabra, "LANUS");
		break;
	case 12: strcpy(palabra, "BANFIELD");
		break;
	case 13: strcpy(palabra, "ARSENAL DE SARANDI");
		break;
	case 14: strcpy(palabra, "ATLETICO RAFAELA");
		break;
	case 15: strcpy(palabra, "COLON DE SANTA FE");
		break;
	case 16: strcpy(palabra, "UNION DE SANTA FE");
		break;
	case 17: strcpy(palabra, "QUILMES");
		break;
	case 18: strcpy(palabra, "OLIMPO DE BAHIA BLANCA");
		break;
	case 19: strcpy(palabra, "VELEZ SARFIELD");
		break;
    }
};

void caracter(char palabra[], char adivinando[])
{
    int contador = 0;
    char a, intento;

    while(getchar() != '\n');
    a = getchar();
    intento = toupper (a);

    printf("\t[ ");
    for (int i = 0; i < strlen(palabra); ++i)
    {
	if (palabra[i] == intento)
	{
	    printf("%c ", intento);
	    adivinando[i] = palabra[i];
	    ++contador;
	}else
	{
	    printf("%c ",adivinando[i]);
	}
    }

    printf("]\n");

    if (contador != 0)
    {
	if (contador == 1)
	{
	    printf("felicidades acertaste 1 vez :)\n");
	}else
	{
	    printf("Felicidades acertaste %d veces :)\n",contador);
	}
    }else
    {
	printf("Lo siento, pero esa letra no se encuentra en la palabra :(\n");
	--num;
    }
    fin = 0;
    for (int i = 0; i < strlen(palabra); ++i)
    {
	if (adivinando[i] != palabra[i])
	{
	    fin = 1;
	}
    }
};

void nombre(char palabra[])
{
    int i, j;
    char letra[30], arriezgo[30];

    while(getchar() != '\n');

    for(i=0; (letra[i] = getchar()) != '\n'; ++i)
	;

    for(j=0; j< i; ++j)
    {
	arriezgo[j] = toupper(letra[j]);
    }

    arriezgo[i+1] = '\n';

    fin = 0;

    for (i = 0; i < strlen(palabra); ++i)
    {
	if (arriezgo[i] != palabra[i])
	{
	    fin = 1;
	}
    }

    if(fin == 1)
    {
	printf("Lo siento pero fallaste :(\n");
	--num;
    }
};
