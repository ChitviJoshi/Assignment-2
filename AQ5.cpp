#include <iostream>
using namespace std;

void triplet(int A[][3], int m) {
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++) {
            if(A[i][j] != 0) {
                count++;
            }
        }
    }
    
    int triplet[count][3];

    for(int p = 0; p < m; p++) {
        for(int q = 0; q < 3; q++) {
            cout << A[p][q] << " ";
        }
        cout << "\n";
    }
    
    int k = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++) {
            if(A[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = A[i][j];
                k++;
            }
        }
    }
    
    cout << "\nTriplet Matrix \n";
    for(int p = 0; p < count; p++) {
        for(int q = 0; q < 3; q++) {
            cout << triplet[p][q] << " ";
        }
        cout << "\n";
    }
}

void triplet_4(int A[][4], int m) {
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            if(A[i][j] != 0) {
                count++;
            }
        }
    }
    
    int triplet[count][3];

    for(int p = 0; p < m; p++) {
        for(int q = 0; q < 4; q++) {
            cout << A[p][q] << " ";
        }
        cout << "\n";
    }
    
    int k = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            if(A[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = A[i][j];
                k++;
            }
        }
    }
    
    cout << "\nTriplet Matrix \n";
    for(int p = 0; p < count; p++) {
        for(int q = 0; q < 3; q++) {
            cout << triplet[p][q] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int dia[3][3] = {{4,0,0}, {0,8,0}, {0,0,1}};
    int tridia[4][4] = {{2,4,0,0}, {2,3,9,0}, {0,2,3,4}, {0,0,1,3}};
    int l_tri[3][3] = {{2,0,0}, {1,3,0}, {7,8,9}};
    int u_tri[3][3] = {{2,4,6}, {0,3,5}, {0,0,9}};
    int sym[3][3] = {{2,3,6}, {3,4,5}, {6,5,9}};
    
    int f = 0;
    
    while(f == 0) {
        cout << "\n--- MENU ---\n"
             << "1. Diagonal Matrix\n"
             << "2. Tridiagonal Matrix\n"
             << "3. Lower Triangular Matrix\n"
             << "4. Upper Triangular Matrix\n"
             << "5. Symmetric matrix\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Diagonal Matrix\n";
                triplet(dia, 3);
                break;
            case 2:
                cout << "Tridiagonal Matrix\n";
                triplet_4(tridia, 4);
                break;
            case 3:
                cout << "Lower Triangular Matrix\n";
                triplet(l_tri, 3);
                break;
            case 4:
                cout << "Upper Triangular Matrix\n";           
                triplet(u_tri, 3);
                break;
            case 5:
                cout << "Symmetric Matrix\n";   
                triplet(sym, 3);
                break;
            case 6:
                f = 1;
                cout << "Have a good day!\n";
                break;
        }
    }
    
    return 0;
}