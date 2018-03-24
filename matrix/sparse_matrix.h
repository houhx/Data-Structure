#include "../include.h"


struct Triple{
    int row, col; //行下标和列下标
    int element;
    void set(int r, int c, int e){
        row = r;
        col = c;
        element = e;
    }
};

class smatrix{
public:
    smatrix(int m=0, int n=0, int **matrix=nullptr);
    void printm()const;
    return_code transposematrix_1(smatrix &result);
    return_code transposematrix_2(smatrix &result);
    friend return_code multiplymatrix(smatrix &result, smatrix &m1, smatrix &m2);
    return_code insert(Triple &item, int pos);
    int gettu(){ return tu;};
    ~smatrix();
private:
    Triple *matrixs;  //非零元三元组表
    int mu, nu, tu;  //行数，列数，非零元个数
    int *rowpos;    //标示每行的第一个非零元素在三元组表中的位置
    static int maxtu;       //非零元的最大个数
};

int smatrix::maxtu = 30;

smatrix::smatrix(int m, int n, int **matrix): mu(m),nu(n){
    matrixs = new Triple[maxtu];
    rowpos = nullptr;
    tu = 0;

    if(matrix){
        for(int i=0; i<mu; i++){
            for(int j=0; j<nu; j++){
                if(tu == maxtu){
                    cout << "exceed the nums of non-zero elements!" << endl;
                    abort();
                }
                if(matrix[i][j] != 0) matrixs[tu++].set(i, j, matrix[i][j]);
            }
        }

        rowpos = new int[mu];
        int nums[mu] = {0};
        for(int i=0; i<mu; i++) rowpos[i] = 0;

        for(int i=0; i<tu; i++) nums[matrixs[i].row]++;

        for(int i=0; i<mu-1; i++) rowpos[i+1] = rowpos[i] + nums[i];
    }
}

smatrix::~smatrix(){
    if(!matrixs){
        delete [] matrixs;
        matrixs = nullptr;
    }

    if(!rowpos){
        delete [] rowpos;
        rowpos = nullptr;
    }
}

void smatrix::printm()const{
    cout << "row\tcol\telement\t" << endl;
    for(int i=0; i<tu; i++){
        cout << matrixs[i].row << "\t" << matrixs[i].col << "\t" << matrixs[i].element << "\t\n";
    } 
}

return_code smatrix::insert(Triple &item, int pos){
    if(tu == maxtu) return overflow;
    matrixs[pos].set(item.row, item.col, item.element);
    tu++;
    return successful;
}

return_code smatrix::transposematrix_1(smatrix &result){
    smatrix out(nu,mu);
    for(int i=0; i<nu; i++){
        for(int j=0; j<tu; j++){
            if(matrixs[j].col == i){
                Triple newtp;
                newtp.set(matrixs[j].col, matrixs[j].row, matrixs[j].element);
                if(out.insert(newtp,out.gettu()) == overflow) return overflow;
            }
        }
    }
    result = out;
    return successful;
}

return_code smatrix::transposematrix_2(smatrix &result){
    smatrix out(nu,mu);

    int num[nu] = {0};  //统计转置后每行的非零元素个数
    for(int i=0; i<tu; i++) num[matrixs[i].col]++;

    int pos[nu] = {0}; //记录每行的第一个非零元素在新的三元组表中的位置
    for(int i=0; i<nu-1; i++) pos[i+1] = pos[i] + num[i];

    for(int i=0; i<tu; i++){
        Triple newtp;
        newtp.set(matrixs[i].col, matrixs[i].row, matrixs[i].element);
        if(out.insert(newtp, pos[matrixs[i].col]++) == overflow) return overflow;
    }

    result = out;
    return successful;
}

return_code multiplymatrix(smatrix &result, smatrix &m1, smatrix &m2){
    if(m1.nu != m2.mu) return Error;
    result.mu = m1.mu;
    result.nu = m2.nu;
    if(m1.tu*m2.tu != 0){
        for(int i=0; i<m1.mu; i++){
            int ctemp[m2.nu] = {0};
            int end = m1.rowpos[i+1];
            if(i == m1.mu-1) end = m1.tu;
            for(int j=m1.rowpos[i]; j<end; j++){
                int nowrow = m1.matrixs[j].col;
                int newend = m2.rowpos[nowrow+1];
                if(nowrow == m2.mu-1) newend = m2.tu;
                for(int q = m2.rowpos[nowrow]; q<newend; q++){
                    ctemp[m2.matrixs[q].col] += m1.matrixs[j].element * m2.matrixs[q].element;
                }
            }
            for(int p=0; p<m2.nu; p++){
                if(ctemp[p]){
                    result.matrixs[result.tu++].set(i,p,ctemp[p]);
                }
            }
        }
    }
    return successful;
}