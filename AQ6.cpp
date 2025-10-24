#include <iostream>
using namespace std;

void printMatrix(int A[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

void makeTriplet(int A[3][3], int triplet[][3], int size) {
    int k = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(A[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = A[i][j];
                k++;
            }
        }
    }
}

void printTriplet(int triplet[][3], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
            cout << triplet[i][j] << " ";
        }
        cout << "\n";
    }
}

void transpose(int triplet[][3], int result[][3], int size) {
    for(int i = 0; i < size; i++) {
        result[i][0] = triplet[i][1];
        result[i][1] = triplet[i][0];
        result[i][2] = triplet[i][2];
    }
}

void addition(int triplet_1[][3], int triplet_2[][3], int result[][3], int size1, int size2, int &resultSize) {
    int k = 0;
    
    for(int i = 0; i < size1; i++) {
        result[k][0] = triplet_1[i][0];
        result[k][1] = triplet_1[i][1];
        result[k][2] = triplet_1[i][2];
        k++;
    }
    
    for(int i = 0; i < size2; i++) {
        int found = 0;
        for(int j = 0; j < k; j++) {
            if(result[j][0] == triplet_2[i][0] && result[j][1] == triplet_2[i][1]) {
                result[j][2] += triplet_2[i][2];
                found = 1;
                break;
            }
        }
        if(found == 0) {
            result[k][0] = triplet_2[i][0];
            result[k][1] = triplet_2[i][1];
            result[k][2] = triplet_2[i][2];
            k++;
        }
    }
    
    resultSize = k;
}

void multiplication(int triplet_1[][3], int triplet_2[][3], int result[][3], int size1, int size2, int &resultSize) {
    int triplet_2_transpose[10][3];
    int temp[3][3] = {0};
    int k = 0;
    
    transpose(triplet_2, triplet_2_transpose, size2);
    
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            if(triplet_1[i][1] == triplet_2_transpose[j][1]) {
                temp[triplet_1[i][0]][triplet_2_transpose[j][0]] += triplet_1[i][2] * triplet_2_transpose[j][2];
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(temp[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = temp[i][j];
                k++;
            }
        }
    }
    
    resultSize = k;
}

int main() {
    int A[3][3] = {{2,3,0}, {0,0,6}, {9,0,0}};
    int B[3][3] = {{5,0,2}, {7,0,9}, {0,1,0}};
    
    int tripletA[4][3];
    int tripletB[5][3];
    int transposeA[4][3];
    int addResult[10][3];
    int multResult[10][3];
    
    makeTriplet(A, tripletA, 4);
    makeTriplet(B, tripletB, 5);
    
    cout << "Matrix A:\n";
    printMatrix(A);
    
    cout << "\nMatrix B:\n";
    printMatrix(B);
    
    cout << "\nTriplet of A:\n";
    printTriplet(tripletA, 4);
    
    cout << "\nTriplet of B:\n";
    printTriplet(tripletB, 5);
    
    int choice;
    
    while(true) {
        cout << "\n1. Transpose of A\n";
        cout << "2. Addition of A and B\n";
        cout << "3. Multiplication of A and B\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            transpose(tripletA, transposeA, 4);
            cout << "\nTranspose of A: (triplet form)\n";
            printTriplet(transposeA, 4);
        }
        else if(choice == 2) {
            int addSize;
            addition(tripletA, tripletB, addResult, 4, 5, addSize);
            cout << "\nAddition of A and B: (triplet form)\n";
            printTriplet(addResult, addSize);
        }
        else if(choice == 3) {
            int multSize;
            multiplication(tripletA, tripletB, multResult, 4, 5, multSize);
            cout << "\nMultiplication of A and B: (triplet form)\n";
            printTriplet(multResult, multSize);
        }
        else if(choice == 4) {
            cout << "\nGoodbye!\n";
            break;
        }
    }
    
    return 0;
}