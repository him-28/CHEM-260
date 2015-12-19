for (n in 1:25) {   
     if (n%%2==0) {  
      cat(n,"is an even\n") # Testing for even or odd  
     } else {    
       cat(n," is an odd\n") 
     }   
     if (n%%10==0) {
         cat(n," is a multiple of 10\n") 
     }
 }
