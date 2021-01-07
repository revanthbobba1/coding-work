# -*- coding: utf-8 -*-
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats

### ***INTRO***


num = 5
print(num)

nums = [1, 2, 3, 4, 5]
print(nums)
for x in nums:
  print(x)
else:
  print("Done with nums")

words = ["hi", "bye", "hello", "goodbye"]
print(words)
for x in words:
  print(x)
else:
  print("Done with words")

for x in range(0, 10):
  print(x)
  if x == 5:
    words[0] = "five"
    print(words)
    words[0] = "new"

arr = np.array([0,1,2,3])
print(arr.size)
print(arr.ndim)

#String Formatting
name = 'RevBob' 
location = 'Cary'
favoriteFood = 'Taco Bell' 
print('My name is {} and I am from {}.'.format(name, location)) 
print('I want to eat {food}. My name is {}.'.format('rev', food = favoriteFood))

#Lists
print(name[:-1:2])

list1 = [0, 2, 1, 4]
print(list1)
list1.sort()
print(list1)
list1.append('hi')
print(list1[-1:])

#Dictionaries
dic = {'Name' : 'RevBob', 'Age' : 10, 'Foods' : ['tuffy', 'lobos', 'bistro'], 'nesteddic':{'item1' : 'hi'}}
print(dic['Name'])
print(dic['Age'])
print(dic['Foods'][-1])
print(dic['nesteddic']['item1'])

#Tuple
tup = (1, 2, 3)

try:
  tup[0] = 0
except TypeError:
  print('Tuples are immutable.')
except:
  print('Some other error occured.')
finally:
  print('My tuple is: {}'.format(tup))

#Sets
set1 = {1,2,3}
print(set1)
set2 = {1,1,2,2,3,3}
print(set2)
set1 == set2

try:
  print(set1[0])
except:
  print('No indeces in sets')

set3 = set([0,2,3])
set3.add('hi')
print(set3)

#Loops
print(range(5))
for x in range(4):
  print(x+1)

list2 = []
for x in range(0,6):
  list2.append(x)

print(list2)

#List Comprehension
list2 = [num**2 for num in list2]
print(list2)

#Functions
def func1(a):
  for x in range(10):
    print(a, end = '')

func1('yo')

print()

def square(num):
  return num**2

print(square(3))

#Lambda Expression
func2 = lambda num:num**2
print(func2(2))

list2 = []
for x in range(0,6):
  list2.append(x)

list(filter(lambda num:num%2 == 0, list2))

#Random
s = 'blah blah'
print(s.upper())
print(s.lower())
print(s.split())

print()

dict = {'k1':1, 'k2':2}
print(dict.keys())
print(dict.values())
print(dict.items())

print()

list3 = [1,2,3]
print(list3.pop())
one = list3.pop(0)
print(one)
print(list3)

2 in list3
1 in list3

print()

#Tuple Unpacking
list4 = [(1,2), (3,4), (5,6)]

for a,b in list4:
  print(a)
  print(b)

"""### ***RANDOM***"""

#Getting the Domain of an email
s = 'user@domain.com'
print(s.split('@')[1])

print()

#Adding 2 to each element

a = [1, 3, 5]
b = a
a = [x + 2 for x in a]
print(a)

print()

#Making second half of list 0's
list5 = [1,2,3,4,5,6]
list5[int(len(list5)/2):] = [x-x for x in list5[int(len(list5)/2):]]
print(list5)

list5 = np.arange(6)
print(list5)
list5[int(len(list5)/2):] = 0
print(list5)

print()

#Checking if 'dog' is in list
#Removing period from end by splitting list
s = "The quick brown fox jumps over the lazy Dog."
list4 = s.lower().split()
list4 = [item.split('.')[0] for item in list4]
print(list4)
print('dog' in list4)
print()
#Recombine list
list4 = [' '.join(list4)]
print(list4)

print()

#Count number of times 'string' is in string using func
string = 'string string string string'
notstring = 'notstring notstring notstring'

def stringcounter(s):
  stringcount = 0
  list_s = s.split()
  for item in list_s:
    if item == 'string':
      stringcount = stringcount + 1

  return stringcount

print('string count in {one} is: {two}'.format(one = 'string', two = stringcounter(string)))
print('string count is: ' + str(stringcounter(string)))
print('string count is: ' + str(stringcounter(notstring)))

"""### ***NUMPY***

"""

