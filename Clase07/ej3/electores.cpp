#include "electores.h"

int validarVotante(int d, int m, int a) {
	if( 1900 <= a && a <= 2020 &&
	       1 <= m && m <= 12   &&
	       1 <= d && d <= 31 ){
	    if( m > 10 || (m == 10 && d >= 22) ){
            a = 2020 - a;
	    } else {
            a = 2020 - (a+1);
	    }
	    if(a < 16) return NO_VOTA;
	    if(a >= 16 && a < 18) return OPCIONAL_MENOR;
	    if(a >= 18 && a < 79) return OBLIGATORIO;
        if(a >= 70) return OPCIONAL_MAYOR;
	}
    return ERROR;
}
