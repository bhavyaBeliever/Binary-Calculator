#include "logic.c"
#include <string.h>
// https://leetcode.com/problems/spiral-matrix-iv/
// this code isn't working in leetcode don't know why
/**
 * Definition for singly-linked list.
 * Node {
 *     int val;
 *     Node *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: btmh returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// typedef ListNode Node;

int **spiralMatrix(int m, int n, Node *head, int *returnSize, int **returnColumnSizes);
int main()
{

    List l;
    append(&l, 3);
    append(&l, 5);
    append(&l, 4);
    append(&l, 3);
    append(&l, 2);
    append(&l, 1);
    append(&l, 11);
    append(&l, 10);
    append(&l, 12);
    append(&l, 13);
    append(&l, 14);
    append(&l, 12);
    append(&l, 16);
    append(&l, 15);
    display(l);
    int **mat;
    int *col;
    mat = spiralMatrix(4, 4, l, col, mat);
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// int **spiralMatrix(int m, int n, Node *head, int *returnSize, int **returnColumnSizes)
// {
//     returnColumnSizes = (int **)malloc(m * sizeof(int *));
//     for (int i = 0; i < m; i++)
//     {
//         returnSize = (int *)malloc(sizeof(int) * n);
//         for (int j = 0; j < n; j++)
//         {
//             returnSize[j] = -1;
//         }
//         returnColumnSizes[i] = returnSize;
//     }
//     int col_left = 0;
//     int col_right = n - 1;
//     int row_up = 0;
//     int row_btm = m - 1;
//     Node *p = head;
//     int j = 0;
//     int i = 0;
//     while (p && col_left <= col_right && row_btm >= row_up)
//     {
//         while (j < (col_right) && p)
//         {
//             returnColumnSizes[i][j] = p->data;
//             p = p->next;
//             j++;
//         }
//         while (i < (row_btm) && p)
//         {
//             returnColumnSizes[i][j] = p->data;
//             p = p->next;
//             i++;
//         }
//         while (j > (col_left) && p)
//         {
//             returnColumnSizes[i][j] = p->data;
//             p = p->next;
//             j--;
//         }
//         while (i > (row_up) && p)
//         {
//             returnColumnSizes[i][j] = p->data;
//             p = p->next;
//             i--;
//         }
//         col_left++;
//         col_right--;
//         row_up++;
//         row_btm--;
//         i = row_up;
//         j = col_left;
//     }
//     return returnColumnSizes;
// }












/**
 * Definition for singly-linked list.
 * Node {
 *     int val;
 *     Node *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// int** spiralMatrix(int m, int n, Node* head, int* returnSize, int** returnColumnSizes) {
//     int x = 0, y = 0;
//     int i,j;

//     *returnSize = m;
//     *returnColumnSizes = (int *)calloc(m, sizeof(int));
//     int **result = (int **)calloc(m, sizeof(int *));

//     for(int row = 0; row < m; row++)
//     {
//         (*returnColumnSizes)[row] = n;
//         result[row] = (int *)calloc(n, sizeof(int));
//         memset(result[row], -1, n*sizeof(int));
//     }

//     Node* p = head;

//     while (p && x < m && y < n){

//         i = x;
//         j = y;

//         for ( ; j < n && p; j++){
//             result[i][j] = p->val;
//             p = p->next;
//         }

//         i++;

//         for ( ; i < m && p; i++){
//             result[i][j] = p->val;
//             p = p->next;
//         }

//         j--;

//         for (; j >= y && x < m && p; j--) {
//             result[i][j] = p->val;
//             p = p->next;
//         }

//         i--;

//         for (; i > x && y < n && p; i--) {
//             result[i][j] = p->val;
//             p = p->next;
//         }

//         x++;
//         y++;
//         m--;
//         n--;
//     }

//     return returnColumnSizes;

// }


/**
 * Definition for singly-linked list.
 * Node {
 *     int val;
 *     Node *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, Node* head, int* returnSize, int** returnColumnSizes)
{
    *returnSize = m;
    *returnColumnSizes = (int *)calloc(m, sizeof(int));
    int **result = (int **)calloc(m, sizeof(int *));

    for(int row = 0; row < m; row++)
    {
        (*returnColumnSizes)[row] = n;
        result[row] = (int *)calloc(n, sizeof(int));
        memset(result[row], -1, n*sizeof(int));
    }

    int startRow = 0, startCol = 0, endRow = m, endCol = n;

    while(head)
    {
        for(int col = startCol; col < endCol && head; col++)
        {
            result[startRow][col] = head->val;
            head = head->next;
        }
        startRow++;
        
        for(int row = startRow; row < endRow && head; row++)
        {
            result[row][endCol - 1] = head->val;
            head = head->next;
        }        
        endCol--;

        if(startRow < endRow)
        {
            for(int col = endCol - 1; col >= startCol && head; col--)
            {
                result[endRow - 1][col] = head->val;
                head = head->next;
            }            
            endRow--;
        }

        if(startCol < endCol)
        {
            for(int row = endRow - 1; row >= startRow && head; row--)
            {
                result[row][startCol] = head->val;
                head = head->next;
            }
            startCol++;    
        }
    }
    
    return result;
}