print(np.arange(10), end='\n\n')
print(np.zeros((3,3)), end='\n\n')
print(np.ones((2,2)), end='\n\n')
print(np.linspace(0,5,10), end='\n\n')
print(np.eye(3), end='\n\n')
print(np.random.rand(4,4), end='\n\n')
print(np.random.randn(4,4), end='\n\n')
print(np.random.randint(0,10,4), end='\n\n')

arr = np.arange(25)
randarr = np.random.randint(0, 50, 10)

print(arr, end='\n\n')
print(randarr, end='\n\n')

reshaped = arr.reshape(5,5)
print(reshaped, end='\n\n')

print(randarr.max())
print(randarr.argmax()) #same with min
print(reshaped.shape)
print(arr.dtype)

print()

#Traversing elements in reshaped, a 2x2 matrix
for x in reshaped:
  for y in x:
    print(y)

# Broadcasting - Slicing the array is a snapshot of original array, not a new copy
arr = np.arange(10)
slice_arr = arr[:5]
print(slice_arr)
print(slice_arr.base)
slice_arr[:] = 0
print(slice_arr)
print(arr)

print()

#Making a copy
arr_copy = arr.copy()
print(arr_copy.base)
arr_copy[:] = 0
print(arr_copy)
print(arr) #Taking a copy does not change the original array

print()

arr_2d = np.arange(5, 50, 5).reshape(3,-1) #Putting a -1 is an 'unknown' dimension, and python will calculate the necessary dimension. Only one allowed
print(arr_2d, end='\n\n')

print(arr_2d[0][0], end='\n\n')
print(arr_2d[0,0], end='\n\n')
print(arr_2d[2,1], end='\n\n')

print(arr_2d[:2,:2], end='\n\n')
print(arr_2d[1:,1:], end='\n\n')
print(arr_2d[-1:,-1:], end='\n\n')


#Flatten array - make into 1D array
print(arr_2d, end='\n\n')
print(arr_2d.reshape(-1), end='\n\n')

arr = np.arange(1,11)
print('1 - arr is: ',end='')
print(arr, end='\n\n')

print('2: ',end='')
print(arr > 5, end='\n\n')

bool_arr = arr > 5

print('3: ',end='')
print(arr[bool_arr], end='\n\n')

print('4: ',end='')
print(arr[arr > 5], end='\n\n')

print('5: ',end='')
print(arr[arr%2 == 0], end='\n\n')

print('6: ',end='')
print(arr+arr, end='\n\n')

print('7: ',end='')
print(arr*5, end='\n\n')

print('8: ',end='')
print(np.sqrt(arr), end='\n\n')

print('9: ',end='')
print(np.ones(10)*5, end='\n\n')

print('10: ',end='')
print(np.arange(10,51), end='\n\n')

print('11: ',end='')
print(np.arange(10,51,2), end='\n\n')

print('12: ',end='')
print(np.arange(1,101).reshape(10,10)/100, end='\n\n')

print('13: ',end='')
print(np.linspace(.01,1,100).reshape(10,10), end='\n\n')

arr_2d = np.arange(1,26).reshape(5,5)
print('14: ',end='')
print(arr_2d, end='\n\n')

print('15: ',end='')
print(np.sum(arr_2d), end='\n\n')

print('16: ',end='')
print(np.std(arr_2d), end='\n\n')

#Sum of columns
print('17: ',end='')
print(arr_2d.sum(axis=0))

arr = np.array([1, 2, 3, 4, 5, 4, 4])
x = np.where(arr == 4)
print(x, end='\n\n')

"""### ***PANDAS***"""

labels = ['a','b','c']
my_data = [10,20,30]
arr = np.array(my_data)
d = {'a':10, 'b':20, 'c':30}
se = pd.Series(my_data, labels)
print(pd.Series(my_data, labels), end='\n\n') # could have used arr instead of my_data
print(se['a'])

print()

print(pd.Series(d), end='\n\n')

se = pd.Series(labels)
print(se, end='\n\n')
print(se[1])

from numpy.random import randn

np.random.seed(101)
df = pd.DataFrame(randn(5,4), ['A', 'B', 'C', 'D', 'E'], ['W', 'X', 'Y', 'Z'])

print(df, end='\n\n\n')
print(df[['W', 'Z']], end='\n\n')

df['new'] = df['W'] + df['Y']
print(df, end='\n\n')

df.drop('new', axis = 1, inplace = True)
print(df, end='\n\n')
df.drop('E', inplace=True)

