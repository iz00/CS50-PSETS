def main():
    text = input("Text: ")

    words = text.split()

    text = " ".join(words)

    letters_count = 0

    for c in text:
        if c.isalpha():
            letters_count += 1

    if letters_count == 0:
        words_count = 0
        sentences_count = 0
    else:
        words_count = len(words)
        sentences_count = text.count(".") + text.count("!") + text.count("?")

    L = letters_count / words_count * 100
    S = sentences_count / words_count * 100

    print(round(0.0588 * L - 0.296 * S - 15.8))


main()
