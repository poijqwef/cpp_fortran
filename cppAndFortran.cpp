#include "cppAndFortran.hpp"

using namespace std;

extern "C" {
    struct CommonData {
        double doubleScalar;
        double doubleArray[2][3];
    };
    extern void fortran_setData();
    extern void fortran_copyDataFromCpp(CommonData* a_dataFromCpp);
    extern void fortran_copyDataToCpp(CommonData* a_dataToCpp);
    extern void fortran_printData();
}

C2F::C2F() {
    cout << "C2F::C2F: I exists!" << endl;
    m_commonData = new CommonData();
}

C2F::~C2F() {
    cout << "C2F::~C2F: I am gone." << endl;
    delete m_commonData;
}

void C2F::setDataInCpp() {
    cout << "C2F::setDataInCpp" << endl;
    m_commonData->doubleScalar = 1.1;
    m_commonData->doubleArray[0][0] = 1.1;
    m_commonData->doubleArray[0][1] = 2.2;
    m_commonData->doubleArray[0][2] = 3.3;
    m_commonData->doubleArray[1][0] = 4.4;
    m_commonData->doubleArray[1][1] = 5.5;
    m_commonData->doubleArray[1][2] = 6.6;
}

void C2F::setDataInFortran() {
    cout << "C2F::setDataInFortran" << endl;
    fortran_setData();
}

void C2F::copyDataFromCpp() {
    cout << "C2F::copyDataFromCpp" << endl;
    fortran_copyDataFromCpp(m_commonData);
}

void C2F::copyDataToCpp() {
    cout << "C2F::copyDataToCpp" << endl;
    fortran_copyDataToCpp(m_commonData);
}

void C2F::printData() {
    cout << "C2F::printCommonData" << endl;
    cout << "cpp: doubleScalar: " << m_commonData->doubleScalar << endl;
    for (int i=0;i<2;++i) {
        for (int j=0;j<3;++j) {
            cout << "cpp: doubleArray[" << i << "][" << j << "]: " << m_commonData->doubleArray[i][j] << endl;
        }
    }
    fortran_printData();
}

int main(int argc, char *argv[]) {
    C2F* m_c2f = new C2F();
    cout << "From Cpp to Fortran:" << endl;
    m_c2f->setDataInCpp();
    m_c2f->copyDataFromCpp();
    m_c2f->printData();

    cout << "From Fortran to Cpp:" << endl;
    m_c2f->setDataInFortran();
    m_c2f->copyDataToCpp();
    m_c2f->printData();

    delete m_c2f;
    return 0;
}
