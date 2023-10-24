.text              
# start code here
.globl main

main:
    la a0, num     # load address of num into a0
    lw a1, 0(a0)
    mv a0, a1
    jal factorial  # call factorial function
    la a0, ans     # load address of result into a1
    sw a1, 0(a0)   # store result into result variable
    j end          # jump to end of program

factorial:
    # PROLOGUE START #
    addi sp, sp, -8
    sw ra, 0(sp)
    sw a1, 4(sp)
    # PROLOGUE END #

    # if (num <= 1) return 1
    li t0, 1
    ble a1, t0, base_case

    addi a1, a1, -1      # num = num -1
    jal factorial        # factorial (num -1)
    lw t1, 4(sp)         # Original num
    mul a1, a1, t1       # num * factorial(num - 1)

    base_case:
        # EPILOGUE START 
        lw ra, 0(sp)
        addi sp, sp, 8
        # EPILOGUE END #
        ret

end:
    # end code here

write_tohost:
li x1, 1
sw x1, tohost, t5
j write_tohost

.data 
# start data section here
num: .word 4
ans: .word 0
# end data section here

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;
