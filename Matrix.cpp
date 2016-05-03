#include <iostream>
#include <stack>
using namespace std;

class Matrix{
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
    
    void rotateMatrix180_2(int (&matrix)[8][8]){
        int first, last, temp, offset;
        for(int i = 0; i < 8/2; i++){
            first = i;
            last = 8 - 1 - i;
            for(int j = first; j < last; j++){
                offset = j - first;
                
                temp = matrix[first][j];
                matrix[first][j] = matrix[last][last - offset];
                matrix[last][last - offset] = temp;
                
                temp = matrix[j][last];
                matrix[j][last] = matrix[last - offset][first];
                matrix[last - offset][first] = temp;
            }
        }
    }
    
    void rotateMatrixDiag(int (&matrix)[8][8]){
        
    }
    
    void rotateMatrix180(int (&matrix)[8][8]){
        int temp = 0, temp1 = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8/2; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][8-j-1];
                matrix[i][8-j-1] = temp;
            }
        }
        for(int i = 0; i < 8/2; i++){
            for(int j = 0; j < 8; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[8-i-1][j];
                matrix[8-i-1][j] = temp;
            }
        }
    }
    
    void rotateMatrix90(int (&matrix)[8][8], string dir = "Anti-Clock"){
        transposeMatrix(matrix);
        int temp = 0;
        if(dir == "Clock"){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8/2; j++){
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[i][8-j-1];
                    matrix[i][8-j-1] = temp;
                }
            }
        }
        else{
            for(int i = 0; i < 8/2; i++){
                for(int j = 0; j < 8; j++){
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[8-i-1][j];
                    matrix[8-i-1][j] = temp;
                }
            }
        }
    }
    
    void transposeMatrix(int (&matrix)[8][8]){
        int temp = 0;
        for(int i = 0; i < 8 - 2; i++){
            for(int j = i + 1; j < 8 - 1; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
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
  	                     ,{0, 1, 2}
  	                     ,{8, 9, 6}};
  	
  	for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
  	return 0;
}
