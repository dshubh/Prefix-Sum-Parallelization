//Strategy - I
//Serial Implementation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

int main ()
{
    //N denotes input array size
    int N;
    
    for(N=1600;N<=1000000000;N=N*10)
    {
        //temp denotes number of outer loop iterations
        int temp = ceil((log(N)/log(2))),i,j,k;
        
        //S is the 2D-array of dimensions (temp+1) X (N)
        //First row contains the input for which prefix-sum is to be computed.
        int **S = (int **)malloc((temp+1) * sizeof(int *));
        
        for(i = 0; i<(temp+1); i++)
        {
        	S[i] = (int *)malloc(N * sizeof(int));  	
        }
            
        //Array Initialization    
        for(i = 0; i <= temp; i++)
        {
            for(j=0;j<N;j++)
            {
                //First row initialized with index+1
                if(i==0)
                {
                    S[i][j]=j+1;
                }
                //All other elements are initialized with 0
                else
                {
                    S[i][j]=0;
                }
            }
        }
        
    	double start = omp_get_wtime(); 
    	
        //Outer loop runs for temp number of times. 
        // After k iterations 2^(k+1) elements are computed correctly
        for(i=0; i<temp; i++)
        {
            //Inner loop runs for N number of times.
            //It updates elements as per the specific condition
            //This step is computed serailly
            for(j=0; j<N; j++)
            {
                if(j >= (int)pow(2,i))
                {
                    S[i+1][j] = S[i][j] + S[i][j - (int)pow(2,i)];
                }
                else
                {
                    S[i+1][j] = S[i][j];
                }
            }
        }
            
        double end = omp_get_wtime();

    	printf("%lf\n\n",end-start);
    	printf("\n");
    }
    
    return 0;
}