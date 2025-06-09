//Ej 8.b.
bool esTriangular(vector<vector<float>> m){				//elementos			filas
	if(m.size() < 2) return false;						// 2				 2
	if(m.size() != m[0].size()) return false;			// 4				 4

    bool triInferior = true, triSuperior = true;	    // 2				 2

    for(int i = 1 ; i < m.size() ; i++){			    // 2				n - 1
        for(int j = i - 1 ; j >= 0 ; j--){
            triInferior &= m[i][j] == 0;				//					5*(n-2)*(n-1)
        }
    }

    for(int i = 0 ; i < m.size()-1 ; i++){
        for(int j = i+1 ; j < m.size() ; j++){
            triInferior &= m[i][j] == 0;
        }
    }

	return triSuperior || triInferior;
}

//Ej 9.b
vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int>> m2){
	vector<vector<int>> res = m1; //armarlo con m1 filas y m2 columnas
													// n=|m1|, m=|m1[0]|=|m2|, r=|m2[0]|
	for(int i = 0 ; i < m1.size() ; i++){			// 3 + n(2 + ... + 2)
		for(int j = 0 ; j < m2[0].size() ; j++){	//		4 + r(3 + ... + 2)
			res[i][j] = 0;							// 			3 +
			for(int k = 0 ; k < m2.size() ; k++){	// 			3 + m(2 + ... + 2)
				res[i][j] += m1[i][k]*m2[k][j];		//				11
			}										// 			3 + 15m
		}											//		4 + r(11 + 15m)
	}												// 3 + n(8 + 11r + 15r*m))

	return res;										//O(n*m*r)
}													// y si n=|m1|=|m1[0]|=|m2|=|m2[0]| ⟶ O(n³)

//Ej 10 Sea mat una matriz de N × N y la siguiente función:
void sumasAcumuladas(vector<vector<int>> &mat, int N){	// n = cant. de elementos de la matriz = N² = n ⟶ N = sqrt(n)
	for(int i = N - 1 ; i >= 0 ; i--) {					// 2 + 1 + sqrt(n)(1 + ... + 2)		
		for(int j = N - 1 ; j >= 0 ; j--) {				//		2 + 1 + sqrt(n)(1 + ... + 2)
			mat[i][j] = sumHasta(mat, i, j, N);			//			3 + O(i*sqrt(n) + j) = 3 + (N-1)*sqrt(n) + (N-1) = O(n + sqrt(n))
		}												//		3 + sqrt(n)(O(n))
	}													//	3 + sqrt(n)(6 + sqrt(n)(O(n)))
}														//	3 + 6*sqrt(n) + n*O(n) ⟶ O(n²)

int sumHasta(vector<vector<int>> &mat, int I, int J, int N){
	int res = 0;								// 1
	int lim;
	for (int i = 0 ; i <= I ; i++) {			// 1 + 1 + I(1 + ... + 2)
		if (i == I) {							// 		1
			lim = J;							// 		1
		} else {
			lim = N - 1;						// 		2
		}
		for (int j = 0 ; j <= lim ; j++) {		//		1 + 1 + lim(1 + ... + 2)
			res += mat[i][j];					//			4
		}										//		5 + 7lim
	}											// 3 + I(7 + 7(N-1)) + 8 + 7J
	return res;									// O(I*sqrt(n) + J)
}


//Ej 11
int buscarImpares(vector<int> v){
	int largo = v.size();

	if(largo == 0) return 0;
	if(largo == 1){
		if(esImpar(v[1])){
			return 1;
		} else {
			return 0;
		}
	}

	maxMeseta = 0, meseta = 0;

	for(int i = 0 ; i < largo-1 ; i++){
		
		if(v[i] == v[i+1] && esImpar(v[i])){
			meseta++;
		
		} else {
			if(meseta+1 > maxMeseta && esImpar(v[i])){
				maxMeseta = meseta+1;
			}
			meseta = 0;
		}
	}

	return maxMeseta;
}

bool esImpar(int n){
	return n % 2 == 1;
}

//Ej 12
vector<int> restarAcumulado(vector<int> s, int x){
	if( s.size() == 0) return {};
	if( s.size() == 1) return {x-s[1]};

	vector<int> res = s;

	for(int i = 1 ; i < s.size() ; i++){
		res[i] = res[i] + res[i-1];
	}

	for(int i = 0 ; i < s.size() ; i++){
		res[i] = x - res[i];
	}

	return res;
}

//Ej 13 ????

//Ej 14.a.
vector<vector<int>> productoriaMatricial(vector<vector<int>> m, int n){
	vector<vector<int>> res = m;		// con |m|=|m[0]|= A y n = n

	for(int i = 1 ; i < n ; i++){		// 3 + n(1 + ... + 2)
		res = multiplicar(res, m);		//		1 + O(A³)
	}									// 3 + 4n + n*O(A³)

	return res;							// O(n*A³)
}

//Ej 14.b. asumo que m > 0
vector<vector<int>> nuevoProductoriaMatricial(vector<vector<int>> m, int n){
	vector<vector<int>> m2 = multiplicar(m, m), res = m2;	// con |m|=|m[0]|= A y n = n
	int i = 1;							// O(A³) + 2

	while(i < n){						// 1 + log₂(n)(1 + ...)
		res = multiplicar(res, m2);		//		1 + O(A³)
		i = i*2							// 		2
	}									// 3 + 4*log₂(n) + log₂(n)*O(A³)

	return res;							// O(log₂(n)*A³)
}

//Ej 15.
vector<bool> dondeEstanLosSolteros(vector<vector<bool>> m){
	vector<int> v {};
	int temp;

	for(int i = 0 ; i < m.size() ; i++){
		temp = 0;
		for(int j = 0 ; j < m.size() ; j++){
			if(m[i][j]) temp += elevar2aLa(j);
		}
		v.push_back(temp);
	}

	return m[ indiceDelDistinto(v) ];	//O(n² + n³) ⟶ O(n³)

}


int elevar2aLa(int n){				
	if(n == 0) return 1;
	res = 2;

	for(int i = 1 ; i < n ; i++){
		res = res*2;
	}
	return res;						//O(n)
}

int indiceDelDistinto(vector<int> v){
	int i = 0, apariciones = 2;
	
	while(apariciones == 2){
		apariciones = 0;
		for(int j = 0 ; j < v.size() ; j++){
			if(v[i]==v[j]) apariciones++;
		}
		i++;
	}

	return i-1;						//O(n²)
}