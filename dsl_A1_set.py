
"""
        Write a Python program to compute following operations on String: 
        a) To display word with the longest length
        b) To determines the frequency of occurrence of particular character in the string
        c) To check whether given string is palindrome or not 
        d) To display index of first appearance of the substring  
        e) To count the occurrences of each word in a given string


"""
A=[]
B=[]
C=[]

n1=int(input("no of students who play cricket:  "))

for i in range(0,n1):	
        stud_A =int(input())
        if stud_A not in A:
                A.append(stud_A)
        else:
                pass
print(A)
                
                
                

n2=int(input("no of students who play badminton:  "))

for i in range(0,n2):
        stud_B =int(input())
        
        if stud_B not in B:
                B.append(stud_B)
        else:
                pass
print(B)

n3=int(input("no of students who play football:  "))

for i in range(0,n3):
        stud_C=int(input())
                
        if stud_C not in C:
                C.append(stud_C)
        else:
                pass
print(C)


def union(a,b):
       uni = []
       for i in a:
               uni.append(i)
       for j in b:
               if j not in a:
                   uni.append(j)
               else:
                       pass
       return uni





def intersection(a,b):
        inter =[]
        for i in a:
                for j in b:
                        if (i==j):
                                inter.append(i)
                        else:
                                pass
        return inter

def difference(a,b):
        diff = []
        for i in a:
                if (i not in b):
                        diff.append(i)
                else:
                        pass

        return diff




                        



def menu():
        print("enter the roll no of students who plays following games  ")
        flag =1
        while flag ==1:
                print("1.list of students who play both cricket and badminton ")
                print("2.list of students who play either cricket or badminton but not both ")
                print("3.list of students who play nither cricket nor badminton ")
                print("4.list of students who play cricket and football but not badminton ")
                print("5. exit")

                ch = int (input("Enter the choice from 1 to 6: "))
                if ch == 1:
                        a =intersection(A,B)
                        print(a)
                        want = input("want to continue,type yes: ")
                        if want =="yes":
                                flag = 1
                        else:
                                flag =0
                                print("thank you for using the program")

                elif ch == 2:
                        a=union(A,B)
                        b=intersection(A,B)
                        c=difference(a,b)
                        print(c)
                        want = input("want to continue,type yes: ")
                        if want =="yes":
                                flag = 1
                        else:
                                flag =0
                                print("thank you for using the program")

                elif ch == 3:
                        a=union(A,B)
                        b=difference(C,a)
                        print(b)
                        want = input("want to continue,type yes: ")
                        if want =="yes":
                                flag = 1
                        else:
                                flag =0
                                print("thank you for using the program")

                elif ch == 4:
                        a=union(A,C)
                        b=difference(a,B)
                        print(b)
                        want = input("want to continue,type yes: ")
                        if want =="yes":
                                flag = 1
                        else:
                                flag =0
                                print("thank you for using the program")
                
                elif ch ==5:
                        flag =0
                        print("thank you for using the program")

                else :
                        print("enter valid choice")

menu()
