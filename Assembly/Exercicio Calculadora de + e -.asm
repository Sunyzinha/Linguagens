.model small 
.data
    msg1 db "Digite o primeiro numero: $"
    msg2 db 0Ah, 0Dh,"Qual operacao voce deseja <+ soma  - subtracao>: $"
    msg3 db 0Ah, 0Dh, "Digite o segundo numero: $"
    sinalsoma db 02Bh
    sinalsubtracao db 02Dh
    
.code 

    PRINTF macro string
       mov ah, 09h    
       lea dx, string 
       int 21h            
    endm 
    
    SCANF macro 
        mov ah, 01h    
        int 21h        
    endm
    
    PRINTC macro char
        mov dl,char    
        mov ah,02h     
        int 21h
    endm  
    
    NEWLINE macro
        PRINTC 0Ah     
        PRINTC 0Dh     
    endm
       

    mov ax, @data  
    mov ds, ax     
    
    
    PRINTF msg1    
    SCANF          
          
    mov ch, al       
    

    
    compara:       
    PRINTF msg2    
    SCANF          
    mov cl,al    
    
    cmp cl, sinalsoma       
    je mais                 
    cmp cl, sinalsubtracao 
    je menos              
    jmp compara             
    
    
    mais:
    PRINTF msg3   
     SCANF          
       mov ah,al     
        add ch,ah          
        sub ch,30h     
       NEWLINE        
       PRINTC ch                     
      jmp fim
        
      
   menos:
   PRINTF msg3    
    SCANF          
      mov cl,al     
        sub ch,cl     
        add ch,30h     
       NEWLINE        
       PRINTC ch                          
      jmp fim      
  
    fim:
    mov ah,4ch    
    int 21h 
end