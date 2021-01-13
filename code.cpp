#include <iostream>
#define N 9
using namespace std;
int suduko[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
bool PresentCol(int c, int num){
    for (int r = 0; r < N; r++)
        if(suduko[r][c] == num)
            return true;
    return false;
}
bool PresentRow(int r, int num){
    for(int c = 0; c < N; c++)
        if(suduko[r][c] == num)
            return true;
    return false;
}
bool PresentBox(int boxSRow, int boxSCol, int num){

    for(int r = 0; r< 3; r++)
        for(int c = 0; c < 3; c++)
            if(suduko[r+boxSRow][c+boxSCol] == num)
                return true;
    return false;
}
void print(){
    for (int r= 0; r< N; r++){
        if(r == 0){
            cout << ' ';
            for(int i = 0; i<N; i++)
                cout << "---";
            cout << endl;
        }
        for (int c = 0; c< N; c++){
            if(c== 0 || c== 3 || c== 6)
                cout << " | ";
            cout << suduko[r][c] <<" ";
            if(c == 8)
                cout << " | ";
        }
        if(r== 2 || r == 5 || r == 8){
            cout << endl << ' ';
            for(int i = 0; i<N; i++)
                cout << "---";
        }
        cout << endl;
    }
}
bool EmptyPlace(int &r, int &c){
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (suduko[r][c] == 0)
                return true;
    return false;
}
bool validPlace(int r, int c, int num){

    return !PresentRow(r, num) && !PresentCol(c, num) && !PresentBox(r- r%3, c- c%3, num);
}
bool solve(){
    int r, c;
    if (!EmptyPlace(r, c))
        return true;
    for (int num = 1; num <= 9; num++){
        if(!validPlace(r, c, num)){
            suduko[r][c] = num;
            if (solve())
                return true;
            suduko[r][c] = 0;
        }
    }
    return false;
}
int main(){
    if(solve() == true)
        print();
    else
        cout << "Solution doesn't Exists!";
    return 0;
}
