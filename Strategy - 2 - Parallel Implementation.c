//Strategy - II
//Parallel Implementation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

int main ()
{
    //N denotes input array size
    //thr denotes number of processors used
    int N, thr;
    
    for(thr=1;thr<=16;thr=thr*2)
    {
        omp_set_num_threads(thr); 
    	
    	for(N=1600;N<=1000000000;N=N*10)
    	{
    	    int i,j,M=thr,temp=N/thr;
            
            //S is the array containing the input.
            //Answer will also be stored in S.    	    
            int *S=(int *)malloc(N*sizeof(int));
            
            //T is the temporary array,
            //used for storing the last element of each subarray
            int *T=(int *)malloc(M*sizeof(int));
              
            //Array Initialization
            for(i=0;i<N;i++)
            {
                S[i]=1;
            }
            
            for(i=0;i<M;i++)
            {
                T[i]=0;
            }        
            
            double start = omp_get_wtime();
            
            //Calculating the prefix-sum of M sub-arrays.
            //M is the number of processors used.
            //This step is done parallelly
            #pragma omp parallel for private(i, j)
            for(i=0;i<N;i=i+temp)
            {
                for(j=i+1;j<i+temp;j++)
                {
                    S[j]=S[j-1]+S[j];
                }
                //T stores the last element of each sub-array
                //After the calculation of prefix-sum of sub-arrays
                T[(j/temp)-1]=S[j-1];
            }            
            
            //Prefix-Sum of array T is calculated serially
            for(i=1;i<M;i++)
            {
                T[i]=T[i]+T[i-1];
            }
            
            //Each element except from the last element from
            //Array T is added to all the elements ofthe next sub-array
            //i-th element added to (i+1)th subarray
            #pragma omp parallel for private(i, j)
            for(i=temp;i<N;i=i+temp)
            {
                for(j=i;j<i+temp;j++)
                {
                    //S will store the result
                    S[j]=S[j]+T[(j/temp)-1];
                }
            }
            
            double end = omp_get_wtime();
        	printf("%lf\n\n",end-start);
        	printf("\n");
        }        
    }
    
    return 0;
}