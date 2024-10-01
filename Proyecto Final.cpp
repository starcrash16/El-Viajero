#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int const TAM=20;


char menu(char nombre[]);
void gotoxy(int x, int y);
void recuadro(int xs, int ys, int xi, int yi);
void menuEstrellas();
void juego(char nombre[]);
void dados(int posJugador[]);
void mostrar(int posJugador[]);
int suma(int posJugador[]);
bool cercanas(int casillas);

int main(){
	char nombre[20];
	nombre[20] = menu(nombre);	
	menuEstrellas();
	recuadro(10,3, 70,21);
	juego(nombre);
	
}

char menu(char nombre[]){
	int num;
	system("mode con: cols=80 lines=30");
	menuEstrellas();
	gotoxy(35,10);printf("EL VIAJERO");
	recuadro(10,3, 70,21);
	gotoxy(25,15);system("pause");
	gotoxy(35,10);printf("       ");
	gotoxy(25,15);printf("                                       ");
	gotoxy(22,10); printf("Bienvenido Viajero! Cual es tu nombre?");
	gotoxy(38,12);scanf("%s", nombre);
	gotoxy(36,12);printf("Hola %s!", nombre);
	gotoxy(16,16);printf(" A continuacion te explicare las reglas del juego", nombre);
	gotoxy(23,18);system("pause");
	system("cls");
	printf("*	    *		       *	     *    	*      *         *\n");
	printf("   *       *       *        *            *            *      *        *\n");
	printf("*           *        *        *               *           *       *           *\n");
	printf("*    *                                                         *          *    *\n");
	printf("\n\tL A  G U I A   D E L  V I A J E R O   I N T E R G A L A C T I C O \n\n");
	printf("\tEstamos ubicados en la galaxia 0 y tenemos como mision viajar\n");
	printf("\tpor todo el universo conocido. Para esto tienes tu nave, que \n");
	printf("\tfunciona con dados especiales. Estos te llevaran a una galaxia \n");
	printf("\taleatoria cada vez que los lances. \n\n ");
	printf("\tPero solo podras viajar entre galaxias cuando la  distancia  es\n");
	printf("\tmenor o igual a 4 anos luz. El universo esta dividido en casillas,\n");
	printf("\tcuando llegues a la casilla 42 seras el ganador del... \n\n\t\t\t\tU N I V E R S O !!\n\n");
	printf("\tPero cuidado viajero... El Universo es un lugar lleno de peligros...\n\n");
	printf(" *    *        *      *               *          *         *      *           *");
	printf("     *              *          *            *                  *      *");
	printf("         *               *                *                   *");
	printf(" *           *         *                   *         *           *        *  ");
	printf("*           *        *        *               *           *       *           *\n");
	printf("       *	    *		    *   	     *    	        *                *");
	printf("  	 *                 *  		    *   	         	        *                *\n\t\t\t");
	system("pause");
	system("cls");
	return nombre[TAM];
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menuEstrellas(){
	printf("*	    *		       *	     *    	*      *         *\n");
	printf("   *      *       *        *            *            *      *        *\n");
	printf("*           *        *        *               *           *       *           *\n");
	printf("*    *                                                         *          *    *\n");
	gotoxy(0,4);printf(" *     *"); gotoxy(72,4);printf(" *   *");
	gotoxy(0,5);printf("*   ");		gotoxy(72,5);printf("      ");
	gotoxy(0,6);printf("  *    *");	gotoxy(72,6);printf("*    *");
	gotoxy(0,7);printf("        ");	gotoxy(72,7);printf(" *       ");
	gotoxy(0,8);printf("     *    ");gotoxy(72,8);printf("    *      ");
	gotoxy(0,9);printf("*        *");gotoxy(72,9);printf("*       ");
	gotoxy(0,10);printf("     * ");	gotoxy(72,10);printf("         *");
	gotoxy(0,11);printf("      ");	gotoxy(72,11);printf("*    *       *");
	gotoxy(0,12);printf(" *    *");	gotoxy(72,12);printf("   *      *");
	gotoxy(0,13);printf("  *   * ");gotoxy(72,13);printf("        ");
	gotoxy(0,14);printf("   ");		gotoxy(72,14);printf(" *      ");
	gotoxy(0,15);printf(" *      ");gotoxy(72,15);printf("   *    ");
	gotoxy(0,16);printf("   *    *");gotoxy(72,16);printf(" *  *  ");
	gotoxy(72,17);printf("*  ");
	gotoxy(0,18);printf(" *      *");gotoxy(72,17);printf(" ");
	gotoxy(0,19);printf("   *   ");	gotoxy(72,18);printf("  *   *");
	gotoxy(0,20);printf(" *       *");gotoxy(72,20);printf("*     *");
	gotoxy(0,21);printf("      *  ");gotoxy(72,21);printf("   *");
	gotoxy(0,22);printf("         *       *             *                *                   *");
	gotoxy(0,23);printf(" *           *         *                   *         *           *        *");
	gotoxy(0,24);printf("*           *        *        *               *           *       *           *\n");
	gotoxy(0,25);printf("       *	    *		    *   	     *    	        *                *");
	gotoxy(0,26);printf("  	 *                 *  		    *   	         	        *                *");
	gotoxy(0,27);printf("   *          *                        *          *                *          ");
	gotoxy(0,28);printf("          *           *                                    *              *");
	gotoxy(0,29);printf("  *              *              *              *     *            *              *  ");
	
}

void recuadro(int xs, int ys, int xi, int yi){
	int i;
	for(i=xs;i<=xi;i++){
		gotoxy(i,ys); printf("%c", 196);
		gotoxy(i,yi); printf("%c", 196);
	}
	
	/*for(i=ys;i<=yi;i++){
		gotoxy(xs,i); printf("%c", 179);
		gotoxy(xi,i); printf("%c", 179);
	}
	*/
	gotoxy(xs,ys); printf("%c", 218);
	gotoxy(xi,yi); printf("%c", 217);
	gotoxy(xi,ys); printf("%c", 191);
	gotoxy(xs,yi); printf("%c", 192);

}

void juego(char nombre[]){
	int iniPart, i;
	int posJugador[3], casillasxavanzar=0;
	srand(time(NULL));
	gotoxy(35,5);printf("C A S I L L A");
	gotoxy(41,6);printf("0");
	gotoxy(35,9);printf("G A L A X I A");
	gotoxy(39,10);printf("0 0 0");
	do{
		gotoxy(13,14);printf("                                               ");
		gotoxy(13,16);printf("                                               ");
		gotoxy(13,17);printf("                                               ");
		gotoxy(13,15);printf("                                               ");
		gotoxy(15,18);printf("                                               ");
		gotoxy(40,13);printf("   ");
		gotoxy(25,12);printf("Tira los dados %s!!  ", nombre); printf("   SI [1]  NO [2]");
		gotoxy(40,13);scanf("%d", &iniPart);
		if(iniPart==1){
			//ARRANCA EL JUEGO
			dados(posJugador);		
			gotoxy(15,18);system("pause");
		}
	}while(iniPart==1);
}

void dados(int posJugador[]){
	bool res=false;
	int iniPart, i, casillasxavanzar=0, casilla=0, inicial=0;
	for(int i=0; i<3; i++){
		posJugador[i]=1+rand()%9;
	}
	casillasxavanzar = suma(posJugador);
	d1=casillasxavanzar;
	d2=
		res =  cercanas(casillas);
		printf("Se avanza la cantidad de: %d", casillas);
	}else{
		
	}
	res =  cercanas(casillasxavanzar);
	gotoxy(13,14);printf("El resultado de los dados espaciales es: "); gotoxy(54,14); mostrar(posJugador);
	if(res==true){
		gotoxy(13,16);printf("Las galaxias son cercanas!!! :)  \n");
		gotoxy(39,10);mostrar(posJugador);
		condicionesCasillas(casilla);
		
	}else{
		gotoxy(13,16);printf("Las galaxias NO son cercanas :( \n");
	}
}

void mostrar(int posJugador[]){
	for(int i=0; i<3; i++){
		printf("%d ",posJugador[i]);
	}
}

int suma(int posJugador[]){
	int unid=0, dec=0, casillasxavanzar=0, res=0;
	for(int i=0;i<3;i++){
		casillasxavanzar+=posJugador[i];
	}
	if(casillasxavanzar>10){
		unid=casillasxavanzar%10;
		dec=casillasxavanzar/10;
		casillasxavanzar=unid+dec;
		if(casillasxavanzar>=10){
			unid=res%10;
			dec=res/10;
			casillasxavanzar=unid+dec;
		}
	}
	gotoxy(13,15);printf("La Galaxia se encuentra a %d light years.", casillasxavanzar);
	
	return casillasxavanzar;
}


bool cercanas(int casillas){
	bool res=false;
	if(casillas<=4){
		res=true;
	}
	else{
		res=false;
	}
	return res;
}