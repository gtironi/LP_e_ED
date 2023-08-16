import numpy as np
import numpy.random as npr

#Questão 1
#Gere dois ndarrays de inteiros de uma dimensão utilizando o método de sua preferência da biblioteca NumPy
#Atribua a um terceiro ndarray a soma elemento a elemento dos dois primeiros ndarrays

def questao_1():
    a1D_int_a = npr.randint(1, 20, 10)
    a1D_int_b = npr.randint(1, 20, 10)
    return a1D_int_a + a1D_int_b

#Questão 2
# Redimensione o terceiro ndarray para duas dimensões
# Converta os dados para algum tipo de ponto flutuante
# Atribua ao terceiro ndarray sua transposta

def questao_2(ndarray = questao_1()):
    a2D_int_c = ndarray.reshape(2,5)
    a2D_float_c = a2D_int_c.astype('float64') 
    a5D_float_c = np.transpose (a2D_float_c)
    return a5D_float_c