np.random.seed(101)
df = pd.DataFrame(randn(5,4), ['A', 'B', 'C', 'D', 'E'], ['W', 'X', 'Y', 'Z'])

print(df.loc['A'], end='\n\n')
print(df.iloc[0], end='\n\n')
print(df.loc[['A', 'B'], ['W', 'Y']], end='\n\n')

np.random.seed(101)
df = pd.DataFrame(randn(5,4), ['A', 'B', 'C', 'D', 'E'], ['W', 'X', 'Y', 'Z'])

print(df, end='\n\n')

#Conditional Selection
print(df[df>0], end='\n\n')
#Only prints values of dataframe where df['W']>0 is true
print(df[df['W']>0], end='\n\n')
#Only prints values of dataframe where df['Z']<0 is true)
print(df[df['Z']<0], end='\n\n')
#Get the X values of data frame with rows where W>0
print(df[df['W']>0]['X'], end='\n\n')

#Multiple Conditional Selection
print(df[ (df['W']>0) & (df['Y']>1) ], end='\n\n')

#Reset Index -> Makes old index into Column
df.reset_index(inplace=True)
print(df, end='\n\n')
df.drop('index', axis=1, inplace=True)
print(df, end='\n\n')

#Setting New Index
newind = 'CA NY WY OR CO'.split()
df['States'] = newind
df.set_index('States', inplace=True)
print(df)

outside = 'G1 G1 G1 G2 G2 G2'.split()
inside = [1,2,3,1,2,3]
hier_index = list(zip(outside,inside))
hier_index = pd.MultiIndex.from_tuples(hier_index)

df = pd.DataFrame(randn(6,2), hier_index, ['A', 'B'])
print(df, end='\n\n')

print(df.loc['G1'].loc[1], end='\n\n')

#Making names for two outer unnamed indeces
df.index.names = ['Groups', 'Num']
print(df, end='\n\n')

#Cross Section of a multi-index dataframe
#print(df.loc['G1'], end='\n\n') -> Traditional Way
print(df.xs('G1'), end='\n\n')

#Getting values from both groups in num = 1
print(df.xs(1, level='Num'))

#Missing Data
d = {'A': [1,2,np.nan], 'B':[5,np.nan,np.nan] , 'C':[1,2,3]}
df = pd.DataFrame(d)
print(df, end='\n\n')

#.dropna() drops any rows/columns with missing values
print(df.dropna(), end='\n\n')
print(df.dropna(axis=1), end='\n\n') #drops null columns
print(df.dropna(thresh=2), end='\n\n') #How many non-nan values to not get dropped. Row 2 gets dropped since 2 nan values

#fill.na fills a nan cell with info
print(df.fillna(value='Filler'), end='\n\n')
#df['A'].fillna(value=df['A'].mean(), inplace = True)   -> Filling 'A' column only with nan values
#df['B'].fillna(value=df['B'].mean(), inplace = True)   -> Filling 'B' column only with nan values
#df.fillna(value=df.mean()['B':'C'], inplace = True)    -> Filling columns from B to C, INCLUSIVE, with their respective mean values
df.fillna(value=df.mean(), inplace = True) #           -> Filling all columns with their respective mean values
print(df, end='\n\n')

#GroupBy
data ={'Company': ['GOOG', 'GOOG', 'MSFT', 'MSFT', 'FB', 'FB'] , 
      'Person': ['Sam', 'Charlie', 'Amy', 'Vanessa', 'Carl', 'Sarah'] , 
      'Sales': [200, 120, 340, 124, 243, 350]}

df = pd.DataFrame(data)
print(df, end='\n\n')

#Only takes numeric values for entire dataframe
print(df.groupby('Company').mean(), end='\n\n') #Groups company, then takes mean
print(df.groupby('Company').count(), end='\n\n') #counts of other vars for each company
print(df.groupby('Company')['Sales'].sum(), end='\n\n') #Sum of company sales
print(df.groupby('Company').describe().loc['FB']) #descriptors variables of facebook company

df = pd.DataFrame({ 'col1':[1,2,3,4],
                    'col2':[444,555,666,444],
                    'col3':['abc', 'def', 'ghi', 'xyz']})

print(df, end='\n\n')

print(df['col2'].unique(), end='\n\n') #numpy array of all unique values
print(df['col2'].nunique(), end='\n\n') #number of unique items in column 2
print(df['col2'].value_counts(), end='\n\n') #How many times each item occurs in column two

def times2(x):
  return x*2

