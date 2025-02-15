def is_palindrome(s):
    s = s.lower()
    return s == s[::-1]

# Input from the user
user_input = input("Enter a string: ")
if is_palindrome(user_input):
    print(f"'{user_input}' is a palindrome.")
else:
    print(f"'{user_input}' is not a palindrome.")