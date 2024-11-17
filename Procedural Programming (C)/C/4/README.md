# Unit 4

* [10.c](./10.c): Checks if a user-entered date (DD/MM/YYYY) is valid, considering leap years and the number of days in each month. It returns "TRUE" if the date is valid and "FALSE" if it's not.

* [11.c](./11.c): Returns the sum of FPA (Value Added Tax) for a given year by reading user-inputted dates and corresponding taxes, while verifying the validity of the dates. It checks for leap years and ensures the date falls within a valid range before accumulating the tax.
  
* [12.c](./12.c): Calculates the factorial of a number less than 12 and approximates the sine of an angle (in radians) using a series expansion. It uses π to determine the angle and iterates through the sine series to compute the result.
  
* [13.c](./13.c): Computes and displays the Fibonacci sequence up to a given term nn using a loop. The program prints each Fibonacci number (with spacing for alignment) up to the nn-th term.

* [14.c](./14.c): Calculates a value Y based on user input for three integers a, b, and c. It uses two functions: max to find the maximum between two numbers and gr to find the largest value between a, b, and c, and then computes Y using the formula (2*max(a,b) + 3*gr(a,b,c))/4.

* [15.c](./15.c): Provides a menu for converting an amount in euros to different currencies based on the user's choice, including US Dollars, British Pounds, Swiss Francs, Canadian Dollars, and Japanese Yen. It continues prompting the user until they choose to exit by selecting option 6.
   
* [16.c](./16.c): Performs different operations (sum, product, average) based on the value of a (1, 2, 3) for given b and c. If a is outside this range, it prints an error and terminates.

* [17.c](./17.c): Finds the sum of integers from 1 to n (where n is 100 and 1000 in this case) using a loop. The result is printed for both n = 100 and n = 1000.

* [18.c](./18.c): Prints "Understanding of C" ten times using two different functions. f1 uses a loop with a starting value of i, and f2 uses a fixed loop count of n.
  
* [19.c](./19.c): Estimates an approximation of π using the John Wallis formula, but only if the input number x is even. It computes the approximation by iterating through a series involving even numbers and their squares.

* [20.c](./20.c): Checks for leap years between two user-specified years. It prints each leap year in the given range based on the leap year rule.
  
* [21.c](./21.c): Calculates BMI using height and weight, then categorizes it as Underweight, Normal weight, Overweight, or Obese. It repeats until height or weight entered is zero.

* [22.c](./22.c): Finds the total cost of 5 products, including VAT, based on their quantities, prices, and VAT categories. It accumulates the total cost with VAT and the total VAT amount, displaying the results after all products are processed.

* [23.c](./23.c): Checks whether a given time, consisting of hours, minutes, and seconds, is valid. It prints "Valid input" if the time is valid (hours between 0-23, minutes and seconds between 0-59), otherwise it prints "Wrong input".
  
* [24.c](./24.c): Calculates the parking charge based on the number of hours a car is parked. The first hour costs 2 euros, and each additional hour costs 0.5 euros.

* [25.c](./25.c): Finds the larger of two numbers entered by the user. The max function compares the two numbers and returns the larger one.

* [26.c](./26.c): Defines two functions f(x) and g(x, y) and performs nested calculations. It computes f(x), then g(x, y), and finally applies f to the result of g(x, y), printing each step's output based on user input for x and y.

*[27.c](./27.c): Provides a program for encoding and verifying a sequence of numbers with a custom encoding system. It takes a lower and upper limit from the user, generates an encoding for each number in that range, and checks whether the encoded value is valid based on a specific modulus operation. 

* [28.c](./28.c): Computes the total cost of items, including discounts and loyalty points, based on a passcode input. It allows the user to enter a passcode and item price, applies a discount based on the passcode, computes the discounted price, and accumulates total costs and loyalty points until the user exits with a passcode of 0.

* [29.c](./29.c): Calculates Euler's Totient function (φ(n)) for integers from 1 to a user-input value x. The program checks how many numbers from 1 to n are coprime with n (i.e., their greatest common divisor is 1) and prints the result for each integer up to x.
  
* [3.c](./3.c): Rounds a given number up to a specified number of decimal places using a custom function. It multiplies the number to shift the desired decimal place to an integer position, rounds it up using ceil, and then shifts it back, displaying the result.

* [4.c](./4.c): Calculates the total amount after applying simple interest to a given principal over a certain number of years, based on the interest rate. The result is rounded up to the nearest whole number using the ceil() function.

* [5.c](./5.c): Identifies Armstrong numbers (numbers equal to the sum of the cubes of their digits) in the range from 1 to 999. It achieves this by repeatedly calculating the cube of each digit, summing them, and comparing the result to the original number.

* [6.c](./6.c): Reads two integers and determines the maximum and minimum values between them. It uses the MAX and MIN functions to perform the comparisons and outputs the results.

* [7.c](./7.c): Performs basic arithmetic operations (addition, subtraction, multiplication, and division) on two integers provided by the user. It also computes two custom expressions using these operations and displays all results.

* [8.c](./8.c): Computes the Greatest Common Divisor (GCD) and the Least Common Multiple (LCM) of two integers entered by the user, using recursion for GCD calculation and a formula for LCM. It then outputs both values.

* [9.c](./9.c): Provides a menu with options to convert various units of measurement. The user can choose to convert minutes to hours, feet to meters, Celsius to Fahrenheit, or Fahrenheit to Celsius. Based on the user's selection, the program prompts for an input value, performs the conversion using respective functions, and displays the result. The program continues running until the user selects the "Quit" option.
