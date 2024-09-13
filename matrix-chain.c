#include <stdio.h>
#include <limits.h>

void parenthesis(int s[][100], int i, int j) {
    if (i == j) {
        printf("M%d", i);
    } else {
        printf("(");
        parenthesis(s, i, s[i][j]);
        parenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        printf("dimension of: d%d ::",i);
        scanf("%d", &p[i]);
    }

    int m[n + 1][n + 1]; 
    int s[n + 1][n + 1]; 
    
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int a = 2; a <= n; a++) {
        for (int i = 1; i <= n - a + 1; i++) {
            int j = i + a - 1;

            m[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n]);
    
    printf("Optimal parenthesization is: ");
    parenthesis(s, 1, n);
    printf("\n");

    printf("The cost matrix m[][] is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) {
                printf("%7d ", m[i][j]);
            } else {
                printf("       ");
            }
        }
        printf("\n");
    }

    return 0;
}
