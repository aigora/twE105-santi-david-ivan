#include<stdio.h>
void stats(int *hj, int *aj, int *cj, int *ej, int *dj)
{
	int puntos, elige;

	printf("Es hora de elegir tus estadisticas!\nContaras con 10 puntos a repartir entre 5 cualidades de tu personaje,\nelige bien valiente pues puede que tu partida dependa de ello!\n");
	system("pause");
	system("cls");

    for(puntos = 10; puntos > 0; puntos--){

    	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Evasion = %i\n(5)Defensa = %i\n\nPuntos %i\nElija la cualidad que desea potenciar:\n", *hj, *aj, *cj, *ej, *dj, puntos);
    	scanf("%i", &elige);

    	switch(elige){
    		case 1:
    			*hj += 50;
    			break;

    		case 2:
    			*aj += 5;
    			break;

    		case 3:
    			*cj += 5;
    			break;

    		case 4:
    			*ej += 5;
    			break;

    		case 5:
    			*dj += 5;
    			break;
    		
    		default:
    			printf("Pierdes el punto, elige bien la proxima vez.\n");
    			system("pause");
    			break;
		}
		system("cls");
	}
	printf("Estas son tus estadisticas finales, podran seguir variando durante la partida,\nno olvides revisar el apartado de informacion para mantenerte al tanto!\n\n");
	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Evasion = %i\n(5)Defensa = %i\n", *hj, *aj, *cj, *ej, *dj);
system("pause");
system("cls");
}
