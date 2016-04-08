module fortran_module

use, intrinsic :: iso_c_binding
implicit none

type, bind(C) :: CommonData
real(c_double) :: doubleScalar;
end type CommonData

public fortran_setData
public fortran_copyDataFromCpp
public fortran_copyDataToCpp
public fortran_printData

private

type(CommonData) :: m_commonData

contains


subroutine fortran_setData() &
    bind (c,name="fortran_setData")
implicit none
    m_commonData%doubleScalar = 2.2
end subroutine fortran_setData


subroutine fortran_copyDataFromCpp(a_dataFromCpp) &
    bind (c,name="fortran_copyDataFromCpp")
implicit none
type(CommonData), intent(in) :: a_dataFromCpp
    m_commonData = a_dataFromCpp
end subroutine fortran_copyDataFromCpp


subroutine fortran_copyDataToCpp(a_dataToCpp) &
    bind (c,name="fortran_copyDataToCpp")
implicit none
type(CommonData), intent(out) :: a_dataToCpp
    a_dataToCpp = m_commonData
end subroutine fortran_copyDataToCpp


subroutine fortran_printData() &
    bind (c,name="fortran_printData")
implicit none
    print *,'fortran: doubleScalar: ',m_commonData%doubleScalar
end subroutine fortran_printData


end module fortran_module
