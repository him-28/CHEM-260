      program testswap
      integer i, j, swap, val
      i=10
      j=20
      write(*,*) 'Before swap i=',i,'j=',j
      val=swap(i,j)
      write(*,*) ' After swap i=',i,'j=',j
      end

      integer function swap(i,j)
      integer temp
      temp=i
      i=j
      j=temp
      swap=1
      return
      end
