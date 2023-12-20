#include "logic.c"
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
int **spiralMatrix(int m, int n, Node *head, int *returnSize, int **returnColumnSizes)
{
    returnColumnSizes = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        returnSize = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            returnSize[j] = -1;
        }
        returnColumnSizes[i] = returnSize;
    }
    int col_left = 0;
    int col_right = n - 1;
    int row_up = 0;
    int row_btm = m - 1;
    Node *p = head;
    int j = 0;
    int i = 0;
    while (p && col_left <= col_right && row_btm >= row_up)
    {
        while (j < (col_right) && p)
        {
            returnColumnSizes[i][j] = p->data;
            p = p->next;
            j++;
        }
        while (i < (row_btm) && p)
        {
            returnColumnSizes[i][j] = p->data;
            p = p->next;
            i++;
        }
        while (j > (col_left) && p)
        {
            returnColumnSizes[i][j] = p->data;
            p = p->next;
            j--;
        }
        while (i > (row_up) && p)
        {
            returnColumnSizes[i][j] = p->data;
            p = p->next;
            i--;
        }
        col_left++;
        col_right--;
        row_up++;
        row_btm--;
        i = row_up;
        j = col_left;
    }
    return returnColumnSizes;
}

