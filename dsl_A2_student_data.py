"""
Experiment Number 2 : Write a python program to store marks stored in subject "Fundamentals of Data Structure" by
                         N students in the class. Write functions to compute following:
                         1. The average score of the class.
                         2. Highest score and lowest score of the class.
                         3. Count of students who were absent for the test.
                         4. Display mark with highest frequency.
"""
no_of_stud = int(input("enter the no. of the students:  "))
limit_of_marks = int(input("enter the maximum marks limit:  "))
marks=[]


i=0
while(i < no_of_stud):
	mark=int(input("enter the marks:  "))
	if mark <= limit_of_marks:
		marks.append(mark)

	else:
		print("enter the marks in limit")
		no_of_stud +=1
	i+=1

def avg(l):
	total = 0
	studs = no_of_stud
	for i in l :
		if i != -1:
			total +=i
		else:
			studs -=1
	return total/studs


def high_freq(mark):
    count_initial = 1 
    freq_list = []    
    count_dyn_list = [] 
    l=len(mark)  
    for i in range(l):
        count_dyn = 1
        
        for j in range(i+1,l):
            if (mark[i]==mark[j] and mark[i] !=-1):
                count_dyn += 1
                
        if count_dyn>count_initial :
            count_dyn_list.append(count_dyn)
            freq_list.append(mark[i])
  

    if len(count_dyn_list)==0:
        print("Every marks' frequency is 1.")
    else:     
        s_max = count_dyn_list[0]
        for k in range(0,len(count_dyn_list),1):
            if count_dyn_list[k]>s_max:
                s_max = count_dyn_list[k]
           
        k_holder = []
        for k in range(0,len(count_dyn_list),1):
            if count_dyn_list[k]==s_max:
                k_holder.append(k)
   
        for h in k_holder:
            print("Highest frequency marks is ",freq_list[h], " with frequency of : ",count_dyn_list[h])


def low(l):
	lowest = l[0]	
	for i in l: 
		if i< lowest and i != -1:
			lowest = i	
	return lowest

def high(l):
	highest = l[0]
	for i in l:
		if i>highest and i != 1:
			highest = i

	return highest 

def absent(l):
	absenty =0 
	for i in l:
		if i == -1:
			absenty += 1
	return absenty
	

def menu():
	
	flag = 1
	while flag ==1:
		print("1. To Display the avarage of marks.")
		print("2. To display the lowest.")
		print("3. To display the highest marks.")
		print("4. To Display the absent number of students.")
		print("5. Exit.")
		
		ch = int(input("Enter the choice from 1 to 6:  "))
		if ch == 1 :
			print("the average marks are: ",avg(marks))
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
		
		elif ch == 2 :
			print("lowest marks are:  ",low(marks))
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
		elif ch == 3 :
			high_freq(marks)
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
				
		elif ch == 4:
			print("absent no of students are:  ",absent(marks))
			want = input("Do You Want to continue,type yes : ")
			if want == "yes":
				flag = 1
			else:
				flag = 0
				print("Thank You for using the Program")
		
		elif ch ==5:
			flag =0
		else:
			print("Enter A Valid Choice")	

menu()
			

