#include<stdio.h>
#include<stdlib.h>

int main(void){
	//Campo es la tabla de juego
	char campo[15][15];
	//Turno indica que equipo juega, dado la cantidad de movimientos disponibles, x1 y x2 son la posicion de la tortuga, y1 y y2 son la posicion de la liebre
	//seed es una semilla aleaotoria ingresada por el usuario, mover sirve para moverse en el campo (1 es derecha y 2 abajo), k es un contador
	//vt y vl son las victorias de la tortuga y liebre correspondientemente, dt y dl son las veces que la tortuga y la liebre cayeron en un pozo respectivamente
	int turno, dado, x1, x2, y1, y2, seed, mover, k = 0, vt = 0, vl = 0, dt = 0, dl = 0;
	//pide la semilla
	printf("Ingrese un numero aleatorio: ");
	scanf("%d", &seed);
	srand(seed);
	printf("Bienvenido al juego de la tortuga (T) y la liebre (L)\n");
	//Llena la matriz de 'X'
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			campo[i][j] = 'X';
		}
	}
	//Pone en cuatro lugares aleatorios dos pozos y dos comodines
	inicio:
	while(k < 2){
		x1 = (rand() % 10) + 1;
		x2 = (rand() % 10) + 1;
		y1 = (rand() % 10) + 1;
		y2 = (rand() % 10) + 1;
		campo[x1][x2] = 'O';
		campo[y1][y2] = 'C';
		k++;
	}
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	turno = 1;
	while(1){
		//Genera un numero aleatorio
		dado = (rand() % 6) + 1;
		//Chequea si turno es un numero par para indicar si va la tortuga o la liebre. Impar es la tortuga y par es la liebre
		if(turno % 2 != 0) printf("\nVa la tortuga\n", dado);
		else{ 
			dado *= 2;
			printf("\nVa la liebre\n", dado);
		}
		//El loop corre mietras que dado sea mayor a 0
		while(dado > 0){
			//Imprime el campo
			for(int i = 0; i < 15; i++){
				for(int j = 0; j < 15; j++){
					if(x1 == i && x2 == j)printf("T ");
					else if(y1 == i && y2 == j)printf("L ");
					else printf("%c ", campo[i][j]);
					//else printf("X ");
				}
				printf("\n");
			}
			error:
			printf("Te quedan %d movimientos\n", dado);
			//Le pide al usuario que haga un movimiento (1 es derecha y 2 abajo)
			printf("A donde te moves? (1 = derecha, 2 = abajo): ");
			printf("\n");
			scanf("%d", &mover);
			switch(mover){
				//De forma resumida, primero se chequea quien va segun el turno. Luego se fija si puede seguir avanzando en esta direccion. Hace el movimiento y chequea si el lugar al que cae el equipo es pozo o comodin
				//En caso de que sea pozo, se chequea si ya cayó tres veces, si es asi gana el equipo contrario
				//Si llega a la final de la matriz, chequea si ya llegó tres veces. De ser ese el caso gana este equipo
				//Si nada de esto pasa, le resta 1 a la cantidad de movimientos restantes y sigue en el loop
				case 1:
					if(turno % 2 != 0){ 
						if(x2 == 14) goto error;
						else x2++;
						if(campo[x1][x2] == 'C') dado *= 2;
						else if(campo[x1][x2] == 'O'){
							printf("Caiste al pozo!\n");
							dt++;
							if(dt == 3){
								printf("La liebre gano el juego con %d caidas y %d comodines!", dl, vl);
								return 0;
							}else goto inicio;
						}
						else if(x1 == 14 && x2 == 14){
							printf("Gana la tortuga!\n");
							vt++;
							if(vt == 3){
								printf("La tortuga gano el juego con %d caidas y %d comodines!", dt, vt);
								return 0;
							}else goto inicio;
						}
						else;
					}
					else{ 
						if(y2 == 14) goto error;
						else y2++;
						if(campo[y1][y2] == 'C') dado = 1;
						else if(campo[y1][y2] == 'O'){
							printf("Caiste al pozo!\n");
							dl++;
							if(dl == 0){
								printf("La tortuga gano el juego con %d caidas y %d comodines!", dt, vt);
								return 0;
							}else goto inicio;
						}
						else if(y1 == 14 && y2 == 14){
							printf("Gana la liebre!\n");
							vl++;
							if(vl == 3){
								printf("La liebre gano el juego con %d caidas y %d comodines!", dl, vl);
								return 0;
							}else goto inicio;
						}
						else;
					}
					dado--;
					break;
				//De forma resumida, primero se chequea quien va segun el turno. Luego se fija si puede seguir avanzando en esta direccion. Hace el movimiento y chequea si el lugar al que cae el equipo es pozo o comodin
				//En caso de que sea pozo, se chequea si ya cayó tres veces, si es asi gana el equipo contrario
				//Si llega a la final de la matriz, chequea si ya llegó tres veces. De ser ese el caso gana este equipo
				//Si nada de esto pasa, le resta 1 a la cantidad de movimientos restantes y sigue en el loop
				case 2:
					if(turno % 2 != 0){ 
						if(x1 == 14) goto error;
						else x1++;
						if(campo[x1][x2] == 'C') dado *= 2;
						else if(campo[x1][x2] == 'O'){
							printf("Caiste al pozo!\n");
							dt++;
							if(dt == 3){
								printf("La liebre gano el juego con %d caidas y %d comodines!", dl, vl);
								return 0;
							}else goto inicio;
						}
						else if(x1 == 14 && x2 == 14){
							printf("Gana la tortuga!\n");
							vt++;
							if(vt == 3){
								printf("La tortuga gano el juego con %d caidas y %d comodines!", dt, vt);
								return 0;
							}else goto inicio;
						}
						else;
					}
					else{ 
						if(y1 == 14) goto error;
						else y1++;
						if(campo[y1][y2] == 'C') dado = 1;
						else if(campo[y1][y2] == 'O'){
							printf("Caiste al pozo!\n");
							dl++;
							if(dl == 0){
								printf("La tortuga gano el juego con %d caidas y %d comodines!", dt, vt);
								return 0;
							}else goto inicio;
						}
						else if(y1 == 14 && y2 == 14){
							printf("Gana la liebre!\n");
							vl++;
							if(vl == 3){
								printf("La liebre gano el juego con %d caidas y %d comodines!", dl, vl);
								return 0;
							}else goto inicio;
						}
						else;
					}
					dado--;
					break;
				default:
					goto error;
			}
		}
		turno ++;
	}
}
