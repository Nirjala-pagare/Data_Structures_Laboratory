"""
        Write a Python program to compute following operations on String: 
        a) To display word with the longest length 
        b) To determines the frequency of occurrence of particular character in the string 
        c) To check whether given string is palindrome or not  
        d) To display index of first appearance of the substring 
        e) To count the occurrences of each word in a given string

"""
def menu():
	string = str(input("Enter the String : "))
	flag = 1
	while flag ==1:
		print("1. To Display the Longest Word.")
		print("2. To Determine the Frequency of Occurence of Particular Character.")
		print("3. To check whether the given string is Pallindrome of Particular Character.")
		print("4. To Display the Index of First Appearance of Substring.")
		print("5. To Count the Occurance of each word in given string.")
		print("6. Exit.")
		
		ch = int(input("Enter the choice from 1 to 6:  "))
		if ch == 1 :
			longest(string)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
			
		
		elif ch == 2 :
			character(string)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
			
		elif ch == 3 :
			pallindrome(string)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
			
				
		elif ch == 4:
			firstindex(string)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
			
		elif ch == 5 :
			occurance(string)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
			
		elif ch ==6:
			flag =0
		else:
			print("Enter A Valid Choice")	

		
			
			
def longest(string):
	words= string.split()
	longest_word = ""
	for s in words:
		if len(s) > len(longest_word):
			longest_word = s
	print("Longest Word in the String is " ,longest_word)
	
	
def character(string):
	count = {}
	current_word = ""
	
	for char in string + ' ' :
		if char != ' ' :
			current_word+= char.lower()
			
		else:
			if current_word in count :
				count [current_word] += 1
			else:
				count[current_word] =1
				
			current_word =""
			
	print(count)
	return count
	
	

			
def pallindrome(string):
	c = string[::-1]
	if string==c:
		print("Yes It is A Palindrome String")
	else:
		print("Not A Palindrome String")
		
		
		

def firstindex(string):
	substring=input("enter the substring : ")
	n=len(string)
	m=len(substring)
	
	for i in range (n-m+1):
		match=True
		for j in range(m):
			if string[i+j] !=substring[j]:
				match=False
				break
		if match:
			print (i)
			return i
			
	return -1
	

def occurance(string):
	count=0
	u=input("Occurance of The Character:  " ) 
	for i in string:
		if i == u:
			count += 1
	print("Occurance of the character " ,u, " is " ,count)
	
	



	
menu()
print("\n\n------Thank You for using the Program-------")	

		
