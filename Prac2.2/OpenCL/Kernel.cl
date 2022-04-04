

__kernel void matrixMultiplication(__global int *matrixA, __global int *matrixB, __global int *size, __global int* output){
		 
		int workItemNum = get_global_id(0); //Work item ID
		//de-referance Size pointer
		int dim=*size;
		//Obtain current row and column
		int row=workItemNum/(dim);
		int col=workItemNum%(dim);

		__local int sum;
		//initialize Sum
		sum=0;
		
		for (int i=0;i<dim;i++){
			//perform matrix multiplication
			sum+=matrixA[row*dim+i]*(matrixB[i*dim+col]);
			//printf("Sum: %d \n",sum);
				//printf("%i\n",sum);
		}
		//Add output sum to buffer
		output[workItemNum]=sum; // save to output
		
		
}

