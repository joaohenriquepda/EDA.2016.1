#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define MAX 400
#define N 22
#define LIVRE 0
#define PAREDE 32767

void cria(int L[N][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		L[i][0] = PAREDE;
		L[i][N-1] = PAREDE;
	}
	for(j=0; j<N; j++) {
		L[0][j] = PAREDE;
		L[N-1][j] = PAREDE;
	}
	
	for(i=1; i<N-1; i++) {
		for(j=1; j<N-1; j++) {
			if( rand()%3==0 )
				L[i][j] = PAREDE;
			else
				L[i][j] = LIVRE;
		L[1][1] = LIVRE;
		L[N-2][N-2] = LIVRE;
		}
	}
}

void exibe(int L[N][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			switch( L[i][j] ) {
				case LIVRE : 
					putchar(' ');
					break;
				
				case PAREDE:
					putchar('#');
					break;
					
				default:
					putchar('x');
			}
		}
		printf("\n");
	}
}


void anota(int L[N][N]) {
	int filai[MAX], filaj[MAX], inifilai = 0, inifilaj = 0, fimfilai = 0, fimfilaj = 0, i , j, d;
	int c;
	
	L[1][1] = 1;
	filai[fimfilai++] = 1;
	filaj[fimfilaj++] = 1;
	c = 1;
	d = 1;
	
	while(inifilai != fimfilai && inifilaj != fimfilaj) {
		i = filai[inifilai++];
		j = filaj[inifilaj++];
		c = d++;
		if(L[i+1][j] == 0) {
			L[i+1][j] = c;
			filai[fimfilai++] = i+1;
			filaj[fimfilaj++] = j;
		}
		if(L[i-1][j] == 0) {
			L[i-1][j] = c;
			filai[fimfilai++] = i-1;
			filaj[fimfilaj++] = j;
		}
		if(L[i][j+1] == 0) {	
			L[i][j+1] = c;
			filai[fimfilai++] = i;
			filaj[fimfilaj++] = j+1;
		}
		if(L[i][j-1] == 0) {
			L[i][j-1] = c;
			filai[fimfilai++] = i;
			filaj[fimfilaj++] = j-1;
		}
	}
	
	extrai(L);
	printf("\n");
}

void extrai(int L[N][N]) {
	int pi[MAX], pj[MAX], inipi = 0, inipj = 0, i, j;
	
	if(L[10][10] == 0) {
		printf("\nSem Saída. \n");
		return;
	}
	
	pi[inipi++] = i = 10;
	pj[inipj++] = i = 10;
	
	while(p[MAX-1] != L[1][1]) {
		if(L[i+1][j] == L[i][j]-1) {
			pi[inipi++] = i+1;
			pj[inipj++] = j;
		}
		if(L[i-1][j] == L[i][j]-1) {
			pi[inipi++] = i-1;
			pj[inipj++] = j;
		}
		if(L[i][j+1] == L[i][j]-1) {	
			
			pi[inipi++] = i;
			pj[inipj++] = j+1;
		}
		if(L[i][j-1] == L[i][j]-1) {
			pi[inipi++] = i;
			pj[inipj++] = j-1;
		}
		
		while(inipi != 0 && inipj != 0) {
			
		}
	}
}

int main(void) {
	int L[N][N];
	char r;
	srand(time(NULL));
	do {
		cria(L);
		anota(L);
		//extrai(L);
		exibe(L);
		printf("Continua (s/n) ");
		scanf("%c%*c", &r);
	} while( toupper(r) != 'n' );
	
	return 0;
}
