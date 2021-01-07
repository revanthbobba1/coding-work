import numpy as np
import pandas as pd


dep_df = pd.read_csv('deputies_dataset.csv')

print(dep_df[dep_df['receipt_value'] == 149754]['deputy_name'])
print(dep_df[dep_df['receipt_value'] == 215000]['deputy_name'])
print(dep_df[dep_df['receipt_value'] == 184500]['deputy_name'])
