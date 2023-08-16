import numpy as np
import numpy.random as npr

def questao_7():
    arr_8 = np.array([[6, 1, 1], 
                  [4, -2, 5], 
                  [2, 8, 7]]) 
    identidade_3 = np.identity(3)
    determinante = np.linalg.det(arr_8)
    inversa = np.linalg.inv(arr_8)
    print("Oitavo array:\n ", arr_8)
    print("Determinante: ", determinante)
    print("Inversa:\n ", inversa)
    print("Mostrando a corretude(Oitavo array multiplicado pela inversa = identidade):\n",np.dot(arr_8, inversa).astype(int))
    


questao_7()
