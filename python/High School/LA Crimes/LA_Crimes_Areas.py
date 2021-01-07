import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('Crime_Data_2010_2017.csv')

np_array = df.iloc[:, 5].unique()
df2 = pd.DataFrame(np_array)
counties = df.iloc[:, 5].tolist()


numout = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

for x in range(len(counties)):
    if counties[x] == '77th Street':
        numout[0] += 1
    elif counties[x] == 'Olympic':
        numout[1] += 1
    elif counties[x] == 'Southeast':
        numout[2] += 1
    elif counties[x] == 'Topanga':
        numout[3] += 1
    elif counties[x] == 'Central':
        numout[4] += 1
    elif counties[x] == 'Northeast':
        numout[5] += 1
    elif counties[x] == 'Foothill':
        numout[6] += 1
    elif counties[x] == 'Mission':
        numout[7] += 1
    elif counties[x] == 'Van Nuys':
        numout[8] += 1
    elif counties[x] == 'Newton':
        numout[9] += 1
    elif counties[x] == 'N Hollywood':
        numout[10] += 1
    elif counties[x] == 'West Valley':
        numout[11] += 1
    elif counties[x] == 'Pacific':
        numout[12] += 1
    elif counties[x] == 'Devonshire':
        numout[13] += 1
    elif counties[x] == 'Rampart':
        numout[14] += 1
    elif counties[x] == 'Southwest':
        numout[15] += 1
    elif counties[x] == 'Hollenbeck':
        numout[16] += 1
    elif counties[x] == 'Harbor':
        numout[17] += 1
    elif counties[x] == 'Hollywood':
        numout[18] += 1
    elif counties[x] == 'West LA':
        numout[19] += 1
    elif counties[x] == 'Wilshire':
        numout[20] += 1
    
se = pd.Series(numout)
df2['1'] = se.values

df2.columns = ['County', 'Value']
df2.to_csv('Areas.csv', index = False)


counties = df2['County'].tolist()
numbers = df2['Value'].tolist()

plt.pie(numbers, labels=counties, counterclock=False, shadow=True, autopct='%1.1f%%')
plt.title('Crimes in Various Counties of LA')
plt.show()


