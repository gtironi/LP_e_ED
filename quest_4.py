import numpy as np
import numpy.random as npr

def questao_4():
    arr_5 = npr.randint(10, 50, size = 20)
    arr_6 = npr.randint(10, 50, size = 20)

    # Obs: Como o método usado para gerar os arrays foi o randint do numpy.random, é possível que haja duplicatas nos índices por um número se repitir.

    in_comun_number  = []

    print(arr_5, arr_6)

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


