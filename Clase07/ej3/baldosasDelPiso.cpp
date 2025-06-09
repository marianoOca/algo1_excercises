int baldosasDelPiso(int M, int N, int B) {
    if(M % B == 0 && N % B ==0){
        return  (M*N)/(B*B);
    } else {
        if(M % B != 0 && N % B ==0) return (M/B + 1)*(N/B);

        if(M % B == 0 && N % B !=0) return (M/B)*(N/B + 1);

        if(M % B != 0 && N % B !=0) return (M/B + 1)*(N/B + 1);
    }
}
