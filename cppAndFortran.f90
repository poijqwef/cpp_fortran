module fortran_module

use, intrinsic :: iso_c_binding
implicit none

type, bind(C) :: CommonData
real(c_double) :: doubleScalar;
real(c_double) :: doubleArray(3,2)
end type CommonData

public fortran_setData
public fortran_copyDataFromCpp
public fortran_copyDataToCpp
public fortran_printData

private

type(CommonData) :: m_commonData
real :: m_doubleArray(2,3)

contains


subroutine fortran_setData() &
    bind (c,name="fortran_setData")
implicit none
    m_commonData%doubleScalar = -1.1
    m_doubleArray(1,1) = -1.1
    m_doubleArray(1,2) = -2.2
    m_doubleArray(1,3) = -3.3
    m_doubleArray(2,1) = -4.4
    m_doubleArray(2,2) = -5.5
    m_doubleArray(2,3) = -6.6
    m_commonData%doubleArray = transpose(m_doubleArray)

end subroutine fortran_setData


subroutine fortran_copyDataFromCpp(a_dataFromCpp) &
    bind (c,name="fortran_copyDataFromCpp")
implicit none
type(CommonData), intent(in) :: a_dataFromCpp
    m_commonData = a_dataFromCpp
    m_doubleArray = transpose(m_commonData%doubleArray)

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
    integer i,j

    print *,'fortran: doubleScalar: ',m_commonData%doubleScalar
    do i=1,2
        do j=1,3
            print *,'fortran: doubleArray(',i,',',j,'): ',m_doubleArray(i,j)
        end do
    end do

    print *,''
    print *,'TO OBTAIN THE SAME VALUES, THE ARRAY NEEDS TO BE TRANSPOSED!'
    print *,''
    print *,'Cpp is row-first filling: '
    print *,''
    print *,'  start  -->  [X]  -->  [X]  -->  [X]  --> (new line)' 
    print *,''
    print *,'         -->  [X]  -->  [X]  -->  [X]' 
    print *,''
    print *,'Fortran is column-first filling: '
    print *,''
    print *,'       start'
    print *,'         |         |'
    print *,'         v         v'
    print *,''
    print *,'        [X]       [X]'
    print *,''
    print *,'         |         |'
    print *,'         v         v'
    print *,''
    print *,'        [X]       [X]'
    print *,''
    print *,'         |         |'
    print *,'         v         v'
    print *,''
    print *,'        [X]       [X]'
    print *,''
    print *,'         |'
    print *,'         v'
    print *,'   (new column)'
    print *,''

end subroutine fortran_printData


end module fortran_module