print(df['col1'].apply(times2), end='\n\n') #Uses custom apply function to multiply every value in column1 by 2
print(df['col2'].apply(lambda x:x*2), end='\n\n') #Multiply each value in a column using lambda function

print(df.sort_values('col2'), end='\n\n') #Sorts values by numerical order from col2
print(df.isnull(), end='\n\n') #Checks if values in dataframe are null

#Pivot Tables
data = {'A':'foo foo foo bar bar bar'.split(), 'B':'one one two two one one'.split(), 'C':'x y x y x y'.split(), 'D':[1,3,2,5,4,1]}
df = pd.DataFrame(data)
print(df.pivot_table(values='D', index=['A','B'], columns = ['C']), end='\n\n')

#I/O
df = pd.read_csv('Data.csv')
df.to_csv('out.csv', index = False)

#Excel
#pd.read_excel('Excel_Sample.xlsx', sheet_name='Sheet1')
#df.to_excel('out.xlsx', sheet_name='NewSheet')

#HTML
data = pd.read_html('https://www.fdic.gov/bank/individual/failed/banklist.html')
data[0].head()

"""Exercise 1"""

#Random Exercises
sal = pd.read_csv('Salaries.csv', nrows=148646, low_memory=False) #Strip ending rows with poor data
print(sal.head(), end='\n\n')
print(sal.info(), end='\n\n')

#average BasePay
print('Average BasePay is:')
print(sal['BasePay'].mean(), end='\n\n')

#Largest OvertimePay
print('Largest OvertimePay is:')
print(sal['OvertimePay'].max(), end='\n\n')

#Job Title of Joseph Driscoll
print('Job Title of Joseph Driscoll is: ')
print(sal[sal['EmployeeName'] == 'JOSEPH DRISCOLL']['JobTitle'], end='\n\n')

#Total income of Joseph Driscoll
print('Total Income of Jospeh Driscoll is: ')
print(sal[sal['EmployeeName'] == 'JOSEPH DRISCOLL']['TotalPayBenefits'], end='\n\n')

#Name of Highest Paid Person
print("Highest Paid Person is: ")
print(sal[sal['TotalPayBenefits'] == sal['TotalPayBenefits'].max()]['EmployeeName'])
print('Their Job Title is: ')
print(sal[sal['TotalPayBenefits'] == sal['TotalPayBenefits'].max()]['JobTitle'], end='\n\n')
#Another Way:
print('Second Way: ', end='\n\n') 
print(sal.iloc[sal['TotalPayBenefits'].idxmax()].loc['EmployeeName'], end='\n\n')

#Lowest Paid Person
print("Lowest Paid Person is: ")
print(sal[sal['TotalPayBenefits'] == sal['TotalPayBenefits'].min()]['JobTitle'])
print("Their pay is: ")
print(sal[sal['TotalPayBenefits'] == sal['TotalPayBenefits'].min()]['TotalPayBenefits'], end='\n\n')
#Another Way
print('or', end='\n\n')
print(sal.iloc[sal['TotalPayBenefits'].idxmin()].loc['JobTitle'])
print(sal.iloc[sal['TotalPayBenefits'].idxmin()].loc['TotalPayBenefits'], end='\n\n')

#Average BasePay of all Employees
print('Average Base pay of all Empployees')
print(sal.groupby('Year').mean()['BasePay'], end='\n\n')
print('Average Base pay of all 2011 Empployees')
print(sal.groupby('Year').mean()['BasePay'].loc[2011], end='\n\n')

#Number of Unique Job Titles
print('The number of unique job titles are: ')
print(sal['JobTitle'].nunique(), end='\n\n')

#Top 5 most common jobs
print('The top 5 most common jobs are:')
print(sal['JobTitle'].value_counts()[:5], end='\n\n')

#How many job title were only represented by 1 person in 2013
print('The number of job titles represented by 1 person in 2013 is: ')
print(sum(sal[sal['Year'] == 2013]['JobTitle'].value_counts() == 1), end='\n\n')

#How many people have the word 'Chief' in their job title
print('The number of people with Chief in their job title is: ')
print(sum(sal['JobTitle'].apply(lambda x:'chief' in x.lower())), end='\n\n')

#Is there a correlation b/w  Job Title length and salary
print('Correlation b/w title length and salary:', end='\n\n')
sal['title_len'] = sal['JobTitle'].apply(len)
print(sal[['title_len', 'TotalPayBenefits']].corr())

"""Exercise 2"""

ecom = pd.read_csv ('Ecommerce_Purchases.txt')
print(ecom.head(), end='\n\n')
print(ecom.info(), end='\n\n')

