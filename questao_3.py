import numpy as np
import numpy.random as npr

arr_3 = npr.randint(1,15,10).reshape(5,2)
def questao_3(arr_3):
    arr_4 = npr.randint(1,15,10).reshape(5,2)
    arr_4 = arr_4*arr_3
    return arr_4
    
questao_3(arr_3)