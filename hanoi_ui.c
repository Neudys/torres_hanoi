#include <stdio.h>
#include <stdlib.h>

/*
	Autor: Willoom
	Fecha: 9 de diciembre de 2024
	Descripción:

		Al jugador se le imprime por pantalla una representación ASCII
		de los ejes tal como
  #     |     |
 ###    |     |
#####   |     |

		En el juego, el jugador ha de pasar un disco por turno a otro eje.

		Existen restricciones: 

			- no podemos poner un disco de diámetro superior sobre otro de 
			diámetro inferior, 

			- no podemos mover un disco desde un eje sin discos,

			- sólo podemos mover un disco a la primera posición inferior libre
			del eje destino. 
 
*/


/*

FUNCIÓN: hanoi_ui_3discos

PARÁMETROS: int * posicion_discos
			Este puntero al primer entero de un array de tres registra las posiciones de los discos
			en cada eje.

			Por tanto sus valores válidos serán:
			-> 1 eje izquierdo
			-> 2 eje central
			-> 3 eje derecho

			Si los valores del array son 3, 2, 1 el resultado esperado a visualizar por pantalla sería:

  |     |     |
  |     |     |
#####  ###    #	 

*/
void hanoi_ui_3discos(int* posicion_discos) {
	int t1 = 2;
	// definir array para manejar torres / discos
	int arr[3][3] =
    {
        {0,0,0},   
        {0,0,0},   
        {0,0,0}
    };
    
    
    // intercambio de posicioenes entre origrn y destino
    arr[t1][posicion_discos[2] - 1] = 3;
    //verificacion de alturas dentro del array
	if (posicion_discos[2] == posicion_discos[1] || posicion_discos[2] == posicion_discos[0]){
		t1=1;
	}
	
	// intercambio de posicioenes entre origrn y destino
	arr[t1][posicion_discos[1] - 1] = 2;
	//verificacion de alturas dentro del array
	if (posicion_discos[1] == posicion_discos[0]){
		t1 = 0;
	}
	// intercambio de posicioenes entre origrn y destino
	arr[t1][posicion_discos[0] - 1] = 1;
	// iteracion para la eliminacion de los espacios sobrandes debajo de cada disco
	for(int i= 0; i < 2 ; i++){
		for (int t = 0; t < 2 ; t++){
			if (arr[i+1][posicion_discos[t] - 1] == 0 ){// verificamos si debajo de el disco queda un espacio en blanco
				arr[i+1][posicion_discos[t] - 1] = arr[i][posicion_discos[t] - 1];// de ser asi bajamos el disco
				arr[i][posicion_discos[t] - 1] = 0; // limpiamos el espacio sobrante
			}
		}
	}
	// muestra de el menu en numeros
	printf("\nEstado de las torre numerica:\n\n");
	printf("\n");
    for (int j = 0; j < 3; j++) { // Recorre las filas
        for (int k = 0; k < 3; k++) { // Recorre las columnas	
            printf(" %2d  ", arr[j][k]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("\nEstado de las torres:\n\n");
    // intercambio de numero a texto en base a bucles y cadenas 
    for (int j = 0; j < 3; j++) { // Recorre las filas
        for (int k = 0; k < 3; k++) { // Recorre las columnas	
            if(arr[j][k] != 0){
            	if(arr[j][k] == 1){
            		printf("  #  ");
				}
				if(arr[j][k] == 2){
            		printf(" ### ");
				}
				if(arr[j][k] == 3){
            		printf("#####");
				}
				
			}else{
				printf("  |  ");
			}
        }
        printf("\n");
    }
    printf("\n");
}


/*

FUNCIÓN: hanoi_ui_ndiscos

PARÁMETROS: int * posicion_discos
			Este puntero al primer entero de un array de n discos y registra las posiciones de estos discos
			en cada eje.

			Por tanto sus valores válidos serán:
			-> 1 eje izquierdo
			-> 2 eje central
			-> 3 eje derecho

			Si num_discos es cuatro y los valores del array son 3, 2, 1, 1 
			el resultado esperado a visualizar por pantalla sería:

   |       |       |
 #####     |       |
#######   ###      #    


*/
void hanoi_ui_ndiscos(int num_discos, int* posicion_discos) {
    int array[num_discos][3]; // matriz para representar las torres
	if (num_discos <= 10){
			// inicializar la matriz con ceros
	    for (int j = 0; j < num_discos; j++) {
	        for (int k = 0; k < 3; k++) {
	            array[j][k] = 0;
	        }
	    }
	
	    // aqui se colocan los discos en las torres según la posicion de los discos
	    int a[3] = {num_discos - 1, num_discos - 1, num_discos - 1}; // altura disponible en cada torre (desde abajo hacia arriba)
	    for (int i = 0; i < num_discos; i++) {
	        int torre = posicion_discos[i] - 1; // se selecciona la torrw correspondiente sea (0, 1 o 2)
	        array[a[torre]][torre] = num_discos - i; // colocar el disco (de mayor a menor)
	        a[torre]--; // se controlan las alturas disponibles dentro de la torre 
	    }
	
	    // imprimir el estado de las torres 
	    printf("\nEstado de las torre numericas:\n\n");
	    for (int j = 0; j < num_discos; j++) {
	        for (int k = 0; k < 3; k++) {
	            printf(" %6d ", array[j][k]); // mostrar el valor del disco o 0
	        }
	        printf("\n");
	    }
	    printf("\n");
	    
	    printf("\nEstado de las torres:\n\n");
	    for (int j = 0; j < num_discos; j++) { // recorre las filas
	        for (int k = 0; k < 3; k++) { // recorre las columnas	
	            if(array[j][k] != 0){
	            	if(array[j][k] == 1){
	            		printf("         #         ");
					}
					if(array[j][k] == 2){
	            		printf("        ###        ");
					}
					if(array[j][k] == 3){
	            		printf("       #####       ");
					}
					if(array[j][k] == 4){
	            		printf("      #######      ");
					}
					if(array[j][k] == 5){
	            		printf("     #########     ");
					}
					if(array[j][k] == 6){
	            		printf("    ###########    ");
					}
					if(array[j][k] == 7){
	            		printf("   #############   ");
					}
					if(array[j][k] == 8){
	            		printf("  ###############  ");
					}
					if(array[j][k] == 9){
	            		printf(" ################# ");
					}
					if(array[j][k] == 10){
	            		printf("###################");
					}
					
				}else{
					printf("         |         ");
				}
	        }
	        printf("\n");
	    }
	    printf("\n");
	}else{
		printf("\n======================================================================");
		printf("\n\n El numero maximo de discos permitidos es de 10, intente otro numero\n\n");
		printf("======================================================================\n");
	}
    
}



int main(int argc, char *argv[]) {


	// Durante la evaluación podré cambiar estos valores.

	printf("Ejemplo de hanoi_ui_3discos\n");
	int posiciones[] = {1,3,2}; // ejes
//					 = {1,2,3};    discos
	hanoi_ui_3discos(posiciones);

	// el numero maximo de discos es de 10
	printf("\nEjemplo de hanoi_ui_ndiscos\n");
	int n_posiciones[] = {3,2,1,3,1,3};// ejes
//					   = {1,2,3,4,5};   discos
	hanoi_ui_ndiscos(6, n_posiciones);
	
	return 0;

}
