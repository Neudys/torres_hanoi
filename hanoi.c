#include <stdio.h>
#include <stdlib.h>

// creacion de el array bidimensional a utilizar dentro de el codigo
int arr[3][3] =
    {
        {1,0,0},// disco 1   
        {2,0,0},// disco 2
        {3,0,0} // disco 3
    //   1,2,3
	//   torres
    };
// variable para manejo de switch mas abajo
char opcion;
// variable para el manejo de el do / while mas abajo 
// variable calificacion para manejar las calificaciones 
// variable resultado para la operacion matematica de saber la cantidad de intentos 
// variable base que sera igual al numero de discos
// variable conteo para manejar las veces que se mueven los discos
int booleano = 0, calificacion = 10, conteo = 0, base = 3 ,res = 0;
// funcion que imprime el estado de el juego
void estado(){
	
	printf("    ==================\n");
    printf("    ESTADO DE EL JUEGO\n");
    printf("    ==================\n\n");
    
//    printf(" estado de la torre numerica: \n\n");
    // for que imprime la torre en numeros
//    for (int j = 0; j < 3; j++) { // Recorre las filas                  // si desea ver el estado de las torres en numeros 
//        for (int k = 0; k < 3; k++) { // Recorre las columnas	          // descomentar estas lineas de codigo
//            printf(" %6d  ", arr[j][k]);
//        }
//        printf("\n");
//    }
    printf("\n");
    printf(" estado de la torre con caracteres: \n\n");
    // for que imprime la torre en caracteres
    for (int j = 0; j < 3; j++) { // Recorre las filas
        for (int k = 0; k < 3; k++) { // Recorre las columnas	
            if(arr[j][k] != 0){
            	if(arr[j][k] == 1){
            		printf("     #     ");
				}
				if(arr[j][k] == 2){
            		printf("    ###    ");
				}
				if(arr[j][k] == 3){
            		printf("   #####   ");
				}
				
			}else{
				printf("     |     ");
			}
        }
        printf("\n");
    }
    printf("\n");
    
    
    // serie de opciones a elegir dentro de la aplicacion 
    printf("a - desplaza disco desde el eje izquierdo al central.\n");
	printf("s - desplaza disco desde el eje izquierdo al derecho.\n");
	printf("d - desplaza disco desde el eje central al izquierdo.\n");
	printf("f - desplaza disco desde el eje central al derecho.\n");
	printf("g - desplaza disco desde el eje derecho al izquierdo.\n");
	printf("h - desplaza disco desde el eje derecho al central.\n");
	printf("x - sal del juego\n\n");
}


// funcion para mover los discos dentro de el juego 
void mover_disco(int origen, int destino){
	// int que almacena el idsco -1 significa que no hay 
	int disco = -1;
	// a= variable temporal para almacenar la altura del destino
	// n= variable temporal para almacenar la altura del origen
	int n,a;
	
	// verificacion de existencia de discos
	// asignar la altura del disco tomado (origen)
	for (int i= 2; i >= 0 ; i--){
		if (arr[i][origen] != 0){
			disco = arr[i][origen];
			n = i;
		}
	}
	
	
	// condicion para saber si hay discos 
	if (disco != -1){
		// for para asignar la altura del destino
		for (int i = 0; i<3 ; i++){
			if (arr[i][destino] == 0){
				a = i;
			}
		}
		// verificar que el destino sea igual a 2 o menor a este 
		// si no es 2, verifica que el disco de abajo sea de mayor diametro que el guardado proximamente 
		if (a == 2 || arr[a + 1][destino] > disco) {
                arr[a][destino] = disco;
                arr[n][origen] = 0;
                conteo++; 
                
        }else{
        	// error de mover el disco a una torre con disco mas pequeño 
        	printf("El Disco que desea mover a la torre %d es muy grande\n", destino + 1);
		}
	}
	// conficional para manejar la calificacion, si el conteo excede la cantidad de itentos, se le restara 1 a la calificacion final 
	if ( conteo > res){
		calificacion--; 
	}
}

// funcion principal que controla todo
int main() {
	// variable temporal para iniciar las operaciones 
	int temp = 2 ;
	// bucle imitanto la operacion de elevar
	// base - 1 porque al elevar 2 ^ 1 es igual a 2 entonces omitimos un numero 
	for( int i = 0 ; i < base - 1 ; i++){
		// almacenamos en res sumandole cada iteracion 
		res += temp * 2;
	}
	// le restamos 1 al resultado y listo
	res = res - 1;
	
	// funcion para imprimir el estado
	estado();
    // switch general que maneja las opciones 
	do {
		// escaner de opciones 
		scanf(" %c", &opcion);
		
		switch(opcion){
			// casos a ocurrir
			case 'a':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(0,1);
				estado();
				break;
			case 's':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(0,2);
				estado();
				break;
			case 'd':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(1,0);
				estado();
				break;
			case 'f':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(1,2);
				estado();
				break;
			case 'g':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(2,0);
				estado();
				break;
			case 'h':
				//limpiar pantalla
				system("cls");
				//añadimos origen y destino dentro de las torres 
				mover_disco(2,1);
				estado();
				break;
			case 'x':
				// variable booleano que maneje la salida del juego
				booleano = 1;
				break;
			default:
				system("cls");
				estado();
				printf("introduzca una opcion valida!!!!\n");
				break;
		}
		// condicional que maneje si el juego fue acabado correctamente
		if (arr[0][2] == 1 && arr[1][2] == 2 && arr[2][2] == 3){
			printf("FELICIDADEZ HAS RESUELTO EL PROBLEMA!!!");
			// condicional que maneje los mensajes segun la calificacion resltante
			if ( calificacion >= 9){
				printf("\nTU CALIFICACION FINAL ES DE %d EXCELENTE", calificacion);
			}else if ( calificacion < 9 && calificacion > 6 ){
				printf("\nTU CALIFICACION FINAL ES DE %d BIEN", calificacion);
			}else{
				printf("\nTU CALIFICACION FINAL ES DE %d PUEDES MEJORAR :(", calificacion);
			}
			
			// variable booleano que maneje la salida del juego si se completa
			booleano = 1;
		}
		
	}while(booleano != 1);  
    return 0;
}