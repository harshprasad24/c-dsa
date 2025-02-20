#type-1
food = input("Food :")
print("sweet") if food=="cake" or food=="maggie" else print("not sweet")

#type-2
age = int(input("age:"))
vote= ("yes" , "No")[age<=18]
print(vote)
#type-3
income=int(input("income:"))
tax=income*(0.1 ,0.2)[income<=50000]
print(tax)

#type-4
food = input("Food :")
eat ="yes" if food=="cake" else "no"
print(eat)

#type-5
color=input("color :")
if(color=="red"):
    print("Stop")
elif(color=="yellow"):
    print("Look")
elif(color=="green"):
    print("Go")
else:
    print("Invalid")