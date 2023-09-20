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
    except FileNotFoundError:
        print('verifique o nome do seu arquivo')
        le_arquivo_texto(input("Digite o nome do arquivo: "))


def difference_in_days(date):
    

for row in df:
    #obter dia de hoje
    d1 = pd.to_datetime(datetime.today())
    #obter data do csv
    d2 = pd.to_datetime(df["PasswordLastSet"], infer_datetime_format=True)
    diff = **abs(**(d1-d2).days **)**