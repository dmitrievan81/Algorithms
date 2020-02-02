#include <stdio.h>
#include "lib/hwrklib.h"

int NumOperation(int N) {
    if (N == 1) {
        return 1;
    } else if (N % 2 == 0) {
        return NumOperation(N - 1) + NumOperation(N / 2);
    } else {
        return NumOperation(N - 1);
    }
}

int TraceKingRoute(int a, int b) {
    if (a == 0 || b == 0)
        return 1;
    else
        return TraceKingRoute(a, b - 1) + TraceKingRoute(a - 1, b);
}

int TracekingRouteWithRestriction(int a, int b, array2 *Map) {
    if (Map->val[a][b] == 0)
        return 0;
    else if (a == 0 || b == 0)
        return 1;
    else
        return TracekingRouteWithRestriction(a, b - 1, Map) + TracekingRouteWithRestriction(a - 1, b, Map);
}

void MainMenu_Task1_Sub_1(array2 *Map) {
    printf("n in [0,%i]\n", Map->SizeRows - 1);
    printf("m in [0,%i]\n", Map->SizeRows - 1);

    printf("Enter num of row i = ");
    int row = 0;
    scanf("%i", &row);
    printf("\n");

    printf("Enter num of col j = ");
    int col = 0;
    scanf("%i", &col);
    printf("\n");

    printf("Enter restriction (1 - allow; 0 - deny) of col restriction = ");
    int restriction = 0;
    scanf("%i", &restriction);
    printf("\n");
    Map->val[row][col] = restriction;
}

void MainMenu_Task1_TextOfSelections() {
    printf("1 - Enter new chess desk\n");
    printf("2 - Enter restrictions\n");
    printf("3 - Print restrictions\n");
    printf("4 - Get number of paths\n");
    printf("0 - Exit to main menu\n");
}

void MainMenu_Task1_Sub_3_TextOfSelections() {
    printf("1 - Enter new coordinates\n");
    printf("0 - Exit to task's 1 menu\n");
}

void MainMenu_Task1_Sub_3(array2 *Map) {
    printf("Enter the coordinates of the cell the number of paths to which you want to find.");
    printf("row in [0,%i], col in [0,%i]\n", Map->SizeRows - 1, Map->SizeCols - 1);
    printf("row i = ");
    int a = 0;
    scanf("%i", &a);
    printf("\n");

    printf("col j = ");
    int b = 0;
    scanf("%i", &b);
    printf("\n");

    int NumberOfPathsToCell = TracekingRouteWithRestriction(a, b, Map);
    printf("TracekingRouteWithRestriction(%i, %i, Map) = %i\n", a, b, NumberOfPathsToCell);
}

void MainMenu_Task1_Sub_3_Menu(array2 *Map) {

    int sel = 0;
    do {
        MainMenu_Task1_Sub_3_TextOfSelections();
        printf("Enter number of point menu: ");
        scanf("%i", &sel);
        printf("\n");
        printf("\n");
        switch (sel) {
            case 1:
                MainMenu_Task1_Sub_3(Map);
                break;
            case 0:
                break;
            default:
                printf("Wrong selection!\n");
        }

    } while (sel != 0);

}

// New chess desk
void MainMenu_Task1_Sub_4(array2 *Map) {
    int n = 0;
    int m = 0;
    printf("Enter the chess desk.\n");

    printf("Enter numbers of row m = ");
    scanf("%i", &m);
    printf("\n");

    printf("Enter numbers of col n = ");
    scanf("%i", &n);
    printf("\n");

    printf("The desk row in [0,%i] , col in [0, %i]\n", n - 1, m - 1);

    getArray2(Map, n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            Map->val[i][j] = 1;
    }
}

void MainMenu_Task1() {

    array2 Map;

    int sel = 0;
    do {
        MainMenu_Task1_TextOfSelections();
        printf("Enter number of point menu: ");
        scanf("%i", &sel);
        printf("\n");
        switch (sel) {
            case 1:
                MainMenu_Task1_Sub_4(&Map);
                break;
            case 2:
                MainMenu_Task1_Sub_1(&Map);
                break;
            case 3:
                printArray2(&Map);
                break;
            case 4:
                MainMenu_Task1_Sub_3_Menu(&Map);
            case 0:
                break;
            default:
                printf("Wrong selection!\n");
        }

    } while (sel != 0);

    freeArray2(&Map);
}

void MainMenuTextOfSelections() {
    printf("1 - Find numbers of the paths leading into cell (with borders)\n");
    printf("2 - Find LCS\n");
    printf("0 - Exit\n");
}

void getTestArray(array2* lcs, array* x, array* y)
{
    getArray2(lcs, 10, 8);

    getArray(x, 9);
    x->val[0] = 1;
    x->val[1] = 2;
    x->val[2] = 4;
    x->val[3] = 3;
    x->val[4] = 2;
    x->val[5] = 1;
    x->val[6] = 2;
    x->val[7] = 4;
    x->val[8] = 3;

    getArray(y, 7);
    y->val[0] = 1;
    y->val[1] = 2;
    y->val[2] = 3;
    y->val[3] = 4;
    y->val[4] = 5;
    y->val[5] = 6;
    y->val[6] = 3;

}

void MainMenu_Task2_Sub_1() {

    int m = 0;
    printf("Enter size of the sequence x m = ");
    scanf("%i", &m);
    printf("\n");
    array x;
    getArray(&x, m);

    for(int i = 0; i < m; i++){
        int x_i = 0;
        printf("x[%i] = ", i);
        scanf("%i", &x_i);
        x.val[i] = x_i;
        printf("\n");
    }

    int n = 0;
    printf("Enter size of the sequence y n = ");
    scanf("%i", &n);
    printf("\n");
    array y;
    getArray(&y, m);
    for(int i = 0; i < n; i++){
        int y_i = 0;
        printf("y[%i] = ", i);
        scanf("%i", &y_i);
        y.val[i] = y_i;
        printf("\n");
    }

    /*array2 lcs;
    array x;
    array y;
    int m = x.Size;
    int n = y.Size;

    getTestArray(&lcs, &x, &y);*/

    printf("x = (");
    for(int i = 0; i < m-1; i++){
        printf("%i, ", x.val[i]);
    }

    printf("%i", x.val[m-1]);
    printf(" )\n");

    printf("y = (");
    for(int i = 0; i < n-1; i++){
        printf("%i, ", y.val[i]);
    }
    printf("%i", y.val[n-1]);
    printf(" )\n");

    array2 lcs;
    getArray2(&lcs, m + 1, n + 1);

    int lcs_result = LCS(&lcs, &x, &y);

    printf("Max length lcs is %i\n", lcs_result);
    printf("LCS matrix is: \n");
    printArray2(&lcs);
    printf("\n");

}

void MainMenu_Task2() {
    int sel = 0;
    do {
        printf("1 - Find LCS\n");
        printf("0 - Exit to main menu\n");
        printf("Enter number of point menu: ");
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                MainMenu_Task2_Sub_1();
                break;
            case 0:
                break;
            default:
                printf("Wrong selection!\n");
        }

    } while (sel != 0);
}

void MainMenu() {

    int sel = 0;
    do {
        MainMenuTextOfSelections();
        printf("Enter number of point menu: ");
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                MainMenu_Task1();
                break;
            case 2:
                MainMenu_Task2();
                break;
            case 0:
                break;
            default:
                printf("Wrong selection!\n");
        }

    } while (sel != 0);
}

int main() {

    MainMenu();

    return 0;
}
