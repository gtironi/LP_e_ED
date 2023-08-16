import numpy as np
import numpy.random as npr
from quest_1_e_2 import questao_1

def questao_6():
    vec_a = questao_1()
    vec_b = questao_1()

    vec_a_b =  np.multiply(vec_a, vec_b)

    print(vec_a_b)

    return vec_a_b