#Average Puchase Price
print('Average Purchase Price')
print(ecom['Purchase Price'].mean(), end='\n\n')

#Highest and Lowest Purchase Price
print('Highest Purchase Price: ')
print(ecom['Purchase Price'].max())
print('Lowest Purchase Price: ')
print(ecom['Purchase Price'].min(), end='\n\n')

#How many people have English ('en') as their Language of choice on the website
print('# of people with english as preferred language: ')
print(sum(df['Language'].apply(lambda x:x=='en'.lower())))
print('or')
print(ecom[ecom['Language'] == 'en'.lower()]['Language'].count(), end='\n\n')

#How many people have the job title of 'Lawyer'
print('# of people with job title Lawyer: ')
print(sum(ecom['Job'].apply(lambda x:'lawyer' in x.lower())))
print('or: ')
print(len(ecom[ecom['Job'] == 'Lawyer'].index))
print('or: ')
print(ecom[ecom['Job'] == 'Lawyer']['Job'].count(), end='\n\n') # not as good since doesn't take into account for case or multiword titles

#How many people made purchases in the am? pm?
print('AM Puchases: ')
print(ecom['AM or PM'].value_counts().loc['AM'])
print('or: ')
print(ecom[ecom['AM or PM'] == 'AM']['AM or PM'].count())
print('Do the same as above for PM', end='\n\n')

#5 Most common Job Titles
print('5 Most common Job Titles: ')
print(ecom['Job'].value_counts()[:5], end='\n\n')

#Someone made a purchase that come from Lot: '90 WT'. What was the Purchase Price
print('Price was: ')
print(ecom[ecom['Lot'] == '90 WT']['Purchase Price'].loc[513], end='\n\n')

#What was the email of the person with the following credit card number: 4926535242672853
print('Email was: ')
print(ecom[ecom['Credit Card'] == 4926535242672853]['Email'].loc[1234], end='\n\n')

#How many people have American Express as the Credit Card Provider and made a purhcase above $95
print('Number of people was: ')
print(len(ecom[(ecom['CC Provider'] == 'American Express') & (ecom['Purchase Price'] > 95)]), end='\n\n')

#How many people haev a cc that expires in 2025
print('Number of people with 2025 expire date is: ')
print(sum(ecom['CC Exp Date'].apply(lambda x: x[3:] == '25')))
print('or: ')
print(ecom[ecom['CC Exp Date'].apply(lambda x: x[3:] == '25')]['CC Exp Date'].count())

#Top 5 most popular email providers
print('Most popular email providers: ')
print(ecom['Email'].apply(lambda x: x.split('@')[1]).value_counts()[:5])

"""### ***MATPLOTLIB***"""

x = np.linspace(0,5,11)
y = x**2

#Functional
plt.plot(x, y)
plt.xlabel('X Label')
plt.ylabel('Y Label')
plt.title('Title')
plt.show()
print()

plt.subplot(1,2,1)
plt.plot(x,y,'r')

plt.subplot(1,2,2)
plt.plot(y,x,'b')
plt.show()

#OOP
fig = plt.figure()
axes = fig.add_axes([.1,.1,.8,.8])
axes.plot(x,y)
axes.set_xlabel('X Label')
axes.set_ylabel('Y Label')
axes.set_title('Title')
plt.show()

fig = plt.figure()
axes1 = fig.add_axes([0,0,1,1]) #Starts at 0,0 and length and width take up 100% of total capacity
axes2 = fig.add_axes([.1,.1,.8,.8]) #Starts at .1,.1 and length and width take up 80% of total capacity (.1+.8, .1+.8)
axes3 = fig.add_axes([.2,.5,.4,.3]) #Starts at .2,.5 and length takes up 40% of capacity and width takes up 30% capacity (.2+.4, .5+.3)

axes2.plot(x,y)
axes2.set_title('Axes 2 Plot')

axes3.plot(x,y)
axes3.set_title('Axes 3 Plot')

plt.show()

fig,axes = plt.subplots(1,2)

for ax in axes:
  ax.plot(x,y)

plt.show()
print()

fig2,axes2 = plt.subplots(1,2)


axes2[0].plot(x,y)
axes2[0].set_title('1st Plot')
axes2[1].plot(y,x)
axes2[1].set_title('2nd Plot')

#plt.tight_layout() -> Eliminates Overlapping Graphs

plt.show()

