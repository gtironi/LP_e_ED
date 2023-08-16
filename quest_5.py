import numpy as np
import numpy.random as npr

#Questão 5
# Declare um sétimo ndarray e atribua o empilhamento horizontal do quinto e do sexto ndarrays
# Imprima no console a média, desvio padrão e variância dos elementos
# A cada elemento ímpar atribua -1
# A cada elemento par atribua 1

def questão_5(arr_5, arr_6):
    arr_7 = npr.randint(10, 50, size = 20)
    arr_horizont = np.hstack((arr_5, arr_6, arr_7))
    
    print('Median: ', np.median(arr_horizont))
    print('Standard Deviation: ', np.std(arr_horizont))
    print('Variance: ', np.var(arr_horizont) ,'\n')
    
    arr_impares_pares = arr_horizont.copy()
    
    for i in range(len(arr_impares_pares)):
        if i%2 != 0:
            arr_impares_pares[i] = -1
        else:
            arr_impares_pares[i] = 1
            
    return arr_impares_pares
