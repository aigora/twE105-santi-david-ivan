#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

int main(){
	int principio();
	principio();
}

int principio()
{
	int elige, hpj=100, ataquej=5, curacionj=5, defensaj=5, evasionj=5, hpb=1000, ataqueb=30, curacionb=30;
	int juego(int hpj, int ataquej, int curacionj, int defensaj, int evasionj);
	void stats(int *hj, int *aj, int *cj, int *dj, int *ej), dificultad(int *hb, int *ab, int *cb);
	int leeFichero(char nombreFichero[150]);
	
	printf("Insetar aqui introduccion e instrucciones.\n");
	system("pause");
	system("cls");
	
	do{
	    printf("(1)Empezar el Juego\n(2)Dificultad\n(3)Salir\n");
	    scanf("%i", &elige);
	    
	    switch(elige){
		case 1:
			if (leeFichero("historia.txt") == 1)
			{
				return;
			}
			stats(&hpj, &ataquej, &curacionj, &defensaj, &evasionj);
			juego(hpj, ataquej, curacionj, defensaj, evasionj);
		    break;

		    
		case 2:
			if (leeFichero("historia_dif.txt") == 1)
			{
				return;
			}
			dificultad(&hpb, &ataqueb, &curacionb);
			break;
		
		case 3:
			if (leeFichero("historia_ex.txt") == 1)
			{
				return;
			}
			exit(EXIT_SUCCESS);
			break;
        }
	}while(elige != 1);	
return 0;	
}

void stats(int *hj, int *aj, int *cj, int *dj, int *ej)
{
	if (leeFichero("stats.txt") == 1)
			{
				return;
			}
			
	int puntos, elige;		
	system("pause");
    for(puntos = 10; puntos > 0; puntos--){
    	
    	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Defensa = %i\n(5)Evasion = %i\n\nPuntos %i\nElija la cualidad que desea potenciar:\n", *hj, *aj, *cj, *dj, *ej, puntos);
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
    			*dj += 5;
    			break;
    			
    		case 5:
    			*ej += 5;
    			break;
		}
		system("cls");
	}
	printf("Estas son tus estadisticas finales, podran seguir variando durante la partida,\nno olvides revisar el apartado de informacion para mantenerte al tanto!\n\n");
	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Defensa = %i\n(5)Evasion = %i\n", *hj, *aj, *cj, *dj, *ej);
system("pause");
system("cls");
}


void dificultad(int *hb, int *ab, int *cb){
	int elige;
	printf("Elija la dificultad:\n(1)No me hagas danho\n(2)Me gustan los retos\n(3)Soy un Guerrero\n");
	scanf("%i", &elige);
	
	switch(elige){
		case 1:
			printf("Buena eleccion, si tienes menos de 10 anhos.\n");
			*hb = 500;
			*ab = 20;
			*cb = 20;
			break;
			
		case 2:
			printf("Espero tu victoria valiente.\n");
			*hb = 1000;
			*ab = 30;
			*cb = 30;
			break;
			
		case 3:
			printf("Ataca Guerro!!!\n");
			*hb = 2000;
			*ab = 40;
			*cb = 40;
			break;
	}
	system("pause");
	system("cls");
}


