# -*- coding: utf-8 -*-
"""
Created on Mon Dec  3 19:46:00 2018

@author: smoor

@description: Gets the max, min, mean, and sum of all data values for each receipt description
"""



import numpy as np
import pandas as pd

import column_adjustment as ca

# creating a dataframe to read in our datasets

#  318 MB
dep_df = pd.read_csv('deputies_dataset.csv')
#  75.3 MB
dirty_dep_df = pd.read_csv('dirty_deputies_v2.csv')

# generating separate dataframes with the max, min, and mean values for each reciept description
dep_max = dep_df.groupby('receipt_description').max()
dep_min = dep_df.groupby('receipt_description').min()
dep_mean = dep_df.groupby('receipt_description').mean().apply(lambda n: round(n, 2))
dep_total = dep_df.groupby('receipt_description').sum()

# concatenating all dataframes together
df = pd.concat([dep_max['receipt_value'],dep_min['receipt_value'],dep_mean['receipt_value'],dep_total['receipt_value']],axis=1)
df.columns = ['max_value','min_value','mean_value','total_value']

print(list(dep_df.columns))

print(dep_df[dep_df['receipt_value'] == 149754]['deputy_name'])
# exporting to csv
df.to_excel('results.xlsx')
df.to_csv('results.csv')
ca.adjust_column('results.xlsx')