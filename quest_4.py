import numpy as np
from quest_1_e_2 import questao_1

def questao_4():
    arr_5 = questao_1()
    arr_6 = questao_1()

    # Obs: Como o método usado para gerar os arrays foi o randint do numpy.random, é possível que haja duplicatas nos índices por um número se repitir.

    in_comun_number  = []

    for number in arr_5:
        if number in arr_6:
            in_comun_number.append(number)
            i_1 = np.where(arr_5 == number)
            i_2 = np.where(arr_6 == number)

            print("Número em comum:", number, f"\nÍndices no array 5 e 6 respectivamente: {i_1[0]} e {i_2[0]}")

    not_in_comun_number = []

    for number_2 in arr_5:
        if number_2 not in in_comun_number:
            not_in_comun_number.append(number_2)

    print("\nElementos do quinto array que não estão no sexto:", end = " ")
    for number_not_comun in not_in_comun_number:
        print(number_not_comun, end = " ")

    return {
        "array_5": arr_5,
        "array_6": arr_6,
        "in_comun_numbers": in_comun_number,
        "not_in_comun_numbers": not_in_comun_number
        }


