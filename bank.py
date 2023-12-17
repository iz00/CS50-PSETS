greeting = input("Greeting: ").lstrip()

first_word = greeting[:5].lower()

if first_word == "hello":
    print("$0")
elif first_word[0] == "h":
    print("$20")
else:
    print("$100")
