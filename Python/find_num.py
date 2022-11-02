# Find Numbers in a String :

# Python3 code to demonstrate
# getting numbers from string 
# using re.findall()
import re
  
# initializing string 
test_string = "There are 2 apples for 4 persons"
  
# printing original string 
print("The original string : " + test_string)
  
# using re.findall()
# getting numbers from string 
temp = re.findall(r'\d+', test_string)
res = list(map(int, temp))
  
# print result
print("The numbers list is : " + str(res))
