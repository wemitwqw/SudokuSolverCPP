#include <iostream>
using namespace std;

int laud[9][9];


void loe(){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> laud[i][j];
        }
    }
}
void tryki(){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << laud[i][j] << " ";
            if (j == 2 || j == 5) {
                cout << "| ";
            }
        }
        cout << endl;
        if (i == 2 || i == 5) {
            cout << "---------------------" << endl;
        }
    }
}


bool kasReasLubatud(int reanr, int vaartus) {
    for (int i = 0; i < 9; i++) {
        if (laud[reanr][i] == vaartus) {
            return false;
        }
    }
    return true;
}

bool kasVeerusLubatud(int veerunr, int vaartus) {
    for (int i = 0; i < 9; i++) {
        if (laud[i][veerunr] == vaartus) {
            return false;
        }
    }
    return true;
}

bool kasPlokisLubatud(int reanr, int veerunr, int vaartus) {
    int plokialgusrida=reanr/3*3;
    //cout << plokialgusrida << " ss" << endl;
    
    int plokialgusveerg=veerunr/3*3;
    //cout << plokialgusveerg << " ss" << endl;

    for (int i=plokialgusrida; i<plokialgusrida+3; i++){
        for (int j=plokialgusveerg; j<plokialgusveerg+3; j++){
            if(laud[i][j]==vaartus){
                return false;
            }
        }
    }
    return true;
}

bool kasLubatud(int reanr, int veerunr, int vaartus) {
    return kasReasLubatud(reanr, vaartus) && kasVeerusLubatud(veerunr, vaartus) && kasPlokisLubatud(reanr, veerunr, vaartus);
}

void uuri() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (laud[i][j] == 0) {
                cout << i << " " << j << endl;
                for(int nr=1; nr<=9; nr++) {
                if(kasLubatud(i, j, nr)){
                    cout << nr << " " << endl;
                    laud[i][j] = nr;
                    tryki();
                    laud[i][j] = 0;
                }
            }
            }
            
        }
}   }

int main(void) {
    loe();
    //tryki();
    //cout << kasReasLubatud(0, 7) << endl;
    //cout << kasVeerusLubatud(1, 4) << endl;
    //cout << kasPlokisLubatud(1, 2, 7) << endl;
    //cout << kasLubatud(4, 5, 9) << endl;

    uuri();
    return 0;
}