fig = plt.figure(figsize=(5,5))
ax = fig.add_axes([0,0,1,1])
ax.plot(x,x**2,label='X Squared')
ax.plot(x,x**3,label='X Cubed')


ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_title('Title')

ax.legend(loc=0) #Location code of 0 chooses best location

plt.show()
'''
fig,axes = plt.subplots(2,1,figsize=(8,2))
axes[0].plot(x,y)
axes[1].plot(y,x)
plt.tight_layout()
plt.show()
'''
fig.savefig('my_pic.png', dpi=200)

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])
'''
Alpha changes transparency.
Linestyle '--' gives a dashed line
'-.' gives a  dashed-dotted line
'' gives no line
'''
#ax.plot(x,y, color = 'blue',lw = 10, alpha = .1) 
ax.plot(x,y, color = 'blue', lw = 5, ls = '--', marker = 'o', ms = 10,
        markerfacecolor = 'yellow', markeredgewidth = '2', markeredgecolor = 'black') 

plt.show()

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])
ax.plot(x,y,color='purple',lw=2,ls='--') #ls is linestyle and lw is linewidth

ax.set_xlim([0,2])
ax.set_ylim([0,5])

plt.show()

"""Exercises"""

x = np.arange(0,100)
y = x*2
z = x**2

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

ax.set_title('Graph of X vs. Y')
ax.set_xlabel('X')
ax.set_ylabel('Y')

ax.plot(x,y)
plt.show()

fig = plt.figure()

ax1 = fig.add_axes([0,0,1,1])
ax2 = fig.add_axes([.2,.5,.2,.2])

ax1.plot(x,y)
ax2.plot(x,y)

plt.show()

fig = plt.figure()

#Adding Axes
ax1 = fig.add_axes([0,0,1,1])
ax2 = fig.add_axes([.2,.5,.4,.4])

#Setting Labels
ax1.set_xlabel('X')
ax1.set_ylabel('Z')

ax2.set_xlabel('X')
ax2.set_ylabel('Y')

ax2.set_title("zoom")

#Setting Limits
ax2.set_xlim([20,22])
ax2.set_ylim([30,50])

#Plotting
ax1.plot(x,z)
ax2.plot(x,y)

plt.show()

fig,ax = plt.subplots(1,2, figsize = (12,2))

#Plotting
ax[0].plot(x,y, color = 'blue', ls = '--', lw = 3)
ax[1].plot(x,z, color = 'red', lw = 3)

fig.tight_layout()
plt.show()

"""### ***SEABORN***"""

tips = sns.load_dataset('tips')
tips.head()

sns.distplot(tips['total_bill'], kde=False, bins=40)
plt.show()

sns.jointplot(x = 'total_bill', y = 'tip', data = tips, kind = 'kde') 
#'hex' is a hex graph, 'reg' is regression, 'kde' gives density

plt.show()

sns.pairplot(tips, height = 3, hue = 'sex', palette = 'coolwarm')

plt.show()

sns.rugplot(tips['total_bill'])

plt.show()

#Create Dataset
dataset = np.random.randn(25)

#Create Rugplot
sns.rugplot(dataset)

#Setup x-axis for plot
x_min = dataset.min() - 2
x_max = dataset.max() + 2

#100 equally spaced points from x_min to x_max
x_axis = np.linspace(x_min,x_max,100)

#Set up the bandwidth
url = 'http://en.wikipedia.org/wiki/Kernel_density_estimation#Practical_estimation_of_the_bandwidth'

bandwidth = ((4*dataset.std()**5)/(3*len(dataset)))**.2


#Create an empty kernel list
kernel_list = []

#Plot each basis function
for data_point in dataset:
  kernel = stats.norm(data_point, bandwidth).pdf(x_axis)
  kernel_list.append(kernel)

  #Scale for plotting
  kernel = kernel / kernel.max()
  kernel = kernel * .4
  plt.plot(x_axis, kernel, color = 'grey', alpha = .5)

plt.ylim(0,1)

plt.show()

#To get the kde plot, we can sim these basis functions

#Plot the sum of the basis function
sum_of_kde = np.sum(kernel_list, axis = 0)

#Plot figure
fig = plt.plot(x_axis, sum_of_kde, color = 'indianred')

#Add the initial rugplot
sns.rugplot(dataset, c = 'indianred')

#Get rid of y tick marks
plt.yticks([])

#Set title
plt.suptitle('Sum of the Basis Functions')

plt.show()

sns.kdeplot(tips['total_bill'])

plt.show()
