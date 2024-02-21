import pandas as pd
from datetime import datetime

def le_arquivo_texto(name_file_txt):
    """
    read the text from the file
    
    Parameters
    ----------
    name_file_txt : str
        this is the name of the .txt file
    
    Returns
    -------
    string
        the content of the .txt file
    
    Raises
    ------
    FileNotFoundError
        when a file error
    """
    try:
        with open(name_file_txt) as f:
            content = f.read()
            return content
    except FileNotFoundError:
        print('verifique o nome do seu arquivo')
        le_arquivo_texto(input("Digite o nome do arquivo: "))


def difference_in_days(date):
    d1, d2 = date.split(" - ")
    print(d1, d2)
    

    d1 = pd.to_datetime(d1, format = 'dd/mm/yyyy')

    d1 = pd.to_datetime(d2, format = 'dd/mm/yyyy')
    diff = abs((d1-d2).days)
    return diff