int juego(int hpj, int ataquej, int curacionj, int defensaj, int evasionj){
    
	int hpb=500, accion, mod, ataqueb=5, curacionb=5, repetir;
	//FUNCIONES DEL JUGADOR
    int ataque(int hpb, int ataquej), curacion(int hpj, int curacionj), aumentoataque(int ataquej), aumentocuracion(int curacionj), reduccionataque(int ataqueb), reduccioncuracion(int curacionb);
    //FUNCIONES DEL ENEMIGO
	int ataqueenemigo(int hpj, int ataqueb), curacionenemigo(int hpb, int curacionb), aumentoataqueb(int ataqueb), aumentocuracionb(int curacionb), reduccionataqueb(int ataquej), reduccioncuracionb(int curacionj);

    srand(time(NULL));
	
	system("cls");
	do{
    	do{
    		printf("TURNO DEL JUGADOR:\n");
			printf("(1)Ataque\n(2)Curacion\n(3)Modificadores\n(4)Informacion\n(5)Rendirse\n");
    		scanf("%i", &accion);
    		
    		if(accion == 4){//INFORMACI�N
    		    printf("TU:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\nENEMIGO:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\n", hpj, curacionj, ataquej, hpb, curacionb, ataqueb);
    		    system("pause");
    		    printf("\n");
    		    }
    		    
		}while(accion == 4);
    	
    	mod = 0;
    	switch(accion){
    		
    		case 1://ATAQUE
    			hpb = ataque(hpb, ataquej);
			    printf("\nEl enemigo tiene %i puntos de salud.\n", hpb);
			    system("cls");
			    break;
			    
			case 2://CURACI�N
				hpj = curacion(hpj, curacionj);
			    printf("\nAhora tienes %i puntos de salud.\n", hpj);
			    system("cls");
			    break;
			    
			case 3://MODIFICADORES
				printf("(1)Aumento de Ataque\n(2)Aumento de Curacion\n(3)Reduccion del Ataque enemigo\n(4)Reduccion de la Curacion del enemigo\n");
    		    scanf("%i", &mod);
    		    system("cls");
    		    break;
    		    
    		case 5://RENDIRSE
    		    
    		    	
				if (leeFichero("historia_ex.txt") == 1)
					{
				     return;
					}
    		    hpj = 0;
    		    break;
		}
    	
		switch(mod){
			
			case 1://AUMENTO DE ATAQUE DEL JUGADOR
				ataquej = aumentoataque(ataquej);
		        printf("\nTienes %i puntos de ataque, haras mas danho con tus proximos golpes.\n", ataquej);
		        system("cls");
		        break;
		        
		    case 2://AUMENTO DE CURACI�N DEL JUGADOR
		    	curacionj = aumentocuracion(curacionj);
		        printf("\nTienes %i puntos de curacion, recuperaras mas vida la proxima vez que te cures.\n", curacionj);
		        system("cls");
		        break;
		        
		    case 3://REDUCCI�N DE ATAQUE DEL ENEMIGO
		    	ataqueb = reduccionataque(ataqueb);
		    	if(ataqueb<=0)
		    	ataqueb=1;
		        printf("\nEl Enemigo tiene %i puntos de ataque, hara menos danho con sus proximos golpes.\n", ataqueb);
		        system("cls");
		        break;
		        
		    case 4://REDUCCI�N DE CURACI�N DEL ENEMIGO
		    	curacionb = reduccioncuracion(curacionb);
		    	if(curacionb<=0)
		    	curacionb=1;
		        printf("\nEl Enemigo tiene %i puntos de curacion, su curacion se ha visto reducida.\n", curacionb);
		        system("cls");
		        break;
		}    	
		
		
	//TURNO DEL ENEMIGO
		printf("\n\nTURNO DEL ENEMIGO:\n");
		accion = rand() % 3 + 1;
		system("pause");
		
		switch(accion){
			
			case 1://ATAQUE
				hpj = ataqueenemigo(hpj, ataqueb);
			    printf("\nTienes %i puntos de salud.\n", hpj);
			    system("cls");
			    break;
			
			case 2://CURACI�N
				hpb = curacionenemigo(hpb, curacionb);
			    printf("\nEl Enemigo tiene %i puntos de salud.\n", hpb);
			    system("cls");
			    break;
			    
			case 3://MODIFICADORES
				accion = rand() % 4 + 4;
			
			case 4://AUMENTO ATAQUE
				ataqueb = aumentoataqueb(ataqueb);
			    printf("\nEl enemigo tiene %i puntos de ataque, hara mas danho con sus proximos golpes.\n", ataqueb);
			    system("cls");
				break;
				
			case 5://AUMENTO CURACI�N
				curacionb = aumentocuracionb(curacionb);
			    printf("\nEl enemigo tiene %i puntos de curacion, recuperara mas vida la proxima vez que se cure.\n", curacionb);
			    system("cls");
				break;
				
			case 6://REDUCCI�N ATAQUE DEL JUGADOR
				ataquej = reduccionataqueb(ataquej);
				if(ataquej<=0)
		    	ataquej=1;
			    printf("\nHa decidido sabotearte ahora tienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
			    system("cls");
				break;
				
			case 7://REDUCCI�N CURACI�N DEL ENEMIGO
				curacionj = reduccioncuracionb(curacionj);
				if(curacionj<=0)
		    	curacionj=1;
			    printf("\nTienes %i puntos de curacion, tu curacion se ha visto reducida.\n", curacionj);
			    system("cls");
				break;
		}

		printf("\n\n");
		
	}while(hpj > 0 && hpb > 0);
	
		system("cls");
	
	printf(" si quires volver a intentarlo indtroduce 1, si por el contrario quieres ir a llorar 0\n");
	    scanf("%i", &repetir);
	    if (repetir == 1)
	    {
	    		system("cls");
	    	principio();
	    	
		}
		
	
return 0;
}




//FUNCION DE ATAQUE DEL JUGADOR
int ataque(int hpb, int ataquej){
	
	int a1, a2, a;
	
	a1 = rand() % 5 + ataquej;
	a2 = rand() % 5 + ataquej;
	a = a1 + a2;
	
	printf("\nTienes %i de poder, tu ataque hace %i de danho al enemigo.\n\n", ataquej, a);
	system ("pause");
	
	return hpb = hpb - a;
}
//FUNCION DE CURACION DEL JUGADOR
int curacion(int hpj, int curacionj){
	
	int c1, c2, c;
	
	c1 = rand() % 5 + curacionj;
	c2 = rand() % 5 + curacionj;
	c = c1 + c2;
	
	printf("\nTienes %i de curacion, tu salud aumenta en %i puntos.\n\n", curacionj, c);
	system ("pause");
	
	return hpj = hpj + c;
}
//FUNCION DE AUMENTO DE PODER DEL JUGADOR
int aumentoataque(int ataquej){
	
	int aa;
	
	aa = rand() % 4 + 2;

	printf("\nHas obtenido %i de poder.\n\n", aa);
	system ("pause");
	
	return ataquej += aa;
}
//FUNCION DE AUMENTO DE CURACION DEL JUGADOR
int aumentocuracion(int curacionj){
	
	int ac;
	
	ac = rand() % 4 + 2;

	printf("\nHas obtenido %i de curacion.\n\n", ac);
	system ("pause");
	
	return curacionj += ac;
}
//FUNCION DE REDUCCION DE ATAQUE DEL JUGADOR HACIA EL ENEMIGO
int reduccionataque(int ataqueb){
	
	int ra;
	
	ra = rand() % 4 + 2;

	printf("\nSe ha reducido %i de poder del enemigo.\n\n", ra);
	system ("pause");
	
	return ataqueb -= ra;
}
//FUNCION DE REDUCCION DE CURACION DEL JUGADOR HACIA EL ENEMIGO
int reduccioncuracion(int curacionb){
	
	int rc;
	
	rc = rand() % 4 + 2;

	printf("\nSe ha reducido %i de la curacion del enemigo.\n\n", rc);
	system ("pause");
	
	return curacionb -= rc;
}





//FUNCION DE ATAQUE DEL ENEMIGO
int ataqueenemigo(int hpj, int ataqueb){
	int a1, a2, a;
	
	printf("\nEl enemigo ha decidido atacarte.\n");
	a1 = rand() % 5 + ataqueb;
	a2 = rand() % 5 + ataqueb;
	a = a1 + a2;
	
	printf("\nEl enemigo tiene %i de poder, su ataque te hace %i de danho.\n", ataqueb, a);
	
	return hpj = hpj - a;
}
//FUNCION DE CURACI�N DEL ENEMIGO
int curacionenemigo(int hpb, int curacionb){
	int c1, c2, c;
	
	printf("\nEl enemigo ha decidido curarse.\n");
	c1 = rand() % 5 + curacionb;
	c2 = rand() % 5 + curacionb;
	c = c1 + c2;
	
	printf("\nEl enemigo tiene %i de curacion, su salud aumenta en %i puntos.\n", curacionb, c);
	
	return hpb = hpb + c;
}

//FUNCION DE AUMENTO DE PODER DEL ENEMIGO
int aumentoataqueb(int ataqueb){
	
	int aa;
	
	printf("\nEl enemigo ha decidido aumentar su poder.\n");
	aa = rand() % 4 + 2;

	printf("\nEl enemigo ha obtenido %i de poder.\n", aa);
	
	return ataqueb += aa;
}
//FUNCION DE AUMENTO DE CURACI�N DEL ENEMIGO
int aumentocuracionb(int curacionb){
	
	int ac;
	
	printf("\nEl enemigo ha decidido aumentar su curacion.\n");
	ac = rand() % 4 + 2;

	printf("\nEl enemigo ha obtenido %i de curacion.\n", ac);
	
	return curacionb += ac;
}
//FUNCION DE REDUCCION DE ATAQUE DEL ENEMIGO HACIA EL JUGADOR
int reduccionataqueb(int ataquej){
	
	int ra;
	
	printf("\nEl enemigo ha decidido reducir tu ataque.\n");
	ra = rand() % 4 + 2;

	printf("\nSe ha reducido %i de tu poder.\n", ra);
	
	return ataquej -= ra;
}
//FUNCION DE REDUCCION DE CURACION DEL ENEMIGO HACIA EL JUGADOR
int reduccioncuracionb(int curacionj){
	
	int rc;
	
	printf("\nEl enemigo ha decidido reducir tu curacion.\n");
	rc = rand() % 4 + 2;

	printf("\nSe ha reducido %i de la curacion del enemigo.\n", rc);
	
	return curacionj -= rc;
}
//FUNCION ENCARGADA DE LEER LOS FICHEROS LLAMADOS
int leeFichero(char nombreFichero[150])
{
	FILE *archivo;
	char caracter;
	
	
	archivo = fopen(nombreFichero,"r");
	
	if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
        return 1;
    }
    else
    {
        while((caracter = fgetc(archivo)) != EOF)
	    {
			printf("%c",caracter);
	    }
    }
    
    fclose(archivo);
    
    printf("\n\n");
    
	return 0;
	
}
