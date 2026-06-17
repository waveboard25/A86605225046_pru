def factorial(n):
    if n == 0 :
        return 1
    else :
        return n*factorial(n-1)
print(factorial(5))
print(f"factorial(n)is : {factorial(4)}")

#DEFINE FUNCTION EX:

def add_numbers(a, b): # 'a' and 'b' are parameters
    return a + b  
# Calling the function with arguments  
result = add_numbers(5, 3) # 5 and 3 are arguments
print("Sum:", result)

#VARIABLE SCOPE #GLOBAL SCOPE:

global_var = 10
def my_function():
    print(global_var) # Accessing the global variable
print(global_var) # Accessible here  
my_function() # Accessible here too

