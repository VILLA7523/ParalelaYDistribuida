#include<bits/stdc++.h>

using namespace std;

double calcTime(unsigned t0 , unsigned t1) {
 return (double(t1-t0)/CLOCKS_PER_SEC);
}

void nested_loops_3(int n) {
    int A[n][n]  , B[n][n] , C[n][n];
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            A[i][j] = i + 1;
            B[i][j] = j + 2;
            C[i][j] = 0;
        }
    }
    unsigned t0 , t1;
    t0=clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    t1 = clock();

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0 ; j < n ; j++) {
    //         cout<<C[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << "Execution Time nested_loops_3: " << calcTime(t0 , t1) << endl;
}

void nested_loops_blocks(int n) {
    int blockSize = n/2 , A[n][n] , B[n][n] , C[n][n];
    unsigned t0 , t1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            A[i][j] = i + 1;
            B[i][j] = j + 2;
            C[i][j] = 0;
        }
    }

    t0=clock();
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int x = 0; x < blockSize; x++) {
                    for (int y = 0; y < blockSize; y++) {
                        for (int z = 0; z < blockSize; z++) {
                            C[i + x][j + y] += A[i + x][k + z] * B[k + z][j + y];
                        }
                    }
                }
            }
        }
    }
    t1 = clock();
    cout << "Execution Time nested_loops_blocks: " << calcTime(t0 , t1) << endl;

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0 ; j < n ; j++) {
    //         cout<<C[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

int main(){
    int n = 50;
    nested_loops_3(n);
    //cout<<endl;
    nested_loops_blocks(n);
    return 0;
}

