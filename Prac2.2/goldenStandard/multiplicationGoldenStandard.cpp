//Author: David Da Costa
//EEE4120F
//University of Cape Twon

#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;



//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				//cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			//cout<<"\n";
		}
	}
	

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1;
			if(displayMatrices){
				//cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			//cout<<"\n";
		}
	}
	

}




int main(void){
//create csv file for timings
	fstream fout;
   fout.open("Golden_Standard.csv", ios::out | ios::app);
      //outer loop to change matrix size
    	for(int i=1;i<17;i++){
	      clock_t start,start2, end,end2;  //Timers
         //initialize matrix size
	      int Size = 50*i;
	      fout
    	   <<"\n"
	      <<"Matrix size = "
	      <<(Size)
	      << "\n"
	      << "Execution time"
	      << "\n";
         //Inner loop to run matrix time multiple times
	      for (int j=0;j<15;j++){
	         //set display matrices
	         bool displayMatrices = false;
	         //Set up Matrix A
	         int countA = Size*Size;
	         int matrixA[countA];
	         createKnownSquareMatrix(Size,matrixA, displayMatrices);
	         cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	         cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	         cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
	         //Set up Matrix B
	         int countB = Size*Size;
	         int matrixB[countB];
	         createKnownSquareMatrix(Size, matrixB, displayMatrices);
	         cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	         cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	         cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
	         //Set up output array
	         int output[countA];
	         
	         start = clock(); //start running clock
	//golden standard matrix multiplication 
	         for (int i = 0; i < Size; i++){
		
               for (int j = 0; j < Size; j++){
			
                  int sum = 0;
                  
			            for (int k = 0; k < Size; k++){
				         
                        sum += matrixA[i*Size+k]*matrixB[k*Size+j];
			            }
			         output[i*Size+j] = sum;
			
		         }
         }	
         
         
	      //End Clock
         end=clock();
	
	
         //This if statement will display the matrix in output	
	      if(displayMatrices){
         
		      printf("\nOutput in the output_buffer \n");
            
		      for(int j=0; j<countA; j++) {
            
			      printf("%i \t " ,output[j]);
               
			      if(j%Size == (Size-1)){
				      printf("\n");
			      }
		      }
	      }
	      //Set time to time of exection
         float time=("%0.8f \n",((float) end - start)/CLOCKS_PER_SEC);
         //Output time to csv
	      fout
	      <<time
         <<"\n";
	   }
	}
	
	
	return 0;
}
