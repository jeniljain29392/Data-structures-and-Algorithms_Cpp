#include <iostream>
using namespace std;

class MatrixPattern{
private:
    bool isMatch(int matrix[][8], int pattern[][3], int i, int j){
        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                if(matrix[i+k][j+l] != pattern[k][l]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool findPattern(int matrix[][8], int pattern[][3]){
        for(int i = 0; i <= 8 - 3; i++){
            for(int j = 0; j <= 8 - 3; j++){
                if(matrix[i][j] == pattern[0][0] && isMatch(matrix, pattern, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
  	int matrix[8][8] = {{9, 8, 7, 1, 2, 3, 4, 5}
  	                   ,{4, 2, 3, 6, 2, 5, 1, 6}
  	                   ,{5, 1, 6, 3, 4, 9, 4, 6}
  	                   ,{7, 5, 6, 2, 1, 3, 8, 9}
  	                   ,{7, 8, 6, 1, 3, 4 ,0, 9}
  	                   ,{0, 1, 4, 9, 0, 8, 6, 3}
  	                   ,{8, 4, 6, 3, 9, 0, 1, 2}
  	                   ,{4, 6, 0, 3, 4, 8, 9, 6}};
  	                   
  	int pattern[3][3] =  {{8, 6, 3}
  	                     ,{0, 0, 2}
  	                     ,{8, 9, 6}};
  	               
    MatrixPattern *matPattern = new MatrixPattern();
  	if(matPattern->findPattern(matrix, pattern))
  	    cout<<"Pattern found";
  	else
  	    cout<<"No pattern found";
  	return 0;
}
